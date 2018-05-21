#include<windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL\glut.h>
#define SORT_NO 4

int SPEED=500;

int MAX=10;
char tt[100];
char times;
int a[1000];
int swapflag=0;
int i=0,j=0;
double t=0,time_taken=0;
int flag=0;
int dirflag=0;
int count=1;
int k=0;
int sorting=0;
char *sort_string[]={"B U B B L E  S O R T","S E L E C T I O N  S O R T","I N S E R T I O N  S O R T","R I P P L E  S O R T"};
int sort_count=0;

void print_text(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}
int notsorted(){
	int q;
	for(q=0;q<MAX-1;q++)
	{
		if(a[q]>a[q+1])
			return 1;
	}
	return 0;
}

void insertionsort()
{
	int temp;

	while(i<MAX)
	{
		if(flag==0){j=i; flag=1;}
		while(j<MAX-1)
		{
			if(a[j]>a[j+1])
			{
				swapflag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

				goto A;
			}
			j++;
			if(j==MAX-1){flag=0;}
			printf("swap %d and %d\n",a[j],a[j+1]);
		}
		i++;
	}
	sorting=0;
	A:
	i=j=0;
}


void selectionsort()
{
	int temp,j,min,pos;

	while(notsorted())
	{

		while(i<MAX-1)
		{
			min=a[i+1];
			pos=i+1;
			if(i!=MAX-1)
			{
				for(j=i+2;j<MAX;j++)
				{
					if(min>a[j])
					{
						min=a[j];
						pos=j;
					}
				}
			}
			printf("\ni=%d min=%d at %d",i,min,pos);
			printf("\nchecking %d and %d",min,a[i]);
			if(min<a[i])
			{

				//j=pos;
				printf("\nswapping %d and %d",min,a[i]);
				temp=a[pos];
				a[pos]=a[i];
				a[i]=temp;
				goto A;
			}
			i++;
		}
	}
	sorting=0;
	i=j=0;
	A:  printf("");
}


void bubblesort()
{
	int temp;
	while(notsorted())
	{

		while(j<MAX-1)
		{
			if(a[j]>a[j+1])
			{
				swapflag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

				goto A;
			}
			j++;
			if(j==MAX-1) j=0;
			printf("swap %d and %d\n",a[j],a[j+1]);
		}
	}
	printf("fun() took %f seconds to execute \n", time_taken);
    glColor3f(1,1,1);
    print_text(500,500,tt,GLUT_BITMAP_TIMES_ROMAN_24);

	sorting=0;
	A: printf("");
}

void ripplesort()
{
	int temp;
	while(notsorted() && sorting)
	{
		if(dirflag==0)
		{
			while(j<MAX-1)
			{
				if(a[j]>a[j+1])
				{
					swapflag=1;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;

					goto A;
				}
				j++;
				if(j==MAX-1) {count++; j=MAX-count;	dirflag=1-dirflag;}
				printf("j=%d forward swap %d and %d\n",j,a[j],a[j+1]);
			}
		}
		else
		{
			while(j>=0)
			{
				if(a[j]>a[j+1])
				{
					swapflag=1;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;

					goto A;
				}
				j--;
				if(j==0){ dirflag=1-dirflag;}
				printf("j=%d backward swap %d and %d\n",j,a[j],a[j+1]);
			}
		}
	}
	sorting=0;
	A: printf("");
}
