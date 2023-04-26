//
//  main.cpp
//  TreeTest
//
//  Created by Adam Lewis on 10/3/16.
//  Copyright © 2016 Adam Lewis. All rights reserved.
//
#include<functional>
#include <iostream>
#include "Tree.hpp"


template<typename T>
int countNodes(std::shared_ptr<T> root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->_lft) + countNodes(root->_rgt);
}

template<typename T>
int countInternalNodes(std::shared_ptr<T> root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->_rgt != nullptr && root->_lft != nullptr)
        return 1 + countInternalNodes(root->_lft) + countInternalNodes(root->_rgt);
    else if (root->_rgt != nullptr && root == nullptr)
        return  1 + countInternalNodes(root->_rgt);
    else if (root->_lft != nullptr && root == nullptr)
        return  1 + countInternalNodes(root->_lft);
    else
        return 1;
}

template<typename T>
void pathLength(std::shared_ptr<T> root, int& count) 
{
    count++;                         //Add one to variable
    if (root->_lft != nullptr)      //Call for children if they exist
        pathLength(root->_lft,count);   
    if (root->_rgt != nullptr)
        pathLength(root->_rgt,count);
}


auto f2 = [](int thing)->void {std::cout << thing << " "; };
auto f3 = [](int thing,int numNodes)->void {numNodes++; };
int main(int argc, const char * argv[]) {

    std::cout << "Tree test program\n";
    Tree<int> aTree({45,74,28,32,45,44,100});

    std::cout << "Preorder: ";
    aTree.preorder(f2);
    std::cout << "\nIn-order: ";
    aTree.inorder(f2);
    std::cout << "\nPostorder: ";
    aTree.postorder(f2);
    std::cout << std::endl;

    aTree.remove(45, aTree.rootNode());
    std::cout << "\n\nDelete 45\n";
    std::cout << "===================================\n";
    std::cout << "Preorder: ";
    aTree.preorder(f2);
    std::cout << "\nIn-order: ";
    aTree.inorder(f2);
    std::cout << "\nPostorder: ";
    aTree.postorder(f2);
    std::cout << std::endl;
    std::cout << "===================================\n";

    aTree.remove(28, aTree.rootNode());
    std::cout << "\n\nDelete 28\n";
    std::cout << "===================================\n";
    std::cout << "Preorder: ";
    aTree.preorder(f2);
    std::cout << "\nIn-order: ";
    aTree.inorder(f2);
    std::cout << "\nPostorder: ";
    aTree.postorder(f2);
    std::cout << std::endl;
    std::cout << "===================================\n";

    aTree.remove(100, aTree.rootNode());
    std::cout << "\n\nDelete 100\n";
    std::cout << "===================================\n";
    std::cout << "Preorder: ";
    aTree.preorder(f2);
    std::cout << "\nIn-order: ";
    aTree.inorder(f2);
    std::cout << "\nPostorder: ";
    aTree.postorder(f2);
    std::cout << std::endl;
    std::cout << "===================================\n";

    aTree.remove(28, aTree.rootNode());
    std::cout << "\n\nDelete 28 (Not in tree)\n";
    std::cout << "===================================\n";
    std::cout << "Preorder: ";
    aTree.preorder(f2);
    std::cout << "\nIn-order: ";
    aTree.inorder(f2);
    std::cout << "\nPostorder: ";
    aTree.postorder(f2);
    std::cout << std::endl;
    std::cout << "===================================\n";
    int b = 0;
    Tree<int> anotherTree({ 45,74,28,32,45,44,100 });
    b = countNodes(anotherTree.rootNode());
    b = countInternalNodes(anotherTree.rootNode());
    b = 0;
    pathLength(anotherTree.rootNode(), b);
    return b;
}
