// Quadratic Equation Formula
#include <iostream>
#include <cmath>
using namespace std;

/// -------------------------------------------------------------------------
/// Function Prototypes
/// -------------------------------------------------------------------------
int myABS(int val);
void getCoefficients(double& a, double& b, double& c);
bool getDiscriminant(double a, double b, double c, double& d);
double getReal(double a, double b);
double getComplex(double a, double d);
void printSolution(double a, double b, double c);
void printNoSolution();
void printReal(double x);
void printReal(double x1, double x2);
void printComplex(double x, double c);
bool isFloatEqual(float a, float b, float epsilon = .0001F);
bool isFloatEqual(double a, double b, double epsilon = .0001);


    int main() {

    // Variable declarations(s)
    const int  EXITSTATE = EXIT_SUCCESS;
    // tracks the exit code for the process

    int testVal;                          // holds test values

    testVal = 0;                          // init variable to silence warning
    for (int i = 1; i < 10; i++) {
        testVal = (testVal > 0)? -i : i;  // generate alternate sign data
        cout << myABS(testVal) << endl;   // output the generated data

    }


    double a;                       // coefficent for x^2
    double b;                       // coefficent for x
    double c;                       // constant

    // input phase
    getCoefficients(a, b, c);
    // output / processing phase
    //
    if (isFloatEqual(a, 0)) {
        // the equation is not quadratic if a = 0; division by 0 error
        printNoSolution();
    } else {
        // calculate and print the roots
        printSolution(a, b, c);
    }
    cout << endl;


return EXITSTATE;
}

/// -------------------------------------------------------------------------
/// Function Implementations
/// -------------------------------------------------------------------------
int myABS(int val) {
    int newVal;     // holds the results of the caluculations
    newVal = (val < 0)? -val : val;     // makes the value always positive

    return newVal;
}

/// This function obtains the coefficients from the user and saves the rest
void getCoefficients(double& a, double& b, double& c) {
    cout << "\nEnter coefficients a, b and c: ";
    cin >> a >> b >> c;


}

/// This function calculates the discriminant and returns the abs result.
bool getDiscriminant(double a, double b, double c, double& d) {
    bool isNegative = false;

    d = b * b - 4 * a * c;
    if (d < 0) {
        isNegative = true;
        d = -d;
    }
    return isNegative;
}

/// This function calculates the real portion of complex reults and
/// -b/2a portion of real number.
double getReal(double a, double b) {
    return -b / (2 * a);
}


/// This function used to calculate imaginary portion of complex result and
/// the square root portion of real result.
double getComplex(double a, double d) {
    return sqrt(d) / (2 * a);
}

/// This function process the user inputs
void printSolution(double a, double b, double c) {
    double x1;              // calculated value for root 1
    double x2;              // calculated value for root 2
    double discriminant;    // calculated discriminant
    double real;            // real portion -b/2a
    double comp;            // complex portion sqrt(|d|)/2a
    bool   isImaginary;     // true is discriminant is negative, else false

    // obtain discriminant and set flag true if imaginary else false
    isImaginary = getDiscriminant(a, b, c, discriminant);

    // get the real component for complex results
    // get part of the real component for real results
    real = getReal(a, b);

    // get the imaginary component for complex results
    // get remaining part of the real compnent for real results
    comp = getComplex(a, discriminant);

    // genrate output based on discriminate values and whether or not
    // there is an imaginary component
    if (isImaginary) {
        printComplex(real, comp);           // print complex reult d < 0
    } else if (discriminant > 0) {
        // calculate the real results
        x1 = real + comp;
        x2 = real - comp;
        printReal(x1, x2);                  // print the real result d > 0
    } else {
        // calculate the real resuls
        x1 = real + comp;
        printReal(x1);                      // print the real resul d = 0
    }

}

/// This function prints a no solution message
void printNoSolution() {
    cout << "There is no solution.\n" << endl;
}

/// This function print the solution when the disccriminant = 0
void printReal(double x) {
    cout << "Roots are real and same." << endl;
    cout << "x1 = x2 = " << x << endl;

}

/// This function is an overload function printing different real results.
void printReal(double x1, double x2) {
    cout << "Roots are real and different." << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

}

/// This function prints complex conjugate pairs
void printComplex(double x, double c) {
    cout << "Roots are complex and different." << endl;

    cout << "x1 = " << x << " + ";
    if (!(isFloatEqual(c, 1))) {            // no need to print a coef of 1
        cout << c;
    }
    cout << "i" << endl;

    cout << "x2 = " << x << " - ";
    if (!(isFloatEqual(c, 1))) {            // no need to print a coef of 1
        cout << c;
    }
    cout << "i" << endl;

}

/// This function checks floats for equality
bool isFloatEqual(float a, float b, float epsilon) {
    float val = a -b;

    // get the abs of val for comparison with epsilon
    val = (val < 0) ? -val : val;

    return (val < epsilon);
}

/// This overloaded function checks doubles for equality
bool isFloatEqual(double a, double b, double epsilon) {
    double val = a - b;

    // get the abs of val for comparision with epsilon
    val = (val < 0) ? -val : val;

    return (val < epsilon);
}

