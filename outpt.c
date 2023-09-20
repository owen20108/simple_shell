#include "shell.h"
/**
 *  _prnterror - Print  Error
 * @argv: Name of Program
 * @c:Error Counter
 * @cmnd:Command
 * Return: Void
 */
void _prnterror(char **argv, int c, char **cmnd)
{
	char *r = _itoa(c);

	PRNTR(argv[0]);
	PRNTR(": ");
	PRNTR(r);
	PRNTR(": ");
	PRNTR(cmnd[0]);
	PRNTR(": Illegal number: ");
	PRNTR(cmnd[1]);
	PRNTR("\n");
	free(r);
}
