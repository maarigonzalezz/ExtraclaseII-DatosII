#include "ASLLSearch.h"

int ASLLSearch::search(const std::vector<int>& array, int number) {
    int N = array.size();
    int i = 0;

    for(; i < N; i++) {
        if (array[i] == number)
            break;
        if (array[i] > number) {
            i = -1;
            break;
        }
    }

    if (i == N)
        i = -1;

    return i;  // Retorna el índice donde se encontró el número o -1 si no se encontró
}
