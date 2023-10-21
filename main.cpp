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

        std::cout << "Preorder: " << std::endl;
        bstMain1.visit(1);

        std::cout << "Inorder: " << std::endl;
        bstMain1.visit(2);

        std::cout << "Postorder: " << std::endl;
        bstMain1.visit(3);

        std::cout << "Level by Level: " << std::endl;
        bstMain1.visit(4);


    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}