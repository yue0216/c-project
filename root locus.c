#include <graphics.h>
#include <math.h>
#include <dos.h>
void dotk(int x,int y,int n)//��עk����ӳ���//
{
	char q[20];
	sprintf(q,"k=%d",n);
	setcolor(62);
	outtextxy(x+5,y-10,q);
	circle(x,y,1);
	circle(x,y,2);
}
void xy()//������ϵ���Ӻ���//
{
  int i;
  int q[5];
  double v;
  line (380,60,380,420);
   line(140,240,500,240);
	for (i=1;i<6;i++)
	{
		line(380,60*(i+1),385,60*(i+1));
		v=3-i;
		gcvt(v,3,q);
		if(v)
		outtextxy(390,60*(i+1)+5,q);
	}
	for (i=1;i<6;i++)
	{
		line(140+60*i,240,140+60*i,235);
		v=i-4;
		gcvt(v,3,q);
		if(v)
		outtextxy(140+60*i,245,q);
	}
	line(375,65,380,60);
	line(380,60,385,65);
	line(495,235,500,240);
	line(495,245,500,240);

}
void myline(float x1,float y1,float x2,float y2)//��ֱ������ϵ����ת��Ϊ��Ļ���겢����//
{
	x1=380+x1*60;//ת��//
	x2=380+x2*60;
	y1=240+y1*60;
	y2=240+y2*60;
	line(x1,y1,x2,y2);//����//
}
main()
{
	int driver=DETECT,mode;
	int i = 0;
	float k,x11=-2.0,x12,x21=0.0,x22,y11=0,y12,y21=0,y22;
   initgraph(&driver,&mode,"c:\\tc20\\bgi");
	xy();
	dotk(380,240,0);//��עk��//
	dotk(260,240,0);
	for(k=0;k<=1;k=k+0.01)//�켣��ʵ������//
	{
			x12=-sqrt(1-k)-1;
			x22=sqrt(1-k)-1;
			setcolor(2);
			myline(x11,0,x12,0);
			setcolor(1);
			myline(x21,0,x22,0);
			x11=x12;
			x21=x22;
			delay(30);
	}
	dotk(320,240,1);
	for(k=1;k<=5;k=k+0.01)//�켣���������//
		{
			y12=-sqrt(k-1);
			y22=sqrt(k-1);
			setcolor(2);
			myline(-1,y11,-1,y12);
			setcolor(1);
			myline(-1,y21,-1,y22);
			y11=y12;
			y21=y22;
			delay(30);
			
			
			
		}	
	dotk(320,180,2);//��k����б�ע//
	dotk(320,300,2);
	delay(30);
	dotk(320,120,5);
	dotk(320,360,5);

   getch();
   closegraph();
}
