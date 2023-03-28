#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdexcept>

class Doc
{
    public:
    	struct Line									//Structure of Each Line (Indent, Data)
    	{
    		size_t indent;
    	        std::string data;
    	};
    	
	Doc();										//Default Constructor	
	Doc& operator=(const Doc &newLineStruct);       				//Copy Assignment Operator
	
	Doc& operator+=(const Doc &rhs);						//Addition Operator (Doc += Doc)
	Doc& operator+=(const std::string &rhs);					//Addition Operator (Doc += String)
	
	friend Doc operator+(const Doc &lhs, const Doc &rhs);				//Addition Operator (Doc + Doc)
	friend Doc operator+(const Doc &lhs, const std::string &rhs);			//Addition Operator (Doc + String)
	friend Doc operator+(const std::string &lhs, const Doc &rhs);			//String + Doc
	
	[[nodiscard]] const Line& operator[](const size_t index);			//Return a Line		
		
	explicit operator bool() const;								//Doc in Boolean Context
	[[nodiscard]] bool empty() const;								//Return if Doc contains no lines
	[[nodiscard]] size_t size() const;								//Return Size of Doc
	~Doc();										//Default Destructor
	
    private:
    	friend std::istream& operator>>(std::istream& in, Doc &rhs);			//Read Data from istream (>>) into a Document
	friend std::ostream& operator<<(std::ostream& out, const Doc &rhs);		//Send Data from Document to Output Stream (<<)		
    	std::vector<Line> lines;
};

//QUESTION ASK ABOUT exit(1) on throw
