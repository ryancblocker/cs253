#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int numUpOne(int i) { return ++i; }

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    	copy(alpha.begin(), alpha.end(), cbuf);
    	cout << cbuf << '\n';

    cout << "Exercise 1\n";
    	reverse(alpha.begin(), alpha.end());
    	cout << alpha << '\n';

    cout << "Exercise 2\n";
    	auto upOne = numUpOne;
    	transform(primes.begin(), primes.end(), ibuf, upOne);
    	for(auto i = 0; i < 10; i++)
    	{
    	    cout << ibuf[i];
    	}
    	cout << '\n';

    cout << "Exercise 3\n"; 
    	if(any_of(primes.begin(), primes.end(), [](int i){ return i % 2 == 0;}))
    	{
        	cout << "div 2\n";
    	}
    	else if(any_of(primes.begin(), primes.end(), [](int i){ return i % 42 == 0;}))
    	{
        	cout << "div 42\n";
    	}

    cout << "Exercise 4\n";
    	auto search = find(primes.begin(), primes.end(), 13);
    	auto nx = next(search, 1);
		cout << *nx << '\n';

    cout << "Exercise 5\n";
		int countThree = count(pi.begin(), pi.end(), 3);
		cout << countThree << "\n";

    cout << "Exercise 6\n";
        int countLess = count_if(pi.begin(), pi.end(), [](int i) {return i < 5;});
		cout << countLess << "\n";

    cout << "Exercise 7\n";
		auto maxNum = max_element(pi.begin(), pi.end());
		cout << *maxNum << '\n';

    cout << "Exercise 8\n";
		sort(pi.begin(), pi.end());
		auto print = [&pi]() {
        for (auto a : pi) {
            cout << a << ' ';
        }
		cout << '\n';
    	};
        print();

    cout << "Exercise 9\n";
		auto lower = lower_bound(pi.begin(), pi.end(), 7);
        cout << distance(pi.begin(), lower) << '\n';

    cout << "Exercise 10\n";
		auto intersect = set_intersection(pi.begin(), pi.end(), begin(powers), end(powers), ibuf);
		for (auto i = &ibuf[0]; i < intersect; i++)
		{
			cout << *i << " ";
		}
		cout << '\n';
}
