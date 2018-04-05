//Name:Grecia Gonzalez
// Summary this program finds prime numbers up to 1000
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int value;
struct node* next ;
}node;


node* insert_head(node* head, int a);
node* insert_tail(node* head, int a);
node* deletemultiples(node* head,int a);

int main()
{
int i = 1;
node* head = NULL, *temp = NULL;

head = insert_head(head,i++);

while(i<=1000){
head = insert_tail(head, i++);   
}

for(i=2 ;i<=32 ;i++){
head = deletemultiples(head,i);
}

  
temp = head;
i=1;
while(temp!= NULL){

printf("%3d ",temp->value);
temp = temp->next;
  
if(i % 11 == 0)
printf("\n");
  
i++;
}

printf("\n");
return 0;
}


node* insert_head(node* head, int a)
{
node* temp = NULL;

temp = (node*)malloc(sizeof(node));
temp->value = a;
temp->next = NULL;

if(head == NULL){
head = temp;
return temp;
}
else{
temp->next = head;
head = temp;
return head;
}
}


node* insert_tail(node* head, int a)
{
node* temp = NULL, *itr = NULL;

temp = (node*)malloc(sizeof(node));
temp->value = a;
temp->next = NULL;

if(head == NULL){
head = temp;
return head;
}

itr = head;
while(itr->next != NULL){
itr = itr->next;
}

itr->next = temp;

return head;
}

node* deletemultiples(node* head,int a)
{
node* itr = NULL, *prev = NULL;

if(head == NULL)
return NULL;

itr = head;

while(itr != NULL){

if( (itr->value > a) && (itr->value % a == 0) ){

if(itr == head){
prev = head;
head = head->next;
itr = itr->next;
prev->next = NULL;
free(prev);
prev = NULL;
}
else{
prev->next = itr->next;
itr->next = NULL;
free(itr);
itr = prev;
}
}
prev = itr;
itr = itr->next;
}

return head;
}
