#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number& operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value = 0;			// default value unless otherwise given
};

istream& operator>>(istream &is, Number &rhs) {
    int n;
    string str;
    is >> n;
    if(!is) {
	is.clear();
	is >> str;
	if(str == "one")
		n = 1;
	else if(str == "two")
		n = 2;
	else if(str == "three")
		n = 3;
	else if(str == "four")
		n = 4;
	else if(str == "five")
		n = 5;
	else
		is.clear(is.failbit);
    }
    rhs = n;
    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}
