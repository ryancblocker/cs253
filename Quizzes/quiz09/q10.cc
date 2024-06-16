#include <iostream>
using namespace std;

void invalid_argument(const string &arg) {
	cerr << "Invalid argument: " << arg << '\n';
}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		invalid_argument(argv[1]);
	}
}
