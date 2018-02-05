#include <math.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#define pi 3.1415926
#define EMS 1e-6
main()
{  
        double a;
	int driver=DETECT,mode,x00,x11,y00,y11,k;
	double x[400],y[400],x1,x2,t,value,xstep,ystep;
	char stt[10];
        do
        {
	initgraph(&driver,&mode,"c:\\tc ");
        printf("please input a:\nif you want to exit,please input 0\n");
	scanf("%lf",&a);
        if(fabs(a)<EMS)break;
        else
	setbkcolor(15);
	for(k=0;k<400;k++)
	{
	 t=k*pi/100;
	 x[k]=40*(t-sin(t));
	 y[k]=40*(1-cos(t));
	}
	x00=50,y00=200,x11=40*4*pi+x00,y11=y00-2*40;
	setcolor(5);
	line(x00,y00,x11,y00);
	line(x00,y00,x00,y11);
	xstep=(40*4*pi)/8;
	ystep=(y00-y11)/8;
	for(k=0;k<9;k++)
	{
	  line(x00+k*xstep,y00,x00+k*xstep,y00+5);
	  value=xstep*k*a/40;
	  gcvt(value,3,stt);
	  outtextxy(x00+xstep*k-8,y00+8,stt);
	  line(x00,y00-k*ystep,x00+5,y00-k*ystep);
	}

	setcolor(2);
	for(k=0;k<399;k++){
	  x1=x00+x[k];
	  x2=x00+x[k+1];
	  line(x1,y00-y[k],x2,y00-y[k+1]);
	  delay(30);
	  }

	getch();
        closegraph();
     }while(a>EMS);
	
}
