#include "Doc.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ofstream("data") << "\r \r  \n\nPeter  \n   Ray\r \n  Egon  \n \n\r\n";
    Doc d("data");
    assert(!d.empty());

//TESTING
    //cout << "\n\n" << d.indent(0) << "\n";
    //cout << d.indent(1) << "\n";
    //cout << d.indent(2) << "\n";
    //cout << d.indent(3) << "\n\n";
    //cout << d.data(3) << "\n";

    assert(d.size()==3);
    assert(d.indent(0) == 0);
    assert(d.indent(1) == 3);
    assert(d.indent(2) == 2);
    assert(d.data(0) == "Peter");
    assert(d.data(1) == "Ray");
    assert(d.data(2) == "Egon");

    d.add("   Winston     ");
    assert(d.size() == 4);
    assert(d.indent(3) == 3);
    assert(d.data(3) == "Winston     ");

    d.add("");
    assert(d.size() == 5);
    assert(d.indent(4) == 0);
    assert(d.data(4) == "");
    cout << "Done.\n";

    const Doc vacant;
    assert(vacant.empty() && vacant.size()==0);
    d = vacant;
    assert(d.empty() && d.size()==0);

	

    return 0;
}
