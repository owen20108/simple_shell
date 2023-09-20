#include "shell.h"

/**
 * prmpt - show Shell prmpt
 */
void prmpt(void)
{
	PRNTR("$ ");
}
/**
 * prnt_err - show Error rely on shell loop
 * @input:User prompt
 * @counter:Simple Shell Counter
 * @argv: Name of Program
 * Return: Void
 */
void prnt_err(char *input, int counter, char **argv)
{
	char *er;

	PRNTR(argv[0]);
	PRNTR(": ");
	er = _itoa(counter);
	PRNTR(er);
	free(er);
	PRNTR(": ");
	PRNTR(input);
	PRNTR(": not found\n");
}
