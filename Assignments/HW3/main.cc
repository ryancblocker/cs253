//Created by Ryan C. Blocker 
//Colorado State University 
//rblocker@colostate.edu

#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <unistd.h>
#include <cstring>


using namespace std;

void wordle(string trueWord, char *arg, int numGuesses, string goodW, string wrongP, string badW, bool valid, size_t length, vector<string> dict)
{
//CHEAT MODE:
	//cout << "\nCHEAT MODE ENABLED: " << trueWord << "\n\n";
//Variables
	string guessWord;
	string displayHint = "";
	string correctAnswer = "";
//Game Logic
	while (numGuesses != 0)
	{
		cout << "Guess: ";
		//cin >> guessWord;

		getline(cin, guessWord);

		//ERROR CHECK: Is the string bigger or less than wordLength charachters
		if (guessWord.size() != length)
		{
			cerr << "\n" << "ERROR: " << arg << " You entered \"" << guessWord << "\" Please enter a word that is more or less than " << length << "  letters" << "\n";
			exit(1);
		}
		if(valid) //if Valid is true loop through and check if guessWord in in the dictionary
		{
			bool valid2 = false;
			for(size_t i = 0; i < dict.size(); i++)
			{
				if(guessWord == dict[i])
				{
					valid2 = true;
				}
			}
			if(valid2 == false)
			{
				cerr << "ERROR: You did not enter a valid word in " << arg << "\n";
				exit(1);
			}
		}
		//Correct Answer!
                if (guessWord == trueWord)
                {
			for(size_t i = 0; i < length; i++)
			{
				correctAnswer += goodW;
			}
                        cout << "       " << correctAnswer << "\n";
                        cout << "You Won!" << "\n";
                        exit(1);
                }
		//Create New Hint
		for(size_t i = 0; i < length; i++)
		{
			if(guessWord[i] == trueWord[i])
			{
				displayHint += goodW;
			}
			else
			{
				size_t index = trueWord.find(guessWord[i]);
				if(index != string::npos && index != i)
				{
					displayHint += wrongP;
				}
				else
				{
					displayHint += badW;
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
		cout << "You lost, the word was \"" << trueWord << "\".\n";
	}
}

//read function
vector<string> read(char *names[], size_t word_length)
{
	vector<string> wordFile;

	for(size_t i = 0; names[i]; i++) 
	{
		ifstream in(names[i]);
		if (!in)
		{
			cerr << "\nERROR: I was not able to open your file \"" << names[i] << "\". Please make sure to put your files after your options!\n";
			exit(1);
		}
		for(string line; getline(in, line);)
		{
			if(line.length() == word_length)
			{
				wordFile.push_back(line);
			}
		}
	}
	
	//ERROR CHECK: If File has No Words
	if(wordFile.empty())
	{
		cerr << "\nERROR: Your file does not exist or has no words with that length\n";
		exit(1);
	}
	
	return wordFile;
}



int main(int argc, char *argv[])
{

//Game Setting Variables
bool isValid = false;
int turnCount = 6;
string goodWord = "=";
string wrongPlace = "-";
string badWord = " ";
size_t wordLength = 5;
int opt;

//Game Settings
while((opt = getopt(argc, argv, "+vt:g:w:b:3456789")) != -1) 
{
	//Has the option be selected already flags
	static int numS = 0;
	static int tflag = 0;
	static int gflag = 0;
	static int wflag = 0;
	static int bflag = 0;
	switch(opt)
	{
		case 'v': //Is Valid Word
		{
			isValid = true;
			break;
		}
		case 't': //# of Turns
		{
                        if(tflag == 1) 
			{
				cerr <<  "\nERROR: You cant specify the number of turns more than once!\n\n"; 
				exit(1);
			}
			//If the turn argument is more than one charachter check if any of them are not digits
			if(strlen(optarg) > 1)
			{
				for(size_t i = 0; i < strlen(optarg); i++)
				{
					if(!isdigit(optarg[i]))
					{
						cerr << "\nERROR: C'mon man you cant use \"" << optarg << "\" as your turn setting. It has to be an integer!\n\n";
						exit(1);
					}
				}
			}
			//If the turn count was just one charachter check if it is a digit
			if(!isdigit(optarg[0]))
					{
						cerr << "\nERROR: C'mon man you cant use \"" << optarg << "\" as your turn setting. It has to be an integer!\n\n";
						exit(1);
					}
			
			turnCount = atoi(optarg);
			tflag = 1;
			break;
		}
		case 'g': //goodWord String
		{
			if(gflag == 1) 
                        {
                                cerr <<  "\nERROR: You cant specify the goodWord more than once!\n"; 
                                exit(1);
                        }
			goodWord = optarg;
                        gflag = 1;
                        break;

		}
		case 'w': //wrongPlace string
		{
			if(wflag == 1) 
                        {
                                cerr <<  "\nERROR: You cant specify the wrongPlace word  more than once!\n\n"; 
                                exit(1);
                        }
                        wrongPlace = optarg;
                        wflag = 1;
                        break;
		}
		case 'b': //badword string
		{
			if(bflag == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the badWord more than once!\n\n"; 
                                exit(1);
                        }
                        badWord = optarg;
                        bflag = 1;
                        break;
		}
		//Size of Words for the Game
		case '3':
		{
			if(numS == 1)
			{
				cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
				exit(1);
			}
			wordLength = 3;
			numS = 1;
			break;
		}
		case '4':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 4;
                        numS = 1;
                        break;
		}
		case '5':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 5;
                        numS = 1;
                        break;
		}
		case '6':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 6;
                        numS = 1;
                        break;
		}
		case '7':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 7;
                        numS = 1;
                        break;
		}
		case '8':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 8;
                        numS = 1;
                        break;
		}
		case '9':
		{
			if(numS == 1)
                        {
                                cerr <<  "\nERROR: You cant specify the word length more than once!\n\n"; 
                                exit(1);
                        }
                        wordLength = 9;
                        numS = 1;
                        break;
		}
		case '?':
		{
			cerr << "\nYou have entered an invalid option\n\n";
			exit(1);
			break;
		}
	}
}

argc -= optind - 1;
argv += optind - 1;

//Open File
	const auto dict = read(argv+1, wordLength);

//Play Game
	cout << "I am thinking of a " << wordLength << "-letter word." << "\n";

	//Play Game and input random word
	random_device rd;
	wordle(dict[rd() % dict.size()], argv[argc-1], turnCount, goodWord, wrongPlace, badWord, isValid, wordLength, dict);

	//Close file
        //dictionary.close();
	return 0;
}
