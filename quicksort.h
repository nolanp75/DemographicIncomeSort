//
// Created by nolan on 11/1/2025.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>
#include "Customer.h"
using namespace std;

void quicksort(vector<Customer>& v, int low, int high, int cat);

int partition(vector<Customer>& v, int low, int high, int cat);

bool isLess(Customer& c1, Customer& c2, int cat);
#endif //QUICKSORT_H
