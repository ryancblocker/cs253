#include "Doc.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <iterator>
using namespace std;

Doc::Doc() { }
Doc::~Doc() { }

std::istream& operator>>(std::istream& in, Doc &rhs)			//Read Data from istream (>>)
{
	rhs.lines.clear();
	for(string s; getline(in, s); ) {
		for(char c : s)
		{
			if(c == '\t') 
			{
				throw runtime_error("ERROR: A tab charachter has been read c'mon man!!");
			}
		}
		while(!s.empty() && (s.back() == ' ' || s.back() == '\r'))
		{
			s.pop_back();
		}
		size_t lSpaces = 0;
		if(!s.empty()) 
		{
			while (lSpaces < s.size() && s[lSpaces] == ' ')
			{ 
				lSpaces++;
			}
			rhs.lines.push_back({lSpaces, s.substr(lSpaces)});
		}
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const Doc &rhs)		//Send Data from Document (<<)
{
	for(size_t i = 0; i < rhs.lines.size(); i++)
	{
		string spaces;
		for(size_t j = 0; j < rhs.lines[i].indent; j++)
		{
			spaces += " ";
		}
		out << spaces << rhs.lines[i].data << "\n";
	}
	
	return out;
}
Doc& Doc::operator=(const Doc &newLineStruct)				//Copy Operator (Doc = Doc)
{
	lines = newLineStruct.lines;
	return *this;
}
Doc& Doc::operator+=(const Doc &rhs)					//Addition Operator (Doc += Doc)
{
	for(auto tmpVector : rhs.lines)
	{
		lines.push_back({tmpVector.indent, tmpVector.data});
	}
	
	return *this;	
}
Doc operator+(const Doc &lhs, const Doc &rhs)				//Addition Operator (Doc + Doc)
{
	Doc newDoc = lhs;
	return newDoc += rhs;
}
Doc& Doc::operator+=(const std::string &rhs)				//Addition Operator (Doc += String)
{
	size_t lSpaces = 0;
	for(char c : rhs) 
	{
		if(c == ' ') { lSpaces++; }
		if(c != ' ') { break; }		
	}
	
	lines.push_back({lSpaces, rhs.substr(lSpaces)});
	return *this;
}
Doc operator+(const Doc &lhs, const std::string &rhs)			//Addition Operator (Doc + String)
{
	Doc newDoc = lhs;
	size_t lSpaces = 0;
	for(char c : rhs) {
		if(c == ' ') { lSpaces++; }
		if(c != ' ') { break; }		
	}

	newDoc.lines.push_back({lSpaces, rhs.substr(lSpaces)});
	return newDoc;
}

Doc operator+(const std::string &lhs, const Doc &rhs)			//Addition Operator (String + Doc)
{
	Doc newDoc;
	newDoc += lhs;
	newDoc += rhs;
	return newDoc;
}

const Doc::Line& Doc::operator[](const size_t index)			//Return a Line				
{
	if(index > lines.size())
	{
		throw out_of_range("ERROR: That line number does not exist!");
	}
	return lines[index];
}
void Doc::erase(size_t start)
{
	for(size_t i = start; i < lines.size(); i++)
	{
		lines.erase(lines.begin()+start);
	}
}
void Doc::erase(size_t start, size_t count)
{
	for(size_t i = start; i < count; i++)
	{
		lines.erase(lines.begin()+start);
	}
}
void Doc::append(const Doc& addDoc)
{
	for(size_t i = 0; i < lines.size(); i++)
	{
		lines.push_back(addDoc.lines[i]);
	}
}
void Doc::insert(const Doc& inputDoc, size_t start)
{
	lines.insert(lines.begin()+start, inputDoc.lines.begin(), inputDoc.lines.end());
}
void Doc::replace(const Doc& inputDoc, size_t start)
{
	for(auto i = start; i < lines.size(); i++)
        {
		lines[i] = inputDoc.lines[i];
	}
}
void Doc::replace(const Doc& inputDoc, size_t start, size_t count)
{
	for(auto i = start; i < count; i++)
        {
		lines[i] = inputDoc.lines[i];
	}
}
Doc::operator bool() const
{
	if(lines.empty()) {return false;}
	else {return true;}
}
bool Doc::empty() const
{
	return lines.empty();
}
size_t Doc::size() const
{
	return lines.size();
}
