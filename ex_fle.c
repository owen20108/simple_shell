#include "shell.h"
/**
 * rd_fle - Read prompt From File
 * @flename:name of file
 * @argv:Program Name
 * Return: -1 or  0
 */

void rd_fle(char *flename, char **argv)
{
	FILE *flp;
	char *line_f = NULL;
	size_t lngth = 0;
	int count = 0;

	flp = fopen(flename, "r");
	if (flp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line_f, &lngth, flp)) != -1)
	{
		count++;
		trt_fle(line_f, count, flp, argv);

	}
	if (line_f)
		free(line_f);
	fclose(flp);
	exit(0);
}
/**
 * trt_fle - analyzer test Command Fork Wait Excute in Line of File
 * @line_f: line of File
 * @count:Error count
 * @flp: Descriptor of File
 * @argv:Program Name
 * Return : Excute A line void
 */
void trt_fle(char *line_f, int count, FILE *flp, char **argv)
{
	char **cmnd;
	int s = 0;

	cmnd = anlyze_cmnd(line_f);

		if (_strngcmp(cmnd[0], "exit", 4) == 0)
		{
			exit_shl_fr_fle(cmnd, line_f, flp);
		}
		else if (check_shll(cmnd) == 0)
		{
			s = handler_shell(cmnd, s);
			free(cmnd);
		}
		else
		{
			s = test_cmnd(cmnd, line_f, count, argv);
			free(cmnd);
		}
}
/**
 * exit_shl_fr_fle - end Shell Case  File
 * @line_f: Line of A File
 * @cmnd: analyzer Command
 * @fd:File Description
 * Return : Case Of Exit in A File line_f
 */
void exit_shl_fr_fle(char **cmnd, char *line_f, FILE *fd)
{
	int statu, x = 0;

	if (cmnd[1] == NULL)
	{
		free(line_f);
		free(cmnd);
		fclose(fd);
		exit(errno);
	}
	while (cmnd[1][x])
	{
		if (_isalphbt(cmnd[1][x++]) < 0)
		{
			perror("illegal number");
		}
	}
	statu = _atoi(cmnd[1]);
	free(line_f);
	free(cmnd);
	fclose(fd);
	exit(statu);



}
