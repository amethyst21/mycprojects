//Name:Grecia Gonzalez
// This program has a factorial methods that calculates factorial
//Then is has a exponent method that computes sum of the firsgt n terms od e to th//e x power. Then main method prints the tables and calls the sub methods,
//I used 'gcc -o assign3 assign3.c -lm -std=c99' to compile
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
/*
* input: integer n>=0
* output: n! as a double
*/
double factorial(int n)
{
    //set initial resultF value to 1
    double resultF = 1;
    while (n>1)
    {
        //finds the factoral and decrements n
        resultF = resultF * n;
        n--;
    }
    //returns the result of the factoral
    return resultF;

}

/*
* input: double x and integer n>=0
* output: return approximation of e^x as a double
*         quality of approximation increases with n
*/
double exponent(double x, int n)
{
    int i;
  
    //sets the intital value of the result to 1
    double resultE = 1;
  
    //so long as n>0, the function will continue to approximate
    while (n>0)
    {
        resultE = pow(x, n)/factorial(n) + resultE;
        n--;
    }
    return resultE;
}

int main(int argc, char*argv[])	
{
	if(argc != 3)
	{
	printf("Invalid number of arguments.\n");
	return 0;
	}
	int n = atoi(argv[1]);
	double x = atof(argv[2]);
	printf("\ti\t\tApproximation\n");
	printf("--------------------------------------------\n");
	for(int i = 0; i <= n; i++)
	printf("\t%4d\t\t%.10f\n", i, exponent(x, i));
	printf("Exact value = %f\n", exp(x));
}
  
