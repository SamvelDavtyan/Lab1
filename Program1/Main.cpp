#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List lst;
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	
	List lst2;
	lst2.push_back(0);
	lst2.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst2.push_back(4);

	lst.push_front(lst2);

	cout << lst2.at(2) << endl << endl;
	cout << lst.at(2) << endl << endl;

	lst.print_to_console();
	return 0;
}