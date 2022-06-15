#pragma once


#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

template <class T>
struct Node
{
    T Data;
    Node* Next = nullptr;

    Node(T data, Node* next = nullptr)
    {
        this->Data = data;
        this->Next = next;
    }
};

template<class T>
class List
{
private:
    Node<T>* _head = nullptr;
    size_t _size = 0U;

public:

    List() = default;

    List(const List& other)
    {
        this->_size = other._size;

        auto* it = other._head;
        while (it) {
            Add(it->Data);
            it = it->next;
        }
    }

    ~List()
    {
        Clear();
    }

    T& Get(size_t Index) {
        if (Index > _size - 1)
            throw invalid_argument("Invalid index");

        Node<T>* Temp = _head;
        for (int i = 0; i < Index; i++)
            Temp = Temp->Next;

        return Temp->Data;
    }


    void Add(const T& Symbol)
    {
        _size += 1;

        if (_head == nullptr)
        {
            _head = new Node<T>(Symbol);
            return;
        }

        Node<T>* temp = _head;
        while (temp->Next != nullptr) {
            temp = temp->Next;
        }

        temp->Next = new Node<T>(Symbol);
    }

    void Add(const T* arr, size_t size)
    {
        for (int i = 0; i < size; i++) {
            Add(arr[i]);
        }
    }

    void Add(const char* arr) {
        Add(arr, strlen(arr));
    }

    bool Delete_element(size_t Index)
    {
        if (Index > _size - 1)
            return false;


        Node<T>* to_delete = nullptr;

        if (Index == 0)
        {
            to_delete = _head;
            _head = _head->Next;
        }
        else
        {
            Node<T>* temp = _head;
            for (int i = 0; i < Index - 1; i++)
                temp = temp->Next;

            to_delete = temp->Next;

            temp->Next = temp->Next->Next;
        }

        _size -= 1;
        delete to_delete;

        return true;
    }


    void Clear() {
        Node<T>* it = _head;
        while (it != nullptr) {
            Node<T>* next = it->Next;
            delete it;
            it = next;
        }

        _head = nullptr;
        _size = 0;
    }

    bool Contains(const T& element) const
    {
        Node<T>* it = _head;
        while (it) {
            if (it->Data == element) {
                return true;
            }

            it = it->Next;
        }

        return false;
    }

    void Print() const
    {
        Node<T>* it = _head;
        while (it) {
            cout << it->Data << " ";

            it = it->Next;
        }
        cout << endl;
    }

    size_t Size() const {
        return _size;
    }
};


template <class T>
List<T>* Task(List<T>& list_1, List<T>& list_2)
{
    List<T>* result = new List<T>();

    for (int i = 0; i < list_1.Size(); i++) {
        T el = list_1.Get(i);
        if (list_2.Contains(el) && !result->Contains(el)) {
            result->Add(el);
        }
    }


    return result;
}


