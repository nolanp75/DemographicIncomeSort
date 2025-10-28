#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

#include "Customer.cpp"
#include "quicksort.cpp"
#include "heapsort.cpp"

using namespace std;

// data formatted in order of customer_id, name, email, age, gender, city, country, income, credit_score, loyalty_points,
// first_purchase_data, last_purchase_date, total_spent, avg_order_value, favorite_category,
// device_type, churn_risk, subscription, marketing_opt_in, support_tickets

int main() {
    string data = "synthetic_customers.csv";
    string input;
    ifstream file(data);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }
    vector<Customer> customers;
    string header;
    getline(file, header);
    while (getline(file, input)) {
        stringstream ss(input);
        string cat;
        vector<string> customer_cats;

        while (getline(ss, cat, ',')) {
            customer_cats.push_back(cat);
        }

        int age = stoi(customer_cats[3]);
        string gender = customer_cats[4];
        string country = customer_cats[6];
        double avg_spent = stod(customer_cats[13]);
        string category = customer_cats[14];
        int credit_score = stoi(customer_cats[8]);
        double total = stod(customer_cats[12]);

        customers.emplace_back(age, gender, country, avg_spent, category, credit_score, total);
    }
    file.close();

    while (true) {
        cout << "Please enter your chosen filters:\n(Default, Age, Gender, Country, Average Spent, Category, Credit Score, or Total Spent)" << endl;
        cin >> input;
        if (input == "Default") {}
        else if (input == "Age") {}
        else if (input == "Gender") {}
        else if (input == "Country") {}
        else if (input == "Average Spent") {}
        else if (input == "Category") {}
        else if (input == "Credit Score") {}
        else if (input == "Total Spent") {}
        else if (input == "Exit") {
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}