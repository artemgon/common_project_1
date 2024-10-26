#include "domain.h"

int main()
{
	Product newProduct("Guitar", 1400, 10);
	newProduct.GetInfo();
	DiscountedProduct newDiscountedProduct("Electric Bass Guitar", 2300, 10, 15);
	newDiscountedProduct.GetInfo();
	Product* productPtr = &newDiscountedProduct;
	productPtr->GetInfo();
	return 0;
}