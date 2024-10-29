#ifndef class_A
#define class_A
#include "libs.h"

class ShoppingCart  {
private:
    vector<shared_ptr<Product>> products; 
    double totalAmount;                    

public:
    ShoppingCart() : totalAmount(0.0) {}

    void addProduct(const shared_ptr<Product>& product) {
        products.push_back(product);
        totalAmount += product->getPrice() * product->getQuantity(); 
    }

    void removeProduct(const shared_ptr<Product>& product) {
        auto it = remove_if(products.begin(), products.end(), [&product](const shared_ptr<Product>& p) {
            return p->getName() == product->getName();
            });

        if (it != products.end()) {
            totalAmount -= product->getPrice() * product->getQuantity(); 
            products.erase(it, products.end());
        }
        else {
            cout << "Product not found in the cart." << endl;
        }
    }

    double calculateTotal() const {
        return totalAmount;
    }
    vector<shared_ptr<Product>> getProducts() const {
        return products;
    }
};

class Order {
private:
    int orderId;                             
    vector<shared_ptr<Product>> products;    
    double totalAmount;                      
    string status;                            

public:
    Order(int id) : orderId(id), totalAmount(0.0), status("In process") {}

    void createOrder(const ShoppingCart& cart) {
        products = cart.getProducts(); 
        totalAmount = cart.calculateTotal(); 
    }

    void updateStatus(const string& newStatus) {
        status = newStatus; 
    }

    string getOrderDetails() const {
        string details = "Order ID: " + to_string(orderId) + "\nStatus: " + status + "\nTotal Amount: " + to_string(totalAmount) + "\nProducts:\n";
        for (const auto& product : products) {
            details += product->GetInfo() + "\n";
        }
        return details;
    }
};

#include <string>
#include <vector>

class User {
private:
    int userId;                              
    string name;                              
    vector<Order> orderHistory;            

public:
    User(int id, const string& userName) : userId(id), name(userName) {}

    void viewOrderHistory() const {
        cout << "Order History for " << name << ":\n";
        for (const auto& order : orderHistory) {
            cout << order.getOrderDetails() << endl;
        }
    }

    void placeOrder(ShoppingCart& cart) {
        static int orderIdCounter = 1;  
        Order newOrder(orderIdCounter++);
        newOrder.createOrder(cart); 
        orderHistory.push_back(newOrder); 
    }

    void addToCart(const shared_ptr<Product>& product, ShoppingCart& cart) {
        cart.addProduct(product); 
    }
};
#endif 



