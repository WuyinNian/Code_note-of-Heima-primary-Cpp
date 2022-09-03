#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
private:
    T *data;
    int capacity;
    int size;

public:
    MyArray(int n)
    {
        cout << "constructor" << endl;
        capacity = n;
        size = 0;
        data = new T[capacity];
    }
    MyArray(const MyArray &arr)
    {
        cout << "copy constructtor" << endl;
        capacity = arr.capacity;
        size = arr.size;
        data = new T[arr.capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr.data[i];
        }
    }
    MyArray &operator=(const MyArray &arr)
    {
        cout << "this is operator=" << endl;
        if (this->data != NULL)
        {
            delete[] this->data;
            this->data = NULL;
            this->capacity = 0;
            this->size = 0;
        }
        capacity = arr.capacity;
        size = arr.size;
        data = new T[arr.capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr.data[i];
        }
        return *this;
    }
    void add(const T &x)
    {
        if (size == capacity)
        {
            cout << "array full" << endl;
            return;
        }
        data[size++] = x;
    }
    void deleteArr()
    {
        if (size == 0)
        {
            cout << "array empty" << endl;
            return;
        }
        size--;
    }
    T operator[](int index)
    {
        return data[index];
    }
    int getSize()
    {
        return size;
    }
    int getCapcity()
    {
        return capacity;
    }
    ~MyArray()
    {
        cout << "destructor" << endl;
        if (data != NULL)
        {
            delete[] data;
            data = NULL;
        }
    }
};
