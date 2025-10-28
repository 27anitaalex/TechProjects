// How_many_days.cpp
// Anita Alex
// 10/3/2024

/* This program asks the user for two dates. The program figures out how many days there are between
the two dates. */

#include <iostream>

using namespace std;

int main()
{
	int jan(31), feb(28), mar(31), apr(30), may(31), june(30),
		july(31), aug(31), sept(30), oct(31), nov(30), dec(31), year(365);
	int month1(0), day1(0), year1(0), month2(0), day2(0), year2(0);
	int days(0), yeardiff(0), monthdiff(0), daydiff(0);
	bool date1_recent;




	cout << "Welcome to the How_many_days! This program will tell you how any days there are between the two dates.\nInput the month of the first date:";
	cin >> month1;
	cout << "Input the day of the first date:";
	cin >> day1;
	cout << "Input the year of the first date:";
	cin >> year1;
	cout << "Your first date is " << month1 << "/" << day1 << "/" << year1 << endl;

	cout << "Input the month of the second date:";
	cin >> month2;
	cout << "Input the day of the second date:";
	cin >> day2;
	cout << "Input the year of the second date:";
	cin >> year2;
	cout << "Your second date is " << month2 << "/" << day2 << "/" << year2 << endl;

	yeardiff = year1 - year2;
	monthdiff = month1 - month2;
	day_diff = day1 - day2;


	if (yeardiff > 0)
	{
		date1_recent = true;
	}
	else if (yeardiff < 0)
	{
		date1_recent = false;
	}
	else
	{
		if (monthdiff > 0)
		{
			date1_recent = true;
		}
		else if (monthdiff < 0)
		{
			date1_recent = false;
		}
		else
		{
			if (daysdiff > 0)
			{
				date1_recent = true;
				cout << "The number of days is " << day1 - day 2 << "." << endl;
			}
			else if (daysdiff < 0)
			{
				date1_recent = false;
				cout << "The number of days is " << day2 - day 1 << "." << endl;
			}
			else
			{
				cout << "Both dates are the same. Program ends." << endl;
			}
		}
	}

	cout << days << endl;
	return 0;

}

