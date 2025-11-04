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
    //info from csv file is grabbed and put into a vector of Customers



    //get filter, we want to make it so that you incrementally add filters, one after another, not all in one go.
    while (true) {
        cout << "\nPlease enter your chosen filters:\n(Income, Age, Gender, Country, Average Spent, Category, Credit Score, or Total Spent)" << endl;
        getline(cin >> ws, input);


        //vector of all filters
        vector<int> filters;
        stringstream ss(input);
        string filter_name;
        while (getline(ss, filter_name, ',')) {

            filter_name.erase(0, filter_name.find_first_not_of(" \t\n\r"));     //rid any spaces
            filter_name.erase(filter_name.find_last_not_of(" \t\n\r") + 1);

            if (filter_name == "Income") filters.push_back(0);
            else if (filter_name == "Age") filters.push_back(1);
            else if (filter_name == "Gender") filters.push_back(2);
            else if (filter_name == "Country") filters.push_back(3);
            else if (filter_name == "Average Spent") filters.push_back(4);
            else if (filter_name == "Category") filters.push_back(5);
            else if (filter_name == "Credit Score") filters.push_back(6);
            else if (filter_name == "Total Spent") filters.push_back(7);
            else cout << "Filter " << filter_name << " does not exist" << endl;
        }

        if (filters.empty()) continue; //ask again

        //timer
        auto start_time = chrono::high_resolution_clock::now();
        quicksort(customers, 0, customers.size()-1, filters); //fix this
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;

        //write sort to file
        ofstream outfile("quicksorted_customers.csv");

        //header
        outfile << "ID"; //always has their id in it
        for (int f : filters) {
            if (f==0) outfile << ", Income";
            else if (f==1) outfile << ", Age";
            else if (f==2) outfile << ", Gender";
            else if (f==3) outfile << ", Country";
            else if (f==4) outfile << ", Average Spent";
            else if (f==5) outfile << ", Category";
            else if (f==6) outfile << ", Credit Score";
            else if (f==7) outfile << ", Total Spent";
        }
        outfile << "\n";

        //actual body, it sorts things in the order u give it (IMPORTANT!!!!)_________________________________________________________________________________________________
        //example if its (country, age, income) they sort in that order
        //if two customers have same country, they sort by age, and so forth
        //changing the order of the filters changes the priority of sorting

        for (Customer c : customers) {
            outfile << c.getID();
            for (int f : filters) {
                if (f==0) outfile << " - $" << c.getIncome();
                else if (f==1) outfile << " - " << c.getAge();
                else if (f==2) outfile << " - " << c.getGender();
                else if (f==3) outfile << " - " << c.getCountry();
                else if (f==4) outfile << " - $" << c.getAvgSpent();
                else if (f==5) outfile << " - " << c.getCategory();
                else if (f==6) outfile << " - " << c.getCreditScore();
                else if (f==7) outfile << " - $" << c.getTotalSpent();
            }
            outfile << "\n";
        }
        outfile.close();

        //commenting this to try and implement several filters, safe to delete

        // //differentiates inputs
        // if (input == "Default") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 0);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Income" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << ": $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Age") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 1);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Age" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Age: " << customers[i].getAge() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Gender") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 2);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Gender" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Gender: " << customers[i].getGender() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Country") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 3);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Country" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Country: " << customers[i].getCountry() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Average Spent") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 4);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Average Spent Per Order" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Average Spent: $" << customers[i].getAvgSpent() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Category") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 5);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Most Common Category of Purchase" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Category: " << customers[i].getAge() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Credit Score") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 6);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Credit Score" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Credit Score: " << customers[i].getCreditScore() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        //
        //
        // else if (input == "Total Spent") {
        //     auto start_time = chrono::high_resolution_clock::now();
        //
        //     quicksort(customers, 0, customers.size()-1, 7);
        //     auto end_time = chrono::high_resolution_clock::now();
        //     auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        //     ofstream outfile("quicksorted_customers.csv");
        //     if (!outfile.is_open()) {
        //         cerr << "Error opening file!" << endl;
        //     }
        //     outfile << "Total Spent" << endl;
        //     for (int i = 0; i < customers.size(); i++) {
        //         outfile << customers[i].getID() << " Total Spent: $" << customers[i].getTotalSpent() << ", Income: $" << customers[i].getIncome() << endl;
        //     }
        //
        //     cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;
        // }
        // else if (input == "Exit") {
        //     break;
        // }
        // else {
        //     cout << "Invalid input!" << endl;
        // }
    }

    return 0;
}