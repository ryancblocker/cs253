#include <iostream>
#include <chrono>
using namespace std;

int main()
{
	auto d = 1h + 30min;
	cout << d.count();
}
