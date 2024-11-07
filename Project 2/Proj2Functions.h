#ifndef PROJ2FUNCTIONS_H_INCLUDED
#define PROJ2FUNCTIONS_H_INCLUDED
#include <algorithm>
#include <vector>
#include <fstream>


#endif // PROJ2FUNCTIONS_H_INCLUDED

using namespace std;

// declaration of functions

//opens the files
void open_file (ifstream& in_stream);

//fill the vector with the sales and cost from sales and cost amounts.txt
void fill_vector_with_sales_and_cost(ifstream& in_stream, vector<double>& sales, vector<double>& cost);

//sort the vector from lowest to highest for sales and cost
void sort_vector (vector<double>& sales, vector<double>& cost);

//get the sum of the sales that are in the vector
double sum_of_sales (vector<double> sales);

//get the sum of the cost that are in the vector
double sum_of_cost ( vector<double> cost);

//get the output of the sales and cost data into the console
void output_sales_data(vector<double> sales, vector<double> cost, double sumSales, double sumCost);
