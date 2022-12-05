//
// Created by jibbe on 3-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"

int main() {
    InputReader inputReader("day3.txt");
    std::vector<std::string> rucksacks = inputReader.getLines();
    int sum = 0;
    for (int j = 0; j + 2 < rucksacks.size(); j += 3) {
        std::vector<char> compartment1;
        std::vector<char> compartment2;
        std::cout << rucksacks[j] << std::endl << std::endl;
        bool done = false;
        for (const auto& item1 : rucksacks[j]){
            for (const auto& item2 : rucksacks[j + 1]){
                for (const auto& item3 : rucksacks[j + 2]){
                    if (item1 == item2 && item2 == item3 && !done){
                        std::cout << item1 << item2 << item3 << std::endl;
                        if (item1 > 96){
                            sum += item1 - 96;
                        }
                        else{
                            sum += item1 - 38;
                        }
                        done = true;
                    }
                }
            }
        }
    }


    std::cout << sum << std::endl;
    return 0;
}