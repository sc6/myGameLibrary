#include "ArrayInventory.h"
#include <iostream>

using namespace std;

const int ArrayInventory::FindEmptySpace() const
{
	if (capacity == 0) {
		cerr << "Debug: FindEmptySpace() size of bag is zero." << endl;
		return -1;	//bag capacity is 0
	}

	for (int i = 0; i < capacity; i++) {
		if (bag[i].GetName().compare("") == 0) {
			return i;
		}
	}

	cerr << "Debug: FindEmptySpace() bag is full." << endl;
	return -1;	//the bag is full
}

void ArrayInventory::DefragBag()
{
	int a = FindEmptySpace();
	if (a == -1) return;			//bag contains no empty spaces.
	
	Item emptyItem = bag[a];

	for (int i = (a + 1); i < capacity; i++) {
		if (bag[i] == emptyItem) {
			bag[a] = bag[i];
			bag[i] = emptyItem;
			a = FindEmptySpace();
			if (a == -1) return;
		}
	}

	return;							//defrag is done
}


ArrayInventory::ArrayInventory(int size)
{
	bag = new Item[size];
	capacity = size;
}

ArrayInventory::~ArrayInventory()
{
	delete[] bag;
}

void ArrayInventory::AddItem(Item& item_ptr)
{
	if (item_ptr.GetQuantity() <= 0) {
		cerr << "Error: Quantity of item is zero, thus cannot be added to the inventory." << endl;
		return;
	}
	item_ptr--;

	int pos = FindItem(item_ptr);
	if (pos == -1) {	//item not found
		pos = FindEmptySpace();
		if (pos == -1) {
			cerr << "Error: Bag is full and cannot add any new items." << endl;
			return;
		}
		bag[pos] = Item(item_ptr);
	}
	else {
		bag[pos]++;
	}
}

void ArrayInventory::AddItem(Item& item_ptr, const int qty)
{
	bool notEnough = false;
	
	int iqty = item_ptr.GetQuantity();
	item_ptr.SubtractQuantity(qty);	//will not go below zero
	
	if (iqty < qty) notEnough = true;
	
	int pos = FindItem(item_ptr);

	if (pos == -1) {	//item not found
		pos = FindEmptySpace();
		if (pos == -1) {
			cerr << "Error: Bag is full and cannot add any new items." << endl;
			return;
		}
		bag[pos] = Item(item_ptr);
		if (notEnough) bag[pos].AddQuantity(iqty);
		else bag[pos].AddQuantity(qty);
	}
	else {
		if (notEnough) bag[pos].AddQuantity(iqty);
		else bag[pos].AddQuantity(qty);
	}

}

void ArrayInventory::RemoveItem(Item& item_ptr)
{
	item_ptr--;	//can't go below zero using this function
	DefragBag();
}

void ArrayInventory::RemoveItem(Item& item_ptr, const int qty)
{
	item_ptr.SubtractQuantity(qty);	//can't go below zero using this function
	DefragBag();
}

const int ArrayInventory::FindItem(const Item& item) const
{
	for (int i = 0; i < capacity; i++)
	{
		if (item == bag[i]) return i;
	}
	return -1;	//item search exhausted
}

void ArrayInventory::PrintInventory(const int viewMode) const
{
	cout << "--Inventory--" << endl;
	for (int i = 0; i < capacity; i++)
	{
		if (bag[i].GetQuantity() == 0) {
			cout << "\t[" << i << "]\t" << "--empty--" << "\t" << endl;
		}
		else {
			cout << "\t[" << i << "]\t" << bag[i].GetName() << "\t" << bag[i].GetQuantity() << endl;
		}
		
	}
}
