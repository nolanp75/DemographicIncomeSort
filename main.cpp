#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

#include "Customer.h"
#include "quicksort.h"
#include "heapsort.cpp"

using namespace std;

// data formatted in order of customer_id, name, email, age, gender, city, country, income, credit_score, loyalty_points,
// first_purchase_data, last_purchase_date, total_spent, avg_order_value, favorite_category,
// device_type, churn_risk, subscription, marketing_opt_in, support_tickets

int main() {
    string data = "../synthetic_customers.csv";
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

        double income = stod(customer_cats[7]);
        int age = stoi(customer_cats[3]);
        string gender = customer_cats[4];
        string country = customer_cats[6];
        double avg_spent = stod(customer_cats[13]);
        string category = customer_cats[14];
        int credit_score = stoi(customer_cats[8]);
        double total = stod(customer_cats[12]);
        string id = customer_cats[0];

        customers.emplace_back(income, age, gender, country, avg_spent, category, credit_score, total, id);
    }
    file.close();

    while (true) {
        cout << "Please enter your chosen filters:\n(Default, Age, Gender, Country, Average Spent, Category, Credit Score, or Total Spent)" << endl;
        getline(cin >> ws, input);
        if (input == "Default") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 0);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Income" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << ": $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Age") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 1);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Age" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Age: " << customers[i].getAge() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Gender") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 2);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Gender" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Gender: " << customers[i].getGender() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Country") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 3);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Country" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Country: " << customers[i].getCountry() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Average Spent") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 4);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Average Spent Per Order" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Average Spent: $" << customers[i].getAvgSpent() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Category") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 5);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Most Common Category of Purchase" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Category: " << customers[i].getAge() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Credit Score") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 6);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Credit Score" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Credit Score: " << customers[i].getCreditScore() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Total Spent") {
            auto start_time = chrono::high_resolution_clock::now();

            quicksort(customers, 0, customers.size()-1, 7);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            ofstream outfile("quicksorted_customers.csv");
            if (!outfile.is_open()) {
                cerr << "Error opening file!" << endl;
            }
            outfile << "Total Spent" << endl;
            for (int i = 0; i < customers.size(); i++) {
                outfile << customers[i].getID() << " Total Spent: $" << customers[i].getTotalSpent() << ", Income: $" << customers[i].getIncome() << endl;
            }

            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        }
        else if (input == "Exit") {
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}