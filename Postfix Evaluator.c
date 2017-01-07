/*
Evaluation of postfix expression
*/

#include "stdio.h"
#include "math.h"
#include "string.h"

#define SIZE 20

struct stack
{
double s[SIZE];
int top;
}st;

void main()
{
char exp[SIZE];
int len;
double result;
double post(char exp[]);
printf("\n\tEnter the expression: ");
scanf("%s",exp);
exp[strlen(exp)]='$';
result = post(exp);
printf("\n\n\t\t**********************\n\n");
printf("\n\t%c Value of the expression = %f",272, result);
getch();
}

double post(char exp[])
{
char ch,*type;
double result,val,op1,op2;
void push(double);
double pop();
int i;

st.top=0;
i=0;
ch=exp[i];
while(ch!='$')
{
if(ch>='0' && ch<='9')
type="operand";

else if (ch == '+'||ch == '-'||ch == '*'||ch == '/' ||ch =='^')
type="operator";

if( strcmp(type,"operand")==0)
{
val=ch-48;
push(val);
}

else if( strcmp(type,"operator")==0)
{
op2=pop();
op1=pop();

switch(ch)
{
case '+':
result = op1 + op2;
break;
case '-':
result = op1 - op2;
break;
case '*':
result = op1 * op2;
break;
case '/':
result = op1 / op2;
break;
case '^':
result = pow(op1,op2);
break;
}
push(result);
}
i=i+1;
ch=exp[i];
}
result = pop();
return (result);
}

void push(double val)
{
if(st.top+1>=SIZE)
printf("Stack is full");
st.top++;
st.s[st.top]=val;
}

double pop()
{
double val;
if(st.top==-1)
printf("Stack is empty");
val = st.s[st.top];
st.top--;
return (val);
}