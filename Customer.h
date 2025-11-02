#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Customer {
private:
    string id;
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

    Customer(double income, int age, string gender, string country, double avg_spent, string category, int credit_score, double total_spent, string id);

    double getIncome();

    string getID();

    int getAge();

    string getGender();

    string getCountry();

    double getAvgSpent();

    string getCategory();

    int getCreditScore();

    double getTotalSpent();


};


#endif //CUSTOMER_H