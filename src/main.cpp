#include <iostream>
#include <assert.h>

#include "BST.h"

using namespace BinarySearchTree;

int main(int argc, char const *argv[])
{
  auto tree = Node<int>(10);

  // Test case 1: insert 1
  std::cout << "Test case 1: Insert 1" << std::endl;
  tree.insert(1);
  tree.print_inorder();
  assert(tree.find(1) && "Failed! Tree should contain 1.");
  std::cout << "Passed!" << std::endl;

  // Test case 2: insert 7
  std::cout << "Test case 2: Insert 7" << std::endl;
  tree.insert(7);
  tree.print_inorder();
  assert(tree.find(1) && tree.find(7) && "Failed! Tree should contain 1, 7");
  std::cout << "Passed!" << std::endl;

  // Test case 3: insert -1
  std::cout << "Test case 3: Insert -1" << std::endl;
  tree.insert(-1);
  tree.print_inorder();
  assert(tree.find(-1) && tree.find(7) && tree.find(1) &&
         "Failed! Tree should contain -1, 1, 7.");
  std::cout << "Passed!" << std::endl;

  return 0; 
}
