
#ifndef MEASURETIME_H
#define MEASURETIME_H
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "Sorters.h"
#include "ASLLSearch.h"
#include "BinarySearchTree.h"

using namespace std;
class MeasureTime {
public:

    double measureTime(const std::string& func, std::vector<int>& data) {
        Sorters sorters;
        ASLLSearch assearch;
        BinarySearchTree bst;

        auto start = std::chrono::high_resolution_clock::now();  // Definir start antes de los ifs
        auto end = start;  // Inicializar end también para evitar el uso de variables sin inicializar

        // Seleccionar el algoritmo basado en 'func'
        if (func == "BubbleSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.bubbleSort(data);
        }
        else if (func == "SelectionSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.selectionSort(data);
        }
        else if (func == "MergeSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.mergeSort(data);
        }
        else if (func == "AllSortedLinkedListSearch") {
            start = std::chrono::high_resolution_clock::now();
            int a = data.size() - 1;
            assearch.search(data, a);
        }
        else if (func == "BinaryTreeSearch") {
            Node* root = new Node(data.size());
            start = std::chrono::high_resolution_clock::now();
            for (int i : data) {
                bst.insert(root, i);
            }
            // Nota: Asegúrate de liberar la memoria de 'root' después si es necesario.
        }
        else {
            throw std::invalid_argument("Error: El algoritmo '" + func + "' no es válido.");  // Lanzar excepción en caso de no coincidir con ningún algoritmo
        }

        // Medir tiempo
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }
};


#endif //MEASURETIME_H
