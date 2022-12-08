//
// Created by jibbe on 6-12-22.
//
#include <iostream>
#include "../Utils/include/inputReader.hpp"
#include <sstream>

enum typeName{
    name, parent, size, type
};

int main() {
    InputReader inputReader("day7.txt");
    auto data = inputReader.getWords(' ');
    std::vector<std::vector<std::string>> tree;
    std::vector<std::string> temp = {"/", "no", "0", "dir"};
    std::vector<std::string> current = temp;
    unsigned long total = 0;
    tree.emplace_back(temp);
    temp.clear();

    for(auto line : data){
        for(auto word : line){
            std::cout << word << " ";
        }
        std::cout << std::endl;

        if(line[0] == "$"){
            if(line[1] == "cd") {
                if (line[2] == "..") {
                    for(auto i : tree){
                        if(i[name] == current[parent]){
                            current = i;
                        }
                    }
                }
                else {
                    for (auto i : tree){
                        if(i[name] == current[name] + "-" + line[2]){
                            current = i;
                        }
                    }
                }
                std::cout << "current: " << current[name] << std::endl;
            }
        }
        else if(line[0] == "dir"){
            bool append = true;
            for (auto item : tree){
                if(item[name] == current[name] + "-" + line[1]){
                    append = false;
                }
            }
            if(append) {
                temp = {current[name] + "-" + line[1], current[name], "0", "dir"};
                tree.emplace_back(temp);
                temp.clear();
            }
        }
        else{
            bool append = true;
            for (auto item : tree){
                if(item[name] == line[1]){
                    append = false;
                }
            }
            if(append) {
                temp = {current[name] + "-" + line[1], current[name], line[0], "file"};
                tree.emplace_back(temp);
                temp.clear();
            }
        }
    }

    for(int j = 0; j < 10; j++) {
        for (int item = tree.size() - 1; item >= 0; item--) {
            if (tree[item][type] == "dir") {
                current = tree[item];
                unsigned long sum = 0;
                for (int i = 0; i < tree.size(); i++) {
                    if (tree[i][parent] == current[name]) {
                        sum += stoul(tree[i][size]);
                    }
                }
                current[size] = std::to_string(sum);
                tree.erase(tree.begin() + item);
                tree.push_back(current);
            }
        }
    }

    std::cout << std::endl;
    std::vector<std::string> smallestBig;
    int space;
    for (auto item : tree){
        if (item[type] == "dir" && item[name] == "/"){
            space = 30000000 - (70000000 - std::stoi(item[size]));
            smallestBig = item;
            std::cout << space << std::endl;
            break;
        }
    }
    for ( auto item : tree){
        std::cout << item[name] << ", " << item[parent] << ", " << item[size] << ", " << item[type] << std::endl;
        if (item[type] == "dir" && stoi(item[size]) >= space && stoi(item[size]) < stoi(smallestBig[size])){
            smallestBig = item;
        }
    }
    std::cout << smallestBig[size] << std::endl;

    return 0;
}
