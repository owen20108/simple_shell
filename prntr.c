#include "shell.h"
/**
 * prnt_numb -Print Unsigned Intger with Putchar
 * @uns: Unisigned Integer
 * Return: Void
 */
void prnt_numb(unsigned int uns)
{
	unsigned int x = uns;

	if ((x / 10) > 0)
		prnt_numb(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * prnt_numb_in -Print Number into Putchar
 * @n:Integer
 * Return: void
 */
void prnt_numb_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		prnt_numb(x / 10);

	_putchar(x % 10 + '0');
}
