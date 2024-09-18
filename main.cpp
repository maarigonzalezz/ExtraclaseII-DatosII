#include <iostream>
#include "MeasureTime.h"

using namespace std;
int main() {
    string alg;
    int N1 = 200;
    int N2 = 500;
    int N3 = 700;
    int N4 = 1000;
    int N5 = 1500;

    // Generación de datos para los diferentes casos
    vector<int> best_case1(N1);   // Ordenado
    vector<int> worst_case1(N1);  // Orden inverso
    vector<int> avg_case1(N1);    // Valores aleatorios

    vector<int> best_case2(N2);   // Ordenado
    vector<int> worst_case2(N2);  // Orden inverso
    vector<int> avg_case2(N2);    // Valores aleatorios

    vector<int> best_case3(N3);   // Ordenado
    vector<int> worst_case3(N3);  // Orden inverso
    vector<int> avg_case3(N3);    // Valores aleatorios

    vector<int> best_case4(N4);   // Ordenado
    vector<int> worst_case4(N4);  // Orden inverso
    vector<int> avg_case4(N4);    // Valores aleatorios

    vector<int> best_case5(N5);   // Ordenado
    vector<int> worst_case5(N5);  // Orden inverso
    vector<int> avg_case5(N5);    // Valores aleatorios


    // Inicialización de los casos
    iota(best_case1.begin(), best_case1.end(), 1);
    iota(worst_case1.begin(), worst_case1.end(), 1);
    reverse(worst_case1.begin(), worst_case1.end());
    generate(avg_case1.begin(), avg_case1.end(), std::rand);

    // Inicialización de los casos
    iota(best_case2.begin(), best_case2.end(), 1);
    iota(worst_case2.begin(), worst_case2.end(), 1);
    reverse(worst_case2.begin(), worst_case2.end());
    generate(avg_case2.begin(), avg_case2.end(), std::rand);

    // Inicialización de los casos
    iota(best_case3.begin(), best_case3.end(), 1);
    iota(worst_case3.begin(), worst_case3.end(), 1);
    reverse(worst_case3.begin(), worst_case3.end());
    generate(avg_case3.begin(), avg_case3.end(), std::rand);

    // Inicialización de los casos
    iota(best_case4.begin(), best_case4.end(), 1);
    iota(worst_case4.begin(), worst_case4.end(), 1);
    reverse(worst_case4.begin(), worst_case4.end());
    generate(avg_case4.begin(), avg_case4.end(), std::rand);

    // Inicialización de los casos
    iota(best_case5.begin(), best_case5.end(), 1);
    iota(worst_case5.begin(), worst_case5.end(), 1);
    reverse(worst_case5.begin(), worst_case5.end());
    generate(avg_case5.begin(), avg_case5.end(), std::rand);


    cout << "Ingrese un algoritmo de los siguientes en lista para observar su complejidad:" << endl;
    cout << "-BubbleSort" << endl << "-SelectionSort" << endl << "-MergeSort" << endl;
    cout << "-AllSortedLinkedListSearch" << endl << "-BinaryTreeSearch" << endl;
    getline(cin, alg);
    MeasureTime medida;

    cout << "Pares ordenados N en funcion del tiempo (N,t)" << endl << "MEJOR CASO" << endl;

    //Par ordenado 1
    auto bc1 = medida.measureTime(alg, best_case1);
    cout << "(" << N1 << " ," << bc1 << ")" << endl;

    //Par ordenado 2
    auto bc2 = medida.measureTime(alg, best_case2);
    cout << "(" << N2 << " ," << bc2 << ")" << endl;

    //Par ordenado 3
    auto bc3 = medida.measureTime(alg, best_case3);
    cout << "(" << N3 << " ," << bc3 << ")" << endl;

    //Par ordenado 4
    auto bc4 = medida.measureTime(alg, best_case3);
    cout << "(" << N4 << " ," << bc4 << ")" << endl;


    cout << endl << "CASO PROMEDIO" << endl;
    //Par ordenado 1
    auto avg1 = medida.measureTime(alg, avg_case1);
    cout << "(" << N1 << " ," << avg1 << ")" << endl;

    //Par ordenado 2
    auto avg2 = medida.measureTime(alg, avg_case2);
    cout << "(" << N2 << " ," << avg2 << ")" << endl;

    //Par ordenado 3
    auto avg3 = medida.measureTime(alg, avg_case3);
    cout << "(" << N3 << " ," << avg3 << ")" << endl;

    //Par ordenado 4
    auto avg4 = medida.measureTime(alg, avg_case4);
    cout << "(" << N4 << " ," << avg4 << ")" << endl;


    cout << endl << "PEOR CASO" << endl;
    //Par ordenado 1
    auto wc1 = medida.measureTime(alg, avg_case1);
    cout << "(" << N1 << " ," << wc1 << ")" << endl;

    //Par ordenado 2
    auto wc2 = medida.measureTime(alg, avg_case2);
    cout << "(" << N2 << " ," << wc2 << ")" << endl;

    //Par ordenado 3
    auto wc3 = medida.measureTime(alg, avg_case3);
    cout << "(" << N3 << " ," << wc3 << ")" << endl;

    //Par ordenado 4
    auto wc4 = medida.measureTime(alg, avg_case4);
    cout << "(" << N4 << " ," << wc4 << ")" << endl;



    /*
    BinarySearchTree bst;
    Node* root = new Node(50);
    root = bst.insert(root, 30);
    root = bst.insert(root, 20);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 60);
    root = bst.insert(root, 80);

    // Print inorder traversal of the BST
    bst.inorder(root);*/

    return 0;
}
