#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#define G 9.8
main()
{
	int driver=DETECT,mode,x00,x11,y00,y11;
	int v,co,k,bc,i=0;
	float x[500],y[500],xz[500],yz[500];
	float t,tmax,a,b;
	printf("Please input Ox , Oy(100,300 is advised):\n");
	scanf("%d,%d",&x00,&y00);
	printf("Please input v,jiaodu:");
	scanf("%d,%f",&v,&b);
        a=(float)b*3.14159/180; 
	printf( "Please input your favourite  line colour:\n" );
	printf("0-black 	1-blue\n");
	printf("2-green 	3-indigo\n");
	printf("4-red 		5-magenta\n");
	printf("20-brown 	7-light grey\n");
	printf("56-dark grey 	57-light blue\n");
	printf("58-light green 	59-light indigo\n");
	printf("60-light red 	61-light magenta\n");
  	printf("62-yellow 	63-white\n");
	scanf("%d",&co);
        printf( "Please input your favourite  background colour:\n" );
        printf("0-black 	1-blue\n");
	printf("2-green 	3-indigo\n");
	printf("4-red 		5-magenta\n");
	printf("6-brown 	7-light grey\n");
        printf("8-dark grey 	9-light blue\n");
	printf("10-light green 	11-light indigo\n");
	printf("12-light red 	13-light magenta\n");
  	printf("14-yellow 	15-white\n");
        scanf("%d",&bc);
        do
       {
        printf("The line color is same with the background!\n");
        scanf("%d",&bc);
	}while(bc == co);
	initgraph(&driver,&mode,"c:\\tc ");
        setbkcolor(bc);
	x11=x00+500,y11=y00-250;
        do
        {
          i++;
        }while(i == bc);
        setcolor(i);
	line(x00,y00,x11,y00);
	line(x00,y00,x00,y11);
	line(x00-2,y11,x00+2,y11);
	line(x00-2,y11,x00,y11-6);
	line(x00+2,y11,x00,y11-6);
	line(x11,y00-2,x11,y00+2);
	line(x11,y00-2,x11+6,y00);
	line(x11,y00+2,x11+6,y00);
	for(k=0,t=0;k<500;k++,t+=0.1)
	{
		x[k]=v*cos(a)*t;
		y[k]=v*sin(a)*t-0.5*G*t*t;
		xz[k]=x[k]+x00;
		yz[k]=y00-y[k];
		}
	setcolor(co);
	tmax=2*v*sin(a)/G;
	for(k=0,t=0;t<tmax;k++,t+=0.1)
	{
		line(xz[k],yz[k],xz[k+1],yz[k+1]);
		if(y[k]>0 && y[k+1]<0)
			break;
		delay(100);
	}
	getch( );
	closegraph( );
}
