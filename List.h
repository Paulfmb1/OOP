#pragma once

#include <iostream>
#include "Lab41.h"

using namespace std;

struct Node
{
    Object* Data;
    Node* Next = nullptr;

    Node() = default;
};

class List
{
private:
    Node* Head = nullptr;
    int Size = 0;

public:
    List() = default;

    List(const List& obj)
    {
        Copy(obj);
    }

    List(List&& obj)
    {
        Size = obj.getSize();
        Head = obj.Head;
        obj.Head = nullptr;
        obj.Size = 0;
    }

    List& operator= (const List& obj)
    {
        Copy(obj);

        return *this;
    }

    List& operator= (List&& obj)
    {
        Size = obj.getSize();
        Head = obj.Head;
        obj.Head = nullptr;
        obj.Size = 0;

        return *this;
    }

    Object*& Get(int Index) const
    {
        if (Index > Size - 1 || Index < 0)
        {
            throw std::invalid_argument("Invalid index");
        }

        Node* Temp = Head;

        for (int i = 0; i < Index; i++)
        {
            Temp = Temp->Next;
        }

        return Temp->Data;
    }

    void Add(Object* value)
    {
        Size++;

        Node* NewNode = new Node;
        NewNode->Data = value;

        if (Head == nullptr)
        {
            Head = NewNode;
        }
        else
        {
            Node* temp = Head;

            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }

            temp->Next = NewNode;
        }
    }

    bool Remove(const int Index)
    {
        if (Size == 0 || Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0)
        {
            auto* next = Head->Next;
            delete Head;
            Head = next;
        }
        else
        {
            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp = Temp->Next;
            }

            auto* to_delete = Temp->Next;
            Temp->Next = Temp->Next->Next;
            delete to_delete;
        }

        Size--;

        return true;
    }

    bool Insert(int Index, Object* value)
    {
        if (Index > Size - 1 || Index < 0)
            return false;

        Node* Temp = new Node;
        Temp->Data = value;

        if (Index == 0)
        {
            Temp->Next = Head;
            Head = Temp;
        }
        else
        {
            Node* Temp1 = Head;

            for (int i = 0; i < Index - 1; i++)
            {
                Temp1 = Temp1->Next;
            }

            Temp->Next = Temp1->Next;
            Temp1->Next = Temp;
        }

        Size++;

        return true;
    }

    ~List()
    {
        Clear();
    }

    void Clear()
    {
     

        while (Head != nullptr)
        {
            auto* temp = Head;
            Head = Head->Next;


            delete temp->Data;
            delete temp;
        }

        Size = 0;
    }

    int getSize() const
    {
        return Size;
    }

    void Print(ostream& os)
    {
        Node* Temp = Head;
        for (int i = 0; i < getSize(); i++)
        {
            (*(Temp->Data)).Print(os);
            Temp = Temp->Next;
        }

        os << std::endl;
    }

    void Copy(const List& obj)
    {
        if (Head)
        {
            delete Head;
        }
        this->Size = obj.Size;

        Node* NewNode = new Node();
        this->Head = NewNode;
        Node* Temp = obj.Head;

        for (size_t i = 0; i < this->Size; i++)
        {
            NewNode->Data = Temp->Data->clone();
            NewNode->Next = new Node();
            Temp = Temp->Next;
            NewNode = NewNode->Next;
        }
    }
};


std::ostream& operator<<(std::ostream& os, List& list)
{
    list.Print(os);

    return os;
}