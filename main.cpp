#include "binaryTree.cpp"

int main (){
    std::cout << "Tree 1: " << std::endl;
    BinaryTree caseTree1 = BinaryTree();
    caseTree1.insert(20);
    caseTree1.insert(5);
    caseTree1.insert(8);
    caseTree1.insert(7);
    caseTree1.insert(4);

    //sirve

    std::cout << "Preorder: " << std::endl;
    caseTree1.visit(1);

    //print ordered vector
    caseTree1.printOrderedVector();
    std::cout << "Resultado de comparaciones: " << compareVector(caseTree1.orderedVector) << std::endl;
    return 0;
}
