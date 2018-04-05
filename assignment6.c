#include <stdio.h>
#include <stdlib.h>

struct wordfreq

{

int count;

char *word;

};

typedef struct wordfreq wordfreq;

int main(int argc, char *argv[])

{ 
wordfreq **wordarray;

int i;

int temp;
FILE *fp, *fp1;
char c;
char word[100];
for(i = 1; i < argc; i++)
        {
        fp = fopen(argv[i], "r");
        if(fp == NULL)
               {
               fprintf(stderr, "cat: can't open %s\n", argv[i]);
               continue;
               }

 
        do {
      c = fscanf(fp1,"%s",word);
      printf("%s\n",word);
temp=0;
for(i=0;i<wordarray.size();i++)
{if(wordarray[i]->word==word)
{temp=1;
wordarray[i]->count= wordarray[i]->count +1;}}
if(temp==1)
{ wordarray = (wordfreq**)malloc(2*sizeof(wordfreq*));
wordarray.word=word;
wordarray->count=1;
temp=0;}
free(wordarray);
   } while (c != EOF); 

 
        
fclose(fp);
fp1 = fopen("frequencies.txt", "w+");
for(i=0;i<wordarray->size();i++)
{
fprintf(fp,"%d\t%s\n" ,wordarray[i]->count,wordarray[i]->word);
}
fclose(fp1);
return 0;
}
