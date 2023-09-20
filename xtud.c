#include "shell.h"

/**
 * handler_shell -  shell Command handeler
 * @cmnd: analyze Command
 * @r:statue last Excute
 * Return: -1 for Fail 0  for Succes
 */

int handler_shell(char **cmnd, int r)
{
	 cmd_f bil[] = {
		{"cd", chng_dir},
		{"env", dsp_env},
		{"help", dsp_hlp},
		{"echo", ech_shll},
		{"history",  hstory_ds},
		{NULL, NULL}
	};
	int x = 0;

	while ((bil + x)->cmd)
	{
		if (_strcomp(cmnd[0], (bil + x)->cmd) == 0)
		{
			return ((bil + x)->func(cmnd, r));
		}
		x++;
	}
	return (-1);
}
/**
 * test_cmnd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmnd:Parsed Command
 * @inpt: User prompt
 * @c:Shell Excution Time Case of prompt Not exist
 * @argv: Name of Program
 * Return: 1 if prompt Null -1 Wrong prompt 0 prompt Excuted
 */
int test_cmnd(char **cmnd, char *inpt, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmnd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strngcmp(*cmnd, "./", 2) != 0 && _strngcmp(*cmnd, "/", 1) != 0)
		{

			pth_cmnd(cmnd);
		}

		if (execve(*cmnd, cmnd, environ) == -1)
		{
			prnt_err(cmnd[0], c, argv);
			free(inpt);
			free(cmnd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handler ^C
 * @signl:Captured Signal
 * Return: Void
 */
void signal_to_handel(int signl)
{
	if (signl == SIGINT)
	{
		PRNTR("\n$ ");
	}
}
