//
// Created by erict on 10/28/2025.
//

#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
using namespace std;

Customer::Customer() {
    age = 0;
    //fix later
}

Customer::Customer(double income, int age, string gender, string country, double avg_spent, string category, int credit_score, double total_spent) {
    this->income = income;
    this->age = age;
    this->gender = gender;
    this->country = country;
    this->avg_spent = avg_spent;
    this->category = category;
    this->total_spent = total_spent;
    this->credit_score = credit_score;
    this->total_spent = total_spent;
}

