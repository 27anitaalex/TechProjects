// Fibonacci.cpp 
// Anita Alex
// 11/06/24

/* This program uses a while-loop to output to screen all the Fibonacci numbers from 1 to whatever number the user inputs.*/


#include <iostream>

using namespace std;

int main()
{
    
    int limit(0), n1(0), n2(1), sequence(0);

    cout << "Welcome to the Fibonacci World! Input a whole number: " << endl;
    cin >> limit;


    while (limit >= sequence)
    {
        sequence = n1 + n2;
        n1 = n2;
        n2 = sequence;
        cout << n1 << endl;
    }


    return 0;
}




