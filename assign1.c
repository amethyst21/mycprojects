


#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){

printf("%s\n", "#include<stdio.h>");
printf("%s\n", "#define PI 3.141593");
printf("\n");
printf("%s\n", "int main()");
printf("%s\n", "{");
printf("%s %d%s\n", "int degrees =", 0, ";");
printf("%s\n", " double radians;");
printf("\n");
printf("%s\n", "printf(\"Degrees to Redians \\n\");");
printf("\n");
//print initial conditions
printf("%s %d%s\n", "int degrees =", 0, ";");
printf("%s %d%s\n", "radians = degrees*PI/", 180, ";");
printf("%s\n", "printf(\"%6i%9.6f\\n\",degrees,radians);");
printf("\n");
//for loop of the program converts degrees to radians

int i;
for( i =10; i<=361; i+=10)
{
  printf("%s %d%s\n","int degrees=",i,";");
  printf("%s\n","radians = degrees*PI/180);");
  printf("%s\n", "printf(\"%6i%9.6f\\n\",degrees,radians);");	
  printf("\n");
}
return 0;
}
