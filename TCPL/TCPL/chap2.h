#define BELL '\x7'


//2-10
int lower(int c);
int bitcount(unsigned x);

//���ض� ��x�ӵ�pλ��ʼ��n��λ����λy�����ұ�nλ��ֵ
/*
* ����˼·�����ȵð�x ��pλ��ʼ��nλ��Ϊ0
* ��y���ұ�nλ���浽ĳ���м���� , ��̫6��
*/
//2-6
unsigned setbits(unsigned x, int p, int n, int y);

//2-7 ��x�ӵ�pλ��ʼ��nλ��, ���������ʵ�ַ�ʽ  �����  Ҳ���ԣ��Ѷ�Ӧ��λ��p-n���ȫ��1����Ȼ�����
unsigned invert(unsigned x, int p, int n);
unsigned lengthofunsigned();


//2-8
//unsigned����unsigned int
//ѭ������
unsigned rightrot(unsigned x, int n);
unsigned lengthofunsigned();

int test(unsigned a, unsigned b);

unsigned test2(unsigned a, unsigned b);

