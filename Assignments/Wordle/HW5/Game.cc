#include "Game.h"
using namespace std;

void Game::set_length(const size_t wordLength)
{
    size = wordLength;
}
void Game::add_dict(const std::string filePath)
{
    ifstream in(filePath);
	if (!in)
	{
		cerr << "\nERROR: I was not able to open your file \"" << filePath << "\". Please make sure to put your files after your options!\n";
		exit(1);
	}
	for(string line; getline(in, line);)
	{
	    allWords.push_back(line);
	}

	//ERROR CHECK: If File has No Words
//	if(allWords.empty())
//	{
//		cerr << "\nERROR: Your file does not exist or has no words with that length\n";
//		exit(1);
//	}
}
void Game::set_good(const std::string &newGoodWord)
{
    goodWord = newGoodWord;
}
void Game::set_wrong(const std::string &newWrongPlace)
{
    wrongPlace = newWrongPlace;
}
void Game::set_bad(const std::string &newBadWord)
{
    badWord = newBadWord;
}
std::string Game::select_target()
{
	for (size_t i = 0; i < allWords.size(); i++) 
	{
	    if(allWords[i].size() == size)
     	    {
	        filterWords.push_back(allWords[i]);	
	    }
	}
	if(filterWords.empty())
	{
	    stringstream errorMsg;
            errorMsg << "length_error: No words with a length of " << size << " exist in any dictionary";
	    throw length_error(errorMsg.str());   
	}

	random_device rd;
	targetWord = filterWords[rd() % filterWords.size()];
	return targetWord;
}
bool Game::contains(std::string containsWord)
{
    bool valid2 = false;
	for(size_t i = 0; i < allWords.size(); i++)
	{
	    if(containsWord == allWords[i])
		{
		    valid2 = true;
		}
	}
	return valid2;
}
std::string Game::feedback(const std::string &guessWord)
{
	string displayHint = "";
	//Create New Hint
	for(size_t i = 0; i < size; i++)
	{
	    if(guessWord[i] == targetWord[i])
		{
			displayHint += goodWord;
		}
		else
		{
			size_t index = targetWord.find(guessWord[i]);
			if(index != string::npos && index != i)
			{
				displayHint += wrongPlace;
			}
			else
			{
				displayHint += badWord;
			}
		}
	}
	return displayHint;
}
