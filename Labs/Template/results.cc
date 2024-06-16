#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph 
{
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
//  void dump() const {
//	for (const auto &val : data)
//	    cout << right << setw(10) << val.first << ' '
//		 << string(val.second, '*') << '\n';
//          cout << '\n';
  private:
    map<T, unsigned> data;

    friend ostream& operator<<(std::ostream &lhs, const BarGraph &rhs) 
    {
	for (const auto &val : rhs.data)
	    lhs << right << setw(10) << val.first << ' '
		<< string(val.second, '*') << '\n';
        return lhs;
    }
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	    datum ? true_count++ : false_count++;
    }
//    void dump() const {
//        cout << "     false " << string(false_count, '*') << "\n"
//                "      true " << string(true_count,  '*') << "\n\n";
//    }
    friend ostream& operator<<(std::ostream &lhs, const BarGraph &rhs) 
    {
	    lhs << "     false " << string(rhs.false_count, '*') << "\n"
               "      true " << string(rhs.true_count,  '*') << "\n\n";
	return lhs;
    }
};

template<>
class BarGraph<char>
{
    public:
        void operator+=(const char &datum) 
        {
            unsigned tmpData = datum;
            data[tmpData]++;
    	}
    	void operator+=(const string &datum)
    	{
    	    for(size_t i = 0; i < datum.size(); i++)
    	    {
    	    	unsigned tmpData = datum[i];
    	    	data[tmpData]++;
    	    }	
    	}
    
    friend ostream& operator<<(std::ostream &lhs, const BarGraph &rhs) 
    {
	for (auto i = 0; i < 128; i++) 
	{
	    if(rhs.data[i] != 0) 
	    {
	        lhs << right << setw(10) << char(i) << ' '<< string(rhs.data[i], '*') << '\n'; 
	    }
	}
      	return lhs;
    }
    
    private:
        unsigned data[128] = {0};    
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}
