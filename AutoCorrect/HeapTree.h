//
// Created by joseg on 3/21/2023.
//

#ifndef HEAPS_HEAPTREE_H
#define HEAPS_HEAPTREE_H
#include <vector>
#include <cmath>

template <typename T>
class HeapTree
{
private:
    std::vector<T> tree;
public:
    // Constructor
    HeapTree();
    HeapTree(T value);
    HeapTree(std::vector<T> vector);

    // BIG 2
    HeapTree(const HeapTree<T>& other);
    HeapTree<T>& operator=(const HeapTree<T>& other);

    // Mutators / Setters
    void swap(int childIndex, int parentIndex);
    void push(const T& item);
    void pop();
    void heapifyUp(int childIndex);
    void heapifyDown(int parentIndex);
    // Override  the += operator
    void operator+=(const T& item);

    void clear();


    // Accessors / Getters
    T& top();
    int size() const;
    bool empty() const;
    int getParent(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);

};

#include "HeapTree.cpp"
#endif //HEAPS_HEAPTREE_H
