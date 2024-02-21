# Linked List Based MinHeap

This repository contains an implementation of a LinkMinHeap, a type of heap where each node has a value less than or equal to its children's values.

## Overview

- `BTNode` Class: Represents a node in the binary tree used for LinkMinHeap.
  - Attributes:
    - `info`: Value of the node.
    - `left`: Pointer to the left child node.
    - `right`: Pointer to the right child node.
- `LinkMinHeap` Class: Represents the LinkMinHeap data structure.
  - Attributes:
    - `root`: Pointer to the root node of the binary tree.
    - `count`: Current number of elements in the heap.
  - Methods:
    - `insert()`: Insert a new key into the heap.
    - `removeMin()`: Remove and return the minimum element from the heap.
    - `getMin()`: Get the minimum element in the heap.
    - `isEmpty()`: Check if the heap is empty.
    - `inOrder()`: Perform an in-order traversal of the heap tree.

## Usage

1. Create an instance of the `LinkMinHeap` class.
2. Use the provided methods to perform operations like insertion, deletion, getting minimum, checking emptiness, and in-order traversal.

```cpp
#include <iostream>
#include "Stack.h" 
using namespace std;

/

int main() {
    LinkMinHeap<int> obj;
    cout << "Min Heap Created" << endl;

    int option, val;

    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Delete Minimum Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. To print InOrder" << endl;
        cout << "6. Bool is empty or not " << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
            // Select Options from Menu
        }

    } while (option != 0);

    return 0;
}
