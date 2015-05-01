// Final Project

#include <iostream>
#include "ItemTree.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    ItemTree Item;

    ifstream infile;
    infile.open(argv[1]);
    string line;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            int commaPos1 = line.find(',');
            string item = line.substr(0, commaPos1);
			string rest = line.substr(commaPos1+1);
			commaPos1 = rest.find(',');
            int price = stoi(rest.substr(0, commaPos1));
            string cat = rest.substr(commaPos1+1);
            

            Item.addItemNode(item, price, cat);
        }

        infile.close();
    }

    int input;
    while (input != 10)
    {
        cout << "*******MENU*******" << endl
			 << "1. Add an item to sell" << endl
			 << "2. Delete an item that was sold" << endl
			 << "3. Look for an item in the list" << endl
			 << "4. Number of unsold items in the list" << endl
			 << "5. Display unsold items (In order)" << endl
			 << "6. Display unsold items (Pre order)" << endl
			 << "7. Display unsold items (Post order)" << endl
			 << "8. Display sold items" << endl
			 << "9. Find items in a category" << endl
			 << "10. Exit" << endl;
        cin >> input;
        cin.ignore(10000,'\n');

        if (input == 1)
        {
            string item;
            cout << "What is your item to sell:" << endl;
            getline(cin, item);

            int price;
            cout << "What is the price of the item:" << endl;
            cin >> price;            
            int _cat;
            cout << "What is the category of the item:" << endl
            << "1. Upper" << endl
			<< "2. Lower" << endl
			<< "3. Hat" << endl
			<< "4. Shoes" << endl
			<< "5. Other" << endl;
            cin >> _cat;
            string cat;
            if (_cat == 1)
            {
				cat = "Upper";
			}
			else if (_cat == 2)
			{
				cat = "Lower";
			}
			else if (_cat == 3)
			{
				cat = "Hat";
			}
			else if (_cat == 4)
			{
				cat = "Shoes";
			}
			else if (_cat == 5)
			{
				cat = "Other";
			}
            Item.addItemNode(item, price, cat);
        }

        else if (input == 2)
        {
            string itemDelete;
            cout << "What is the item that is sold:" << endl;
            getline(cin, itemDelete);

            Item.deleteItemNode(itemDelete);
        }

        else if (input == 3)
        {
            string itemFind;
            cout << "What is the item you want to find:" << endl;
            getline(cin, itemFind);

            Item.findItem(itemFind);
        }

        else if (input == 4)
        {
            cout << Item.countItemNodes() << " items remain unsold" << endl;
        }

        else if (input == 5)
        {
            Item.printInOrder();
        }

        else if (input == 6)
        {
            Item.printPreOrder();
        }

        else if (input == 7)
        {
            Item.printPostOrder();
        }

        else if (input == 8)
        {
            Item.printSold();
        }
        else if (input == 9)
        {
            int _cat;
            cout << "Enter a category to search for:" << endl
            << "1. Upper" << endl
			<< "2. Lower" << endl
			<< "3. Hat" << endl
			<< "4. Shoes" << endl
			<< "5. Other" << endl;
            cin >> _cat;
            string cat;
            if (_cat == 1)
            {
				cat = "Upper";
			}
			else if (_cat == 2)
			{
				cat = "Lower";
			}
			else if (_cat == 3)
			{
				cat = "Hat";
			}
			else if (_cat == 4)
			{
				cat = "Shoes";
			}
			else if (_cat == 5)
			{
				cat = "Other";
			}
            Item.printFromCat(cat);
        }
    }

    cout << "Exit" << endl;
}
