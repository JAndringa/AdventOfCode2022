//
// Created by jibbe on 2-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"

int main() {
    InputReader inputReader("day2.txt");
    std::string opponent;
    std::string me;
    int totalScore = 0;
    auto words = inputReader.getWords();
    for (const auto &line: words) {
        opponent = line.at(0);
        me = line.at(1);
        std::cout << "Opponent: " << opponent << ", Me: " << me << std::endl;
        if (opponent == "A") {
            if (me == "X") {
                totalScore += 3;
            }
            else if (me == "Y") {
                totalScore += 4;
            }
            else if (me == "Z") {
                totalScore += 8;
            }
            else {
                std::cout << "Unknown input" << std::endl;
            }
        }
        else if (opponent == "B") {
            if (me == "X") {
                totalScore += 1;
            }
            else if (me == "Y") {
                totalScore += 5;
            }
            else if (me == "Z") {
                totalScore += 9;
            }
            else {
                std::cout << "Unknown input" << std::endl;
            }
        }
        else if (opponent == "C") {
            if (me == "X") {
                totalScore += 2;
            }
            else if (me == "Y") {
                totalScore += 6;
            }
            else if (me == "Z") {
                totalScore += 7;
            }
            else {
                std::cout << "Unknown input" << std::endl;
            }
        }
        else {
            std::cout << "Unknown input" << std::endl;
        }
        std::cout << totalScore << std::endl;
    }


    return 0;
}