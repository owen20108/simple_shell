#include "shell.h"

/**
 * _strcomp - Compares two Strings
 * @str1: frist String0
 * @str2:second String
 * Return: 0 If ideal Otherwise get Diffrence
 */
int _strcomp(char *str1, char *str2)
{
int comp = 0, i, lngth1, lngth2;
lngth1 = _strlnght(str1);
lngth2 = _strlnght(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (lngth1 != lngth2)
		return (1);
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			comp = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (comp);
}
/**
 * _isalphbt - test Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalphbt(int c)
{
if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - get Integer intTo Character
 * @n: Intger To be Convert
 * Return: Character Pointer
 */
char *_itoa(unsigned int n)
{
	int lngth = 0, i = 0;
	char *s;

	lngth = intlngth(n);
	s = malloc(lngth + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rvrs(s, lngth);
	s[i + 1] = '\0';
	return (s);
}
/**
 *  array_rvrs - Reverse Array list
 * @arr:Array list To be Reverse
 * @lngth: Array list Length
 * Return: Void
 */
void array_rvrs(char *arr, int lngth)
{
	int i;
	char temp;

	for (i = 0; i < (lngth / 2); i++)
	{
		temp = arr[i];
		arr[i] = arr[(lngth - 1) - i];
		arr[(lngth - 1) - i] = temp;
	}
}
/**
 * intlngth - get Length Of Intgwe
 * @numb:  Intger
 * Return: Length Of Intger
 */
int intlngth(int numb)
{
	int lngth = 0;

	while (numb != 0)
	{
		lngth++;
		numb /= 10;
	}
	return (lngth);
}
