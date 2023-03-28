#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << '$' << left << setw(3) << 42 << '$';
	return 0;
}
