#include <stdio.h>
#include <string.h>
void check(char *pa,int n)
{
    int flag=0,num=0;
    do
	{
        *pa=getchar();
        getchar();
        num=(*pa)-'0';
        if(num>=0&&num<=n-1)
        {
            flag=1;
        }
        else
        {
            printf("Wrong!Please input again.\n");
        }
    }while(flag==0);
    printf("Input correctly!\n");
}
float f(float x,int n)
{
    float num=1,i;
    for(i=0;i<n;i++)
    {
        num=num*x;
    }
    return num;
}
float j(float x)
{
    float num=1,i;
    for(i=x;i>0;i--)
    {
        num=num*i;
    }
    return num;
}
float c(float a,float b)
{
    float num;
    num=(j(a))/(j(b))/(j(a-b));
    return num;
}
void zhuanhua(float a[8],int n,float T)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=a[i]*f(T,n-i);
    }
}
void jisuan(float a[9],float b[9],int n,float T)
{
    int i,j,k;
    for(i=0;i<=n;i++)
    {
        for(j=i,k=0;j<=n;j++,k++)
        {
            b[i]=b[i]+a[j]*f(-1,k)*c((float)j,(float)k);
        }
    }
}
int main()
{
      float a1[9],a2[9]={0,0,0,0,0,0,0,0,0},b1[9],b2[9]={0,0,0,0,0,0,0,0,0},T=1;
       int i,n,flag=0;
    char n1,*n2=&n1,c='1';
    do
    {
        printf("Please input n:\n");
        check(n2,9);
        n=n1-'0';
        printf("Please input T:\n");
        do
        {
            scanf("%f",&T);
            if(T!=0.0)
            {
                flag=1;
            }
            else
            {
               printf("Wrong!Please input again.\n");
            }
        }while(flag==0);
        printf("Input corretcly!\n");
        printf("Please input a\n");
         for(i=0;i<=n;i++)
        {
           printf("a%d:",i);
           scanf("%f",&a1[i]);
        }
         printf("a is over\n");
         printf("Please input b\n");
        for(i=0;i<=n;i++)
       {
           printf("b%d:",i);
           scanf("%f",&b1[i]);
       }
        printf("Input is over,following are the answers:(ai=>ci  bi=>di)\n\n");
        zhuanhua(a1,n,T);
        zhuanhua(b1,n,T);
        jisuan(a1,a2,n,T);
        jisuan(b1,b2,n,T);
       for(i=0;i<=n;i++)
       {
         printf("c%d=%f\n",i,a2[i]);
       }
         printf("c is over\n\n");
        for(i=0;i<=n;i++)
        {
           printf("d%d=%f\n",i,b2[i]);
        }
        printf("d is over\n");
        printf("\nDo you want to use it again?\n1.Yes 2.No\n");
        getchar();
        c=getchar();
        if(c=='1')
        {
            printf("\n\n");
        }
    }while(c=='1');
    printf("Thank you for your using.\n");
    return 0;
}
