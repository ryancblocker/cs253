#include <iostream>

using namespace std;

void foo(int chi)
{
	constexpr auto c = chi;
	cout << c;
}
int main()
{
	foo(5);
	return 0;
}
