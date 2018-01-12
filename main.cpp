#include <cmath>
#include <iostream>
#include <iomanip>
#include "yieldtomaturity.h"

using namespace std;

int main()
{
    double FV, c, PV, T, d;
    // Call for inputs from the user
    cout << "Please provide coupon percentage rate of interest: "; cin >> c;
    cout << "Please provide face value of the bond: "; cin >>  FV;
    cout << "Please provide today's price of the bond: "; cin >>  PV;
    cout << "Please provide number of years remaining until maturity: "; cin >>  T;
    cout << "Please provide year fraction until next coupon payment: "; cin >>  d;
    c = c/100;
    double a = 0.000001;
    double b = 10;
    double YTM = CalYTM(FV, c, PV, T, d, a, b);
    YTM = YTM * 100;
    //Final Output
    cout << "The computed YTM of this bond is: " <<setprecision(3) <<YTM<<" %"<<endl;
}
