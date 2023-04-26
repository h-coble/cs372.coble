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
    count++;
    if (root->_lft != nullptr)
        pathLength(root->_lft,count);
    if (root->_rgt != nullptr)
        pathLength(root->_rgt,count);
}


auto f2 = [](int thing)->void {std::cout << thing << " "; };

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

    int b = 0;
    b = countNodes(aTree.rootNode());
    b = countInternalNodes(aTree.rootNode());
    b = 0;
    pathLength(aTree.rootNode(), b);
    return b;
}
