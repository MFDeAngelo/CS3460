#include "WordTree.hpp"
#include "rlutil.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

std::shared_ptr<WordTree> readDictionary(std::string filename);

int main()
{
    std::cout << "Loading words..." << std::endl;
    WordTree wordTree = *readDictionary("dictionary.txt");
    std::string input = "";
    rlutil::cls();
    std::cout << input << "\n\n--- prediction ---\n";
    while (true)
    {
        rlutil::locate(1 + input.length(), 1);
        auto key = rlutil::getkey();
        if (key == rlutil::KEY_BACKSPACE)
            input = input.substr(0, input.length() - 1);
        else if (std::isalpha(static_cast<char>(key)))
            input += static_cast<char>(key);
        rlutil::cls();
        std::cout << input << "\n\n--- prediction ---\n";
        std::vector<std::string> predicted = wordTree.predict(input, static_cast<std::uint8_t>(rlutil::trows() - 4));
        for (unsigned short i = 0; i < predicted.size(); i++)
        {
            std::cout << predicted[i] << std::endl;
        }
    }

    return 0;
}

std::shared_ptr<WordTree> readDictionary(std::string filename)
{
    auto wordTree = std::make_shared<WordTree>();
    std::ifstream inFile = std::ifstream(filename, std::ios::in);

    while (!inFile.eof())
    {
        std::string word;
        std::getline(inFile, word);
        // Need to consume the carriage return character for some systems, if it exists
        if (!word.empty() && word[word.size() - 1] == '\r')
        {
            word.erase(word.end() - 1);
        }
        // Keep only if everything is an alphabetic character -- Have to send isalpha an unsigned char or
        // it will throw exception on negative values; e.g., characters with accent marks.
        if (std::all_of(word.begin(), word.end(), [](unsigned char c) { return std::isalpha(c); }))
        {
            std::transform(word.begin(), word.end(), word.begin(), [](char c) { return static_cast<char>(std::tolower(c)); });
            wordTree->add(word);
        }
    }

    return wordTree;
}