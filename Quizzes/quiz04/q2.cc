#include <iostream>
using namespace std;

class Foo {
	public: char red[32];
	private: char blue[32];
	static char green[32];
};
int main() {
	Foo bar;
	cout << sizeof(bar);
	return 0;
}
