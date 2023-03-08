//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_CONTAINER_H
#define LIBPROJECT1_CONTAINER_H

#include "Member.h"
using namespace std;

template <typename T>
class Container
{
private:
    T *arr;     // 객체 포인터 배열을 가리키는 포인터
    int length; // 배열의 길이
    int aIndex; // 저장된 객체의 수

public:
    Container(int len = 20);
    ~Container();
    void Insert(T data);
    T Remove(int idx);
    T GetItem(int idx);
    int GetElemSum();
};

template <typename T>
Container<T>::Container(int len) : aIndex(0)
{
    if (len <= 0)
        len = 20;
    length = len;
    arr = new T[length];
}

template <typename T>
Container<T>::~Container()
{
    delete[] arr;
}

template <typename T>
void Container<T>::Insert(T data)
{
    if (aIndex == length)
    {
        cout << "No Storage Space" << endl;
        return;
    }
    arr[aIndex++] = data;
}

template <typename T>
T Container<T>::Remove(int idx)
{
    if (idx < 0 || idx >= aIndex)
    {
        cout << "there is no" << endl;
        return NULL;
    }
    T del = arr[idx];

    for (int i = idx; i < aIndex - 1; i++)
        arr[i] = arr[i + 1];
    aIndex--;
    return del;
}

template <typename T>
T Container<T>::GetItem(int idx)
{
    if (idx < 0 || idx >= aIndex)
    {
        cout << "there is no" << endl;
        return NULL;
    }
    return arr[idx];
}
template <typename T>
int Container<T>::GetElemSum() // 총 가입 수
{
    return aIndex;
}

#endif //LIBPROJECT1_CONTAINER_H
