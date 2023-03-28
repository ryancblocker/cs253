#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include <sstream>


class Game {
    public:
	void set_length(const size_t wordLength);
	void add_dict(const std::string filePath);
	void set_good(const std::string &newGoodWord);
	void set_wrong(const std::string &newWrongPlace);
	void set_bad(const std::string &newBadWord);
	[[nodiscard]] std::string select_target();
	bool contains(std::string containsWord);
	[[nodiscard]] std::string feedback(const std::string &guessWord);
    private:
        size_t size = 5;
        std::string goodWord = "=";
        std::string wrongPlace = "-";
        std::string badWord = " ";
	std::string targetWord;
        bool isValidWord;
	std::vector<std::string> allWords;
	std::vector<std::string> filterWords;
};

#endif /*GAME_H_INCLUDED*/
