#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <string.h>
void jza(long m);
void jzb(long m);
int main()
{
  int i,n,b[100];
  double s=0;
 long m=0,l;
  char a[100];
  printf("请输入需要转换的数字：\n");
  loop:
  for (i=0;;i++)
  {
      a[i]=getchar();
      if(a[i]<'0'||a[i]>'9')
      {
         break;
      }
  }/*i位*/
  if(i>10)
  {
     printf("超过计算范围请重新输入!\n");
     goto loop;
  }
  else{
        n=i;
        for(i=0;i<n;i++)
        {
            switch(a[i])
            {
                case'0':
                    b[i]=0;
                break;
                case'1':
                    b[i]=1;
                    break;
                case'2':
                    b[i]=2;
                    break;
                case'3':
                    b[i]=3;
                    break;
                case'4':
                    b[i]=4;
                    break;
                case'5':
                    b[i]=5;
                    break;
                case'6':
                    b[i]=6;
                    break;
                case'7':
                    b[i]=7;
                    break;
                case'8':
                    b[i]=8;
                    break;
                case'9':
                    b[i]=9;
                    break;
                default:;
            }
        }
        m=0;
        for(i=0;i<n;i++)
        {
        s=s+b[i]*pow(10,(n-i-1));
        m=(long)s;
        }
        jza(m);
        printf("\n");
        jzb(m);
     }
return(0);

}
void jza(long m)
{
int a[20],i=0;
char c;
while(m!=0)
{
a[i]=m%16;
m/=16;
i++;
}
i--;
printf("转换为十六进制是:");
for(;i>=0;i--)
{
if(a[i]>=10)
{
c=55+a[i];
printf("%c",c);
}
else
printf("%d",a[i]);
}
printf("\n");
}
void jzb(long m)
{
int str[500];
int i=0,j;
while(m!=0)
{
 str[i++]=m%2;
 m/=2;
}
printf("转换为二进制是:");
for(j=i-1;j>=0;j--)
{
    printf("%d",str[j]);
}
printf("\n");
}
