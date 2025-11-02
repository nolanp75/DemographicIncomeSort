#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.h"
#include "quicksort.h"

using namespace std;

bool isLess(Customer& c1, Customer& c2, int cat) {
    if (cat == 0) {
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 1) {
        if (c1.getAge() < c2.getAge()) {
            return true;
        }
        if (c1.getAge() > c2.getAge()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 2) {
        if (c1.getGender() < c2.getGender()) {
            return true;
        }
        if (c1.getGender() > c2.getGender()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 3) {
        if (c1.getCountry() < c2.getCountry()) {
            return true;
        }
        if (c1.getCountry() > c2.getCountry()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 4) {
        if (c1.getAvgSpent() < c2.getAvgSpent()) {
            return true;
        }
        if (c1.getAvgSpent() > c2.getAvgSpent()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 5) {
        if (c1.getCategory() < c2.getCategory()) {
            return true;
        }
        if (c1.getCategory() > c2.getCategory()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 6) {
        if (c1.getCreditScore() < c2.getCreditScore()) {
            return true;
        }
        if (c1.getCreditScore() > c2.getCreditScore()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }
    else if (cat == 7) {
        if (c1.getTotalSpent() < c2.getTotalSpent()) {
            return true;
        }
        if (c1.getTotalSpent() > c2.getTotalSpent()) {
            return false;
        }
        return c1.getIncome() < c2.getIncome();
    }

}

void quicksort(vector<Customer>& v, int left, int right, int cat) {
    if (left < right) {
        int pivot = partition(v, left, right, cat);
        quicksort(v, left, pivot-1, cat);
        quicksort(v, pivot+1, right, cat);
    }
}

int partition(vector<Customer>& v, int low, int high, int cat) {
    int mid = (low + high) / 2;

    Customer& first = v[low];
    Customer& second = v[mid];
    Customer& last = v[high];

    int p;
    if ((isLess(first,second, cat) && isLess(second, last, cat)) || (isLess(last, second, cat) && isLess(second, first, cat))) {
        p = mid;
    }
    else if ((isLess(second, first, cat) && isLess(first, last, cat)) || (isLess(last, first, cat) && isLess(first, second, cat))) {
        p = low;
    }
    else {
        p = high;
    }

    swap(v[p], v[high]);
    Customer pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (isLess(v[j], pivot, cat)) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[high]);
    return i+1;
}


