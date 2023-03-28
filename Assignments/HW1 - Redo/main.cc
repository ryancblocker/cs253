//Created by Ryan C. Blocker 
//Colorado State University 
//rblocker@colostate.edu

#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

void wordle(string trueWord, char *arg)
{

//CHEAT MODE:
	//cout << "\nCHEAT MODE ENABLED: " << trueWord << "\n\n";

//Variables
	int numGuesses = 6;
	string guessWord;
	string displayHint;
	string correctAnswer = "=====";

//Game Logic
	while (numGuesses != 0)
	{
		cout << "Guess: ";
		//cin >> guessWord;

		getline(cin, guessWord);

		//ERROR CHECK: Is the string bigger or less than 5 charachters
		if (guessWord.size() != 5)
		{
			cerr << "\n" << "ERROR: " << arg << " You entered \"" << guessWord << "\" Please enter a word that is more or less than 5 letters" << "\n";
			exit(1);
		}

		//Correct Answer!
                if (guessWord == trueWord)
                {
                        cout << "       " << correctAnswer << "\n";
                        cout << "You Win!" << "\n";
                        break;
                }

		//Create New Hint
		for(size_t i = 0; i < 5; i++)
		{
			
			if(guessWord[i] == trueWord[i])
			{
				displayHint.push_back('=');
			}
			else
			{
				size_t index = trueWord.find(guessWord[i]);
				if(index != string::npos && index != i)
				{
					displayHint.push_back('-');
				}
				else
				{
					displayHint.push_back(' ');
				}
			}
		}

		//Hint
		cout << "       " << displayHint << "\n";
		displayHint = "";
		//Decrement Guess for Next Round
		numGuesses--;
	}

	if (numGuesses == 0)
	{
		cout << "You lost, the word was \"" << trueWord << "\"\n";
	}
}

int main(int argc, char *argv[])
{

//ERROR CHECK: More than one argument given
	if (argc >  2 || argc == 1)
	{
		cerr << "\nERROR: " << argv[0] << " \"" << argv[2] << "\" Please, give only one dictionary file\n\n";
		exit(1);
	}

//Open File
	ifstream dictionary;
	dictionary.open(argv[1]);

	//ERROR CHECK: Program was not able to open the file
	if(!dictionary)
        {
        	cerr << "\nERROR: " << argv[0] << " I was not able to open your file \"" << argv[1] << "\"\n\n";
		exit(1);
        }

//Play Game
	cout << "I am thinking of a 5-letter word." << "\n";
	vector<string> wordFile;

	for(string line; getline(dictionary, line);)
	{
		if(line.size() == 5)
		{
			wordFile.push_back(line);
		}
	}

	//ERROR CHECK: If File has No Words
	if(wordFile.empty())
	{
		cerr << "\nERROR: " << argv[0] << " Your file \"" << argv[1] << "\" has no words\n\n";
		exit(1);
	}

	//Play Game and input random word
	random_device rd;
	wordle(wordFile[rd() % wordFile.size()], argv[0]);

	//Close file
        dictionary.close();
	return 0;
}
