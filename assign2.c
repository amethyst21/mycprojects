// Name: Grecia Gonzalez
// This program prints out a table of decimal
//numbers and the corresponding roman numeral
#include<stdio.h>
void beforedigit(char num1, char num2);
void afterdigit(char c, int n);

int i=0;
char romanval[1000];
int main()
{
int j,l;
long number;
   //Loop to repeat 1000 numbers
for(l=1;l<=1000;l++)
{
  
   i = 0;
  
       //process to convert each number to roman numerical
           number=l;
          
           if (number <= 0)
           {
           printf("Incorrect number");
           return 0;
           }
               //number is checked many conditons using if else's until the value is not eual to zero
           while (number != 0)
           {
           if (number >= 1000)
           {
           afterdigit('M', number / 1000);
           number = number - (number / 1000) * 1000;
           }
           else if (number >= 500)
           {
           if (number < (500 + 4 * 100))
           {
           afterdigit('D', number / 500);
           number = number - (number / 500) * 500;
           }
           else
           {
           beforedigit('C','M');
           number = number - (1000-100);
           }
           }
           else if (number >= 100)
           {
           if (number < (100 + 3 * 100))
           {
           afterdigit('C', number / 100);
           number = number - (number / 100) * 100;
           }
           else
           {
           beforedigit('L', 'D');
           number = number - (500 - 100);
           }
           }
           else if (number >= 50 )
           {
           if (number < (50 + 4 * 10))
           {
           afterdigit('L', number / 50);
           number = number - (number / 50) * 50;
           }
           else
           {
           beforedigit('X','C');
           number = number - (100-10);
           }
           }
           else if (number >= 10)
           {
           if (number < (10 + 3 * 10))
           {
           afterdigit('X', number / 10);
           number = number - (number / 10) * 10;
           }
           else
           {
           beforedigit('X','L');
           number = number - (50 - 10);
           }
           }
           else if (number >= 5)
           {
           if (number < (5 + 4 * 1))
           {
           afterdigit('V', number / 5);
           number = number - (number / 5) * 5;
           }
           else
           {
           beforedigit('I', 'X');
           number = number - (10 - 1);
           }
           }
           else if (number >= 1)
           {
           if (number < 4)
           {
           afterdigit('I', number / 1);
           number = number - (number / 1) * 1;
           }
           else
           {
           beforedigit('I', 'V');
           number = number - (5 - 1);
           }
           }
           }
           printf(" %d\t",l);
           for(j = 0; j < i; j++)
           printf("%c", romanval[j]);
           printf("\n");
   }
return 0;
}
//This gives the roman values part before digit
void beforedigit(char num1, char num2)
{
romanval[i++] = num1;
romanval[i++] = num2;
}
//This gives roman values part after digit
void afterdigit(char c, int n)
{
int j;
for (j = 0; j < n; j++)
romanval[i++] = c;
}   
