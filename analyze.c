#include "shell.h"

/**
 * anlyze_cmnd - analyze  input Line
 * @inpt:User Input To analyze
 * Return: list Of Char
 */
char **anlyze_cmnd(char *inpt)
{
	char **tokens;
	char *token;
	int i, bufsize = BUFSIZE;

	if (inpt == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strok(inpt, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
