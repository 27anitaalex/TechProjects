/*Name:[Anita Alex]
*Course:[CSE 110]
*Assignment:[Lab 7]
*Due Date:[7/21/2024]
*Instructor:[Anne Pinder]
*Description:[Read in a series of sales dollar amounts and cost dollar amounts from a file that are tab
separated(tab delimited), and store the amounts in two (2) vectors. Sort both of the vectors from l
owest to highest. The price and cost will coincide when sorted]
*Requirements of the Lab.
1.Read in a series of sales dollar amounts and cost dollar amounts from a file that are tab separated
(tab delimited), and store the amounts in two (2) vectors.
2.Sort both of the vectors from lowest to highest. The price and cost will coincide when sorted.
3.Output the sorted lists of sales and costs to the console window, in two (2) columns right aligned,
and the sum for each column. Use “\t”, setw(x), and include dollar signs and precision as
appropriate. The totals may be computed in the output function.
4.EXTRA CREDIT (15 Points): Compute the profit for each sale and output to a third column in
the console window along with the sum of the profit. The profits may be computed in the
output function.
5.Required functions called from main and included in a header file: (1) opening the input file with
error handling (shown below), (2) reading the input and storing the values in vectors, (3) output to
the console window. Sort may be called from main using the vector sort function shown below.
The function definitions are to be in the header file.
6.Create the input file named “sales_and_cost_amounts.txt” and add the following values in the
order that they appear in two (2) columns with a tab between them. The sale price is in the left
column and cost is to the right. Use them to compute profit for extra credit.
7.Sample output to the console window. Use the size() member function for the number of sales items
in the vectors for the loops. Do not hard code the number. Assume we do not know what is in the file.

Test-suit:This is to check multiple parts of the program.
    Example: Normal:if the user types a number that works as a radius(not less then or equal to zero)
    should calculate everything.
    Rating:Success
    Example: Boundary:Should loop if the radius is less than or equal to zero.
    Rating:Succes
   Example:  Extreme:types in a big number like 1000 and works.
    Rating:Success
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "Proj2Functions.h"
#include <algorithm>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main()
{
	// variable declarations
    vector<double> sales;
    vector<double> cost;
    vector<double> profit;
    ifstream in_stream;
    double sales_sum = 0;
    double cost_sum = 0;

    //call the functions

    // open the file
    open_file (in_stream);

    //fill the vector from the file
    fill_vector_with_sales_and_cost(in_stream, sales, cost);

    //sort the data
    sort_vector (sales, cost);

    //compute the sum of sales
    sales_sum = sum_of_sales(sales);

    // compute the sum of cost
    cost_sum = sum_of_cost(cost);

    //give the output of the data
    output_sales_data(sales, cost, sales_sum, cost_sum);

    //close the file
    in_stream.close ( );

    return 0;

}

double sumCost = 0;
double sumSales = 0;

//opens the files
void open_file (ifstream& in_stream)
{
	// open the input file
    in_stream.open("sales_and_cost_amounts.txt");

	// if the open failed show that it failed
    if (in_stream.fail())
    {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}

// to split the input file so that it would sales and cost
std::vector<std::string> split(const std::string str, const std::string delimiter)
{
    std::vector<std::string> list;
    int start, end = -1*delimiter.size();
    do {
        start = end + delimiter.size();
        end = str.find(delimiter, start);
        string temp = str.substr (start, end - start);
        list.push_back (temp);
    } while (end != -1);

    return list;
}

//fill the vector with the sales and cost from sales and cost amounts.txt
void fill_vector_with_sales_and_cost(ifstream& in_stream, vector<double>& salesVector, vector<double>& costVector)
{

    string line;

    if (in_stream.is_open())
    {
        int index = 0;

        // the while gets the line in the input file and splits it
        while (getline(in_stream, line))
        {
            std::vector<std::string> salesData = split (line, "\t");
            //the push back is used to assign each line to the sales and the cost

            double sales = stod (salesData.at(0));
            salesVector.push_back (sales);

            double cost = stod (salesData.at(1));
            costVector.push_back (cost);
            index++;
        }
    }
}

//sort the vector from lowest to highest for sales and cost
void sort_vector (vector<double> & sales, vector<double>& cost)
{
	//sort both the sales and cost into lowest to highest
    sort(sales.begin(), sales.end());
    sort(cost.begin(), cost.end());
}

//get the sum of the sales that are in the vector
double sum_of_sales (vector<double> sales)
{
	//for loop to get the sum of the sales
    for (double val : sales)
    {
        sumSales += val;
    }
    return sumSales;
}

//get the sum of the cost that are in the vector
double sum_of_cost ( vector<double> cost)
{
	//for loop to get the sum of the cost
    for (double val : cost)
    {
        sumCost += val;
    }
    return sumCost;
}

//get the output of the sales and cost data into the console
void output_sales_data(vector<double> sales, vector<double> cost, double sumSales, double sumCost)
{
    cout.setf(ios::fixed);  //use fixed point
    cout.setf(ios::showpoint);    //display the decimal
    cout.precision(2);
    cout << "\t Project #2 - Anita Alex" << endl;
    cout << endl;
    cout << "\t The number of sales in the file is: " << sales.size() << endl;
    cout << "\t Amounts sorted from lowest to highest: " << endl;
    cout << endl;
    cout << "\t Sale Price" << setw(14) << "Cost" << setw(14) << "Profit" << endl;
    cout << endl;
    //for loop for to get all the values inside the vector as an output
    for (long i = 0; i < sales.size(); i++)
    {
		cout << "\t" << setw(6) << "$  " << setw(5) << right << sales.at(i)  ;
		cout << "\t" << setw(4) << "$  " << setw(5) << right << cost.at(i)  ;
		cout << "\t" << setw(2) << "$  " << setw(5) << right << sales.at(i)- cost.at(i)<< endl;

    }
    // include the sum of the sales, cost, and profit in the output as well
    cout << setw(19) << "--------" <<  setw(14) << "--------" <<  setw(15) << "--------" << endl;
    cout << "\t" << setw(5) << "$ " << setw(5) << sumSales << "\t" << setw(3) << "$ " << setw(5)
    << sumCost << "\t" << setw(2) << "$  " << setw(4) << sumSales - sumCost << endl;


}


