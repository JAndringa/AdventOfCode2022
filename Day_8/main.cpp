//
// Created by jibbe on 6-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"
#include <sstream>

enum typeName {
    name, parent, size, type
};

int main() {
    InputReader inputReader("day8.txt");
    auto data = inputReader.getLines();
    int total = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            int tree = data[i][j] - '0';
            int maxX = 0;
            int minX = 0;
            int maxY = 0;
            int minY = 0;
            if(j > 0) {
                for (int k = j - 1; k >= 0; k--) {
                    minX++;
                    if (data[i][k] - '0' >= tree) {
                        break;
                    }
                }
            }
            for(int k = j + 1; k < data[i].size(); k++){
                maxX++;
                if(data[i][k] - '0' >= tree){
                    break;
                }
            }
            if(i > 0) {
                for (int k = i - 1; k >= 0; k--) {
                    minY++;
                    if (data[k][j] - '0' >= tree) {
                        break;
                    }
                }
            }
            for(int k = i + 1; k < data.size(); k++){
                maxY++;
                if(data[k][j] - '0' >= tree){
                    break;
                }
            }
            if(minX * maxX * minY * maxY > total){
                total = minX * maxX * minY * maxY;
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}
