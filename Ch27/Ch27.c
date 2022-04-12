#include <stdio.h>
// gcc Ch27.c -o Ch27
int main()
{
void my_print(char* p, int x)
{
	printf("p is \"%s\" and x is %i\n",p,x);
}
	int x = 7;
	char* p = "foo";
	my_print(p,x);
	char* egyik = "Hello";
	char* masik = "World!";
	printf("%s %s\n",egyik,masik);
	return 0;
}