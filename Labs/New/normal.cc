#include <iostream>

using namespace std;

class Foo {
  public:
    double datum;
};

int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    for(size_t i = 0; i < 10000000; i++)
    {
    	Foo *b;
    	cout << b;
    }
    
    cout << "\n\nTIME: \n";
    return 0;
}
