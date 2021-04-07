
#include <stdlib.h>

/*
	$ size a.out
*/

/*
__TEXT	__DATA	__OBJC	others	dec	hex
4096	0	    0	    4294971392	4294975488	100002000
*/
// int main(int argc, char const *argv[])
// {
// 	return 0;
// }


/*
__TEXT	__DATA	__OBJC	others	dec	hex
4096	4096	0	4294971392	4294979584	100003000
*/
// int main(int argc, char const *argv[])
// {
// 	char *p = malloc(sizeof(char)*100);
// 	return 0;
// }


int a[30];
int main(int argc, char const *argv[])
{
	char *p = malloc(sizeof(char)*100);
	return 0;
}
