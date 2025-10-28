#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.cpp"

using namespace std;

void quicksort(vector<int> &v, int left, int right){}

void quicksort(vector<int> &v, int left, int right, int cat) {

}

int partition(vector<Customer> &v, int low, int high) { //v is Customer vector
    auto pivot = v[low];
    int up = low, down = high;
    while (up < down)
        for (int j = up; j < high; j++)
            if(v[up] > pivot) break;
            up++;
            for (int j = high; j > low; j--)
                if(v[down].getIncome() < pivot.getIncome()) break;
                down--;
                if (up < down)
                    swap(v[up], v[down]);
    swap(v[low], v[down]);
    return down;
}


