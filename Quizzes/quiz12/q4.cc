#include <iostream>
using namespace std;

int main()
{
    auto out = [](auto a) { cout << a+1;};
    out("hello");
    cout << ' ';
    out(4.56);
}
