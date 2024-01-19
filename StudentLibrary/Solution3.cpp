#include "Solution3.h"

#include <vector>
#include <algorithm>
#include <stdexcept>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

/*
 * Exercice 3 : Alphabetical Word Sorter
 *
 * This exercise is designed to create a program that sorts a list of words in alphabetical order.
 * As an input, a vector of words is given. You must store the words, sort the words in alphabetical order and then return the sorted list.
 * The programm should sort them in alphabetical order, regardless of their original case. It means that "Hello" and "hello" should be considered as the same word.
 *
 * If the vector is null or empty, the program must throw an exception.
 */

void Solution3::SetWords(const std::vector<std::string>& _words)
{
	words = _words;
}

void Solution3::SortWords() {}

std::vector<std::string> Solution3::GetSortedWords() const
{
    if (words.empty()) {
        throw std::runtime_error("Tu crois j'allais te sort");
    }

    std::vector<std::string> sortedWords = words;

    std::sort(sortedWords.begin(), sortedWords.end(), [](const std::string& a, const std::string& b) {
        std::string lowerA = a;
        std::string lowerB = b;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    });

    return sortedWords;
}

#endif
