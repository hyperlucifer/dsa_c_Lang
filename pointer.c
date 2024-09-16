#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud
{
    int roll_no;
    char name[23];
    char c_name[23];
    int per;
}*ptr;

void accept(){
    ptr=(struct stud*)malloc(sizeof(struct stud));
    char s_name[23];
    char ch_name[23];
    printf("enter the roll no\n");
    scanf("%d",&ptr->roll_no);
    printf("enter the name of a student\n");
    scanf("%s",&s_name);
    strcpy(ptr->name,s_name);
    printf("enter the name of a cource\n");
    scanf("%s",&ch_name);
    strcpy(ptr->c_name,ch_name);
    printf("enter the percentage\n");
    scanf("%d",ptr->per);
}
void display(){
   printf("%d\n",ptr->roll_no);
    printf("%s\n",ptr->name);
    printf("%s\n",ptr->c_name);
    printf("%d\n",ptr->per); 
}
int main(int argc, char const *argv[])
{
    accept();
    printf("asfdasf");
    display();

    return 0;
}
