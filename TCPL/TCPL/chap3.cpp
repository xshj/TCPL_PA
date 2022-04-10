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
	//��ʼ��
	nspace = 0, nothers=0;
	int i;
	//digits������0-9 10����
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
//3-2  ���ַ���t�е��ַ����Ƶ�s�У��������з����\n,�Ʊ������\t
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

//���ַ�����t�е�\\t \\n��ԭ��\t \n
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
//�ַ���ת
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

//����ת�ַ��������ϵİ汾
void itoa(int n, char s[])
{
	//�ж�������
	//Ȼ�󰤸�ȡ�࣬������10,
	int sign,i=0;
	if ((sign = n) < 0)	n = -n;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n/=10)>0);
	if (sign < 0)
		s[i++] = '-';
	//������������ģ���Ϊreverse��������'\0'�����û�������������reverse��ʧ��
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
* ��ע������ĺ궨��
* #define abs(x)	((x)<0?(-x):(x))
* ���Ǵ���ģ���ֻ���滻���������x�Ǹ����ʽ����ôֻ�Ὣ���ʽ�ĵ�һ������ǰ��
* ���һ������
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
//3-5,��10����ת��Ϊb���ƣ�b����[2,35],��10��ʼ������a,b,c...�ȱ�ʾ
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
//������ת��Ϊ�ַ�����������С��len�������ַ��������Ӷ���Ŀո�
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


//��ȡһ�У����ض�ȡ����
int getline(char in[], int limit)
{
	int i,c;
	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		in[i] = c;
	}
	//�������Ϊ���е��µĽ�������Ҫ�ѻ��з����뵽����
	if (c == '\n')
	{
		in[i++] = c;
	}
	in[i] = '\0';
	return i;
}
