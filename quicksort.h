//
// Created by nolan on 11/1/2025.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>
#include "Customer.h"
using namespace std;

void quicksort(vector<Customer>& v, int low, int high, const vector<int>& filters);

int partition(vector<Customer>& v, int low, int high, const vector<int>& filters);

bool isLess(Customer& c1, Customer& c2, const vector<int>& filters);
#endif //QUICKSORT_H
