#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

int main() {

	//variables (input + vector) (1)
	string in1;
	int conversionVal;
	vector<int> vInt;
	//get input from std input
	getline(cin, in1);

	//convert string to int + add to vector
	stringstream convert(in1);
	while(convert >> conversionVal) {
		if (conversionVal != 0) {
			vInt.push_back(conversionVal);
		}
		else {
			break;
		}
	}

	//print out values (2)
	for (size_t i = 0; i < vInt.size(); i++) {
		cout << vInt[i] << '\n';
	}

	//reading contents from a file (3)
	string empt = "";
	char wholefile;
	ifstream in("/etc/resolv.conf");
	while(in.get(wholefile)) {
		empt += wholefile;
	}
	//test print
	//cout << "STRING FROM FILE" <<  empt;

	//copy string to multiset (4)
	multiset<char> cpMSet;
	set<char> cpSet;
	for(char c : empt) cpMSet.insert(c);

	//copy multiset to set 
	for (char c : cpMSet) cpSet.insert(c);
	//display .size() + string
	cout << "string: size = " << empt.length() << '\n';
	cout << empt << "\n";
	//display set size and set
	cout << "set: size = " << cpSet.size() << "\n";
	for(char c : cpSet) cout << c;
	cout << "\n\n";
	//display multiset size and multiset
	cout << "multiset: size = " << cpMSet.size() << "\n";
	for(char c : cpMSet) cout << c;

	//QUESTION 7: The string and multiset size are both 113 because, the multiset
	//and string contain every charachter in the file. Whereas the set only 
	//contrains the 26 unique charchters that both the string and multiset 
	//contains.  
}
