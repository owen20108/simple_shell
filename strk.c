#include "shell.h"
/**
 * test_delimtr - test Character Matchs other Char *
 * @ca: Character To test
 * @strng: String To test
 * Return: 1 Succes, 0 Failed
 */
unsigned int test_delimtr(char ca, const char *strng)
{
	unsigned int i;

	for (i = 0; strng[i] != '\0'; i++)
	{
		if (ca == strng[i])
			return (1);
	}
	return (0);
}

/**
 * _strok- Token  String will be Token
 * @strng: a String
 * @delimtr: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strok(char *strng, const char *delimtr)
{
	static char *tos;
	static char *t;
	unsigned int i;

	if (strng != NULL)
		t = strng;
	tos = t;
	if (tos == NULL)
		return (NULL);
	for (i = 0; tos[i] != '\0'; i++)
	{
		if (test_delimtr(tos[i], delimtr) == 0)
			break;
	}
	if (t[i] == '\0' || t[i] == '#')
	{
		t = NULL;
		return (NULL);
	}
	tos = t + i;
	t = tos;
	for (i = 0; t[i] != '\0'; i++)
	{
		if (test_delimtr(t[i], delimtr) == 1)
			break;
	}
	if (t[i] == '\0')
		t = NULL;
	else
	{
		t[i] = '\0';
		t = t + i + 1;
		if (*t == '\0')
			t = NULL;
	}
	return (tos);
}
