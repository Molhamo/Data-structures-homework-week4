#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//List used for questions 1 and 2
typedef struct number{
    int data;
    struct number *next;
}node;

//List used for questions 3 onward
typedef struct student{
    char *name;
    int age;
    int snumber;
    struct student *next;
}student;

//question 1 function
void addnode(node **head, int input){
    if(*head==NULL){ 
        *head=(node*)malloc(sizeof(node));
        (*head)->data=input;
        (*head)->next=NULL;
    }
    else if(input%2==0){
        node *n=(*head);
        while(n->next!=NULL)
            n=n->next;
        node* temp=(node*)malloc(sizeof(node));
        temp->data=input;
        n->next=temp;
        temp->next=NULL;
    }
    else{
        node* temp=(node*)malloc(sizeof(node));
        temp->data=input;
        temp->next=(*head);
        (*head)=temp;
    }
}

//question 2 function
void printorder(node **head){
    int count, input;
    srand(time(0));
    for(count=0;count<100;count++){
        input=(rand()%200)+1;
        if(*head==NULL){ 
            *head=(node*)malloc(sizeof(node));
            (*head)->data=input;
            (*head)->next=NULL;
        }
        else if((*head)->data<input){
            node *n=*head;
            while(n->next!=NULL){
                if(n->next->data<input)
                    n=n->next;
                else
                    break;
            }
            node *temp=(node*)malloc(sizeof(node));
            temp->data=input;
            temp->next=n->next;
            n->next=temp;
        }
        else{
            node* temp=(node*)malloc(sizeof(node));
            temp->data=input;
            temp->next=(*head);
            (*head)=temp;
        }
    }
    node *n=(*head);
    while(n!=NULL){
        printf("%d  ",n->data);
        n=n->next;
    }
}

//Question 3 function
void studentdata(student *start){
    if(start==NULL)
        printf("There is no student data being stored");
    else{
        int count=1;
        while(1){
            printf("%d- %s %d %d\n",count, start->name, start->age, start->snumber);
            count++;
            if(start->next==NULL)
                break;
            else
                start=start->next;
        }
    }
}

//Question 4 function
void findstudent(student *start){
    if(start==NULL)
        printf("There is no student data being stored\n");
    else{
        char find[30];
        printf("Enter the student's name (case sensitive) you want to find:\n");
        scanf("%s",&find);
        while(1){
            if(strcmp(find, start->name)==0){
                printf("Student found! %s age:%d no.:%d\n",start->name, start->age, start->snumber);
                break;
            }
            else if(start->next!=NULL)
                start=start->next;
            else{
                printf("student not found\n");
                break;
            }
        }
    }
}

//Question 5 function
void deletenext(student *start){
    if(start==NULL)
        printf("There is no student data being stored\n");
    else{
        char del[30];
        printf("Enter the student's name:\n");
        scanf("%s",&del);
        while(1){
            if(strcmp(del, start->name)==0){
                if(start->next==NULL){
                    printf("There is no data to delete\n");
                    break;
                }
                else{
                    student *temp=(student*)malloc(sizeof(student));
                    temp=start->next;
                    start->next=temp->next;
                    free(temp);
                    break;
                }
            }
            else if(start->next!=NULL)
                start=start->next;
            else{
                printf("student not found\n");
                break;
            }
        }
    }
}

//Question 6 function
void printlongest(student *start){
    student *longest=start;
    while(start->next!=NULL){
        if(strlen(longest->name)<strlen(start->next->name))
            longest=start->next;
        start=start->next;
    }
    printf("The longest student's name is %s\nLength: %d", longest->name, strlen(longest->name));
}

//function to add students
void addstudent(student **start, char *name, int age, int snumber){
    if((*start==NULL)){
        *start=(student*)malloc(sizeof(student));
        (*start)->name=name;
        (*start)->age=age;
        (*start)->snumber=snumber;
        (*start)->next=NULL;
    }
    else{
        student *n=(*start);
        student *temp=(student*)malloc(sizeof(student));
        while(n->next!=NULL)
            n=n->next;
        temp->name=name;
        temp->age=age;
        temp->snumber=snumber;
        n->next=temp;
        temp->next=NULL;
    }
}

//function to print numbers
void printall(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

void main(){
    int question;
    node* head=NULL;
    student* start=NULL;
    addstudent(&start, "Molham", 20, 576);
    addstudent(&start, "Ali", 21, 782);
    addstudent(&start, "Abdulrahman", 25, 304);
    addstudent(&start, "Cemal", 19, 981);
    printf("Enter the question number whose function you want to run:\n");
    scanf("%d",&question);
    switch(question){
        case 1:
            int input;
            printf("Enter numbers to add to the list, input -1 to end:\n");
            scanf("%d",&input);
            while(input!=-1){
                addnode(&head, input);
                scanf("%d",&input);
            }
            break;
        case 2:
            printorder(&head);
            break;
        case 3:
            studentdata(start);
            break;
        case 4:
            findstudent(start);
            break;
        case 5:
            deletenext(start);
            break;
        case 6:
            printlongest(start);
            break;
    }
}