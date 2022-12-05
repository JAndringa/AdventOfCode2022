//
// Created by jibbe on 2-12-22.
//
#include <utility>
#include <fstream>
#include <sstream>

#include "../include/inputReader.hpp"

InputReader::InputReader(std::string fileName) {
    inputFile = std::move(fileName);
}

std::vector<std::string> InputReader::getLines() {
    std::ifstream file ("../../inputs/" + inputFile);
    std::string tempLine;
    std::vector<std::string> lines;

    while(getline(file, tempLine)){
        lines.emplace_back(tempLine);
    }
    file.close();
    return lines;
}

std::vector<std::vector<std::string>> InputReader::getWords(char delim) {
    std::ifstream file ("../../inputs/" + inputFile);
    std::vector<std::string> lines = getLines();
    std::vector<std::vector<std::string>> words;
    std::string tempWord;

    for(const auto& line : lines){
        std::stringstream lineStream(line);
        std::vector<std::string> tempWords;
        while(getline(lineStream, tempWord, delim)){
            tempWords.emplace_back(tempWord);
        }
        words.emplace_back(tempWords);
    }
    return words;
}