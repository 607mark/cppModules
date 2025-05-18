#include <iostream>
#include <fstream>
#include <string>

int checkArgs(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Wrong number of args.\nUsage: <filename> <string1> <string2>\n";
        return 1;
    }
    if (std::string(av[1]).empty() || std::string(av[2]).empty() || std::string(av[3]).empty()) {
        std::cerr << "Arguments cannot be empty.\n";
        return 1;
    }   
    return 0;
}

int readContent(std::string *content, std::ifstream *inFile) {
    std::string str;
    while (std::getline(*inFile, str))
        *content += str + "\n";
    if (inFile->bad()) {
        std::cerr << "I/O failure\n";
        return 1;
    }
    if (!content->empty() && content->back() == '\n')
        content->pop_back();
    return 0;
}

std::pair<std::ifstream, std::ofstream> setIO(char *filename) {
    std::ifstream inFile(filename);
    std::string outFilename = std::string(filename) + ".replace";
    std::ofstream outFile(outFilename);
    if (!inFile.is_open())
        std::cerr << "Cannot open " << filename << "\n";
    if (!outFile.is_open())
        std::cerr << "Cannot open " << outFilename << "\n";
    return {std::move(inFile), std::move(outFile)};
}

int replaceStrings(std::string *content, std::string *result, const std::string &s1, const std::string &s2) {
    size_t pos = 0;
    size_t rPos;
    while ((rPos = content->find(s1, pos)) != std::string::npos) {
        result->append(*content, pos, rPos - pos);
        result->append(s2);
        pos = rPos + s1.length();
    }
    result->append(*content, pos, std::string::npos);
    return 0;
}

int main(int ac, char** av) {
    std::string content;
    std::string result;
    if (checkArgs(ac, av))
        return 1;
    auto [inFile, outFile] = setIO(av[1]);
    if (!inFile.is_open() || !outFile.is_open())
        return 1;
    if (readContent(&content, &inFile))
        return 1;
    inFile.close();
    if (replaceStrings(&content, &result, std::string(av[2]), std::string(av[3])))
        return 1;
    outFile << result;
    if (outFile.fail()){
        std::cerr << "Failed to write to output file\n"; return 1;
    }
    outFile.close();
    return 0;
}