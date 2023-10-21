#include "./bst/bst.hpp"
#include "./testcase/testcase.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // Binary Search Tree Basic Structure - For the testcases
        
        // Case #1
        BST bstMain1(5);
        bstMain1.insertNode(20);
        bstMain1.insertNode(5);
        bstMain1.insertNode(8);
        bstMain1.insertNode(7);
        bstMain1.insertNode(4);

        std::cout << "Preorder: " << '\n';
        bstMain1.visit(1);
        std::cout << "Comparaciones: " << compare(bstMain1.getComparisonVector()) << '\n';

        std::cout << "Inorder: " << '\n';
        bstMain1.visit(2);
        std::cout << "Comparaciones: " << compare(bstMain1.getComparisonVector()) << '\n';

        std::cout << "Postorder: " << '\n';
        bstMain1.visit(3);
        std::cout << "Comparaciones: " << compare(bstMain1.getComparisonVector()) << '\n';

        std::cout << "Level by Level: " << '\n';
        bstMain1.visit(4);
        std::cout << "Comparaciones: " << compare(bstMain1.getComparisonVector()) << '\n';


    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}