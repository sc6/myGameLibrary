#include "ArrayInventory.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Item pencil = Item("Pencil", "A wooden stick with a graphite carbon interior, allowing you to write things with it.");
	pencil.AddQuantity(-16);

	//Unit tests for ArrayInventory.h
	ArrayInventory bag = ArrayInventory(2);
	cout << "Created space in " << &bag << " for bag." << endl;
	bag.AddItem(pencil);
	bag.AddItem(pencil);
	bag.AddItem(pencil);
	bag.PrintInventory(1);

	string end;
	cout << "Enter a character to end the program." << endl;
	cin >> end;
}