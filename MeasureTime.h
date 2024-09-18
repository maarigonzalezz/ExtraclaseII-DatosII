
#ifndef MEASURETIME_H
#define MEASURETIME_H
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "Sorters.h"
#include "ASLLSearch.h"
#include "BinarySearchTree.h"

using namespace std;
class MeasureTime {
public:

    // Función para medir el tiempo de ejecución de un algoritmo
    double measureTime(const std::string& func, std::vector<int>& data) {
        Sorters sorters;
        ASLLSearch assearch;
        BinarySearchTree bst;
        auto start = chrono::high_resolution_clock::now();
        if (func == "BubbleSort") {
            start = chrono::high_resolution_clock::now();
            sorters.bubbleSort(data);
        }
        if (func == "SelectionSort") {
            start = chrono::high_resolution_clock::now();
            sorters.selectionSort(data);
        }
        if (func == "MergeSort") {
            start = chrono::high_resolution_clock::now();
            sorters.mergeSort(data);
        }
        if (func == "AllSortedLinkedListSearch") {
            start = chrono::high_resolution_clock::now();
            int a = data.size() - 1;
            assearch.search(data, a);
        }
        if (func == "BinaryTreeSearch") {
            Node* root = new Node(data.size());
            start = chrono::high_resolution_clock::now();
            for (int i : data) {
                bst.insert(root, i);
            }
        }
        auto end = chrono::high_resolution_clock::now();  // Mantener end fuera de los if
        chrono::duration<double> duration = end - start;  // Aquí ya puedes usar start y end
        return duration.count();
    }
};


#endif //MEASURETIME_H
