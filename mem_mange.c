#include "shell.h"

/**
 **_relloc -  Realloc  Memory Block with Malloc And Free
 *@pntr: Pointer
 *@o_sze: old Size Of The Pointer
 *@n_sze: New Size Of The Pointer
 *Return: Void Pointer Rellocated
 */
void *_relloc(void *pntr, unsigned int o_sze, unsigned int n_sze)
{
	void *result;

	if (n_sze == o_sze)
		return (pntr);
	if (n_sze == 0 && pntr)
	{
		free(pntr);
		return (NULL);
	}
	result = malloc(n_sze);
	if (result == NULL)
		return (NULL);
	if (pntr == NULL)
	{
		fll_an_arr(result, '\0', n_sze);
		free(pntr);
	}
	else
	{
		_memocpy(result, pntr, o_sze);
		free(pntr);
	}
	return (result);

}
/**
 * free_allc - Free list Of Char Pointer and Char Pointer
 * @cmnd:list of Pointer
 * @lne:Char Pointer
 * Return: Void
 */
void free_allc(char **cmnd, char *lne)
{
	free(cmnd);
	free(lne);
	cmnd = NULL;
	lne = NULL;
}

/**
 * _memocpy - Copy Byte From Source To location
 * @dest: Destination for  Pointer
 * @src: Source Pointer
 * @n: Size of copies
 *Return: Void Pointer
 */
char *_memocpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fll_an_arr - Fill An list By Constant Byte
 * @a:Void Pointer
 * @el: Intger
 * @lnght:Length Intger
 *Return: Void Pointer
 */
void *fll_an_arr(void *a, int el, unsigned int lnght)
{
	char *p = a;
	unsigned int i = 0;

	while (i < lnght)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _callc -  Allocate Memory For An list, Using Malloc.
 * @sze: Size
 * Return: Void Pointer
 */
void *_callc(unsigned int sze)
{
	char *a;
	unsigned int i;

	if (sze == 0)
	return (NULL);
	a = malloc(sze);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < sze; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
