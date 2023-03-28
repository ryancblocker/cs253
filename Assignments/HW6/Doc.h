#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <iterator>

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
	explicit operator bool() const;							//Doc in Boolean Context

	void erase(size_t start);
        void erase(size_t start, size_t count);
	void append(const Doc &);
	void insert(const Doc&, size_t start);
        void replace(const Doc& doc, size_t start);
	void replace(const Doc& doc, size_t start, size_t count);

/*	template <typename T>*/
/*	void append(iterStart, iterEnd)*/
/*	{*/
/*		T<string> randomCollection;*/
/*		iterStart = T<string::std::iterator start;*/
/*		*/
/*	}*/
	//void insert(iterStart, iterEnd, size_t start);
	//void replace(iterStart, iterEnd, size_t start);
	//void replace(iterStart, iterEnd, size_t start, size_t count);

        [[nodiscard]] bool empty() const;						//Return if Doc contains no lines
	[[nodiscard]] size_t size() const;						//Return Size of Doc
	~Doc();										//Default Destructor

    private:
    	friend std::istream& operator>>(std::istream& in, Doc &rhs);			//Read Data from istream (>>) into a Document
	friend std::ostream& operator<<(std::ostream& out, const Doc &rhs);		//Send Data from Document to Output Stream (<<)
    	std::vector<Line> lines;
};

