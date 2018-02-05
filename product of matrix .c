#include<stdio.h>
main()
{
	int n1,m1,n2,m2,matrix1[5][5],matrix2[5][5],result[5][5]={0},i,j,t,k,a,b,c,d,e;

	printf("Input matrix1 n1,m1:");              //输入矩阵一的行与列
	scanf("%d,%d",&n1,&m1);
	printf("Input matrix2 n2,m2:");				//输入矩阵二的行与列 
	scanf("%d,%d",&n2,&m2);
	if(n2==m1)                                   //判断矩阵相乘是否可行
	{
		printf("Input matrix1:\n");
		for(i=0;i<=n1-1;i++)                     //输入矩阵一
		{
			for(j=0;j<=m1-1;j++)
			{
				scanf("%d",&matrix1[i][j]);
			}
		}
		printf("Input matrix2:\n");
		for(t=0;t<=n2-1;t++)                          //输入矩阵二
		{
			for(k=0;k<=m2-1;k++)
			{
				scanf("%d",&matrix2[t][k]);
			}
		}
		for(a=0;a<=n1-1;a++)                           //计算矩阵相乘
		{
			for(b=0;b<=m2-1;b++)
			{
				for(c=0;c<=m1-1;c++)
				{
					result[a][b]=result[a][b]+(matrix1[a][c])*(matrix2[c][b]);
				}
			}
		}
		printf("the result is:\n");                
		for(d=0;d<=n1-1;d++)						//输出结果矩阵
		{
			for(e=0;e<=m2-1;e++)
			{
				printf("%d ",result[d][e]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("It's an error.\n");						//若不可行，提示错误
	}
	getch();
}

