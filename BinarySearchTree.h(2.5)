#pragma once

#include <iostream>

using namespace std;


template <class T>
struct Node
{
    T Value;
    Node* Left;
    Node* Right;

    Node()
    {
        Value = 0;
        Left = nullptr;
        Right = nullptr;
    }

    Node(T Value)
    {
        this->Value = Value;
        Left = nullptr;
        Right = nullptr;
    }

};

template <class T>
class BinarySearchTree
{
private:
    Node<T>* Root;

private:

    void print_tree_level(Node<T>* top, int level = 0)
    {
        if (top)
        {
            print_tree_level(top->Left, level + 1);

            for (int i = 0; i < level; i++)
                cout << "    ";
            cout << top->Value << endl;
            print_tree_level(top->Right, level + 1);
        }
    }

    void Delete_Tree(Node<T>* node)
    {
        if (node)
        {
            Delete_Tree(node->Right);
            Delete_Tree(node->Left);
            delete node;
        }
    }

    bool Find_elementImpl(const Node<T>* root, T value) const
    {
        if (root->Value == value)
            return true;
        else
        {
            if (root->Left)
                Find_elementImpl(root->Left, value);

            else if (root->Right)
                Find_elementImpl(root->Right, value);
            else
                return false;
        }
    }

    void Delete_leafsImpl(Node<T>* root)
    {
        if (root->Left != nullptr && (root->Left->Left == nullptr && root->Left->Right == nullptr))
        {
            Node<T>* X = root->Left;
            root->Left = nullptr;
            delete X;
            return;
        }
        else if (root->Left != nullptr)
        {
            Delete_leafsImpl(root->Left);

        }

        if (root->Right != nullptr && (root->Right->Left == nullptr && root->Right->Right == nullptr))
        {
            Node<T>* X = root->Right;
            root->Right = nullptr;
            delete X;
            return;
        }
        else if (root->Right != nullptr)
        {
            Delete_leafsImpl(root->Right);
        }
    }

    void printLeaves(Node<T>*root)
        {
            if ((root->Right != nullptr) || (root->Left != nullptr))
            {
                if (root->Left != nullptr)
                    TaskImpl(root->Left);
                if (root->Right != nullptr)
                    TaskImpl(root->Right);
            }
            else
                cout << root->Value << " ";
        }

 public:
    BinarySearchTree()
        {
            Root = nullptr;

        }
    BinarySearchTree(const BinarySearchTree<T>&other)
        {
            Node<T>* temp = other->Root;
            if (temp)
            {
                Delete_Tree(temp->Right);
                Delete_Tree(temp->Left);
                this->Add(temp->Value);
            }
        }

    ~BinarySearchTree()
        {
            Delete_Tree(Root);
        }

    void Add(T Value)
        {
            Add(new Node<T>(Value));
        }

    void Add(Node<T>*NewNode)
        {
            if (Root == nullptr)
            {
                Root = NewNode;
                return;
            }

            Node<T>* TempNode = Root;
            while (true)
            {
                if (TempNode->Value < NewNode->Value)
                {
                    if (TempNode->Right == nullptr)
                    {
                        TempNode->Right = NewNode;
                        return;
                    }
                    else
                    {
                        TempNode = TempNode->Right;
                    }

                }
                else
                {
                    if (TempNode->Left == nullptr)
                    {
                        TempNode->Left = NewNode;
                        return;
                    }
                    else
                    {
                        TempNode = TempNode->Left;
                    }
                }
            }
        }

    bool Find_element(T value)
    {
        if (Root != nullptr)
            Find_elementImpl(Root, value);
        else
            return false;
    }

    void Delete_leafs()
    {
        if (Root != nullptr && (Root->Left == nullptr && Root->Right == nullptr))
            delete Root;
        else if (Root != nullptr)
            Delete_leafsImpl(Root);
        else
            return;
            
    }

    void Print() const
    {
        print_tree_level(top);
    }

    Node<T>* GetRoot() { return Root; }

    void PrintLeaves() const {
        printLeaves(Root);
    }
};

