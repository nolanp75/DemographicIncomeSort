#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "heapsort.h"


using namespace std;

bool isLessHeap(Customer& c1, Customer& c2, const vector<int>& filters) {
    for (int f : filters) {

        if (f == 0) {
            if (c1.getIncome() < c2.getIncome())
                return true;
            if (c1.getIncome() > c2.getIncome())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 1) {
            if (c1.getAge() < c2.getAge())
                return true;
            if (c1.getAge() > c2.getAge())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 2) {
            if (c1.getGender() < c2.getGender())
                return true;
            if (c1.getGender() > c2.getGender())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 3) {
            if (c1.getCountry() < c2.getCountry())
                return true;
            if (c1.getCountry() > c2.getCountry())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 4) {
            if (c1.getAvgSpent() < c2.getAvgSpent())
                return true;
            if (c1.getAvgSpent() > c2.getAvgSpent())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 5) {
            if (c1.getCategory() < c2.getCategory())
                return true;
            if (c1.getCategory() > c2.getCategory())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 6) {
            if (c1.getCreditScore() < c2.getCreditScore())
                return true;
            if (c1.getCreditScore() > c2.getCreditScore())
                return false;
            return c1.getIncome() < c2.getIncome();
        }

        if (f == 7) {
            if (c1.getTotalSpent() < c2.getTotalSpent())
                return true;
            if (c1.getTotalSpent() > c2.getTotalSpent())
                return false;
            return c1.getIncome() < c2.getIncome();
        }
    }
    return false;
}

void heapsort(vector<Customer>& customers, const vector<int>& filters) {
    //slide 45 of heaps powerpoint
    int size = customers.size();
    if (customers.size() <= 1) return;
    //building
    for (int i = customers.size()/2 - 1; i>=0; i--) {
        // heapifydown();
        heapifydown(customers, size, i, filters);
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
        if (left < size && isLessHeap(customers[largest], customers[left], filters)) {
            largest = left;
        }
        // If right child is greater than current largest
        if (right < size && isLessHeap(customers[largest], customers[right], filters)) {
            largest = right;
        }

        if (largest == index) break; // heap property satisfied

        swap(customers[index], customers[largest]);
        index = largest;
    }
}