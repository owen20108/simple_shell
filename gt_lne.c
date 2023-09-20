#include "shell.h"

/**
* _gtlne - Read The prompt from User in Stdin
* Return: Input
*/
char *_gtlne()
{
int i, bufsize = BUFSIZE, rd;
char c = 0;
char *buff = malloc(bufsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= bufsize)
		{
			buff = _relloc(buff, bufsize, bufsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	hshtg_hndl(buff);
	return (buff);
}

/**
 * hshtg_hndl - remove anu after #
 * @buff: input;
 * Return:void
 */
void hshtg_hndl(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
