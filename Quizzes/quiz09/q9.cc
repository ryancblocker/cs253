#include <iostream>
#include <istream>
#include <fstream>
using namespace std;

int main() {
ofstream("zork") << "omg\n";
ifstream in("zork");
int a;
in >> a;
if (in)
	cout << 1;
if (in.bad())
	cout << 2;
if (in.eof())
	cout << 3;
if (in.fail())
	cout << 4;
if (in.good())
	cout << 5;
return 0;	
}
