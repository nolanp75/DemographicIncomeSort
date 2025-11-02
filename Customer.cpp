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
    income = 0;
    gender = "";
    country = "";
    avg_spent = 0;
    category = "";
    credit_score = 0;
    total_spent = 0;
    id = "";
}

Customer::Customer(double income, int age, string gender, string country, double avg_spent, string category, int credit_score, double total_spent, string id) {
    this->id = id;
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

double Customer::getIncome() {
    return income;
}


int Customer::getAge() {
    return age;
}

string Customer::getGender() {
    return gender;
}

string Customer::getCountry() {
    return country;
}

double Customer::getAvgSpent() {
    return avg_spent;
}

string Customer::getCategory() {
    return category;
}

int Customer::getCreditScore() {
    return credit_score;
}

double Customer::getTotalSpent() {
    return total_spent;
}

string Customer::getID() {
    return id;
}
