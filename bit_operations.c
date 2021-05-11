#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 char carryadd=0;
 char carrysub=0;
 char carrymult=0;
void strrev(char c[])
{
	int l=strlen(c);
	int i=0;
	int t;
	while(i<l/2)
	{
		t=c[i];
		c[i]=c[l-i-1];
		c[l-i-1]=t;
		i++;
	}
}
void strcpy1(char c[],char d[])
{
	int i=0;
	while(d[i]!='\0')
	{
		c[i]=d[i];
		d[i]=0;
		i++;
	}
	c[i]='\0';
}
int stringcmp(char a[],char b[])
{
    int retval=2;
    int i=0,j=0;
    if(strlen(a)>strlen(b))
        retval=1;
    else if(strlen(a)<strlen(b))
        retval=0;
    else
    {
        while(a[i]!='\0')
        {
            if(a[i]>b[i])
            {
                retval=1;
                i=strlen(a);
            }
            else if(a[i]<b[i])
            {
                retval=0;
                i=strlen(a);
            }
            else
                i++;
        }
    }
    return retval;

}
void add(char a,char b,char c[],int count)
{
    char sum=(a-'0')+(b-'0')+carryadd;
    carryadd=sum/10;
    sum=sum%10;
    c[count]=sum+'0';

}
void Addition(char a[],char b[],char c[])
{
	int i=0,j=0;
            while((a[i]!='\0')&&(b[j]!='\0'))
            {
                    add(a[i],b[j],c,i);
                    i++;
                    j++;
            }
            if((a[i]=='\0')&&(b[i]=='\0'))
            {
                if(carryadd==1)
                {
                   c[i]=carryadd+'0';
                   i++;
                }
            }
            while(a[i]!='\0')
            {
                add(a[i],(carryadd+'0'),c,i);
                i++;
            }
            while(b[j]!='\0')
            {
                add(b[j],(carryadd+'0'),c,j);
                j++;
            }
	    if(i>j)
            	c[i]='\0';
	    else 
		c[j]='\0';
}
void initialize(char c[],int l1,int l2)
{
    int i=0;
    while(i<(l1+l2))
    {
        c[i]='0';
        i++;
    }
    c[i]='\0';
}
void multiply(char a[],char b[],char c[])
{
    
    int l1=strlen(a);
    int l2=strlen(b);
    initialize(c,l1,l2);
    char mult;
	char temp[309],result[309];
    char carry=0;
    int multindex=0;
    int i=0;int j=0;
    while(a[i]!='\0')
    {
        multindex=i;
        j=0;
        carry=0;
	carrymult=0;
	initialize(temp,l1,l2);
        while(b[j]!='\0')
        {
            mult=(a[i]-'0')*(b[j]-'0')+carrymult;

            carrymult=mult/10;

            mult=mult%10;
            temp[multindex]=mult+'0';
		multindex++;
	     j++;
	}
	if(carrymult!=0)
	{
		temp[multindex]=carrymult+'0';
		multindex++;
	}
        Addition(temp,c,c);
        i++;
    }
	
	strrev(c);
	printf("%s\n",c);
}

void subtract(char a,char b,char c[],int count)
{
    char sub;
    if((a-'0')>=(b-'0'))
    {
        sub=(a-'0')-(b-'0')-carrysub;
        carrysub=0;
    }
    else
    {
        sub=(a-'0')-(b-'0')+10-carrysub;
        carrysub=1;
    }
    c[count]=sub+'0';
}
int main()
{
    char a[309],b[309],c[309];
    int choice;
    scanf("%s",a);

    scanf("%s",b);
    int i=0,j=0;
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
	    strrev(a);
            strrev(b);
            Addition(a,b,c);
	    strrev(c);
	    printf("%s",c);

        }
        break;
        case 2:
        {
            if(stringcmp(a,b)==1)
            {
                 strrev(a);
                 strrev(b);
                 while((a[i]!='\0')&&(b[j]!='\0'))
                 {
                     subtract(a[i],b[j],c,i);
                     i++;
                     j++;
                 }
                 while(a[i]!='\0')
                {
                    subtract(a[i],'0',c,i);
                    i++;
                }
                while(b[j]!='\0')
                {
                    subtract(b[j],'0',c,j);
                    j++;
                }
		c[i]='\0';
            	strrev(c);
            	printf("%s",c);
            }
            else if(stringcmp(a,b)==0)
            {
                 strrev(a);
                 strrev(b);
                 while((a[i]!='\0')&&(b[j]!='\0'))
                 {
                     subtract(b[j],a[i],c,i);
                     i++;
                     j++;
                 }
                 while(a[i]!='\0')
                 {
                    subtract(a[i],'0',c,i);
                    i++;
                 }
                while(b[j]!='\0')
                {
                    subtract(b[j],'0',c,j);
                    j++;
                }
		c[j]='-';
		j++;
		c[j]='\0';
            	strrev(c);
            	printf("%s",c);
            }
	    else
	    {
		printf("0");
	    }

        }
        break;
        case 3:
        {
            strrev(a);
            strrev(b);
            multiply(a,b,c);
        }
        break;
    }
    return 0;
}
