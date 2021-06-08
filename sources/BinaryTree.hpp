#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <stack>
#include <unordered_set>
using namespace std;
namespace ariel
{
    template <typename T>

    class BinaryTree
    {
        /************Node************/
        struct Node
        {
            T data;
            Node *left = nullptr;
            Node *right = nullptr;

            Node(T d) : data(d), left(nullptr), right(nullptr) {}
        };
        /************BinaryTree************/
    public:
        Node *root;
        std::map<T, Node *> _nodes;
        BinaryTree<T>()
        {
            root = nullptr;
        }
        ~BinaryTree(){}
        BinaryTree(const BinaryTree& otherTree){
            if (this != &otherTree){
            root = new Node(otherTree.root->data);
            copyTree(otherTree.root, root);
        }
        }
        BinaryTree(BinaryTree&& otherTree) noexcept{
            root = otherTree.root;
            otherTree.root = nullptr;
        }
        void copyTree(Node* from, Node* to){
            if(from->right){
                to->right = new Node(from->right->data);
                copyTree(from->right, to->right);
            }
            if(from->left){
                to->left = new Node(from->left->data);
                copyTree(from->left, to->left);
            }
        }
        BinaryTree& operator=(BinaryTree otherTree) {
            if (this == &otherTree){ return *this;}
            if(root != nullptr){delete root;}
            root = new Node(otherTree.root->data);
            copyTree(otherTree.root, root);
            return *this;
        }
       BinaryTree& operator=(BinaryTree&& otherTree) noexcept{
            root = otherTree.root;
            otherTree.root = nullptr;
            return *this;
        }
        BinaryTree<T> add_root(const T &data)
        {
            if (this->root == nullptr)
            {
                (this->root) = new Node(data);
            }
            else
            {
                this->root->data = data;
            }
            return *this;
        }
        
        BinaryTree<T> add_left(const T &data, const T &left)
        {
             Node* parent = nullptr;
            for (preorder_iterator it = this->begin_preorder(); it != this->end_preorder(); it++)
            {
                if (*it == data)
                {
                    parent = it.getNode();
                    break;
                }
            }
            if (parent != nullptr)
            {
                if (parent->left == nullptr)
                {
                    parent->left = new Node(left);
                }
                else
                {
                    parent->left->data = left;
                }
            }
            else
            {
                throw std::out_of_range("could not find the parent node with data =");
            }

            return *this;
        }
        BinaryTree<T> add_right(const T &data, const T &right)
        {
               Node* parent = nullptr;
            for (preorder_iterator it = this->begin_preorder(); it != this->end_preorder(); it++)
            {
                if (*it == data)
                {
                    parent = it.getNode();
                    break;
                }
            }
            if (parent != nullptr)
            {
                if (parent->right == nullptr)
                {
                    parent->right = new Node(right);
                }
                else
                {
                    parent->right->data = right;
                }
            }
            else
            {
                T print = right;
                throw std::out_of_range("could not find the parent node with data ");
            }
            return *this;
        }
        /************PreOrder Iterator************/
        class preorder_iterator
        {
        public:
            preorder_iterator(Node *ptr = nullptr)
            {
                if (ptr != nullptr)
                {
                    nodeStack.push(ptr);
                    curr = nodeStack.top();
                }
                else
                {
                    curr = nullptr;
                }
            }

            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }

            preorder_iterator &operator++()
            {
                if (!nodeStack.empty() && curr != nullptr)
                {
                    nodeStack.pop();
                    if (curr->right != nullptr)
                    {
                        nodeStack.push(curr->right);
                    }
                    if (curr->left != nullptr)
                    {
                        nodeStack.push(curr->left);
                    }
                    if (!nodeStack.empty())
                    {
                        curr = nodeStack.top();
                    }
                    else
                    {
                        curr = nullptr;
                    }
                }
                else
                {
                    curr = nullptr;
                }
                return *this;
            }
            preorder_iterator operator++(int)
            {
                preorder_iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const preorder_iterator &rhs) const
            {
                return (curr == rhs.curr);
            }

            bool operator!=(const preorder_iterator &rhs) const
            {
                return !(*this == rhs);
            }
            Node *getNode()
            {
                return curr;
            }

        private:
            Node *curr;
            std::stack<Node *> nodeStack;

        };
        /************InOrder Iterator************/
        class inorder_iterator
        {
        public:
            inorder_iterator(Node *ptr = nullptr)
            {
                if (ptr == nullptr)
                {
                    curr = nullptr;
                }
                else
                {
                    while (ptr != nullptr)
                    {
                        nodeStack.push(ptr);
                        ptr = ptr->left;
                    }
                    curr = nodeStack.top();
                    nodeStack.pop();
                }
            }

            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }

            inorder_iterator &operator++()
            {
                if (!nodeStack.empty() || curr != nullptr)
                {
                    if (curr->right != nullptr)
                    {
                        curr = curr->right;

                        while (curr != nullptr)
                        {
                            nodeStack.push(curr);
                            curr = curr->left;
                        }
                        curr = nodeStack.top();
                        nodeStack.pop();
                    }
                    else
                    {
                        if (!nodeStack.empty())
                        {
                            curr = nodeStack.top();
                            nodeStack.pop();
                        }
                        else
                        {
                            curr = nullptr;
                        }
                    }
                }
                return *this;
            }

            inorder_iterator operator++(int)
            {
                inorder_iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const inorder_iterator &rhs) const
            {
                return (curr == rhs.curr);
            }

            bool operator!=(const inorder_iterator &rhs) const
            {
                return !(*this == rhs);
            }
            Node *getNode()
            {
                return curr;
            }

        private:
            Node *curr;
            std::stack<Node *> nodeStack;

        }; 

        /************PostOrder Iterator************/
        class postorder_iterator
        {
        public:
            postorder_iterator(Node *ptr = nullptr)
            {
                if (ptr != nullptr)
                {
                    stack<Node *> temp;
                    temp.push(ptr);
                    while (!temp.empty())
                    {
                        curr = temp.top();
                        temp.pop();
                        nodeStack.push(curr);
                        if (curr->left != nullptr)
                        {
                            temp.push(curr->left);
                        }
                        if (curr->right != nullptr)
                        {
                            temp.push(curr->right);
                        }
                    }
                    curr = nodeStack.top();
                    nodeStack.pop();
                }
                else
                {
                    curr = nullptr;
                }
            }

            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }

            postorder_iterator &operator++()
            {
                if (!nodeStack.empty())
                {
                    curr = nodeStack.top();
                    nodeStack.pop();
                }
                else
                {
                    curr = nullptr;
                }
                return *this;
            }

            postorder_iterator operator++(int)
            {
                postorder_iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const postorder_iterator &rhs) const
            {
                return (curr == rhs.curr);
            }

            bool operator!=(const postorder_iterator &rhs) const
            {
                if (curr == nullptr && rhs.curr == nullptr)
                {
                }
                return (curr != rhs.curr);
            }

        private:
            Node *curr;
            std::stack<Node *> nodeStack;

        }; 
        preorder_iterator begin_preorder()
        {
            return preorder_iterator{root};
        }
        preorder_iterator end_preorder()
        {
            return preorder_iterator{nullptr};
        }

        inorder_iterator begin_inorder()
        {
            return inorder_iterator{root};
        }
        inorder_iterator begin() const
        {
            return inorder_iterator{root};
        }
        inorder_iterator end() const
        {
            return inorder_iterator{};
        }
        inorder_iterator end_inorder()
        {
            return inorder_iterator{nullptr};
        }

        postorder_iterator begin_postorder()
        {
            return postorder_iterator{root};
        }

        postorder_iterator end_postorder()
        {
            return postorder_iterator{nullptr};
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            return os;
        }
    };

};
