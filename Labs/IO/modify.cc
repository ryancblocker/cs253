#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
		cerr << "usage: " << argv[0] << "ERROR: wrong amount of files (Program Name Infile)\n";
		return 1;
    }
    fstream in(argv[1]);
    
    if (!in) {
		cerr << argv[0] << ": can't open " << argv[1] << '\n';
		return 2;
    }
    string before = "Trump";
    string after = "Biden";
    
    for (string line; getline(in, line); ) {
		for (size_t pos=0; (pos=line.find(before, pos)) != line.npos; pos+=before.size()) {
		    auto save = in.tellg();
		    in.seekp(-(line.size()+1) + pos, ios::cur);
		    in << after;
		    in.seekp(save);
		}
    }
    
    return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
