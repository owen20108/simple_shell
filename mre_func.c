#include "shell.h"
/**
 * _strcpy - Copy Source To location Character
 * @dst:location
 * @sorc:Source0
 * Return: Copy Of Char *
 */
char *_strcpy(char *dst, char *sorc)
{
int i;

i = 0;
	while (sorc[i])
	{
		dst[i] = sorc[i];
		i++;
	}
dst[i] = '\0';
return (dst);
}
/**
 * _strngcat - Concation Two Strings
 * @dst:1st String
 * @sorc:2nd String
 * Return:Concation Two Strings Char *
 */
char *_strngcat(char *dst, char *sorc)
{
	char *s = dst;

	while (*dst != '\0')
	{
		dst++;
	}

	while (*sorc != '\0')
	{
		*dst = *sorc;
		dst++;
		sorc++;
	}
	*dst = '\0';
	return (s);
}
/**
 * _strngchr - Location Character  String
 * @s:String Search Inside
 * @c:Char To Search about
 * Return: Pointer for Char*
 */
char *_strngchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * _strngcmp - Compare numbers Of Characters for Two Strings.
 * @str1: A String.
 * @str2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strngcmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strngdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *_strngdup(char *str)
{
	size_t lnght, i;
	char *str2;

	lnght = _strlnght(str);
	str2 = malloc(sizeof(char) * (lnght + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= lnght; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
