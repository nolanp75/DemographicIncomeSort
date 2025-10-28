#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Customer {
private:
    double income; //main sort
    int age;
    string gender;
    string country;
    double avg_spent;
    string category;
    int credit_score;
    double total_spent;

public:
    Customer();

    Customer(double income, int age, string gender, string country, double avg_spent, string category, int credit_score, double total_spent);

    double getIncome();

    int getAge();

    string getGender();

    string getCountry();

    double getAvgSpent();

    string getCategory();

    int getCreditScore();

    double getTotalSpent();

    bool operator>(vector<Customer>::const_reference value) const;
};


#endif //CUSTOMER_H