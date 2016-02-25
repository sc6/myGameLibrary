#pragma once

#include "Item.h"
#include <string>

#ifndef INVENTORY_INVENTORY_ARRAYINVENTORY_H_
#define INVENTORY_INVENTORY_ARRAYINVENTORY_H_

using namespace std;


//Holds a baggage of Items. (Structured using an array)
class ArrayInventory
{

	Item* bag;		//Array where Items are stored.
	int capacity, spaceTaken;

	//Returns the next available space in the bag as an index. This may return an empty
	//space between two items.
	//Returns -1 if bag is full or bag capacity is 0.
	const int FindEmptySpace() const;

	//Defragments the bag, removing empty spaces between any two items.
	void DefragBag();

	
public:

	//Creates an inventory with a max size of "size"
	ArrayInventory(const int size);

	//Properly deallocates bag from memory
	~ArrayInventory();

	//TODO(steve): fix inconsistancies between this and below function.
	//Deducts one of item_ptr and adds one equivalent to the bag.
	//Checks if item quantity is <= zero first.
	//Note: If item cannot be added for whatever reason, the source item still may still be deducted!
	void AddItem(Item& item_ptr);

	//Deducts "qty" of item_ptr and adds "qty" of its equivalent to the bag.
	void AddItem(Item& item_ptr, const int qty);

	//Removes one of item_ptr equivalent from the bag.
	//Afterwards, defragments the bag.
	void RemoveItem(Item& item_ptr);

	//Removes "qty" of item_ptr equivalent from the bag.
	//Afterwards, defragments the bag.
	void RemoveItem(Item& item_ptr, const int qty);

	//Returns the position in inventory that contains item equivalent.
	//Returns -1 if item not found.
	const int FindItem(const Item& item) const;

	//Prints to cout the contents of the inventory (bag).
	//Defaults viewMode to 1. No other options are currently supported.
	void PrintInventory(const int viewMode) const;
};

#endif // INVENTORY_INVENTORY_ARRAYINVENTORY_H_