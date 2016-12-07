#pragma once
#include <memory>
#include <functional>
#include <iostream>

namespace BinarySearchTree 
{
  template<typename T>
  class Node 
  {
    private:
    T value;
    std::unique_ptr<Node<T>> left_node = nullptr;
    std::unique_ptr<Node<T>> right_node = nullptr;

    public:
      Node(T _value) : value(_value){};

      // inserts "val" into the tree
      void insert(T const& val) 
      {
        if (this->value == val)
        {
          return;
        }
        else if (this->value < val) 
        {
          if (this->right_node == nullptr)
            this->right_node = std::unique_ptr<Node<T>>(new Node(val));
          else
            this->right_node->insert(val);
        }
        else
        {
          if (this->left_node == nullptr)
            this->left_node = std::unique_ptr<Node<T>>(new Node(val));
          else
            this->left_node->insert(val);
        }
      }

      // returns true if and only if "val" exists in the tree.
      bool find(T const& val)
      {
        if (this->value == val)
        {
          return true;
        }
        else if (this->value < val)
        {
          if (this->right_node  == nullptr)
            return false;
          else
            return this->right_node->find(val);
        }
        else
        {
          if (this->left_node == nullptr)
            return false;
          else
            return this->left_node->find(val);
        }
      }

      // prints the tree elements in the in-order traversal order
      void print_inorder()
      {
        std::cout << this->value  << std::endl;
        if (this->left_node != nullptr)
          this->left_node->print_inorder();
        if (this->right_node != nullptr)
          this->right_node->print_inorder();
      }
      
      T get_value()
      {
        return this->value;
      }
    };
}
