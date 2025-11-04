#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "quicksort.h"

using namespace std;

void heapsort(vector<Customer> customers, const vector<int> filters) {
    //slide 45 of heaps powerpoint
    if (customers.size() <= 1) return;
    //building
    for (int i = customers.size()/2 - 1; i>=0; i--) {
        // heapifydown();
        heapifydown(customers, n, i, filters);
    }

    //removing one by one
    for (int i = customers.size() - 1; i>=0; i--) {
        swap(customers[0], customers[i]);
        heapifydown(customers, i, 0, filters);
        //heapifydown();
    }

}

void heapifydown(vector<Customer>& customers, int size, int index, const vector<int>& filters) {
    while (true) {
        int left  = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        // If left child is greater than current largest
        if (left < size && isLess(customers[largest], customers[left], filters)) {
            largest = left;
        }
        // If right child is greater than current largest
        if (right < size && isLess(customers[largest], customers[right], filters)) {
            largest = right;
        }

        if (largest == index) break; // heap property satisfied

        swap(customers[index], customers[largest]);
        index = largest;
    }
}