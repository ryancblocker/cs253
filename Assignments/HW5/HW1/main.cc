#include <iostream>
#include <string>

using namespace std;

void sensorWord(string& word, string const& OGword, string const& replaceWord) {

	//index in line
	size_t index  = word.find(OGword);
	//loops through line until null position (end of file)
	while(index != string::npos) {
		//checks charchter before and after is it is a letter
		if(!isalpha(word[index - 1]) && !isalpha(word[index + OGword.size()])) {
			//if the index before and after OG word is a letter and not whitespace
			word.replace(index, OGword.size(), replaceWord);
			index = word.find(OGword, index - replaceWord.size());
		}
	//if it is not OG word dont replace it
	index = word.find(OGword, index - replaceWord.size());

	//texting index
	//cout << index;
	}
}

int main(int argc, char**) {

	//Did it compile?
	cout << "It compiled :)" << "\n\n";
	//more than one argument
	if (argc != 1) {
		cerr << "Error more or less than one argument! Please change and run again" << "\n\n";
		return 0;
	}
	else {
		//cin data file and sensor words
		for (string word; getline(cin, word);) {
			//call helper method
			sensorWord(word,"alpha", "CENSORED");
        		sensorWord(word, "beta", "CENSORED");
        		sensorWord(word, "gamma", "CENSORED");
        		sensorWord(word, "delta", "CENSORED");
			//print
			cout << word << "\n";
		}
	return 0;
	}
}
