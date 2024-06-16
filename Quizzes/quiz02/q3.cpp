#include <iostream>
#include <string>
#include <fstream>
#include <pwd.h>
using namespace std;

int main()
{
	const string home = getpwnam("cs253")->pw_dir;
	ifstream in("~/cs253/quiz02/q3.txt");
	string s; 
	cin << s;
	cout << s;
	return 0;
}
