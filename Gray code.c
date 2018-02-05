#include <stdio.h>
#include<string.h>
/*用户从键盘输入需要被转换的数据*/
/*输入变量：*p：数据指针(数据按字符存储）*/
/*返回值：输入数据位数*/
int get_grey_binary(unsigned char *p)
{	
	unsigned int i=1;/*计算输入的数据位数*/
	/*从键盘输入数据，获取值为ASCII码*/
	while(1)
	{
		*p=getchar();/*获取按键值*/
		if(*p=='e')  /*以'e' 表示数据结尾*/		{
			i--;
			break;
		}
		else
		{
			if(*p!='1'&& *p!='0')
			{
				if(*p!='\n')
				{
					printf("illegal character\n");/*如果输入的字符不是 '1'或'0',则显示该字符非法*/
					printf("number%d",i);	      /*显示非法的字符为第几个*/
				}
			}
			else  /*如果输入的字符合法*/
			{
				i++;/*计数*/
				p++;/*指针指向下一位*/
			}
		}
	}
		return i;/*返回数据*/
}
/*格雷码转换为二进制码*/
/*输入变量：*grey：格雷码指针，内存放格雷码；*binary：二进制指针，用于存放转换得到的二进制码*/
*返回值：无*/
void change_grey_binary(unsigned char *grey,unsigned char *binary)
{
	*binary=*grey; /*按照格雷码转换二进制码规则，格雷码第一位与二进制码第一位相同*/
	grey++;		/*格雷码指针指向第二位*/
	while(*grey!='\0')/*格雷码没有到达结尾的时候，则格雷码的下一位与二进制码的此位做异或运算*/
	{
	  if(*binary==*grey)/
	  {
		binary++;
		*binary='0';
		grey++;
	  }
	  else
	  {
		binary++;
		*binary='1';
		grey++;
	  }
	}
}
/*格雷码转换为二进制码*/
/*输入变量：*grey：格雷码指针，内存放格雷码；*binary：二进制指针，用于存放转换得到的二进制码;count:二进制码位数*/
*返回值：无*/；
void change_binary_grey(unsigned char *grey,unsigned char *binary,unsigned int count)
{
	unsigned int i=0;
	strrev(binary);/*二进制码倒序*/
	while(i<count-1)/*倒序后的二进制码如果是一，则格雷码此位与二进制码下一位不同，反之则相同*/
	{
	  if(*binary=='1')
	  {
		  if(*(binary+1)=='0') *grey='1';
		  else *grey='0';
	  }
	  else
	  {
		  if(*(binary+1)=='1') *grey='0';
		  else *grey='1';
	  }
	  binary++;grey++;
	}
	*grey=*binary;/*格雷码第一位与二进制码相同*/
	strrev(grey);/*格雷倒序*/
	
		  
}	
main()
{
	unsigned char grey[100]={0};
	unsigned char binary[100]={0};
	unsigned count;
	unsigned int i;
	unsigned char step=0;
	
	printf("grey-binary  0\nbinary_grey  1\nexit  '2'\nchoose function:\n");/*显示菜单*/
	scanf("%c",step);
	switch(step)?
	{
		case '0':
		{
			printf("Input grey:")
			count=get_grey_binary(&grey[0]);/*输入数据*/
			grey[count]='\0';/*给数据加结尾*/
			printf("total %d\n",count);
			change_grey_binary(&grey[0],&binary[0]);
			for(i=0;i<count;i++)/*打印*/
			{
				printf("%c",binary[i]);
			}
		}break;
		case '1':
		{
			printf("Input binary:")
			count=get_grey_binary(&binary[0]);
			printf("total %d\n",count);
			change_binary_grey(&grey[0],&binary[0],count);
			for(i=0;i<count;i++)
			{
				printf("%c",grey[i]);
			}
		}break;
		case '2'
		{
			exit();/*退出*/
		}
	}
} 
