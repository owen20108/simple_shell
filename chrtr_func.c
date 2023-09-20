#include "shell.h"

/**
 * _putchar - write one character c to stdout
 * @chr:  character will be print
 *
 * Return: On success 1.
 * if error, -1 , and errno is set suitable.
 */
int _putchar(char chr)
{
	return (write(1, &chr, 1));
}
/**
 * _strngcpy - copy string
 * @dst:char
 *  @surc:char
 * @ntgr:int
 * Return:char
 */

char *_strngcpy(char *dst, char *surc, int ntgr)
{
int vr;

vr = 0;
	while (vr < ntgr && *(surc + vr))
	{
	*(dst + vr) = *(surc + vr);
	vr++;
	}
	while (vr < ntgr)
	{
	*(dst + vr) = '\0';
	vr++;
	}
	return (dst);
}

/**
 * _strlnght - string lenght
 * @str:char
 * Return:int
 */

int _strlnght(char *str)
{
	int vr;

		for (vr = 0; str[vr] != '\0'; vr++)
		{
			continue;
		}
return (vr);
}

/**
 * _atoi - change to a int
 * @str:string
 * Return:int
 */
int _atoi(char *str)
{
int i, j, v, z;

	i = v = 0;
	z = 1;
	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			z *= -1;
		i++;
	}
	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		v = (v * 10) + z * ((str[j]) - '0');
		j++;
	}
	return (v);
}
/**
 * _puts - print  string
 * @strng:pointer charater
 * return:void
 */
void _puts(char *strng)
{
	int vr;

	for (vr = 0; strng[vr] != '\0'; vr++)
	{
		_putchar(strng[vr]);
	}
_putchar('\n');
return;
}
