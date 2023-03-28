#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ofstream("data17") << "Asoka\n master\n  lord\n word\n peter\n";
    const Doc d("data17");
    cout << "Low Ground Size " << d.size() << "\n";
    return 0;
}
