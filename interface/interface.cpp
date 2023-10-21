#include "interface.hpp"
#include <iostream>
#include <fstream>

int run(std::string fileName) {
    std::ifstream inputFile;
    inputFile.open(fileName); //RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    if (!inputFile.is_open()) throw std::runtime_error("Error - Unable to open the file.");

    BST bst;
    int n, num;
    
    inputFile >> n;
    if (n <= 0) throw std::runtime_error("Error - Vector size must be a positive integer.");
    
    for (int i = 0; i < n; ++i) {
        inputFile >> num;
        bst.insertNode(num);
    }

    bst.visit(2);
    return compare(bst.getComparisonList().getHead());
}