#include <iostream>
#include <stdexcept>
using namespace std;

void bella() {
	throw runtime_error("Edward");
}
void jacob() {
	bella();
}
int main() {
	try {
		jacob();
	}
	catch (const runtime_error &re) {
		cout << "[[[" << re.what() << "]]]\n";
	}
}
