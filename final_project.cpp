// Project done by SANTOSH MAHATO KOIRI
// ACE 079 BCT 059
// SCIENTIFIC CALCULATOR

#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

const double PI = 3.1415;

class Calculator {

private:
char operation, ch;
double num1, num2, angle;

public:
Calculator() {
    num1 = 0;
    num2 = 0;
    angle = 0;
}
// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Error: Division by zero!\n";
        return 0;
    }
}

// Function to calculate sine in degrees
double sine(double angle) {
    return sin(angle * PI / 180.0);
}

// Function to calculate cosine in degrees
double cosine(double angle) {
    return cos(angle * PI / 180.0);
}

// Function to calculate tangent in degrees
double tangent(double angle) {
    return tan(angle * PI / 180.0);
}

// Function to calculate arcsine in degrees
double arcsine(double value) {
    return asin(value) * 180.0 / PI;
}

// Function to calculate arccosine in degrees
double arccosine(double value) {
    return acos(value) * 180.0 / PI;
}

// Function to calculate arctangent in degrees
double arctangent(double value) {
    return atan(value) * 180.0 / PI;
}

// Function to calculate exponential
double exponential(double x) {
    return exp(x);
}

// Function to calculate natural logarithm
double logarithm(double x) {
    if (x > 0) {
        return log(x);
    } else {
        cerr << "Error: Argument of log must be greater than 0!\n";
        return 0; 
    }
}

// Function to calculate base-10 logarithm
double logarithm10(double x) {
    if (x > 0) {
        return log10(x);
    } else {
        cerr << "Error: Argument of log10 must be greater than 0!\n";
        return 0; //
    }
}

void Display() {
    do {
        system("cls");
        cout << "\n\n**************************Scientific Calculator Program**********************\n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "## Operations Menu:\n\n";
        cout << "A. Basic Operations:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n\n";
        cout << "B. Scientific Functions:\n";
        cout << "1. Sine (sin) (s/S)\n";
        cout << "2. Cosine (cos) (c/C)\n";
        cout << "3. Tangent (tan) (t/T)\n";
        cout << "4. Arcsine (asin) (a/A)\n";
        cout << "5. Arccosine (acos) (a/A)\n";
        cout << "6. Arctangent (atan) (a/A)\n";
        cout << "7. Exponential (exp) (e/E)\n";
        cout << "8. Natural Logarithm (log) (l/L)\n";
        cout << "9. Base-10 Logarithm (log10) (g/G)\n";

        cout << "\n\nEnter an operation (+,-,*,....) or function (s,c,t,....): ";
        cin >> operation;

        switch (operation) {
        // Basic arithmetic operations
        case '+':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
            break;
        case '/':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
            break;

        // Trigonometric functions
        case 's': // sin
        case 'S': // Sin
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: sin(" << num1 << ") = " << sine(num1) << endl;
            break;
        case 'c': // cos
        case 'C': // Cos
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: cos(" << num1 << ") = " << cosine(num1) << endl;
            break;
        case 't': // tan
        case 'T': // Tan
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: tan(" << num1 << ") = " << tangent(num1) << endl;
            break;
        case 'a': // arcsin, arccos, arctan
        case 'A': // Arcsin, Arccos, Arctan
            cout << "Enter value for arcsine, arccosine, or arctangent: ";
            cin >> num1;
            cout << "Result: asin(" << num1 << ") = " << arcsine(num1) << " degrees\n";
            cout << "        acos(" << num1 << ") = " << arccosine(num1) << " degrees\n";
            cout << "        atan(" << num1 << ") = " << arctangent(num1) << " degrees\n";
            break;

        // Exponential and logarithmic functions
        case 'e': // exp
        case 'E': // Exp
            cout << "Enter value for exponential function: ";
            cin >> num1;
            cout << "Result: exp(" << num1 << ") = " << exponential(num1) << endl;
            break;
        case 'l': // log
        case 'L': // Log
            cout << "Enter value for natural logarithm: ";
            cin >> num1;
            cout << "Result: log(" << num1 << ") = " << logarithm(num1) << endl;
            break;
        case 'g': // log10
        case 'G': // Log10
            cout << "Enter value for base-10 logarithm: ";
            cin >> num1;
            cout << "Result: log10(" << num1 << ") = " << logarithm10(num1) << endl;
            break;

        default:
            cerr << "Invalid operation or function!\n";
            break;
        }
    cout << "Do you want to continue ? (Enter y for yes!): ";
    cin >> ch;
    }while(ch == 'y' || ch == 'Y');
}
};


int main() {
    Calculator C;
    C.Display();
    return 0;
}
