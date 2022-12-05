//
// Created by jibbe on 3-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"
#include <sstream>

int main() {
    InputReader inputReader("day4.txt");
    std::vector<int> assignments1;
    std::vector<int> assignments2;
    std::vector<std::vector<std::string>> pairs = inputReader.getWords(',');
    int sum = 0;
    for (const auto &pair: pairs) {
        std::stringstream assStream1(pair[0]);
        std::string tempAss;
        while (getline(assStream1, tempAss, '-')) {
                assignments1.emplace_back(std::stoi(tempAss));
        }
        std::stringstream assStream2(pair[1]);
        while (getline(assStream2, tempAss, '-')) {
                assignments2.emplace_back(std::stoi(tempAss));
        }
        std::cout << pair[0] << " , " << assignments2[0] << "-" << assignments2[1] << std::endl;
        if((assignments1[0] <= assignments2[0] && assignments1[1] >= assignments2[1])
        || (assignments1[0] >= assignments2[0] && assignments1[1] <= assignments2[1])
        || (assignments1[0] <= assignments2[0] && assignments1[1] >= assignments2[0])
        || (assignments1[0] <= assignments2[1] && assignments1[1] >= assignments2[1])){
            sum++;
            std::cout << "found duplicate in: " << pair[0] << " and " << pair[1] << std::endl << "new sum = " << sum << std::endl;
        }
        assignments1.clear();
        assignments2.clear();
    }


    return 0;
}