#include <graphics.h>
#include <math.h>
#include <dos.h>
char fupin();
char xiangpin();
main()
{ 
char j;
char c;
do {
printf("Please select an option\n ");
printf("\n");
printf("1----------fupintexingtu\n");
printf("\n");
printf("2----------xiangpintexingtu\n");
printf("\n");
printf("q----------fanhui\n");
printf("\n");
printf("any key------exit\n");
printf("\n");
printf("Input:");
j=getch();
if(j=='1')
c = fupin();
else if(j=='2')
c = xiangpin();
else
break;
}while(c == 'q' || c == 'Q');
}

char fupin()
{
  int driver=DETECT,mode,x00,x11,y00,y11,m,xstep,ystep;
  int l,n,i;
  char c;
  char stt[10];
  double data1,data2,value,k,h,a,b,E,x1,x2;
  initgraph(&driver,&mode," ");
  x00=100,y00=150,x11=x00+400,y11=y00+150;
  setcolor(63);
  rectangle(x00,y00,x11,y11);                              /*用于绘制矩形框*/
  xstep=(x11-x00)/40;
  ystep=(y11-y00)/3;
 for(n=0;n<=4;n++)                                          /*用于标横坐标*/
{
  for(i=1;i<=10;i++)
 {
   if(n==4)
   break;
   setcolor(63);
   line(x00+100*(n)+100*log10(i),y11,x00+100*(n)+100*log10(i),y11+5);
   line(x00+100*(n)+100*log10(i),y00,x00+100*(n)+100*log10(i),y00+5);
}
   value=pow(10,n-2);
   gcvt(value,3,stt);
   outtextxy(x00+100*n,y11+8,stt);
   }
   setcolor(63);
for(n=0;n<=3;n++)                                             /*用于标纵坐标*/
{
   line(x00-5,y00+ystep*n,x00,y00+ystep*n);
   line(x11-5,y00+ystep*n,x11,y00+ystep*n);
   setlinestyle(3,1,1);                                         /*用于画图中横向虚线*/
   line(x00,y00+ystep*n,x11,y00+ystep*n);
   value=-50+50*n;
   gcvt(value,3,stt);
   outtextxy(x00-40,y00+ystep*n,stt);
   setlinestyle(0,1,1);
}
   
for(i=2;i<=6;i++)
{
   setcolor(i);                                                 /*对于不同的E，选择不同的线的颜色*/
   E=0.1+0.2*(i-2);
   for(k=0.01;k<100;k=k+0.01)                                    /*用于绘制0.01<k<100范围内的函数图像*/
{  
    a=(1-k*k)/(1+k*k*k*k-2*k*k+4*E*E*k*k);
    b=(2*E*k)/(1+k*k*k*k-2*k*k+4*E*E*k*k);
    data1=-log10(sqrt(a*a+b*b));
    h=k+0.01;
    a=(1-h*h)/(1+h*h*h*h-2*h*h+4*E*E*h*h);
    b=(2*E*h)/(1+h*h*h*h-2*h*h+4*E*E*h*h);
    data2=-log10(sqrt(a*a+b*b));
    x1=log10(k);
    x2=log10(k+0.01);
    line(300+100*x1,200+20*data1,300+100*x2,200+20*data2);
    }
}
   

   c = getch();
   closegraph();


   return c;
}

char xiangpin()
{
int driver=DETECT,mode,x00,x11,y00,y11,m,xstep,ystep;
  int l,n,i;
  char c;

  char stt[10];
  double data1,data2,value,k,h,a,b,E,x1,x2;
  initgraph(&driver,&mode," ");
  x00=100,y00=150,x11=x00+400,y11=y00+200;
  setcolor(63);
  rectangle(x00,y00,x11,y11);                                 /*用于绘制矩形框*/
  xstep=(x11-x00)/40;
  ystep=(y11-y00)/4;
 for(n=0;n<=4;n++)                                          /*用于标横坐标*/
{
  for(i=1;i<=10;i++)
 {
   if(n==4)
   break;
   setcolor(63);
   line(x00+100*(n)+100*log10(i),y11,x00+100*(n)+100*log10(i),y11+5);
   line(x00+100*(n)+100*log10(i),y00,x00+100*(n)+100*log10(i),y00+5);
}
   value=pow(10,n-2);
   gcvt(value,3,stt);
   outtextxy(x00+100*n,y11+8,stt);
   }
   setcolor(63);
for(n=0;n<=4;n++)                                          /*用于标纵坐标*/
{
   line(x00-5,y00+ystep*n,x00,y00+ystep*n);
   line(x11-5,y00+ystep*n,x11,y00+ystep*n);
   setlinestyle(3,1,1);                                    /*用于画图中横向虚线*/
   line(x00,y00+ystep*n,x11,y00+ystep*n);
   setlinestyle(0,1,1);
   value=-50*n;
   gcvt(value,3,stt);
   outtextxy(x00-40,y00+ystep*n,stt);
}
   
   
for(i=2;i<=6;i++)
{                    
   setcolor(i);                                /*对于不同的E，选择不同的线的颜色*/
   E=0.1+0.2*(i-2);
   for(k=0.01;k<0.98;k=k+0.01)                  /*用于绘制0.01<k<1范围内的函数图像*/
{  
    a=(1-k*k);
    b=(2*E*k);
    data1=atan(b/a);
    h=k+0.01;
    a=(1-h*h);
    b=(2*E*h);
    data2=atan(b/a);
    x1=log10(k);
    x2=log10(k+0.01);
    line(x00+200+100*x1,y00+180*data1/3.14,x00+200+100*x2,y00+180*data2/3.14);
    }

    k=k+0.01;                                    /*用于绘制k=1附近的函数图像*/
    a=(1-k*k);
    b=(2*E*k);
    data1=atan(b/a);
    h=k+0.01;
    a=(1-h*h);
    b=(2*E*h);
    data2=atan(b/a);
    x1=log10(k);
    x2=log10(k+0.02);
    line(x00+200+100*x1,y00+180*data1/3.14,x00+200+100*x2,y00+180+180*data2/3.14);

for(k=1.01;k<100;k=k+0.01)                     /*用于绘制1<k<100范围内的函数图像*/
{  
    a=(1-k*k);
    b=(2*E*k);
    data1=atan(b/a);
    h=k+0.01;
    a=(1-h*h);
    b=(2*E*h);
    data2=atan(b/a);
    x1=log10(k);
    x2=log10(k+0.01);
    line(x00+200+100*x1,y00+180+180*data1/3.14,x00+200+100*x2,y00+180+180*data2/3.14);
    }
}
   c = getch();
   closegraph();


   return c;
}








