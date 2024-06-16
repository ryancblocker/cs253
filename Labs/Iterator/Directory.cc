#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg, const std::string &str) : dp(dp_arg), match(str)
{
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	    name = p->d_name;		    // C-string ⇒ C++ string
        if(wanted())
	    {
            return *this;
	    }			                // Everything else, I like!
    }
    dp = nullptr;			        // readdir failed; don’t try again.
    return *this;
}

bool DirectoryIterator::wanted() const // Fix #2.
{
	if (name == ".")		// Stupid entry for current directory?
	    return false;			// Nobody wants that.
	if (name == "..")		// Stupid entry for parent directory?
	    return false;
	if	(name.find(match) == string::npos)	//Fix #3.		
	    return false;
	return true;
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}

//////////////// Directory methods

Directory::Directory(const char dirname[], const std::string &str) : dp(opendir(dirname)), match(str) //Fix #3.
{
	if(dp == NULL)
	{
		throw runtime_error("ERROR: That directory does not exist. Please give a valid directory"); // Fix #1.
	} 
}

Directory::Directory(const char dirname[]) : dp(opendir(dirname)) 
{
	if(dp == NULL)
	{
		throw runtime_error("ERROR: That directory does not exist. Please give a valid directory"); // Fix #1.
	} 
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);		//   should we close it.
}

Directory::iterator Directory::begin() const {
    return iterator(dp, match);
}

Directory::iterator Directory::end() const {
    return iterator();
}
