//Name: Grecia Gonzalez
// Summary: a program to find the frequency of words in a file. You need to use //dynamic memory allocation for this assignment.
//This program needs to compiled 'gcc -o assign6 assign6.c -ld -std=c99'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct wordfreq
{  
    int count;
    char *word;
}wordfreq;
int main(int argc, char* argv[])
{
    //Use array of pointers to store words and frequencies.
    //Set array size to 1000, and initialize all the pointers to NULL.
    wordfreq wordCounts[1000];
    for(int i = 0; i < 1000; i++)
        wordCounts[i].word = NULL;
    if(argc != 3)
    {
       printf("Invalid number of parameters.\nUsage - assign6 inputFileName outputFileName\n");
       return 0;
    }  
    FILE *fpIn = fopen(argv[1], "r");  
    if(fpIn == NULL)
    {
       printf("Unable to open the input file.\n");
       return 0;
    }
    FILE *fpOut = fopen(argv[2], "w");
    char word[30];
    int count = 0;
    while(!feof(fpIn))
    {
       fscanf(fpIn, "%s", word);
       int found = 0;
       for(int i = 0; i < count; i++)
       {
          if(strcmp(wordCounts[i].word, word) == 0)   //If word is found.
          {
             wordCounts[i].count++;   //Increment the count.
             found = 1;   //Confirm the word is in the list.
             break;   //And come out of the loop.
          }
       }
       if(!found)   //if the word is not found.
       {
          wordCounts[count].word = malloc(strlen(word) * sizeof(char));
          strcpy(wordCounts[count].word, word);   //Copy the word into last position.
          wordCounts[count].count = 1;   //Initialize count to 1.
          count++;   //Increment the counter.
       }   
    }
    fclose(fpIn);
    for(int i = 0; i < count; i++)
    {
       fprintf(fpOut, "%d\t%s\n", wordCounts[i].count, wordCounts[i].word);
       free(wordCounts[i].word);
    }  
    fclose(fpOut);     
}
