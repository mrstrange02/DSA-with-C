#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h> 

  

int precedence(char operator)
{
    switch(operator)
     {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
  

char* infixToPostfix(char* infix)
{
    int i,j;
    int len=strlen(infix);
    char stack[100];
    int top=-1;
    char* postfix=(char*)malloc(sizeof(char));
  
    for (i=0,j=0; i<len;i++) 
    {
        if (infix[i]== ' ' || infix[i]== '\t')
            continue;
        
      
        if (isalnum(infix[i]))
         {
            postfix[j++]=infix[i];
        }
        
      
        else if(infix[i]=='(') 
        {
            stack[++top]=infix[i];
        }
        
     
        else if(infix[i]==')') 
        {
            while(top>-1 && stack[top]!='(')
                postfix[j++]=stack[top--];
                  
                   top--;
        }
        
        
        else 
        {
            while (top>-1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
                stack[++top] = infix[i];
        }
    }
  
    
    while (top>-1) 
    {
       if(stack[top]=='(') 
       {
          return "Invalid Expression";
        }
          postfix[j++] = stack[top--];
    }
    postfix[j]='\0';
    return postfix;
}
  
int main()
{
   
    char infix[100];
    printf("enter the expression: a");
    scanf("%s",infix);
    char* postfix=infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}

