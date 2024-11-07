//Anita Alex Project1
#include <iostream>
#include "WeatherData.h"
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // variable declarations
    double temp, windSpeed, windchill, cloudBase, dewPoint;
    ifstream in_stream;
    ofstream out_stream;
    string inputFilePath = "weatherData.txt";
    string outputFilePath = "Anita.txt";
    bool isInvalidWindchill = false;

    // get the input and output file stream
    get_input_file_stream(inputFilePath, in_stream);
    get_output_file_stream(outputFilePath, out_stream);

    // if input file is opened
    if (in_stream.is_open())
    {
        show_header(out_stream);
        show_subheader(out_stream);
        bool endOfFile = false;

        string line;

        //read temperature, windSpeed, and dewpoint from file
        while (endOfFile == false)
        {
            if( getline(in_stream, line) )
            {
                temp = stod( line);

                 if( getline(in_stream, line) )
                {
                    windSpeed = stod( line);

                     if( getline(in_stream, line) )
                    {
                        dewPoint = stod( line);
                        windchill = get_windchill(temp, windSpeed);
                        cloudBase = get_cloudBase(temp, dewPoint);

                        //write output to the file
                        show_output(out_stream, temp, windSpeed, windchill, cloudBase, dewPoint);

                        // if invalid windchill set the flag
                        if (windchill == 0.0)
                        {
                            isInvalidWindchill = true;
                        }

                    }
                    else
                        endOfFile = true;
                }
                else
                    endOfFile = true;
            }
            else
            {
                endOfFile = true;

            }
        }

    }

      // if input file is open then close it
      if (in_stream.is_open())
        {
            in_stream.close();
        }

      // if output file is open then close it
      if (out_stream.is_open())
        {
            show_footer( out_stream, isInvalidWindchill );
            out_stream.close();
        }

    return 0;
}


using namespace std;

// get the input from file stream
void get_input_file_stream( string filepath, ifstream & in_stream )
{
    in_stream.open(filepath);
}

//calculate windchill
double get_windchill( double temp, double windSpeed )
{
    double windchill = 0.0;

    // if to make sure that the temp and windSpeed is valid then find windchill
    if (temp <= 50 && windSpeed > 3.0)
    {
        windchill = 35.74 + (0.6215 * temp) - (35.75 * pow(windSpeed, 0.16)) + (0.4275 * temp * pow(windSpeed, 0.16));
    }
    return windchill;

}

// calculate the cloudbase
double get_cloudBase( double temp, double dewPoint)
{
    double cloudBase = 0, spread = 0;

    spread = temp - dewPoint;
    cloudBase = spread / 4.4 * 1000;

    return cloudBase;
}

//show the output
void show_output( ofstream &out_stream, double temp, double windSpeed, double windchill, double cloudBase, double dewPoint)
{
    std::ostringstream strs;
    strs.setf(ios::fixed);  //use fixed point
    strs.setf(ios::showpoint);    //display the decimal
    strs.precision(1);
    strs << windchill <<  " dF";
    string windchillstr = strs.str();

    // if to know if the windchill is valid or not
    if (windchill == 0)
    {
        windchillstr = "***";
    }


    cout.setf(ios::fixed);  //use fixed point
    cout.setf(ios::showpoint);    //display the decimal
    cout.precision(1);
    cout << setw(9) << temp << setw(3) << "dF" << setw(9) << windSpeed << setw(3) << " mph"
    << setw(10) << dewPoint << setw(3) << "dF" << setw(13) << windchillstr << setw(12) << cloudBase
    << setw(3) << "ft" << endl;

    // write to output file
    out_stream.setf(ios::fixed);  //use fixed point
    out_stream.setf(ios::showpoint);    //display the decimal
    out_stream.precision(1);
    out_stream << setw(9) << temp << setw(3) << "dF" << setw(9) << windSpeed << setw(3) << " mph"
    << setw(10) << dewPoint << setw(3) << "dF" << setw(13) << windchillstr << setw(12) << cloudBase
    << setw(3) << "ft" << endl;
}

//function to display the header
void show_header( ofstream &out_stream)
{
    cout << endl;
    cout << setw(25) << "Project #1 - Anita Alex" << endl;
    cout << endl;

    // write to output file
    out_stream << endl;
    out_stream << setw(25) << "Project #1 - Anita Alex" << endl;
    out_stream << endl;
}

// function to show the subheader
void show_subheader( ofstream &out_stream)
{
    cout.setf(ios::fixed);  //use fixed point
    cout.setf(ios::showpoint);    //display the decimal
    cout.precision(1);
    cout << setw(13) << "Temperature" << setw(13) << "Wind Speed" << setw(13) << "Dew Point" << setw(13)
    << "Wind Chill" << setw(14) << "Cloud Base" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    // write to output file
    out_stream.setf(ios::fixed);  //use fixed point
    out_stream.setf(ios::showpoint);    //display the decimal
    out_stream.precision(1);
    out_stream << setw(13) << "Temperature" << setw(13) << "Wind Speed" << setw(13) << "Dew Point" << setw(13)
    << "Wind Chill" << setw(14) << "Cloud Base" << endl;
    out_stream << "---------------------------------------------------------------------------------" << endl;
}

//get the output file stream
void get_output_file_stream( string filepath, ofstream & out_stream)
{
    out_stream.open(filepath);

}

// write footer
void show_footer(ofstream &out_stream, bool isInvalidWindchill)
{
    cout << endl;
    out_stream << endl;

    //if windchill is invalid display message
    if (isInvalidWindchill == true)
    {
        cout << setw(75) << "*** There is no wind chill factor at this temperature or wind speed. ***" << endl;
        cout << endl;
        cout << "\t*** Temperature must be 50 degrees or less, and" << endl;
        cout << "\t    wind speed must be > 3 mph to compute wind chill." << endl;

        // write to output file
        out_stream << setw(75) << "*** There is no wind chill factor at this temperature or wind speed. ***" << endl;
        out_stream << endl;
        out_stream << "\t*** Temperature must be 50 degrees or less, and" << endl;
        out_stream << "\t    wind speed must be > 3 mph to compute wind chill." << endl;
    }
}

