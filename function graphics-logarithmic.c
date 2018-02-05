#include<stdio.h>
#include<math.h>
#include<graphics.h>

void delay(int x)                          //延时函数
{
	int k;
	for(k=0;k<=x;k++)
	{
	}
}

main()
{
	int m,driver=DETECT,mode,x00,y00,x11,y11,c;
	float a,y1,y2,k;
	initgraph(&driver,&mode,"");                //初始化图形系统函数
	cleardevice();
	printf("Input a:");                    
	scanf("%f",&a);                 //输入底数a
	x00=100,y00=60,x11=x00+512,y11=y00+128;              
	rectangle(x00,y00,x11,y11);                 //绘制矩形框
	m=(y00+y11)/2;
	line(x00,m,x11,m);                      //绘制与矩形框相交的线段
	for(k=0.00000000000001;k<=511;k=k+0.1)                 //绘制曲线（利用微分思想）
	{
		y1=log10(k)/log10(a);
		y2=log10(k+1)/log10(a);
		line(k+100,m-y1,k+1+100,m-y2);
		delay(250);
	}
	getch();
	closegraph();                      //关闭图形模式函数
}
