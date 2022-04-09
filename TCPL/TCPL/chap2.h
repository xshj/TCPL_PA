#define BELL '\x7'


//2-10
int lower(int c);
int bitcount(unsigned x);

//返回对 将x从第p位开始的n个位设置位y中最右边n位的值
/*
* 解题思路：首先得把x 从p位开始的n位变为0
* 把y最右边n位保存到某个中间变量 , 我太6了
*/
//2-6
unsigned setbits(unsigned x, int p, int n, int y);

//2-7 将x从第p位开始的n位求反, 除了下面的实现方式  用异或  也可以，把对应的位置p-n造个全是1的数然后异或
unsigned invert(unsigned x, int p, int n);
unsigned lengthofunsigned();


//2-8
//unsigned代表unsigned int
//循环右移
unsigned rightrot(unsigned x, int n);
unsigned lengthofunsigned();

int test(unsigned a, unsigned b);

unsigned test2(unsigned a, unsigned b);

