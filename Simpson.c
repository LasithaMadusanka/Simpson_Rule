#include <stdio.h>
#include <math.h>

double f(double x){
    return sin(x);
}
int main(){
    double a = 0, b = M_PI, sum=0, Simpson_integral, x,h,error,error_1=0, Convergence_Order;
    int i, N ;
    
    for(N =20; N <= 320; N *=2){
        h = (b-a)/N;
        sum = h*(f(a)+f(b))/3.0;
        for( i = 1; i < N; i++)
        {
            x = a + i*h;
            
            if (i%2==0) //need to specify the even case
            {
                sum += 2*f(x);
            }
            else{
                sum += 4*f(x);
            }
            
        }
        Simpson_integral = h* sum /3.0;
        error = fabs(2 - Simpson_integral);//use fabs to get a posotive value and the exact value is 2
        Convergence_Order = log10(error_1/error)/log(2);// log represent by log10() and natural log repsent by log()
        error_1= error;

        printf("\nThe Simpson Integral when N= %d is: %lf and error is %lf with the Convergence Order %lf",N, Simpson_integral,error,Convergence_Order);
    }
//like in the Trapezoidal Rule calculation, I accept an -infinity output to the first Convergence Order since I initialized my error_1=0
}
