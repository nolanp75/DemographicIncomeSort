#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

#include "Customer.h"
#include "quicksort.h"
#include "heapsort.h"

using namespace std;

// data formatted in order of customer_id, name, email, age, gender, city, country, income, credit_score, loyalty_points,
// first_purchase_data, last_purchase_date, total_spent, avg_order_value, favorite_category,
// device_type, churn_risk, subscription, marketing_opt_in, support_tickets

void mainSort(ofstream& outfile, const vector<int>& filters, const vector<Customer>& customers) {
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

}

int main() {
    bool exit = false;
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
        cout << "\nPlease enter your chosen filters seperated by commas:\n(Income, Age, Gender, Country, Average Spent, Category, Credit Score, Total Spent, or Exit to quit (ex. 'Income, Age')" << endl;
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
            else if (filter_name == "Exit") {
                exit = true;
                break;
            }
            else cout << "Filter " << filter_name << " does not exist" << endl;
        }
        if (exit) {
            cout << "Goodbye!" << endl;
            break;
        }
        if (filters.empty()) continue; //ask again


        //choose algorithm here_________________________________________________________________________________________
        string algorithm;
        cout << "Sort by which algorithm (QuickSort or HeapSort)" << endl;
        getline(cin >> ws, algorithm);

        //timer start
        auto start_time = chrono::high_resolution_clock::now();

        //call algorithm
        if (algorithm == "QuickSort") {
            quicksort(customers, 0, customers.size()-1, filters);
            //timer logic
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;


            //write sort to file
            ofstream outfileQuick("quicksorted_customers.csv");
            mainSort(outfileQuick, filters, customers);
        }
        else if (algorithm == "HeapSort") {
            //heapsort();
            heapsort(customers, filters);
            //timer logic
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            cout << "Quicksort Execution time: " << duration.count() * 0.000001 << " seconds" << endl;


            //write sort to file
            ofstream outfileHeap("heapsorted_customers.csv");
            mainSort(outfileHeap, filters, customers);
        }
        else {
            cout << "Invalid algorithm" << endl;
        }


    }


    return 0;
}