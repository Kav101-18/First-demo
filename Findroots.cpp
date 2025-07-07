#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x)
{
    return 10-x*x;
}

double bisection(double a, double b, double tol)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return 0;
    }

    double c; // midpoint
    cout<<setw(10)<<"iteration"<<setw(15)<<"a"<<setw(15)<<"b"<<setw(15)<<"c"<<setw(15)<<"f(c)"<<endl;
    int i = 0;
    while ((b - a) > tol)
        {
            c = (a + b)/2.0;
            cout<<setw(10)<<i<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<setw(10)<<f(c)<<endl;

            if (fabs(f(c)) < tol)
                break;
            else if (f(a)*f(c) < 0)
                b = c;
            else
                a = c;
            i++;
            
        }
    cout<<"\nThe root is: "<<fixed<<setprecision(10)<<c<<endl;
    return c;
}

 int main()
{
    double a, b;
    double tol = 0.01;
    cout<<"enter the interval (a and b): "<<endl;
    cin>>a>>b;
    cout<<"using tolerance: "<<tol<<endl;
    double root = bisection(a, b, tol);
    if (root != -1)
    {
        cout<<"root found: "<<root<<endl;
    }
    return 0;
    
}
