#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL\glut.h>
#include<mmsystem.h>
#include<windows.h>
#include "op.cpp"
#include "time.h"

void print_text2(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}




void int_str(int rad,char r[])
{
	itoa(rad,r,10);
}

void doub_str(double time, char s[])
{
   // double num = 123412341234.123456789;
//char output[50];

snprintf(s, 50, "%f", time);

//printf("%s", output);
}

void second_text()
{
	if (sorting == 0)
	{
        glColor3f(1,1,1);
        print_text(10, 730, "MENU",GLUT_BITMAP_HELVETICA_18);
		print_text(10, 690, "Press s to SORT",GLUT_BITMAP_9_BY_15);
		print_text(10, 670, "Press c to SELECT the sort algorithm",GLUT_BITMAP_9_BY_15);
		print_text(10, 650, "Press r to RANDOMISE",GLUT_BITMAP_9_BY_15);
		print_text(10, 630, "Press i to INCREASE the elements",GLUT_BITMAP_9_BY_15);
		print_text(10, 610, "Press d to DECREASE the elements",GLUT_BITMAP_9_BY_15);
		print_text(10, 590, "Press m to INCREASE the speed",GLUT_BITMAP_9_BY_15);
		print_text(10, 570, "Press l to DECREASE the speed",GLUT_BITMAP_9_BY_15);


		print_text(10, 550, "Press Esc to QUIT",GLUT_BITMAP_9_BY_15);

		print_text2(520, 660, *(sort_string+sort_count),GLUT_BITMAP_HELVETICA_18 );
        glColor3f(1,1,1);
        print_text(150,480,"Actual time taken by the algorithm is : ",GLUT_BITMAP_TIMES_ROMAN_24);
        print_text(500,480,tt,GLUT_BITMAP_TIMES_ROMAN_24);
        print_text(570,480,"sec",GLUT_BITMAP_HELVETICA_12);

	}
	else if (sorting == 1)
    {


		glColor3f(0.5,0.5,0.5);
		print_text(10, 750, "Sorting in progress...",GLUT_BITMAP_9_BY_15);
		print_text(10, 730, "Press p to PAUSE",GLUT_BITMAP_9_BY_15);
		glColor3f(0.0,0.0,0.0);
	}

}

void front_page()
{
	glColor3f(0.0,1.0,0.0);
	print_text(120, 615, "WELCOME",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(120, 605);
		glVertex2f(205, 605);
	glEnd();
	print_text(220, 615, "TO",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(220, 605);
		glVertex2f(245, 605);
	glEnd();

	print_text(260, 615, "VISUALIZATION OF SORTING ALGORITHMS",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(260, 605);
		glVertex2f(550, 605);
	glEnd();
	glColor3f(1.0,1.0,1.0);
    print_text(330, 455, "BY",GLUT_BITMAP_TIMES_ROMAN_24);
    print_text(230, 365, "Manish K                   1BY15CS046",GLUT_BITMAP_TIMES_ROMAN_24);
    print_text(230, 275, "Karthik LN                 1BY15CS038",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,1.0,0.0);
	print_text(530, 025, "Press Enter to continue.......",GLUT_BITMAP_HELVETICA_18);
}

void Initialize() {
	int temp1;
    PlaySound(TEXT("C:\\Users\\This\\Documents\\codeblocks\\TRIAL-2\\starwars.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

	for(temp1=0;temp1<MAX;temp1++){
		a[temp1]=rand()%100+1;

		printf("%d ",a[temp1]);
	}


	i=j=0;
	dirflag=0;
	count=1;
	flag=0;
	time_taken=0;

	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 699,0,799);
}





void display()
{
	int ix,temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if(k==0)
		front_page();
	else{
		second_text();
		char text[10];

		for(ix=0;ix<MAX;ix++)
		{
			glColor3f(0,1,0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(10+(750/(MAX+1))*ix,50);
				glVertex2f(10+(750/(MAX+1))*(ix+1),50);
				glVertex2f(10+(750/(MAX+1))*(ix+1),50+a[ix]*4);
				glVertex2f(10+(750/(MAX+1))*ix,50+a[ix]*4);
			glEnd();

			int_str(a[ix],text);
			//printf("\n%s",text);
			if(MAX<=30)
            {


                glColor3f(1,1,1);
                print_text(45+(750/(MAX+1))*ix, 35, text,GLUT_BITMAP_TIMES_ROMAN_10);
            }
		}


		if(swapflag || sorting==0)
		{
			glColor3f(0,1,0);
			glBegin(GL_POLYGON);
				glVertex2f(10+(750/(MAX+1))*j,50);
				glVertex2f(10+(750/(MAX+1))*(j+1),50);
				glVertex2f(10+(750/(MAX+1))*(j+1),50+a[j]*4);
				glVertex2f(10+(750/(MAX+1))*j,50+a[j]*4);
			glEnd();

			swapflag=0;
		}
	}
	glFlush();
}




void makedelay(int)
{

	if(sorting)
	{
	    t=clock();
		switch(sort_count)
		{
			case 0:	bubblesort();PlaySound(TEXT("C:\\Users\\This\\Documents\\codeblocks\\TRIAL-2\\starwars.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);		break;
			case 1:	selectionsort();	break;
			case 2: insertionsort();	break;
			case 3: ripplesort();		break;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(SPEED/MAX,makedelay,1);
    t=clock()-t;
    if(sorting){
    time_taken  = time_taken+((double)t)/CLOCKS_PER_SEC;
    int ttt=int(time_taken);
    }

    snprintf(tt,10,"%f",time_taken);

    glColor3f(1,1,1);
    //print_text(500,500,tt,GLUT_BITMAP_TIMES_ROMAN_24);
    //print_text(500,500,tt,GLUT_BITMAP_TIMES_ROMAN_24);
    }


void keyboard (unsigned char key, int x, int y)
{
	if(key==13)
		k=1;
	if (k==1 && sorting!=1)
	{
		switch (key)
		{
			case 27	 :	exit (0);
			case 's' :	sorting = 1; break;
			case 'r' :	Initialize(); break;
			case 'c' :	sort_count=(sort_count+1)%SORT_NO;	break;
			case 'i' :  MAX=MAX+10; Initialize();break;
            case 'd' :  MAX=MAX-10; Initialize();break;
            case 'm' :  SPEED=SPEED-500;
                        if(SPEED<=0)
                            {SPEED=100;}break;
            case 'l' :  SPEED=SPEED+500;break;
		}
	}
	if(k==1 && sorting==1)
		if(key=='p')	sorting=0;
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Visualization of Sorting Algorithm");

	Initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutTimerFunc(1000,makedelay,1);

	glutMainLoop();

}
