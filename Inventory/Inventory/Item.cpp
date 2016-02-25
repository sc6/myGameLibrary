#include "Item.h"
#include <iostream>

Item::Item() 
{
	this->name = "";
	this->description = "";
	this->quantity = 0;
}

Item::Item(const Item& item) 
{
	this->name = item.name;
	this->description = item.description;
	this->quantity = 1;
}

Item::Item(const string name, const string description)
{
	this->name = name;
	this->description = description;
	this->quantity = 1;
}

Item::~Item()
{

}

bool Item::operator==(const Item& b) const
{
	if (name.compare(b.name) == 0 && description.compare(b.description) == 0) {
		return true;
	}
	else return false;
}

Item& Item::operator++(int)
{
	AddQuantity(1);
	return *this;
}

Item& Item::operator--(int)
{
	quantity--;
	if (quantity < 0) quantity = 0;
	return *this;
}

const string Item::GetName() const
{
	return this->name;
}

const string Item::GetDescription() const
{
	return this->description;
}

int Item::GetQuantity() const
{
	return quantity;
}

void Item::AddQuantity(const int amount)	//TODO(steve): Must fix calls of this so that for edge cases, items are not subtracted as function this does nothing.
{
	long check = amount + quantity;
	if (INT_MAX < check) {
		cerr << "Error: This amount of this item cannot be added, and so this request was ignored." << endl;
		return;
	}
	if (amount <= 0) {
		cerr << "Error: A non-positive amount of this item was requested; this request was ignored." << endl;
		return;
	}
	quantity += amount;
}

void Item::SubtractQuantity(const int amount)
{
	if (amount <= 0) return;
	quantity -= amount;
	if (quantity < 0) quantity = 0;
}