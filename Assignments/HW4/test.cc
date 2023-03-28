#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream("data") << "\r \r  \n\n Peter  \n   Ray\r \nEgon  \n \n\r\n\n";
    Doc d;
    assert(d.empty() && !d);
    ifstream in("data");
    in >> d;
    assert(d && !d.empty());
    assert(d.size()==3);
    assert(d[0].indent == 1);
    assert(d[1].indent == 3);
    assert(d[2].indent == 0);
    assert(d[0].data == "Peter");
    assert(d[1].data == "Ray");
    assert(d[2].data == "Egon");

    d += "      Winston     ";
    assert(d.size() == 4);
    assert(d[3].indent == 6);
    assert(d[3].data == "Winston     ");

    for (size_t n=0; n<d.size(); n++) {
        const auto stuff = d[n];
        cout << n << ": " << stuff.indent << ' ' << stuff.data << '\n';
    }
    cout << "---\n" << d << "---\n";

    d += "";
    assert(d.size() == 5);
    assert(d[4].indent == 0);
    assert(d[4].data == "");

    const Doc vacant;
    assert(vacant.empty() && !vacant && vacant.size()==0);
    d = vacant;
    assert(d.empty() && !d && d.size()==0);
    
    cout << "\n-----------------------------------------------";
    cout << "\nRyans Tests\n\n";
    
    ofstream("data") << "\r \r  \n\n Ryan\n   Ray Blocker\r \n    Egon  \n \n\r\n\n";
    Doc t;
    ifstream input("data");
    input >> t;
    cout << "t[]: " << t[0].indent << "\n";
    ofstream("beta") << "\r \r  \n\n Hello\n   Max\r \n    Meyer  \n \n\r\n\n";
    Doc p;
    ifstream input2("beta");
    input2 >> p;
    Doc g = t + p;
    cout << g;
    Doc f = g + " SemperFiBrother";
    cout << "\n\ng: " << f;
    Doc e = "SpideyMan" + f;
    cout << "\n\nE: \n" << e;
    cout << d << "---\nDone.\n";

    return 0;
    
}
