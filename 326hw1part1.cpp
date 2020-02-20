// Justin Santer
// SBU ID: 111501672
// AMS 326 HW 1
// Problem 1

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>

static double upper_heart(double x);
static double lower_heart(double x);
static double rand_double(double a, double b);
static double rec_area(double length, double width);
static double circle_area(double r);

static const int SAMPLE = 1000000000;
static const double MIN_X = 0.0;
static const double MAX_X = sqrt(2);
static const double MIN_Y = -sqrt(2);
static const double MAX_Y = 2.067;
static const double MAX_RADIUS = 1.032764;

int main(){
    clock_t start, end;
    start = clock();

    printf("Starting AMS 326 HW 1 Problem 1.1...\n");

    printf("Using Monte Carlo method to find area...\n");

    double rand_x, rand_y;
    double upper_val, lower_val;
    
    int valid_count = 0; //counter for valid points

    srand(time(0)); //sets seed for random algorithm with current time

    printf("Generating %d random coordinates...\n", SAMPLE);
    for(int i = 0; i < SAMPLE; i++){
        rand_x = rand_double(MIN_X, MAX_X); //random x coordinate
        rand_y = rand_double(MIN_Y, MAX_Y); //random y coordinate

        upper_val = upper_heart(rand_x); //upper y value
        lower_val = lower_heart(rand_x); //lower y value

        if (rand_y <= upper_val && rand_y >= lower_val){ //if random y is between lower and upper value, increase counter
            valid_count++; 
        }
    }

    double valid_rate = valid_count / (double) SAMPLE; 

    printf("Valid Rate %f\n", valid_rate);

    double total_area = rec_area(MAX_X - MIN_X, MAX_Y - MIN_Y); //get the sample area
    double half_heart_area = valid_rate * total_area; //area of half the heart
    double total_heart_area = 2 * half_heart_area; //area of full heart

    printf("Sample Area: %f\n", total_area);
    printf("Half Heart Area (Valid Rate * Sample Area): %f\n", half_heart_area);
    printf("Total Heart Area (2 * Half Heart Area): %f\n", total_heart_area);

    double c_area = circle_area(MAX_RADIUS); //max area of circle
    double final_area = total_heart_area - c_area; //final area

    printf("Max Circle Area: %f\n", c_area);
    printf("Final Area: %f\n", final_area);

    end = clock();
    double diff = (double) end - (double) start;
    diff = diff / CLOCKS_PER_SEC;
    diff = diff / 60; //get the running time of the program
    printf("Runtime: %.2f minutes", diff);
    return 0;
}

//upper value of the heart, floating point operations: 6
double upper_heart(double x){
    return sqrt(2 - pow(x,2)) + sqrt(abs(x));
}

//lower value of the heart, floating point operations: 6
double lower_heart(double x){
    return sqrt(abs(x)) - sqrt(2 - pow(x,2));
}

//gets a random double value between the given range values, floating point operations: 4
double rand_double(double a, double b){
    double random = ((double) rand()) / (double) RAND_MAX;
    double difference = b - a;
    return random * difference + a;
}

//area of a rectangle, floating point operations: 1
double rec_area(double length, double width){
    return length * width;
}

//area of a circle, floating point operations: 2
double circle_area(double r){
    return M_PI * pow(r, 2);
}