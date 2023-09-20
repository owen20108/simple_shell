#include "shell.h"

/**
 * pth_cmnd -  Search Into $PATH For Excute Command
 * @cmnd: analayze Input
 * Return: 1  Fail  0  Success.
 */
int pth_cmnd(char **cmnd)
{
	char *pth, *val, *cmnd_pth;
	struct stat buf;

	pth = _getenv("PATH");
	val = _strok(pth, ":");
	while (val != NULL)
	{
		cmnd_pth = bld(*cmnd, val);
		if (stat(cmnd_pth, &buf) == 0)
		{
			*cmnd = _strngdup(cmnd_pth);
			free(cmnd_pth);
			free(pth);
			return (0);
		}
		free(cmnd_pth);
		val = _strok(NULL, ":");
	}
	free(pth);

	return (1);
}
/**
 * bld - Build prompt
 * @token: Excute prompt
 * @value: Dirctory have prompt
 *
 * Return: analayze Full Path Of prompt Or NULL Case Failed
 */
char *bld(char *token, char *value)
{
	char *cmnd;
	size_t lngth;

	lngth = _strlnght(value) + _strlnght(token) + 2;
	cmnd = malloc(sizeof(char) * lngth);
	if (cmnd == NULL)
	{
		return (NULL);
	}

	memset(cmnd, 0, lngth);

	cmnd = _strngcat(cmnd, value);
	cmnd = _strngcat(cmnd, "/");
	cmnd = _strngcat(cmnd, token);

	return (cmnd);
}
/**
 * _getenv - Get  Value Of Enviroment Variable with Name
 * @name: Environment Name of Variable
 * Return: The Value of the Environment Variable Else NULL.
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlnght(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strngcmp(name, environ[i], nl) == 0)
		{
			vl = _strlnght(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
