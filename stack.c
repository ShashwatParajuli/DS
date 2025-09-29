#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void push(int);
void pop();
void peek();
void display();
int stack[SIZE],top=-1;
void main()
{
    int value,choice;
    while(1){
        printf("***MENU***\n");
        printf("1.Push\n 2.Pop\n 3.Peek\n 4. Display\n 5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted:");
            scanf("%d", &value);
            push(value);
            break;
            case 2:pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 5: exit(0);
            break;
            default: printf("\n Wrong selection!!! Try again!!!");

        }
    }
}
void push(int value){
    if(top == SIZE-1){
    printf("\nSize is Full!!! Insertion is not possible.\nStack overflow.\n");
    }
    else{
        top ++;
        stack[top]=value;
        printf("\nInsertion success!");
    }
}
void pop(){
    if(top ==-1){
        printf("\n Stack is empty, deletion not possible!\n Stack underflow\n");
    }
    else{
        printf("\n Deleted:%d", stack[top]);
        top--;
    }
}
void peek(){
    if (top ==-1){
        printf("Underflow\n");
    }
    else{
        printf("%d\n",stack[top]);
    }
}
void display(){
    if(top ==-1){
        printf("\n Stack is empty");
    }
    else{
        int i;
        printf("\n Stack elements are:\n");
        for(i=top; i>0; i--)
        printf("%d\n", stack[i]);
    }
}

