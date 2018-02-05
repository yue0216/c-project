#include <graphics.h>
#include <math.h>
#include <dos.h>
main()
{ int driver=DETECT,mode,x00=20,x11=532,y00=20,y11=276,m,xstep,ystep,k;
  int data[256],sec[256],thr[256],x1,x2,add[256],a,d,g;
  float s,f,h;
  char stt[10];
  double value;
  initgraph(&driver,&mode," ");
    printf("Please input the first line's amplitude and frequency:\n");
    scanf("%d%*c%f",&a,&s);
    getch();
    printf("Please input the second line's amplitude and frequency:\n");
    scanf("%d%*c%f",&d,&f);
    getch();
    printf("Please input the third line's amplitude and frequency:\n");
    scanf("%d%*c%f",&g,&h);
    for(k=0;k<255;k++)     /* 分别计算出三个函数的函数值 */
    {
      data[k]=a*sin(s*k);
      sec[k]=d*sin(f*k);
      thr[k]=g*sin(h*k);
      add[k]=data[k]+sec[k]+thr[k];
    }
    x00=20,y00=120,x11=x00+512,y11=y00+256;   /* 设定坐标轴 */
    rectangle(x00,y00,x11,y11);    /* 绘制坐标轴 */
    m=(y00+y11)/2;
    line(x00,m,x11,m);  /* x=0所在直线 */
    xstep=(x11-x00)/16;
    ystep=(y11-y00)/8;
    for(k=0;k<=16;k++)   /* 确定x轴坐标 */
    {
        line(x00+xstep*k,y11,x00+xstep*k,y11+5);
        value=xstep*k/2;
        gcvt(value,3,stt);
        outtextxy(x00+xstep*k-8,y11+8,stt);
    }

    for(k=0;k<=4;k++)  /* 确定y轴坐标 */
    {
       line(x00-5,y00+ystep*k,x00,y00+ystep*k);
       value=-ystep*k/2;
       gcvt(value,3,stt);
       outtextxy(x00-5,m+ystep*k-8,stt);
       settextstyle(0,1,0);
    }
    for(k=0;k<=4;k++)  /* 确定y轴坐标 */
    {
       line(x00-5,y00+ystep*(k+4),x00,y00+ystep*(k+4));
       value=ystep*k/2;
       gcvt(value,3,stt);
       outtextxy(x00-5,m-ystep*k-8,stt);
       settextstyle(0,1,0);
    }
    x1=x00;
    setcolor(2);
    for(k=0;k<254;k++)
    {
        x2=x1+2;
        line(x1,m-data[k],x2,m-data[k+1]);
        delay(50);
        x1=x2;
    }
    x1=x00;
    setcolor(5);
    for(k=0;k<254;k++)
    {
        x2=x1+2;
        line(x1,m-sec[k],x2,m-sec[k+1]);
        delay(25);
        x1=x2;
    }
    x1=x00;
    setcolor(4);
    for(k=0;k<254;k++)
    {
        x2=x1+2;
        line(x1,m-thr[k],x2,m-thr[k+1]);
        delay(50);
        x1=x2;
    }
    x1=x00;
    setcolor(15);
    for(k=0;k<254;k++)
    {
        x2=x1+2;
        line(x1,m-add[k],x2,m-add[k+1]);
        delay(50);
        x1=x2;
    }
    getch();
    closegraph();
}
