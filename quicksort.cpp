#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.h"
#include "quicksort.h"

using namespace std;

bool isLess(Customer& c1, Customer& c2, const vector<int>& filters) {
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

    //commenting this to try and implement several filters, safe to delete

    // if (cat == 0) {
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 1) {
    //     if (c1.getAge() < c2.getAge()) {
    //         return true;
    //     }
    //     if (c1.getAge() > c2.getAge()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 2) {
    //     if (c1.getGender() < c2.getGender()) {
    //         return true;
    //     }
    //     if (c1.getGender() > c2.getGender()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 3) {
    //     if (c1.getCountry() < c2.getCountry()) {
    //         return true;
    //     }
    //     if (c1.getCountry() > c2.getCountry()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 4) {
    //     if (c1.getAvgSpent() < c2.getAvgSpent()) {
    //         return true;
    //     }
    //     if (c1.getAvgSpent() > c2.getAvgSpent()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 5) {
    //     if (c1.getCategory() < c2.getCategory()) {
    //         return true;
    //     }
    //     if (c1.getCategory() > c2.getCategory()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 6) {
    //     if (c1.getCreditScore() < c2.getCreditScore()) {
    //         return true;
    //     }
    //     if (c1.getCreditScore() > c2.getCreditScore()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }
    // else if (cat == 7) {
    //     if (c1.getTotalSpent() < c2.getTotalSpent()) {
    //         return true;
    //     }
    //     if (c1.getTotalSpent() > c2.getTotalSpent()) {
    //         return false;
    //     }
    //     return c1.getIncome() < c2.getIncome();
    // }

}

void quicksort(vector<Customer>& v, int left, int right, const vector<int>& filters) {
    if (left < right) {
        int pivot = partition(v, left, right, filters);
        quicksort(v, left, pivot-1, filters);
        quicksort(v, pivot+1, right, filters);
    }
}

int partition(vector<Customer>& v, int low, int high, const vector<int>& filters) {
    int mid = (low + high) / 2;

    Customer& first = v[low];
    Customer& second = v[mid];
    Customer& last = v[high];

    int p;
    if ((isLess(first,second, filters) && isLess(second, last, filters)) || (isLess(last, second, filters) && isLess(second, first, filters))) {
        p = mid;
    }
    else if ((isLess(second, first, filters) && isLess(first, last, filters)) || (isLess(last, first, filters) && isLess(first, second, filters))) {
        p = low;
    }
    else {
        p = high;
    }

    swap(v[p], v[high]);
    Customer pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (isLess(v[j], pivot, filters)) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[high]);
    return i+1;
}


