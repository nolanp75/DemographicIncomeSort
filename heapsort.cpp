#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "quicksort.h"

using namespace std;

void heapsort(vector<Customer> customers, const vector<int> filters) {
    //slide 45 of heaps powerpoint

    //building
    for (int i = customers.size()/2; i>=0; i--) {
        // heapifydown();
    }

    //removing one by one
    for (int i = customers.size()-1; i>=0; i--) {
        swap(customers[0], customers[i]);
        //heapifydown();
    }

}

void heapifydown(vector<Customer> customers, int size, int index, const vector<int>& filters) {
    //
}
