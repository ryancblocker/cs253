#include <iostream>
using namespace std;

class Bob {
    public:
	Bob(int n) : purple(n) { }
	int purple = 52;
};

int main() {
	Bob b;
	cout << b.purple << '\n';
	return 0;
}
