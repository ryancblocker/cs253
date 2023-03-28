#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

using namespace std;

int main()
{


	//1. Read all integers into vector<int> until 0 is entered

	vector<int> inputVector;
        int inputNum;

	//cout << "Enter numbers into your vector: \n\n";

	while(cin >> inputNum)
	{
		if (inputNum != 0)
		{
			inputVector.push_back(inputNum);
		}
		else
		{
			cout << "\n";
			break;
		}
	}

	//cout << "Your vector contains: \n\n";

	//2. Display all the integers from vector one per line

	for (size_t i = 0; i < inputVector.size(); i++)
	{
		cout << inputVector[i] << "\n";
	}

	cout << "\n";

	//3. Read everything from the file /etc/resolv.conf into one big string

	string emptyString  = "";
	char WholeFile;
	ifstream in("/etc/resolv.conf");
	while(in.get(WholeFile))
	{
		emptyString += WholeFile;
	}

	//4. Copy everything from file into a multiset<char>

	multiset<char> ms;
	for(auto c : emptyString) ms.insert(c);

	//5. Copy everything from the multiset<char> to a set<char>

	set<char> s(ms.begin(), ms.end()) ;
	//for(auto c : ms) s.insert(c);

	//6. display the size and charachters from the string, set<char> and multiset<char

	cout << "string: size=" << emptyString.size() << " " << emptyString;
	cout << "set: size=" << s.size();
	for (auto val : s)
		cout << val;
	cout << "\n";
	cout << "multiset: size=" << ms.size();
	for (auto val : ms)
		cout << val;
	cout << "\n\n";

	//QUESTION 7. The string and multiset size are both 113 because they both can store
	//duplicate values. Whereas, the set can only store unique values. This is why the
	//string and multiset have a size of 113 while the set only has 26. Additionally,
	//we cannot chnage the values of a set after the values have been inserted.
	//However, the multiset and string can change there values after the values have
	//been assigned. 

	return 0;
}
