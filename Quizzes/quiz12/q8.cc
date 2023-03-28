#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {5, 17, 23, 43, 52, 204};
    cout << *find(a, a+4, 31);
}
