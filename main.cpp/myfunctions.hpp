
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

string requestString()
{

    string text;

    cout << "Enter a value for the angle:" << endl;
    cin >> text;

    return text;
}

int analyseString(string text)
{
    int typeText;
    std::string str(text);
    bool isAllNumber;

    // this loop check if all chracter in the string is numbers
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if ((*it >= 48 && *it <= 57) or (*it == 46))
        {
            isAllNumber = true;
        }
        else
        {
            // there are one character in the string that is not a number
            isAllNumber = false;
            typeText = 2;
            break; // stop the loop
        }
    }

    if (isAllNumber) // is true if all character in the string is number
    {
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        {
            if (*it == 46) // 46 is the decimal that represents dot (.) in ASCII
            {
                typeText = 1;
                break; // break the loop when find a point (dot)
            }
            else
            {
                typeText = 0;
            }
        }
    }

    return typeText;

    // future work there are two errors to solve
    // First: we user gives two dots
    // Second: we give , instead of .
}

void stringToAngle(string text, int &angle) //receive the reference/address of angle
{
    int* pointer = &angle; //point to the addess of angle
    *pointer = std::stoi(text); //change the value of angle at the address of angle
}

void stringToAngle(string text, float &angle) //receive the reference/address of angle
{
    float* pointer = &angle; //point to the addess of angle
    *pointer = std::stof(text); //change the value of angle at the address of angle
}

void computeCosSin(int angle, float &cosValue, float &sinValue)
{
    float *pointCosValue = &cosValue;
    float *pointSinValue = &sinValue;

    *pointCosValue = cos(angle*M_PI/180);
    *pointSinValue = sin(angle*M_PI/180);

}

void computeCosSin(float angle, float &cosValue, float &sinValue)
{
    float *pointCosValue = &cosValue;
    float *pointSinValue = &sinValue;

    *pointCosValue = cos(angle);
    *pointSinValue = sin(angle);

}