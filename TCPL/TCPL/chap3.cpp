#include"chap3.h"

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
void calc_chars(char digits[], int& nspace, int& nothers)
{
	//³õÊ¼»¯

}
int trim(char s[])
{

}
//3-2
void escape(char s[], char t[])
{

}
void unescapte(char s[], char t[])
{

}
int atoi(char s[])
{

}
void shellsort(int v[], int n)
{

}
void reverse(char s[])
{

}
void itoa(int n, char s[])
{

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