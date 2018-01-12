#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double PvCal(double FV,double c,double ytm, double d, double T)
{
    //Define initial value of a Bond
    double BV=0.;
    //add in coupon payments
    double TN = T + d;
    double cpn=(c) * FV;
        for(double i = d;i <= TN; i++)
        {
            BV = BV + cpn * pow((1 + ytm),-i);
        }
    //add the PV of face value of a bond
        BV = BV + FV * pow((1 + ytm),- TN);
    return BV;
}

double CalYTM(double FV, double c, double PV, double T, double d, double a, double b){
    // a is the minimum YTM value assumed & b is the maximum YTM value assumed

    const int MaxIter = 5000;
    double Tol=0.0000001; // Assumed tolerance level
    double midPt=0.0, midDiff;

    double lowDiff = PV - PvCal(FV, c, a, d, T);
    double highDiff = PV - PvCal(FV, c, b, d, T);

        if (lowDiff*highDiff > 0)
            return -1;
        else
            for (int i=0; i<=MaxIter; i++)
            {
            midPt = (a+b)/2.0;
            midDiff=PV-PvCal(FV,c,midPt,d,T);
                if(abs(midDiff)<Tol) goto LastLine;
                else
                {
                if (midDiff>0) b = midPt;
                else a= midPt;
                }

            }
    LastLine:

    return midPt;
}

