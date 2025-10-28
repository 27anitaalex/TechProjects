// Comparing_Fuel_Costs.cpp
// Anita Alex
// 10/22/24

/* This program asks the user how many miles they drive each weekday. Then it asks the user whether they drive 
a compact car, a sedan, or SUV. Using estimates from online sources, output what the cost is of driving their 
vehicle along with an estimate for how much it would cost driving an EV that is charged at a "fast-driving" station
not owned by the user and what it would cost driving an EV that is charged at home using the user's privately 
owned charger. */

#include <iostream>

using namespace std;

int main()
{
	double miles(0.0), cost(0.0), premiumcost(0.0), EVcost1(0.0), EVcost2(0.0), gallons(0.0), type(0.0), EV(0.0),
		EV1(0.0);

	cout << "Welcome to the ComparingFuelCosts World! " << endl;
	cout << "Enter how many miles you drive each week: " << endl;
	cin >> miles;
	cout << "If the vehicle you operate is a compact car - enter 1, a sedan car - enter 2, or an SUV - enter 3: " << endl;
	cin >> type;

	if (type == 1)
	{
		// 25MPG $3.25 regular or $4.13 premium
		cost = (miles / 25) * 3.25;
		premiumcost = miles / 25 * 4.13;
		cout << "If you use premium gasoline you spend $" << premiumcost << ", and if regular - $" << cost << " per week" << endl;
	}
	else if (type == 2)
	{
		// 31.7 MPG
		cost = (miles / 31.7) * 3.25;
		premiumcost = (miles / 31.7) * 4.13;
		cout << "If you use premium gasoline you spend $" << premiumcost << ", and if regular - $" << cost << " per week." << endl;
	}
	else if (type == 3)
	{
		// 31 MPG
		cost = (miles / 31) * 3.25;
		premiumcost = (miles / 31) * 4.13;
		cout << "If you use premimum gasoline you spend $" << premiumcost << ", and if regular - $" << cost << " per week." << endl;
	}
	else
	{
		cout << "The number you input is not valid. ";
	}

	/* EV cost: 
	25 miles = 8 kwh. 3.125 miles per 1 kwh
	1 kwh = $0.50 
	if the person own a station = $0.05 */

	EV = miles / 3.125 * .5;
	EV1 = miles * 0.05;

	cout << "If you would ride an EV car you would spend $" << EV << " per week using public stations and $" <<
		EV1 << " per week if using personaly owned stations. " << endl;


    return 0;
}




