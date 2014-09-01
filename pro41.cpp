#include<stdio.h>
#include<iostream>
using namespace std;

int calc(int);
int eval(int);

char s[500];

int main()
{
	scanf("%s",s);
	int fin;
	
	fin =eval(0);
	
	cout<<fin<<endl;
	return 0;
}

int eval(int i)
{	int v1,v2,count=0;
	char exp;
	if(s[i]=='(')
	{
		i++;
		if(s[i]=='(')
		{
			v1=eval(i);
			i++;
			count=0;
			while(count>=0)
			{
				if(s[i]=='(')
					count++;
				if(s[i]==')')
					count--;
				i++;
			}
		}
		else
		{
			v1 = calc(i);
		}
		while((( int)s[i] > 47 && (int)s[i]<59))
			i++;

		exp=s[i];
		i++;
		if(s[i]=='(')
		{
			
			v2=eval(i);
                        count=0;
                        i++;
			while(count>=0)
                        {
                                if(s[i]=='(')
                                        count++;
                                if(s[i]==')')
                                        count--;
                        	i++;
			}

		}
		else
		{
			v2=calc(i);
		}
	switch(exp)
	{
		case '+': return v1+v2;
				break;
		case '*': return v1*v2;
				break;
		case '/': return v1/v2;
				break;
		case '-': return v1-v2;
				break;
		default: return 0;
				break;
	}
	}
	return 0;
}
int calc(int i)
{
	int ret=0;
	while((int)s[i]>47&&(int)s[i]<59)
	{
		ret = ret*10;
		ret = ret + (((int )s[i])-48);
		i++;
	}
	return ret;
}
