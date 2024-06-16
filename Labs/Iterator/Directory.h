#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED

#include <dirent.h>
#include <string>

// Normally, I’d have DirectoryIterator be a nested class, Directory::iterator,
// to avoid namespace pollution.  However, this is easier to read.

class DirectoryIterator {
  public:
    DirectoryIterator() = default;
    DirectoryIterator(DIR *, const std::string &str);
    DirectoryIterator& operator++();
    std::string operator*() const;
    bool operator!=(const DirectoryIterator &) const;
  private:
    bool wanted() const;
    DIR *dp = nullptr;
    std::string name;
    std::string match;
};

class Directory {  
  public:
    typedef DirectoryIterator iterator;
    Directory() = delete;		// not really necessary
    Directory(const char dirname[], const std::string &str);
    Directory(const char dirname[]);
    ~Directory();
    iterator begin() const;
    iterator end() const;
  private:
    DIR *dp;				// null if open failed
    std::string match;
};

#endif /* DIRECTORY_H_INCLUDED */
