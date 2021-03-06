#include <iostream.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
void initiarray( );
void initiones();
void display( float *r);
void solve();
void backloop();
static float  *p,*q;
int N;
void main()    //利用要求矩阵和单位矩阵一起行变化，当要求矩阵成为单位矩阵时
{              // 单位矩阵变成其逆矩阵
 printf("input array size N:");
 scanf("%d",&N);
 p=(float *)malloc(sizeof(float)*(N*N));
 q=(float *)malloc(sizeof(float)*(N*N));
 initiarray();
 initiones();
 display(p);
 solve( );
 backloop();
 display(q);
}
void initiarray( ) //初始化
{
 int i,j;
 extern N;
 printf("initialize array……\ninput array:\n");
 for(i=0;i<N;i++)
  for(j=0;j<N;j++)
   scanf("%f",&p[i*N+j]);
}
void initiones()  //形成单位矩阵
{
 int i,j;
 for(i=0;i<N;i++)
  for(j=0;j<N;j++)
  { if(i==j)
  q[i*N+j]=1;
  else
   q[i*N+j]=0;
  }
}
void display(float *r ) //显示
{
 int i,j;
 printf("out put array:\n");
 for(i=0;i<N;i++)
 {
 for(j=0;j<N;j++)
 printf("%10.4f",r[i*N+j]);
 printf("\n");
 }

}
void swap(float *r,int i,int line)  //换行
{
 int j;
 float m;
 for(j=0;j<N;j++)
 { m=r[i*N+j];
 r[i*N+j]=r[line*N+j];
 r[line*N+j]=m;
 }
}
void solve()   //形成下三角矩阵
{
 int i ,j,k,m,line;
 float max,temp,savep;
 for (i=0;i<N;i++)
 {
  max=fabs(p[i*N+i]);
  temp=p[i*N+i];
  line=i;
  for (j=i+1;j<N;j++)
  {
   if(fabs(p[j*N+i])>max)  //找出绝对值最大元
   {line=j;
   max=fabs(p[j*N+i]);
   temp=p[j*N+i]; }
  }
  if(max<=1e-5)  //三角矩阵的对角元等于0则无解
  {
   cout<<"no inverse array\n";
   exit(0);}
  if(line!=i)
  {
   swap(p,i,line);
   swap(q,i,line);}
  for (k=0;k<N;k++)
  {
   p[i*N+k]/=temp;
   q[i*N+k]/=temp;}
  for(k=i+1;k<N;k++) //消元，成下三角阵；
  {
   savep=p[k*N+i];
   for( m=0;m<N;m++)
   {
    q[k*N+m]=q[k*N+m]-q[i*N+m]*savep;
    p[k*N+m]=p[k*N+m]-p[i*N+m]*savep;}
  }
 }
}
void backloop()  //回带，形成单位矩阵
{
 int i,j,k;
 float savep;
 for(i=N-1;i>0;i--)
 {
  for(j=i-1;j>=0;j--)
  {
   savep=p[j*N+i];
   p[j*N+i]=p[j*N+i]-p[i*N+i]*savep;
   for(k=0;k<N;k++)
    q[j*N+k]=q[j*N+k]-q[i*N+k]*savep;

  }
 }
}
