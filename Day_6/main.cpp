//
// Created by jibbe on 6-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"
#include <sstream>

int main() {
    InputReader inputReader("day6.txt");
    std::string data = inputReader.getLines()[0];

    for(int i = 13; i < data.size(); i++){
        bool found = true;
        for(int j = 13; j >= 0; j--){
            for(int k = j - 1; k >= 0; k--){
                if(data[i-j] == data[i-k]){
                    found = false;
                }
            }
        }
        if (found){
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }
    return 0;
}
