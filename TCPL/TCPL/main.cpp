#include<stdio.h>
#include<limits.h>
#include "chap2.h"
#include "chap3.h"

int main()
{
	int x = 2;
	//printf("%d\n",x+=3);
	//printf("%c\n", lower('N'));
	//printf("%d\n", bitcount(077));
	//printf("%u\n", lengthofunsigned());
	//printf("%u\n", rightrot(4294967294, 1));
	//printf("%d\n", test(3, 4));
	//printf("%u\n", test2(3, 5));
	printf("%d\n", INT_MIN);
	unsigned t = ~0;
	int bitcount = 0;
	while (t != 0)
	{
		++bitcount;
		//���x��int����ô���ƹ����У���������������ô��λ��1�������ʼ�ղ��䣬*******��
		//����Ҫ������Ҫ������Ҫ
		//��Ҫ��λ���0����Ҫ��x���unsigned����
		t>>=1;
	}
	printf("int len:%d\n", bitcount);
	char s[33] = { 0 };
	itoa2(INT_MIN, s);
	//itoa(-876134, s);
	printf("%s\n", s);
	for (int i = 0; s[i] != '\0'; ++i)
	{
		printf("%c ", s[i]);
	}
	printf("\n");
	//goto end;
	//������һ������ȡ�࣬����ҲΪ����
	//����Ҫ������Ҫ������Ҫ
	printf("%d\n", -108 % 10);
	printf("%d\n", -108 % -10);
	printf("%u\n", -108 % 10);
	printf("%d\n", 108 % 10);

//end:
	//printf("end\n");
	return 0;
}