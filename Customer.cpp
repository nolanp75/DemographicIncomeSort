//
// Created by erict on 10/28/2025.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Customer {
private:
    int age;
    string gender;
    string country;
    double avg_spent;
    string category;
    int credit_score;
    double total_spent;

public:
    Customer() {
        age = 0;
        gender = "";
        country = "";
        avg_spent = 0;
        category = "";
        credit_score = 0;
        total_spent = 0;
    }

    Customer(int a, string g, string c, double a_s, string cat, int c_s, double t_s){
        age = a;
        gender = g;
        country = c;
        avg_spent = a_s;
        category = cat;
        credit_score = c_s;
        total_spent = t_s;
    }

    int getAge() {
        return age;
    }

    string getGender() {
        return gender;
    }

    string getCountry() {
        return country;
    }

    double getAvgSpent() {
        return avg_spent;
    }

    string getCategory() {
        return category;
    }

    int getCreditScore() {
        return credit_score;
    }

    double getTotalSpent() {
        return total_spent;
    }
};