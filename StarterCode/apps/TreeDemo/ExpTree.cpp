//
// File:   ExpTree.cpp
// Author: Adam.Lewis@athens.edu
// Purpose:
// Use the tree class from lecture to build an expression tree. By intent, we
// don't use inheritance here as we're using the Tree rather than extending it.
//
#include <stack>
#include <string>
#include <iostream>
#include "Tree.hpp"
using namespace std;

using TreeOfStrings = Tree<string>;
stack<TreeOfStrings> nodes;
stack<char> operations;

TreeOfStrings & buildExpTree(string expString) {
  const char DECIMAL = '.';
  const char RIGHTPAREN = ')';
  TreeOfStrings leftOp;
  TreeOfStrings rightOp;
  size_t i = 0;
  size_t limit = expString.length();
  string str;
  while (i < limit) {
    if (isdigit(expString[i]) || (expString[i] == DECIMAL)) {
      str = "" ;
      while (isdigit(expString[i]) || (expString[i] == DECIMAL)) {
        str += expString[i];
        ++i;
      }
      nodes.push( TreeOfStrings({ str } ));
    }
    else if (expString[i] == RIGHTPAREN) {
      ++i;
      rightOp = nodes.top();
      nodes.pop();
      leftOp = nodes.top();
      nodes.pop();
      str = "";
      str += operations.top();
      nodes.push( TreeOfStrings(leftOp, str, rightOp) );
    }
    else {
      ++i;
    }
  }
  return nodes.top();
}

void evalExpTree(TreeOfStrings & anExpTree) {
  cout << "Left as exercise for the student." << endl;
}

int main(int argc, char *argv[]) {
  string exp = "";
  cout << "Enter an expression in infix format: ";
  cin >> exp;
  TreeOfStrings expTree = buildExpTree(exp);
  auto f2 = [](string thing)->void {std::cout << thing << " ";};
  cout << "Pre-order traversal of expression tree" << endl;
  expTree.preorder(f2);
  cout << "In-order traversal of expression tree" << endl;
  expTree.inorder(f2);
  evalExpTree(expTree);
  return 0;
}
