//
// Created by nolan on 10/28/2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream file("synthetic_customers.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    while (getline(file, line)) {
        // data formatted in order of customer_id, name, email, age, gender, city, country, income, credit_score, loyalty_points,
        // first_purchase_data, last_purchase_date, total_spent, avg_order_value, favorite_category,
        // device_type, churn_risk, subscription, marketing_opt_in, support_tickets
        cout << line << endl;
    }

    file.close();
    return 0;
}