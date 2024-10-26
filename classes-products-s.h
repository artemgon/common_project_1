#ifndef classes_products_s
#define classes_products_s
#include "libs.h"
class Product
{
protected:
	string name;
	double price;
	int quantity;
public:
	Product(const string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}
	virtual ~Product() = default;

	virtual string getName() const
	{
		return name;
	}
	virtual double getPrice() const
	{
		return price;
	}
	virtual int getQuantity() const
	{
		return quantity;
	}
	virtual void updatePrice(double newPrice)
	{
		price = newPrice;
	}
	virtual void updateQuantity(int newQuantity)
	{
		quantity = newQuantity;
	}

	virtual string GetInfo() const
	{
		return "Product: " + name + "\nPrice: " + to_string(price) + "\nQuantity: " + to_string(quantity) + "\n";
	}

};


class DiscountedProduct : public Product
{
private:
	double discount;
public:
	DiscountedProduct(const string name, double price, int quantity, double discount) : Product(name, price, quantity), discount(discount) {}
	double getPrice() const override
	{
		return price * (1 - discount / 100);
	}
	void setDiscount(double newDiscount)
	{
		discount = newDiscount;
	}

	virtual string getInfo() const
	{
		return "Product: " + name + "\nPrice: " + to_string(price) + "\nQuantity: " + to_string(quantity) + "\nDiscount: " + to_string(discount) + "%" + "\nDiscounted price:" + to_string(getPrice()) + "\n";
	}
};

class Category
{
private:
	string name;
	vector<shared_ptr<Product>> products;
public:
	Category(const string& name) : name(name) {}


	void addProduct(const shared_ptr<Product>& product)
	{
		products.push_back(product);
	}
	void removeProduct(const string productName)
	{
		products.erase(remove_if(products.begin(), products.end(), [&productName](const shared_ptr<Product>& product) 
			{
				return product->getName() == productName;
			}),
			products.end());
			
	}
	void listProducts() const
	{
		cout << "Category: " << name << endl;
		for (const auto& product : products)
		{
			cout << product->GetInfo() << endl;
		}
	}
	int getProductCount() const
	{
		return products.size();
	}

};
#endif 