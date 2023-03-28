#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>

class Doc 
{
        public:
		//Default Contructor
		Doc();

		//Methods: Read, Write, Add, Size, Empty, Indent, Data
		Doc(std::string &filePath);
		Doc(std::istream &in);

		void read(std::string filePath);
		void read(std::istream readIn);

		void write(std::string docPath);
		void write(std::ostream out);

		void add(std::string addLine);

		size_t size() const;
		bool empty() const;
		size_t indent(size_t lineNum);
		std::string data(size_t lineNum);

		~Doc();

	//Asignment Operators	
	Doc& operator=(const Doc &newLineStruct);

	private:
		//Line infrastrucuture
		struct Line
		{
			size_t indent;
			std::string data;			
		};

		std::vector<Line> lines;

	
};

//std::ostream& operator << (std::ostream& stream, Line const &l);
//std::string &operator==(Lines const &lhs, std::string const &rhs);
#endif /* DOCUMENT */
