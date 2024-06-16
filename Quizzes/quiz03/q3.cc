#include <iostream>

int main()
{
	auto p = new bool[1000];
	delete p;
	delete p;
	return 0;
}

