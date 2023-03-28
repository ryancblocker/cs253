#include <iostream>
using namespace std;

void foo(constexpr auto psi)
{
	constexpr auto c = psi;
	cout << c;
}

int main()
{
	foo(5);
	return 0;
}
