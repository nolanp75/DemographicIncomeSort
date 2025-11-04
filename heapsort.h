//
// Created by nolan on 11/1/2025.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//idk if we need to make it a class but it should be fine with this

void heapsort(vector<Customer>& customers, const vector<int>& filters);

void heapifydown(vector<Customer>& customers, int size, int index, const vector<int>& filters);


#endif //HEAPSORT_H
