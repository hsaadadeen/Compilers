#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define oper(x) (x=='+' || x=='-' || x=='*' || x=='/')

char in[30], post[30], stack[30];
int top=-1;

void push(char x)
{
	stack[++top]=x;
}

char pop()
{
	return stack[top--];
}

int precedence(char c)
{
	if (c=='+' || c=='-')
		return 1;
	if (c=='*' || c=='/')
		return 2;
	if (c=='(')
		return 3;
}

void main()
{
	char c;
	int l,i,j=0,st1[20],k,h,f,eval,s,N;
	printf("Enter the infix exp<b></b>ression : ");
	scanf("%s",&in);
	l=strlen(in);
	for(i=0;i<=l;i++)
	{	
		if(oper(in[i]))
		{	
			post[j++]=' ';
			while(precedence(in[i])<precedence(stack[top])) //any problem here?
			{
				post[j++]=stack[top];
				pop();
				post[j++]=' ';

			}
			push(in[i]);
		}
		else if(in[i]=='\0')
		{
			while(top!=-1)
			{
				post[j++]=' ';
				post[j++]=stack[top];
				pop();
			}
		}
		else
			post[j++]=in[i];
	}
	post[j]='\0';
	printf("\n\tPostfix Expression : %s\n",post);
	printf("\t***************************\n\n");
	i=0;top=-1;f=0;k=0;
	while(i<=j)
	{
		if(oper(post[i]))
		{	
			f=1;
			c=post[i];
			eval=0;
			switch(c)
			{
			case '+':
				eval=st1[top-1]+st1[top];
				break;		
			case '-':
				eval=st1[top-1]-st1[top];
				break;
			case '*':
				eval=st1[top-1]*st1[top];
				break;
			case '/':
				eval=st1[top-1]/st1[top];
				break;
			}
			top--;
			st1[top]=eval;	
		}
		else if(post[i]==' ')
		{
			if(f==0)
			{
				h=i-k;
				s=0;
				while(post[h]!=' ')
				{
					N=(int)post[h];
					N=N-48;
					//s=s+N*(pow(10,(k-1)));
					k--;
					h++;
				}
				st1[++top]=s;
			}
			k=0;
		}
		else 
		{
			k++;
			f=0;
		}
		i++;	
	}
	printf("\n\t%c Value : %d\n",272, st1[top]);
	getch();
}