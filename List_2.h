#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node {

    T Data;
    Node* Next;
    Node* Prev;

    Node(T data, Node* prev = nullptr, Node* next = nullptr) {
        Data = data;
        Next = next;
        Prev = prev;
    }
};


template <class T>
class DoubleLink
{
private:
    Node<T>* _head = nullptr;
    Node<T>* _tail = nullptr;
    int _size = 0;

public:

    DoubleLink() = default;

    DoubleLink(const DoubleLink<T>& other)
    {
        this->_size = other._size;

        auto* it = other._head;
        while (it) {
            Add(it->Data);
            it = it->next;
        }
    }

    int getSize() const
    {
        return _size;
    }

    const Node<T>* getHead() const
    {
        return _head;
    }

    const Node<T>* getTail() const
    {
        return _tail;
    }

    void Add(const T& Value)
    {
        if (_head == nullptr)
        {
            _tail = _head = new Node<T>(Value); 
        }
        else
        {
            _tail->Next = new Node<T>(Value, _tail);
            _tail = _tail->Next;
        }

        _size++;
    }

    bool Remove(size_t Index)
    {
        if (_size == 0 || Index >= _size)
            return false;

        if (Index == 0)
        {
            auto* delete_el = _head;
            _head = _head->Next;
            _head->Prev = nullptr;
            delete delete_el;
        }
        else
        {
            Node<T>* Temp = _head;

            for (int i = 0; i < Index; i++)
            {
                Temp = Temp->Next;
            }

            auto* delete_el = Temp;
            Temp->Next->Prev = delete_el->Prev;
            Temp->Prev->Next = delete_el->Next;
            delete[] delete_el;
        }

        _size--;

        return true;
    }

    T& Get_element(int index) const
    {
        if (index >= _size || index < 0)
            throw invalid_argument("Invalid index");

        Node<T>* Temp = _head;
        for (int i = 0; i < index; i++)
        {
            Temp = Temp->Next;
        }
        return Temp->Data;
    }

    void PrintList()
    {
        Node<T>* Temp = _head;
        for (int i = 0; i < _size; i++)
        {
            if (i % 10 == 0 && i != 0)
                cout << endl;

            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }

    void Clear()
    {
        Node<T>* current = _head;
        while (current)
        {
            _head = _head->Next;
            delete current;
            current = _head;
        }

        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }

    ~DoubleLink()
    {
        Clear();
    }
};


template <class T>
void Fill(DoubleLink<T>& list, int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        list.Add((rand() % 1000 + 1) / 100.0);
    }
}

template <class T>
void Task(const DoubleLink<T>& list)
{
    if (list.getSize() < 2 || list.getSize() % 2)
        throw invalid_argument("Invalid list size");

    T temp = 1.0;
    const Node<T>* Temp1 = list.getHead();
    for (int i = 0; i < list.getSize() / 2 - 1; i++)
    {
        Temp1 = Temp1->Next;
    }
    const Node<T>* Temp2 = Temp1->Next;


    for (int i = 0; i < list.getSize() / 2; i++)
    {
        temp *= Temp1->Data - Temp2->Data;
        Temp1 = Temp1->Prev;
        Temp2 = Temp2->Next;
    }

    cout << temp;
}