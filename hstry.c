#include "shell.h"
/**
 * hstry - Fill File from User prompt
 * @inpt: User Input
 * Return: -1 Fail 0 Succes
 */
int hstry(char *inpt)
{
	char *flenme = ".simple_shell_history";
	ssize_t fd, w;
	int lngth = 0;

	if (!flenme)
		return (-1);
	fd = open(flenme, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (inpt)
	{
		while (inpt[lngth])
			lngth++;
		w = write(fd, inpt, lngth);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_en - Frees Enviro Variable list
 * @env:  Environment variables.
 * Return: Void
 */
void free_en(char **env)
{
	int x;

	for (x = 0; env[x]; x++)
	{
		free(env[x]);
	}
}
