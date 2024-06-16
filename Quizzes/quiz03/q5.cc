#include <iostream>
#include <string>

using namespace std;

int main()
{
	string omega = "abc";
	omega += 'd';
	omega.push_back('e');
	cout << omega.length();
}
