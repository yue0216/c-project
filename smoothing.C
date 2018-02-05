#include <graphics.h>#include <math.h>#include <dos.h>
void InputValue(int x[])
{
    int i;
    char a;
    printf("reset x?(y/n)\n");
    scanf(" %c",&a);
    if(a=='Y'||a=='y')
    {
        printf("Input x\n");
        for(i=0;i<9;i++)                                  /*  输入x的值*/
        {
            scanf("%d",x+i);

        }
    }

}

void DrawLine(int x[])
{
    int driver=DETECT,mode,x00,x11,y00,y11,xstep,ystep,k,y[9],i,xl,yl;
    char stt[11],a;
    double value;
    x00=90,y00=30,xl=540;yl=420;
    printf("reset zuobiaozhou?(y/n)\n");
    scanf(" %c",&a);
    if(a=='Y'||a=='y')
    {
        printf("Input x00 (>90)\n");
        scanf("%d",&x00);
        printf("Input y00 (>25)\n");
        scanf("%d",&y00);
        printf("Input xl\n");
        scanf("%d",&xl);
        printf("Input yl\n");
        scanf("%d",&yl);
    }
    x11=x00+xl,y11=y00+yl;
    initgraph(&driver,&mode," ");                      /*初始化函数*/
    setbkcolor(9);                                     /*  设置背景颜色*/    setlinestyle(0,2,3);                                /*  设置线形*/
    setviewport(0,0,639,479,0);
    setcolor( 63);                                      /*  设置线性颜色为白色*/
    rectangle(x00,y00,x11,y11);                         /*  画矩形框函数*/
    xstep=(x11-x00)/10;    ystep=(y11-y00)/10;
      for(k=0,value=0;k<=10;k++)                      /*  标x轴*/
    {        line(x00+xstep*k,y11,x00+xstep*k,y11+5);        gcvt(value,3,stt);                           /*将浮点数转换成字符串函数*/        outtextxy(x00+xstep*k-8,y11+8,stt);          /*  定位字符串输出函数*/        value++;
    }    for(k=1;k<=10;k++)                              /*  标y轴*/
    {        line(x00-5,y00+ystep*k,x00,y00+ystep*k);
        value=ystep*k;        gcvt(value,3,stt);                           /*将浮点数转换成字符串函数*/        outtextxy(x00-25,y11-ystep*k-8,stt);         /*  定位字符串输出函数*/    }
    y[0]=(69*x[0]+4*(x[1]+x[3])-6*x[2]-x[4])/70;       /*  计算y的值*/
    y[1]=(2*(x[0]+x[4])+27*x[1]+12*x[2]-8*x[3])/35;
    y[2]=(-3*(x[0]+x[4])+12*(x[1]+x[3])+17*x[2])/35;
    y[3]=(-3*(x[1]+x[5])+12*(x[2]+x[4])+17*x[3])/35;
    y[4]=(-3*(x[2]+x[6])+12*(x[3]+x[5])+17*x[4])/35;
    y[5]=(-3*(x[3]+x[7])+12*(x[4]+x[6])+17*x[5])/35;
    y[6]=(-3*(x[4]+x[8])+12*(x[5]+x[7])+17*x[6])/35;
    y[7]=(2*(x[4]+x[8])-8*x[5]+12*x[6]+27*x[7])/35;
    y[8]=(-x[4]+4*(x[5]+x[7])-6*x[6]+69*x[8])/70;
    for(i=0;i<9;i++)                                     /*  打印处理前，处理后的值*/
    {
        printf("%d~",x[i]);
        printf("%d\n",y[i]);
    }

    for(i=0,k=1;i<8;i++,k++)                           /* 画处理前的曲线*/
    {
        line(x00+xstep*k,y11-x[i],x00+xstep*(k+1),y11-x[i+1]);
        delay(200);                                       /*  延时函数*/
    }
    setcolor( 5);                                    /*  设置线性颜色为红色*/
    for(i=0,k=1;i<8;i++,k++)                              /*  画处理后的平滑曲线*/
    {

        line(x00+xstep*k,y11-y[i],x00+xstep*(k+1),y11-y[i+1]);
        delay(200);                                         /*  延时函数*/
    }

}



int main(){
    int x[9]={54,145,227,359,401,342,259,112,65};
    char b;
 start:   InputValue(x);              /*调用输入值函数*/    DrawLine(x);                /*调用绘图函数*/    printf("draw again?\n");
    printf("y/n \n");
    scanf(" %c",&b);
    if(b=='Y'||b=='y')
    {
        cleardevice();
        clearviewport();
        setbkcolor(0);
        goto start;
    }
    else exit(0);
}
