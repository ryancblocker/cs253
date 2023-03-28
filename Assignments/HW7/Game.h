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
#include <iterator>


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
	
	    class iterator;
	    [[nodiscard]] iterator begin() const;
		[[nodiscard]] iterator end() const;
		void set_wanted(bool (*p)(std::string)) { wanted = p; }
    private:
        size_t size = 5;
        std::string goodWord = "=";
        std::string wrongPlace = "-";
        std::string badWord = " ";
	    std::string targetWord;
        bool isValidWord;
		std::vector<std::string> allWords;
	    //std::vector<std::string> filterWords;
		bool (*wanted)(std::string) = takeAllWords;
		static bool takeAllWords(std::string) { return true; }
};
class Game::iterator {
    public:
		//iterator() = default;
		iterator(const Game* game, size_t index);
		//~iterator() = default;

		iterator operator++() //++git
		{
			++index;
			forward();
			return *this;
		}
		[[nodiscard]] iterator operator++(int) //git++
		{
			const auto saveGit = *this;
			++*this;
			return saveGit;
		}
		[[nodiscard]] bool operator==(const iterator &rhs) const //git==git
		{
			return index == rhs.index;
		}
		[[nodiscard]] bool operator!=(const iterator &rhs) const //git!=git
		{
			return !(*this == rhs);
		}
		[[nodiscard]] std::string operator*() const //*git
		{
			return git->allWords[index];
		}
    private:
			const Game *git;
			void forward();
			size_t index;
};

#endif /*GAME_H_INCLUDED*/
