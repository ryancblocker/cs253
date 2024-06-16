#include <iostream>
using namespace std;

class Red {
    public:
	Red() { cout << 1; }
	~Red() { cout << 2; }
};

class White {
    public:
	White() { cout << 3; }
	~White() { cout << 4; }
};

class Blue : public White {
    public:
	Blue() { cout << 5; }
	~Blue() { cout << 6; }
	Red r;
};

int main() {
    Blue b;
    cout << 7;
}
