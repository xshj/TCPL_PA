#define MAX_LINE_CHARS	100

int binsearch(int x, int v[], int n);
//3-1
int binsearch2(int x, int v[], int n);
void calc_chars(char s[], char digits[], int& nspace, int& nothers);
int trim(char s[]);
//3-2
void escape(char s[], char t[]);
void unescapte(char s[], char t[]);
int atoi(char s[]);
void shellsort(int v[], int n);
void reverse(char s[]);

//3-3
void expand(char s1[], char s2[]);

void itoa(int n, char s[]);
//3-4
void itoa2(int n, char s[]);
//3-5
void itob(int n, char s[], int b);
//3-6
void itoa3(int n, char s[], int len);

void getline(char in[], int limit);