//
// Created by jibbe on 2-12-22.
//

#ifndef DAY_2_ROCK_PAPER_SCISSORS_INPUTREADER_HPP
#define DAY_2_ROCK_PAPER_SCISSORS_INPUTREADER_HPP

#include <vector>
#include <string>

class InputReader {
public:
    explicit InputReader(std::string fileName);

    std::vector<std::string> getLines();

    std::vector<std::vector<std::string>> getWords(char delim);

private:
    std::string inputFile;
};

#endif //DAY_2_ROCK_PAPER_SCISSORS_INPUTREADER_HPP
