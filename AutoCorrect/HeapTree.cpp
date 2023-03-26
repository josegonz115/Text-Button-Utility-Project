//
// Created by joseg on 3/21/2023.
//

#ifndef HEAPS_HEAPTREE_CPP
#define HEAPS_HEAPTREE_CPP
#include "HeapTree.h"

// Constructor----------------------------------------------------------------
template<typename T>
HeapTree<T>::HeapTree()
{
}

template<typename T>
HeapTree<T>::HeapTree(T value)
{
    tree.push_back(value);
}

template<typename T>
HeapTree<T>::HeapTree(std::vector<T> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        tree.push_back(vector[i]);
    }
}

template<typename T>
HeapTree<T>::HeapTree(const HeapTree<T> &other)
{
    tree = other.tree;
}

template<typename T>
HeapTree<T>& HeapTree<T>::operator=(const HeapTree<T>& other){
    if(this == &other)
        return *this;
    tree = other.tree;
    return *this;
}

// Mutators / Setters---------------------------------------------------------
template<typename T>
void HeapTree<T>::swap(int childIndex, int parentIndex)
{
    T temp = tree[childIndex];
    tree[childIndex] = tree[parentIndex];
    tree[parentIndex] = temp;
}

template<typename T>
void HeapTree<T>::push(const T &item)
{
    tree.push_back(item);
    heapifyUp(tree.size() - 1);
}

template<typename T>
void HeapTree<T>::pop()
{
    tree[0] = tree[tree.size() - 1];
    tree.pop_back();
    heapifyDown(0);
}

template<typename T>
void HeapTree<T>::heapifyUp(int childIndex)
{
    int parentIndex = getParent(childIndex);
    if(tree[childIndex] > tree[parentIndex]){
        swap(childIndex, parentIndex);
        heapifyUp(parentIndex);
    }
}

template<typename T>
void HeapTree<T>::heapifyDown(int parentIndex)
{
    int max = getMaxChild(parentIndex);
    if(tree[max] > tree[parentIndex]){
        swap(max, parentIndex);
        heapifyDown(max);
    }
}
template <typename T>
void HeapTree<T>::operator+=(const T& item){
    push(item);
}


// Accessors / Getters---------------------------------------------------------
template<typename T>
T &HeapTree<T>::top()
{
    return tree[0];
}

template<typename T>
int HeapTree<T>::size() const
{
    return tree.size();
}

template<typename T>
bool HeapTree<T>::empty() const
{
    return tree.empty();
}

template<typename T>
int HeapTree<T>::getParent(int childIndex)
{
    return (childIndex - 1) / 2;
}

template<typename T>
int HeapTree<T>::getLeftChild(int parentIndex)
{
    return (2 * parentIndex) + 1;
}

template<typename T>
int HeapTree<T>::getRightChild(int parentIndex)
{
    return 2 * parentIndex + 2;
}

template<typename T>
int HeapTree<T>::getMaxChild(int parentIndex)
{
    // In case only left child exists.
    int leftIndex = getLeftChild(parentIndex);
    int rightIndex = getRightChild(parentIndex);
    int size = tree.size();
    if(leftIndex < size && rightIndex >= size){
        if(tree[leftIndex] > tree[parentIndex]){
            return leftIndex;
        }
        return parentIndex;
    }
        // In case no children exist.
    else if(leftIndex >= size && rightIndex >= size){
        return parentIndex;
    }

    // In case both children exist.
    T leftChild = tree[leftIndex];
    T rightChild = tree[rightIndex];

    //check for max among left and right child
    int maxChildIndex = (leftChild >= rightChild) ? leftIndex : rightIndex;
    // check if tree[maxChild} is greater
    if(tree[maxChildIndex] > tree[parentIndex]){
        return maxChildIndex;
    }
    return parentIndex;
}

#endif //HEAPS_HEAPTREE_CPP