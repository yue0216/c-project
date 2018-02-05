#include <graphics.h>
#include <math.h>
#include <dos.h>
int main()
{
	int i,a[10]={0},s[10]={0},c[10]={0},m=1;
    int driver=DETECT,mode,x00,x11,y00,y11,xstep,ystep,k;
    int x1,x2;
    char stt[11],x;
    double value;
    initgraph(&driver,&mode," ");
    x00=100,y00=100,x11=x00+400,y11=y00+300;

    xstep=(x11-x00)/10;
    ystep=(y11-y00)/30;

	rectangle(x00,y00,x11,y11);
	setcolor(62);
	line(100,250,500,250);
	printf("please input 10 data:");
	for(i=0;i<10;i++)
	{
	  scanf("%d%*c",&a[i]);
	  s[i]=a[i];
	}
	  for(i=2;i<10;i++)
	  {
	   c[i]=a[i-1]+(a[i-1]-a[i-2]);
	   if(fabs(c[i]-a[i])>m)
		   {
			a[i]=c[i];
		   }
	  }
   printf("xiuzheng hou:");
   setcolor(63);
  for(k=0;k<=10;k++)
  {
    line(x00+xstep*k,y11,x00+xstep*k,y11+5);
	 value=xstep*k/40+1;
     gcvt(value,3,stt);
	 outtextxy(x00+xstep*k-5,y11+8,stt);
   }
    for(k=0;k<=30;k++)
  {
    line(x00-5,y11-ystep*k,x00,y11-ystep*k);
   }

   for(i=0;i<10;i++)
   {
       printf(" %d",a[i]);
   }
   printf("\n");
   printf("Green is xiuzheng qian.\n");
   printf("Red is xiuzheng hou.");
    x1=x00;
    setcolor(4);
    for(i=0;i<10;i++)
    {
      x2=x1+40;
	  line(x1,250-a[i]*10,x2,250-a[i+1]*10);
      x1=x2;
	}
	x1=x00;
	setcolor(2);
	for(i=0;i<10;i++)
	{
	  x2=x1+40;
	  line(x1,250-s[i]*10,x2,250-s[i+1]*10);
	  x1=x2;
	}
   getch();
   closegraph();
   return 0;
}

