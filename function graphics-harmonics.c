#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <dos.h>
main()
{
	FILE *p,*q,*e,*r;
	int driver=DETECT,mode,x00,x11,y00,y11,m,i,xstep,ystep,k,a00,a11,b00,b11,n00,n11,m11,m00,s11,s00,d11,d00;
	int data1[256],data2[256],data3[256],data4[256],x1,x2,a1=80,a2,n1=80,n2,s1=80,s2;
	float h;
	char stt[10];
	double value;
	printf("Please input amplitude :");
	scanf("%f",&h);
	initgraph(&driver,&mode,"c:\\tc");
	for(k=0;k<255;k++)
	 data1[k]=h*sin(2.0*3.1415926/128.0*k);
	x00=80,y00=80,x11=x00+512,y11=y00+3*h;
		rectangle(x00,y00,x11,y11);
	m=(y00+y11)/2;
        line(x00,m,x11,m);
	x1=x00;
        for(k=0;k<254;k++){
	  x2=x1+2;
	  setcolor(4);
		  line(x1,m-data1[k],x2,m-data1[k+1]);
	  delay(20);
          x1=x2;}
        for(k=0;k<255;k++)
	 data2[k]=0.5*h*sin(2.0*3.1415926/64.0*k);
	a00=800,b00=80,a11=a00+512,b11=b00+h*2;
	for(k=0;k<254;k++){
	  a2=a1+2;
	  setcolor(2);
		  line(a1,m-data2[k],a2,m-data2[k+1]);
	  delay(20);
          a1=a2;}
        for(k=0;k<255;k++)
	 data3[k]=0.25*h*sin(2.0*3.1415926/32.0*k);
	n00=80,m00=80,n11=n00+512,m11=m00+h*2;
	for(k=0;k<254;k++){
	  n2=n1+2;
	  setcolor(62);
		  line(n1,m-data3[k],n2,m-data3[k+1]);
	  delay(20);
		  n1=n2;}
	 for(k=0;k<255;k++)
	 data4[k]=0.25*h*sin(2.0*3.1415926/32.0*k)+0.5*h*sin(2.0*3.1415926/64.0*k)+h*sin(2.0*3.1415926/128.0*k);
	 s00=80,d00=80,s11=s00+512,d11=d00+h*2;
	 for(k=0;k<254;k++){
	 s2=s1+2;
	 setcolor(5);
		line(s1,m-data4[k],s2,m-data4[k+1]);
		delay(20);
		s1=s2;}
	p=fopen("Data1.txt","w+");
	for(i=0;i<255;i++)
	fprintf(p,"%d",data1[i]);
	q=fopen("Data2.txt","w+");
	for(i=0;i<255;i++)
	fprintf(q,"%d",data2[i]);
	e=fopen("Data3.txt","w+");
	for(i=0;i<255;i++)
	fprintf(e,"%d",data3[i]);
	r=fopen("Data4.txt","w+");
	for(i=0;i<255;i++)
	fprintf(r,"%d",data4[i]);
	  getch();
	closegraph();
}
