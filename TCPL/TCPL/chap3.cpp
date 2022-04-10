#include"chap3.h"
#include<string.h>
#include<ctype.h>
#include<stdio.h>


int binsearch(int x, int v[], int n)
{
	int left = 0, right = n - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) >> 2;
		if (x > v[mid])
			left = mid + 1;
		else if (x < v[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
//3-1
int binsearch2(int x, int v[], int n) 
{
	int left = 0, right = n - 1;
	int mid;

	while (left <= right && x != v[mid=((left + right) >> 2)])
	{
		if (x < v[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (x == v[mid]) ? mid : -1;
}
void calc_chars(char s[], char digits[], int& nspace, int& nothers)
{
	//初始化
	nspace = 0, nothers=0;
	int i;
	//digits数组是0-9 10个数
	for (i = 0; i < 10; i++)
		digits[i] = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		int c = s[i];
		switch (c)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				digits[c - '0']++;
				break;
			case ' ':
			case '\t':
			case '\n':
				nspace++;
				break;
			default:
				nothers++;
				break;
		}
	}
}

int trim(char s[])
{
	int n;
	for (n = strlen(s) - 1; n >= 0; n--)
	{
		if (s[n] != '\n' && s[n] != '\t' && s[n] != ' ')
			break;
	}
	s[n + 1] = '\0';
	return n;
}
//3-2  把字符串t中的字符复制到s中，并将换行符变成\n,制表符换成\t
void escape(char s[], char t[])
{
	int i,j;
	for (i = 0,j=0; t[i] != '\0'; i++,j++)
	{
		int c = t[i];
		switch (c)
		{
		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		default:
			s[j] = c;
			break;
		}
	}
	s[j] = '\0';
}

//把字符数组t中的\\t \\n还原成\t \n
void unescapte(char s[], char t[])
{
	int i, j;
	for (i = 0, j = 0; t[i] != '\0'; i++, j++)
	{
		int c = t[i];
		switch (c)
		{
		case '\\':
			++i;
			if (t[i] == 't')
			{
				s[j] = '\t';
			}
			else if (t[i] == 'n')
			{
				s[j] = '\n';
			}
			break;
		default:
			s[j] = c;
			break;
		}
	}
	s[j] = '\0';
}
//字符串转
int atoi(char s[])
{
	int i, sign, n;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
	{
		n = n * 10 + (s[i] - '0');
	}
	return n*sign;
}


void insertsort(int v[], int n)
{
	int i,j;
	for (i = 1; i < n; i++)
	{
		int temp = v[i];
		j = i - 1;
		while (temp < v[j] && j >= 0)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
}

void insertsort_gap(int v[], int n, int gap)
{
	int i, j;
	for (i = gap; i < n; i += gap)
	{
		j = i - gap;
		int temp =v[i];
		while (temp < v[j] && j >= 0)
		{
			v[j + gap] = v[j];
			j -= gap;
		}
		v[j + gap] = temp;
	}
}

void shellsort(int v[], int n)
{
	int gap = n;
	while ((gap /= 2) > 0)
	{
		insertsort_gap(v, n, gap);
	}
}
void reverse(char s[])
{
	int i, j;
	for (i = 0,j = strlen(s) - 1; i < j; i++, j--)
	{
		int c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

//整数转字符串，书上的版本
void itoa(int n, char s[])
{
	//判断正负数
	//然后挨个取余，再整除10,
	int sign,i=0;
	if ((sign = n) < 0)	n = -n;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n/=10)>0);
	if (sign < 0)
		s[i++] = '-';
	//以下是有问题的，因为reverse函数依赖'\0'，因此没有这个结束符，reverse会失败
	//reverse(s);
	//s[i] = '\0';
	s[i] = '\0';
	reverse(s);
}

//3-3
void expand(char s1[], char s2[])
{

}

//3-4
#define abs(x)	((x)<0?-(x):(x))
/*
* 请注意下面的宏定义
* #define abs(x)	((x)<0?(-x):(x))
* 这是错误的，宏只是替换，如果传的x是个表达式，那么只会将表达式的第一个变量前面
* 添加一个负号
*/

void itoa2(int n, char s[])
{
	int sign, i = 0;
	sign = n;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n/=10)!=0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
//3-5,将10进制转换为b进制，b属于[2,35],从10开始依次用a,b,c...等表示
void itob(int n, char s[], int b)
{
	if (b < 2)	return;
	int i = 0, sign = n;
	do
	{
		int j = abs(n % b);
		s[i++] = (j<=9)? j +'0':j-10+'a';
	} while ((n/=b)!=0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
//3-6
//将整数转换为字符串后，若长度小于len，则在字符串左边添加额外的空格
void itoa3(int n, char s[], int len)
{
	int sign, i = 0;
	sign = n;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n/=10)!=0);
	if (sign < 0)
		s[i++] = '-';
	for (; i < len; i++)
	{
		s[i] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}


//读取一行，返回读取长度
int getline(char in[], int limit)
{
	int i,c;
	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		in[i] = c;
	}
	//如果是因为换行导致的结束，需要把换行符加入到数组
	if (c == '\n')
	{
		in[i++] = c;
	}
	in[i] = '\0';
	return i;
}
