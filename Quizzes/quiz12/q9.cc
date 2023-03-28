#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    const char *gold = "James T. Kirk";
    cout << find(begin(gold), end(gold), 'T');
}
