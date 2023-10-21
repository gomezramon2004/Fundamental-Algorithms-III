#include "./bst/bst.hpp"
#include "./testcase/testcase.hpp"
#include "./interface/interface.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        
        // Case #0 - Check which travel method gives the smallest number of comparisons
        BST bstMain1(5);
        bstMain1.insertNode(20);
        bstMain1.insertNode(5);
        bstMain1.insertNode(8);
        bstMain1.insertNode(7);
        bstMain1.insertNode(4);

        std::cout << "Preorder: " << '\n';
        bstMain1.visit(1);
        std::cout << "Comparisons: " << compare(bstMain1.getComparisonVector()) << '\n'; // It should be 125

        std::cout << "Inorder: " << '\n';
        bstMain1.visit(2);
        std::cout << "Comparisons: " << compare(bstMain1.getComparisonVector()) << '\n'; // It should be 83 <- This is the smallest number of comparisons

        std::cout << "Postorder: " << '\n';
        bstMain1.visit(3);
        std::cout << "Comparisons: " << compare(bstMain1.getComparisonVector()) << '\n'; // It should be 88

        std::cout << "Level by Level: " << '\n';
        bstMain1.visit(4);
        std::cout << "Comparisons: " << compare(bstMain1.getComparisonVector()) << '\n'; // It should be 125

        // Case #1 - input1.txt
        std::cout << run("input1.txt") << '\n'; // It should be 83

        // Case #2 - input2.txt
        std::cout << run("input2.txt") << '\n'; // It should be 128

        // Case #3 - input3.txt
        std::cout << run("input3.txt") << '\n'; // It should be 7018

        // Case #4 - input4.txt
        std::cout << run("input4.txt") << '\n'; // It should be 196

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}