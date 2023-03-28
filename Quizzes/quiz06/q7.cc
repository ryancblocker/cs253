#include <iostream>
using namespace std;

class Base {
	virtual void foo();
};

class h1 : public Base {};
class h2 : public Base {};

int main() {

Base *b1 = new h1;
Base *b2 = new h2;


if (dynamic_cast<h1 *>(b1)) 
	cout << '1';
if (dynamic_cast<h1 *>(b2)) 
	cout << '2';
if (dynamic_cast<h2 *>(b1)) 
	cout << '3';
if (dynamic_cast<h2 *>(b2)) 
	cout << '4';

return 0;

}
