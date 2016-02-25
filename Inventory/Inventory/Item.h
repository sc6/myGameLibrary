#pragma once

#include <string>

#ifndef INVENTORY_INVENTORY_ITEM_H
#define INVENTORY_INVENTORY_ITEM_H

using namespace std;


class Item
{
	string name;
	string description;
	int quantity;


public:
	//Default constructor.
	Item();

	//Creates a copy of "item."
	Item(const Item& item);

	//Creates an item with "name" and "description."
	Item(const string name, const string description);

	//No special function.
	~Item();
	
	//Equivalency operator checks for same name and description. Does NOT check quantity.
	bool operator==(const Item& b) const;

	//Implements AddQuantity(1)
	Item& operator++(int);

	//Decrement operator reduces quantity by 1.
	//Quantity never drops below zero.
	Item& operator--(int);

	//Returns the item's name.
	const string GetName() const;

	//Returns the item's description.
	const string GetDescription() const;

	//Returns the item's quantity.
	int GetQuantity() const;

	//Add "amount" to item's quantity.
	//Does nothing if input would cause an integer overflow.
	//Does nothing if input is negative.
	void AddQuantity(const int amount);

	//Subtract "amount" from item's quantity.
	//Item's quantity never drops below zero.
	//Does nothing if input is negative.
	void SubtractQuantity(const int amount);

};

#endif // INVENTORY_INVENTORY_ITEM_H