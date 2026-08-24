#include <stdio.h>;

#define Max 100; 
int stack[100];
int top = -1;


int push(char ch){
   stack[++top] = ch;
}

int pop(){
    return stack[top--];
}

int priority(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '+' || ch == '-'){
        return 1;
    }

    return 0;
}



int main(){
    int infix[100] , postfix[100];
    printf("Enter Infix");
    scanf("%s",infix);
    infixToPostfix(infix , postfix);
    printf("%s",postfix);
}