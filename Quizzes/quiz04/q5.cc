#include <iostream>
using namespace std;

class RainbowDash {
    public:
        RainbowDash() : company("Hasbro") { }
        RainbowDash(string c) : company("pony") { }
	string company = "pegasus";
};
int main() {
	RainbowDash rd();
	cout << rd.company << '\n';
	return 0;
}
