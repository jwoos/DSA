#include <vector>

template <typename T>
void insertionSort(std::vector<T>&);

template <typename T, typename C>
void insertionSort(std::vector<T>&, C);

template <typename T>
void mergeSort(std::vector<T>&);

template <typename T, typename C>
void mergeSort(std::vector<T>&, C);

template <typename T>
void quickSort(std::vector<T>&);

template <typename T, typename C>
void quickSort(std::vector<T>&, C);

template <typename T>
void selectionSort(std::vector<T>&);

template <typename T, typename C>
void selectionSort(std::vector<T>&, C);

template <typename T>
void shellSort(std::vector<T>& v);

template <typename T, typename C>
void shellSort(std::vector<T>& v, C);

template <typename T>
void setSort(std::vector<T>&);

#include "sort.cpp"
