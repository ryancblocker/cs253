#include <iostream>
#include "ll.h"

using namespace std;

int main() {
	LinkedList list;
        for (bool done = false; !done; ) {
		unsigned int i;
		int option;

		cout << "Choose your operation:\n"
	     	<< "1. insert\t2. remove\t3. exit\t      4. print\n";

		cin >> option;

		switch (option) {
			case 1:
				cout << "Enter the number to insert\n";
				cin >> i;
				list.insert(i);
				break;
	    		case 2:
				if (list.remove(i))
		        		cout << "You removed " << i << " from the list\n";
				else
		        		cout << "No numbers in the linked list\n";
				break;
	        	case 3:
				done = true;
				list.stop();		//quit the program and remove nodes
				break;
	        	case 4: 			//print method
				cout << list;
				break;
		}
	}

	return 0;
}
