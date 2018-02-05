#include <graphics.h>
#include <math.h>
#include <dos.h>
main()
{ int driver=DETECT,mode,x00,x11,y00,y11,m,xstep,ystep,k,c=1;
  int data[256],data2[256],x1,x2;
  float lan;
  char stt[10],stt2[10];
  double value;
  initgraph(&driver,&mode," ");
  for(k=0;k<255;k++)
  data[k]=2000*(2.0*3.14159/96)*sin(2.0*3.14159/96*k);
  x00=60,y00=30,x11=x00+512,y11=y00+200;
  rectangle(x00,y00,x11,y11);
  rectangle(x00,y11,x11,y11+200);
  xstep=(x11-x00)/16;
  ystep=(y11-y00)/8;
  for(k=0;k<=16;k++){
   line(x00+xstep*k,y11,x00+xstep*k,y11+5);
   value=xstep*k/32;
   gcvt(value,3,stt);
   outtextxy(x00+xstep*k-8,y11+8,stt);
   }
  for(k=0;k<=7;k++){
   line(x00,y11+ystep*k,x00+5,y11+ystep*k); 
   line(x00,y11-ystep*k,x00+5,y11-ystep*k);
   }
  for(k=0;k<=8;k++)
  { 
   value=ystep*k/24;
   gcvt(value,3,stt2);
   outtextxy(x00-16,y11-ystep*k,stt2);
   outtextxy(x00-16,y11+ystep*k,stt2);
  }
 x1=x00;
    for(k=0;k<249;k++){
      x2=x1+2;
      setcolor(63); /*设曲线颜色为白色 */
      line(x1,y11-data[k],x2,y11-data[k+1]);  /*画一段曲线*/
      delay(5);
      setcolor(1);                           /*设曲线颜色为蓝色 */
      line(x1,y11-data[k],x2,y11-data[k+1]);
      x1=x2;                                 /*用蓝色线段覆盖白色曲线 */
      }
 for(lan=0.1;lan<=0.9;lan+=0.2){
  for(k=0;k<255;k++)
  data2[k]=2000*(2.0*3.14159/96)/(sqrt(1-lan*lan))*(exp(0-lan*(2.0*3.14159/96)*k))*sin(2.0*3.14159/96*sqrt((1-lan*lan))*k);
 x1=x00;
    for(k=0;k<249;k++){
      x2=x1+2;

      setcolor(63); /*设曲线颜色为白色 */
      line(x1,y11-data2[k],x2,y11-data2[k+1]);  /*画一段曲线*/
      delay(5);
      setcolor(1+c);                           /*设曲线颜色为蓝色 */
      line(x1,y11-data2[k],x2,y11-data2[k+1]);
      x1=x2;                                 /*用蓝色线段覆盖白色曲线 */
      }
      c++;
   }
   getch();
   closegraph();
}

