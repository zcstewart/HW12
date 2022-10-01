//Homework 12

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to determine the 
 *                      longest pipe that can maneuver through a 90 degree
 *                      hallway. The each hallway has a separate width 
 *                      (in feet) the user will be prompted to enter. If 
 *                      the ideal length is not a whole number, it will be
 *                      rounded down to the nearest whole number. There are
 *                      two primary methods to solve this problem. One is 
 *                      through incrementing theta and finding the minimum
 *                      length of the pipe. The other is accomplished with
 *                      calculus. For the purposes of this program, the 
 *                      incremental method will be employed.
 *  
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/30/2017 13:25 PST
 */

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

using namespace std;

const double step_size = 0.01;
const double _PI = 3.14159265;

void longestPipe(double wHallway1, double wHallway2, 
                 double &mTheta, double &mLength); 

int main(int argc, char** argv)
{
    
    //Declare variables
    double length_AC = 0;
    double theta_CRIT = 0;
    double width_AB, width_BC;
    
    //Prompt user for input
    cout << "Enter the length of the first hallway: " << endl;
    cin >> width_AB;
    cout << "Enter the length of the second hallway: " << endl;
    cin >> width_BC;
    
    width_AB = fabs(width_AB);
    width_BC = fabs(width_BC);
    
    //Initialize 
    longestPipe(width_AB, width_BC, theta_CRIT, length_AC);    
    
    //Output Data
    cout << "The length constraint occurs at Theta: " << fixed << showpoint;
    cout << setprecision(2) << theta_CRIT << " deg." << endl;
    
    //Remove fixed format to clear decimal ending
    cout.unsetf(ios::fixed);
    
    cout << "Length of longest pipe is: " << noshowpoint;
    cout << floor(length_AC) << " ft." << endl;
    
    //Terminate program upon successful completion.
    exit(EXIT_SUCCESS);
}

void longestPipe(double wHallway1, double wHallway2, 
                 double &mTheta, double &mLength)
{
    double step_size = 0.01;
    double length_MAX, angle_THETA, seg_A, seg_B;
    
    //Initialize theta to step size
    angle_THETA = step_size;
    
    //Determine initial lengths of pipe segments
    seg_A = wHallway1 / (sin(angle_THETA));
    seg_B = wHallway2 / (cos(angle_THETA));
    mLength = seg_A + seg_B;
    
    while(angle_THETA < (_PI / 2))
    {
        //Determine length of pipe segments
        seg_A = wHallway1 / (sin(angle_THETA));
        seg_B = wHallway2 / (cos(angle_THETA));
        
        //Find total pipe length
        length_MAX = seg_A + seg_B;
        
        //Compare to current maximum to determine which length is smaller
        if(length_MAX < mLength)
        {
            mLength = length_MAX;
            mTheta = angle_THETA;
        }
        //Increment angle_THETA by stepsize
        angle_THETA += step_size;
    }
    //Convert theta from radians to degrees
    mTheta = mTheta * 180.0 / _PI;
}

