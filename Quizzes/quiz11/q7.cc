#include <iostream>
#include <string>
using namespace std;

int main() {

string s("A");
s.resize(100);
auto it = s.begin();
for (int i = 0; i<50; i++)
    s += 'B';
cout << *it << endl;

return 0;
}
