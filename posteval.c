#include<stdio.h>
#include<ctype.h>
#define max 100

int stack[max];
int top=-1;

void push();
int pop();
int posteval( char post[])
{
 int a,b,result,i;
 for(i=0;post[i]!='\0';i++)
 {
  if(isdigit(post[i]))
  {
   push(post[i]-'0');
   }
   else
   {
     a=pop();
     b=pop();
     switch(post[i])
     {
     case '+':
     result=b+a;
     break;
     case '-':
     result=b-a;
     break;
     case '*':
     result=b*a;
     break;
     case '/':
     result=b/a;
     break;
     }
     push(result);
     }
     }
     return pop();
     }
     
     void push(int element)
     {
     if(top>=max-1)
     {
     printf("Stack is overflow");
     return;
     }
     stack[++top]=element;
     }
     
     int pop()
     {
     if(top<0)
     {
     printf("stack is underflow");
     return 0;
     }
     return stack[top--];
     }
     
     int main()
     {
     char post[10];
     int res;
     printf("enter postfix expression: ");
     scanf("%s",post);
     res=posteval(post);
     printf("resut: %d \t",res);
     return 0;
     }
     
     
     
     
     
     
 

