// Justin Santer
// SBU ID: 111501672
// AMS 326 HW 1
// Problem 2

#include <stdio.h>
#include <math.h>

static double func(double x);
static double secant_method(double x0, double x1);

static const int ITERATIONS = 6;

int main(){

    printf("Using secant method after %d iterations...\n", ITERATIONS);
    double x0;
    double x1;

    x0 = -0.8;
    x1 = -0.85;
    printf("Finding first root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    x0 = 1.25;
    x1 = 1.3;
    printf("Finding second root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    x0 = 1.4;
    x1 = 1.45;
    printf("Finding third root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    x0 = 1.65;
    x1 = 1.7;
    printf("Finding fourth root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    x0 = 1.8;
    x1 = 1.85;
    printf("Finding fifth root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    x0 = 1.9;
    x1 = 1.95;
    printf("Finding sixth root using x range of [%.2f, %.2f]: %f\n", x0, x1, secant_method(x0, x1));

    return 0;
}

//the given function of the problem
double func(double x){
    return pow(2.020, pow((-1 * x), 3)) - pow(x, 3) * cos(pow(x, 4)) - 1.984;
}

//function encapsulating the secant method
double secant_method(double x0, double x1){
    double x2; //the next x value in the method

    for(int i = 0; i < ITERATIONS; i++){
        x2 = x1 - ((func(x1) * (x1 - x0)) / (func(x1) - func(x0))); //calculates the next x value using secant formula
        x0 = x1; //turns the current x into the previous x
        x1 = x2; //turns the next x into the current x, loop repeats
    }

    return x2; //final value
}