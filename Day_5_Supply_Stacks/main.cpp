//
// Created by jibbe on 3-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"
#include <sstream>

int main() {
    InputReader inputReader("day5.txt");
    std::vector<std::string> stacks = {" FDBZTJRN", " RSNJH", " CRNJGZFQ", " FVNGRTQ", " LTQF", " QCWZBRGN", " FCLSNHM", " DNQMTJ", " PGS"};
    auto commands = inputReader.getWords(' ');

    for (const auto& word : stacks){
        std::cout << word << " ";
    }
    std::cout << std::endl << std::endl;

    for (const auto& command : commands){
        std::string tempStr = "";
        for (int i = 0; i < std::stoi(command[1]); i++) {
            const char temp = stacks[std::stoi(command[3]) - 1].back();
            tempStr += (temp);
            stacks[std::stoi(command[3]) - 1].pop_back();
        }
        int size = tempStr.size();
        for (int i = 0; i < size; i++){
            char temp = tempStr.back();
            stacks[std::stoi(command[5]) - 1] += temp;
            tempStr.pop_back();
        }
        for (const auto& word : stacks){
            std::cout << word << std::endl;
        }
        std::cout << std::endl << std::endl;
    }


    for (const auto& word : stacks){
        std::cout << word << " ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}