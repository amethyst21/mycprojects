//Name: Grecia Gonzalez
//Summary: Write a program to find the largest palindrome in a string. A palindrome is a
//sequence that reads the same backward as forward. r
#include<stdio.h>
#include<string.h>

//This function takes a string str and two points i and j and determines whether the stringfrom i to j is a palindrome. If it is a palindrome, it returns the length of //the palindrome and if it is not a palindrome, it returns -1.

int palindromeLength(char *str, int i, int j){
int flag = 0,len = 0;
while(i < j){
if(str[i] == str[j]){
i++;
j--;
len += 2;;
}else{
flag = 1;
break;
}
}
if(flag == 1){
return -1;
}
if(i == j){
len++;
}

return len;
}

//The main method pompts user to enter string and calls function palindromeLengthWrite
int main(){
char str[500];
int maxLength = 0,maxStart,maxEnd;
int i,j,length;

printf("Enter a string : ");
scanf("%s",str);
int len = strlen(str);
for(i=0; i<len; i++){
for(j = len-1; j>i; j--){
length = palindromeLength(str, i, j);
if(length > maxLength){
maxLength = length;
maxStart = i;
maxEnd = j;
}
}
}

printf("Largest palindrome is ");
for(i = maxStart; i<= maxEnd; i++){
printf("%c", str[i]);
}
printf("\n");

return 0;
}
