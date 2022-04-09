#include"chap3.h"
#include<string.h>
#include<ctype.h>


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

void shellsort(int v[], int n)
{

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
	int sign;
	if ((sign = n) < 0)	n = -n;
}

//3-4
void itoa2(int n, char s[])
{

}
//3-5
void itob(int n, char s[], int b)
{

}
//3-6
void itoa3(int n, char s[], int len)
{

}