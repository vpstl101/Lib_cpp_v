//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_CREATARRAY_H
#define LIBPROJECT1_CREATARRAY_H

#include "Member.h"
#include "BookInfo.h"
using namespace std;

template<typename T>
class CreatArray {
private:
    T *arr;     // 객체 포인터 배열을 가리키는 포인터
    int arrlen;

    CreatArray(const CreatArray &arr) {}

    CreatArray &operator=(const CreatArray &arr) {}

public:
    CreatArray(int len = 100);

    T &operator[](int idx);

    T operator[](int idx) const;

    int GetArrLne() const;

    ~CreatArray();
};

template<typename T>
CreatArray<T>::CreatArray(int len) : arrlen(len) {
    arr = new T[len];
}

template<typename T>
T &CreatArray<T>::operator[](int idx) {
    if (idx < 0 || idx >= arrlen) {
        cout << "there is no" << endl;
        exit(1);
    }
    return arr[idx];
}

template<typename T>
T CreatArray<T>::operator[](int idx) const {
    if (idx < 0 || idx >= arrlen) {
        cout << "there is no" << endl;
        exit(1);
    }
    return arr[idx];
}

template<typename T>
int CreatArray<T>::GetArrLne() const {
    return arrlen;
}

template<typename T>
CreatArray<T>::~CreatArray() {
    delete[] arr;
}

#endif //LIBPROJECT1_CREATARRAY_H
