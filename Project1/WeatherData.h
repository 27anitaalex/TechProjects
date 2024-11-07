#ifndef WEATHERDATA_H_INCLUDED
#define WEATHERDATA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>



#endif // WEATHERDATA_H_INCLUDED
//function declaration

// get input file stream
void get_input_file_stream( std::string filepath, std::ifstream & in_stream);

// calculate windchill
double get_windchill( double temp, double windSpeed );

// calculate the cloudbase
double get_cloudBase( double temp, double dewPoint);

//show the output
void show_output( std::ofstream &out_stream, double temp, double windSpeed, double windchill, double cloudBase, double dewPoint);

//function to display the header
void show_header( std::ofstream &out_stream);

// function to show the subheader
void show_subheader( std::ofstream &out_stream);

//get the output file stream
void get_output_file_stream( std::string filepath, std::ofstream & out_stream);

// write footer
void show_footer(std::ofstream &out_stream, bool isInvalidWindchill);
