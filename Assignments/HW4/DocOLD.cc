#include "Doc.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

Doc::Doc() { }

Doc& Doc::operator=(const Doc &newLineStruct)
{
	lines = newLineStruct.lines;
	return *this;
}

Doc::~Doc() { }
/*
	ifstream path(filePath);
	if(!path)
	{
		cerr << "\nERROR: The file: \"" << filePath << "\" was not able to be read\n";
		exit(1);
	}
	//Put file into string and count leading spaces
	for(string wholeLine; getline(path, wholeLine);) {
		string tabSearch = "\t";
		size_t found = wholeLine.find(tabSearch);
		if(found!=string::npos)
			cerr << "\nERROR: A tab charachter has been read\n";
		size_t indentCount = 0;
		for(size_t i = 0; i < wholeLine.size(); i++) {
			if(wholeLine.back() == ' ' || wholeLine.back() == '\r') {
				wholeLine.pop_back();
			}
		}
		for(char c : wholeLine)
			if(c == ' ') { indentCount++; }
			else { goto addToVector; }
	addToVector:
		if(wholeLine.size() != 0) {
			lines.push_back({indentCount, wholeLine});
		}
	}
	lines.erase(lines.begin()); 
	*/

//Doc Constructor (same as .read (PATH))
Doc::Doc(std::string &filePath)
{
	read(filePath);
}
//Doc Constructor (same as .read (ISTREAM))
Doc::Doc(std::istream &in)
{
	read(in);
}

//Read Method (PATH): Read from the given file path removing trailing spaces and \r carriage returns
void Doc::read(std::string &filePath)
{
	//Jack's Read Method he wrote in class.
	ifstream path(filePath);
	if(!path) {
		cerr << "\nERROR: The file: \"" << filePath << "\" was not able to be read\n";
		exit(1);
	}
	
	lines.clear();
	for(string s; getline(path, s); ) {
		for(char c : s)
			if(c == '\t') {
				cerr << "\nERROR: A tab charachter has been read\n";
				exit(1);
			}
		while(!s.empty() && (s.back() == ' ' || s.back() == '\r'))
			s.pop_back();
		size_t leading = 0;
		while (leading < s.size() && s[leading] == ' ') leading++;
		Line addme;
		addme.indent = leading;
		addme.data = s.substr(leading);
		lines.push_back(addme);
}
//Read Method (ISTREAM): Read from the input stream
void Doc::read(std::istream &readIn)
{
	lines.clear();
	for(string s; getline(in, s); ) {
		for(char c : s)
			if(c == '\t') {
				cerr << "\nERROR: A tab charachter has been read\n";
				exit(1);
			}
		while(!s.empty() && (s.back() == ' ' || s.back() == '\r'))
			s.pop_back();
		size_t leading = 0;
		while (leading < s.size() && s[leading] == ' ') leading++;
		Line addme;
		addme.indent = leading;
		addme.data = s.substr(leading);
		lines.push_back(addme);
}
//Write Method (PATH): Write to the document to another file at the path each line terminated by \n
void Doc::write(std::string docPath)
{
	ofstream newDoc(docPath);
	for(size_t i = 0; i < lines.size(); i++)
	{
		newDoc << lines[i].data;
	}
}

//Write Method (OSTREAM): Write to to the given ostream
void Doc::write(std::ostream out)
{
	for(size_t i = 0; i < lines.size(); i++)
	{
		out << lines[i].data;
	}	
}
//Add Method: Add a line to the end of the document object. Treat leading spaces as indentation, ignore trailing spaces
void Doc::add(std::string addLine)
{
	
	size_t indTmp = 0;
	string str = addLine;
	//CHECK FOR INDENT
	while(str[0] == ' ')
	{
		indTmp++;
		str.erase(0,1);
	}
	
	lines.push_back({indTmp, addLine});
}

//Size Method: Return the number of lines in the object
size_t Doc::size() const
{
	return lines.size();
}

//Empty Method: Is the document empty?
bool Doc::empty() const
{
	if(lines.empty()) { return true; }

	else { return false; }
}

//Indent Method: Return number of spaces before charachters at a specific line, error if line does not exist
size_t Doc::indent(size_t lineNum)
{
	if(lineNum > lines.size())
	{
		cerr << "That line number does not exist in the document";
		exit(1);
	}
	else
	{
		return lines[lineNum].indent;
	}

}
//Data Method: Get data at line without indentation, error if line does not exist
string Doc::data(size_t lineNumData)
{
	if(lineNumData > lines.size())
        {
                cerr << "That line number does not exist in the document";
                exit(1);
        }
        else
	{
		size_t end = 0;
		for(size_t i = 0; i < lines[lineNumData].data.size(); i++)
		{
			if(lines[lineNumData].data[i] == ' ')
			{
				 end++;
			}
			else { goto skipSpaceReturn; }		
		}
	skipSpaceReturn:		
		return lines[lineNumData].data.substr(end, lines[lineNumData].data.size());
        }
}
