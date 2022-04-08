#include<stdio.h>

#define BELL '\x7'


//2-10
int lower(int c)
{
	return (c > 'A' && c < 'Z') ? (c + 'a' - 'A') : c;
}

//2-9
int bitcount(unsigned x)
{
	int count = 0;
	while (x != 0)
	{
		++count;
		x &= (x - 1);
	}
	return count;
}

//返回对 将x从第p位开始的n个位设置位y中最右边n位的值
/*
* 解题思路：首先得把x 从p位开始的n位变为0
* 把y最右边n位保存到某个中间变量 , 我太6了
*/
//2-6
unsigned setbits(unsigned x, int p, int n, int y)
{
	unsigned t = ~(~0 << n) & y;
	unsigned t2 = t << (p + 1 - n);
	unsigned t3 = ~t2;
	unsigned t4 = x & t3;
	return t2 | t4;
}

//2-7 将x从第p位开始的n位求反, 除了下面的实现方式  用异或  也可以，把对应的位置p-n造个全是1的数然后异或
unsigned invert(unsigned x, int p, int n)
{
	//要取反的几位保存下来
	unsigned t = ~(~0 << n) & (x >> (p + 1 - n));
	//再移位和x中要移位的对齐,取反
	unsigned t2 = ~(t << (p + 1 - n));
	//把原数相应位置置为0
	unsigned t3 = (~(~0 << n)) << (p + 1 - n);
	unsigned t4 = ~t3 & x;
	return t4 | t2;
}

unsigned lengthofunsigned();


//2-8
//unsigned代表unsigned int
//循环右移
unsigned rightrot(unsigned x, int n)
{
	//右移前 保存即将丢失的低位
	unsigned t1 = x >> n;
	unsigned t = x & ~(~0 << n);
	//再把因为右移位丢失的低位 移到最高位去 然后通过或运算
	t <<= lengthofunsigned() - n;
	unsigned res = t | t1;
	return res;
}
//4294967295-1
unsigned lengthofunsigned()
{
	unsigned x = ~0;
	unsigned counter = 0;
	for (; x != 0; x >>= 1)
	{
		++counter;
	}
	return counter;
}

int test(unsigned a, unsigned b)
{
	return a - b > 0;
}

unsigned test2(unsigned a, unsigned b)
{
	return a - b;
}



int main()
{
	int x = 2;
	//printf("%d\n",x+=3);
	//printf("%c\n", lower('N'));
	//printf("%d\n", bitcount(077));
	//printf("%u\n", lengthofunsigned());
	//printf("%u\n", rightrot(4294967294, 1));
	printf("%d\n", test(3, 4));
	printf("%u\n", test2(3, 5));
	return 0;
}