#include "binaryTree.hpp"
#include <random>
#include <iostream>


BinaryTree::BinaryTree() {
    this->root = nullptr; 
}

//Constructor with size with randomize values and nodes
BinaryTree::BinaryTree(int size) {
    root = nullptr;
    int random;
    int minusOrPlus[] = {-1, 1};
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            random = rand() % 100 + 1;
        } else {
            // Random factor between -size and size
            int randomFactor = rand() % size/2 + 1;
            random = this->root->data + randomFactor * minusOrPlus[rand() % 2];
        }
        insert(random);
    }
}


void BinaryTree::insert(int data) {
    root = insertRecursive(root, data);
}


Node* BinaryTree::insertRecursive(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertRecursive(root->left, data);
    } else if (data > root->data) {  
        root->right = insertRecursive(root->right, data);
    }
    else 
        std::cout << "Duplicate value" << std::endl;
    return root;
}


void BinaryTree::preorder() {
    this->preorderRecursive(this->root);
}

void BinaryTree::preorderRecursive(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void BinaryTree::inorder() {
    this->inorderRecursive(root);

}

void BinaryTree::inorderRecursive(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderRecursive(root->left);
    orderedVector.push_back(root->data);
    std::cout << root->data << " ";
    inorderRecursive(root->right);
}

void BinaryTree::postorder() {
    this->postorderRecursive(root);
}

void BinaryTree::postorderRecursive(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    std::cout << root->data << " ";
}

void BinaryTree::levelByLevelRecursive(Node* root, int level) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        std::cout << root->data << " ";
    }
    this->levelByLevelRecursive(root->left, level - 1);
    this->levelByLevelRecursive(root->right, level - 1);
}

void BinaryTree::levelByLevel() {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        std::cout << "Level " << i << ": ";
        levelByLevelRecursive(root, i);
        std::cout << std::endl;
    }
}

void BinaryTree::visit(int parameter) {
    switch (parameter) {
        case 1:
            preorder();
            std::cout << std::endl;
            break;
        case 2:
            inorder();
            std::cout << std::endl;
            break;
        case 3:
            postorder();
            std::cout << std::endl;
            break;
        case 4:
            levelByLevel();
            std::cout << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
}

int BinaryTree::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

void BinaryTree::ancestors(int data) {
    if (isInTree(data)) {
        ancestorsRecursive(root, data);
    } else if (!isInTree(data)) {
        std::cout << "Number is not in tree" << std::endl;
        return;
    } 
    if (root->data == data) {
        std::cout << "Number is the root of the tree" << std::endl;
        return;
    }
}

void BinaryTree::ancestorsRecursive(Node* root, int data) {
    if (root == nullptr) {
        return;
    }
    if (root->data == data) {
        return;
    }
    if (root->left != nullptr && root->left->data == data) {
        std::cout << root->data << " ";
        return;
    }
    if (root->right != nullptr && root->right->data == data) {
        std::cout << root->data << " ";
        return;
    }
    if (data < root->data) {
        ancestorsRecursive(root->left, data);
    } else {
        ancestorsRecursive(root->right, data);
    }
    std::cout << root->data << " ";
}

int BinaryTree::whatlevelamI(int data) {
    return whatlevelamIRecursive(root, data, 1) == 0 ? -1 : whatlevelamIRecursive(root, data, 1);
}

int BinaryTree::whatlevelamIRecursive(Node* root, int data, int level) {
    if (root == nullptr) {
        return 0;
    }
    if (root->data == data) {
        return level;
    }
    int downlevel = whatlevelamIRecursive(root->left, data, level + 1);
    if (downlevel != 0) {
        return downlevel;
    }
    downlevel = whatlevelamIRecursive(root->right, data, level + 1);
    return downlevel;
}

bool BinaryTree::isInTree(int data) {
    Node* current = root;
    if (current == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return false;
    }
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void BinaryTree::printOrderedVector() {
    for (int i = 0; i < orderedVector.size(); i++) {
        std::cout << orderedVector[i] << " ";
    }
    std::cout << std::endl;
}

//comparevector function that sums the first two values than substracts 1 that the resukt ius added to a counter that the smae operation is carried with the result the following number

int compareVector(std::vector <int> vector) {
    int resultadoTotal = 0, resultado, counter = 2;
    resultado = vector[0] + vector[1] - 1;
    while (counter<=vector.size()) {
        resultadoTotal = resultadoTotal + resultado;
        resultado = resultado + vector[counter] -1;
        counter++;
    }
    return resultadoTotal;
}