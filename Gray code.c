#include <stdio.h>
#include<string.h>
/*�û��Ӽ���������Ҫ��ת��������*/
/*���������*p������ָ��(���ݰ��ַ��洢��*/
/*����ֵ����������λ��*/
int get_grey_binary(unsigned char *p)
{	
	unsigned int i=1;/*�������������λ��*/
	/*�Ӽ����������ݣ���ȡֵΪASCII��*/
	while(1)
	{
		*p=getchar();/*��ȡ����ֵ*/
		if(*p=='e')  /*��'e' ��ʾ���ݽ�β*/		{
			i--;
			break;
		}
		else
		{
			if(*p!='1'&& *p!='0')
			{
				if(*p!='\n')
				{
					printf("illegal character\n");/*���������ַ����� '1'��'0',����ʾ���ַ��Ƿ�*/
					printf("number%d",i);	      /*��ʾ�Ƿ����ַ�Ϊ�ڼ���*/
				}
			}
			else  /*���������ַ��Ϸ�*/
			{
				i++;/*����*/
				p++;/*ָ��ָ����һλ*/
			}
		}
	}
		return i;/*��������*/
}
/*������ת��Ϊ��������*/
/*���������*grey��������ָ�룬�ڴ�Ÿ����룻*binary��������ָ�룬���ڴ��ת���õ��Ķ�������*/
*����ֵ����*/
void change_grey_binary(unsigned char *grey,unsigned char *binary)
{
	*binary=*grey; /*���ո�����ת������������򣬸������һλ����������һλ��ͬ*/
	grey++;		/*������ָ��ָ��ڶ�λ*/
	while(*grey!='\0')/*������û�е����β��ʱ������������һλ���������Ĵ�λ���������*/
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
/*������ת��Ϊ��������*/
/*���������*grey��������ָ�룬�ڴ�Ÿ����룻*binary��������ָ�룬���ڴ��ת���õ��Ķ�������;count:��������λ��*/
*����ֵ����*/��
void change_binary_grey(unsigned char *grey,unsigned char *binary,unsigned int count)
{
	unsigned int i=0;
	strrev(binary);/*�������뵹��*/
	while(i<count-1)/*�����Ķ������������һ����������λ�����������һλ��ͬ����֮����ͬ*/
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
	*grey=*binary;/*�������һλ�����������ͬ*/
	strrev(grey);/*���׵���*/
	
		  
}	
main()
{
	unsigned char grey[100]={0};
	unsigned char binary[100]={0};
	unsigned count;
	unsigned int i;
	unsigned char step=0;
	
	printf("grey-binary  0\nbinary_grey  1\nexit  '2'\nchoose function:\n");/*��ʾ�˵�*/
	scanf("%c",step);
	switch(step)?
	{
		case '0':
		{
			printf("Input grey:")
			count=get_grey_binary(&grey[0]);/*��������*/
			grey[count]='\0';/*�����ݼӽ�β*/
			printf("total %d\n",count);
			change_grey_binary(&grey[0],&binary[0]);
			for(i=0;i<count;i++)/*��ӡ*/
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
			exit();/*�˳�*/
		}
	}
} 
