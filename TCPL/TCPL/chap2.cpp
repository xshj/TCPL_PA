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

//���ض� ��x�ӵ�pλ��ʼ��n��λ����λy�����ұ�nλ��ֵ
/*
* ����˼·�����ȵð�x ��pλ��ʼ��nλ��Ϊ0
* ��y���ұ�nλ���浽ĳ���м���� , ��̫6��
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

//2-7 ��x�ӵ�pλ��ʼ��nλ��, ���������ʵ�ַ�ʽ  �����  Ҳ���ԣ��Ѷ�Ӧ��λ��p-n���ȫ��1����Ȼ�����
unsigned invert(unsigned x, int p, int n)
{
	//Ҫȡ���ļ�λ��������
	unsigned t = ~(~0 << n) & (x >> (p + 1 - n));
	//����λ��x��Ҫ��λ�Ķ���,ȡ��
	unsigned t2 = ~(t << (p + 1 - n));
	//��ԭ����Ӧλ����Ϊ0
	unsigned t3 = (~(~0 << n)) << (p + 1 - n);
	unsigned t4 = ~t3 & x;
	return t4 | t2;
}

unsigned lengthofunsigned();


//2-8
//unsigned����unsigned int
//ѭ������
unsigned rightrot(unsigned x, int n)
{
	//����ǰ ���漴����ʧ�ĵ�λ
	unsigned t1 = x >> n;
	unsigned t = x & ~(~0 << n);
	//�ٰ���Ϊ����λ��ʧ�ĵ�λ �Ƶ����λȥ Ȼ��ͨ��������
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