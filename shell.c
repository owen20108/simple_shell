#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *inpt, **cmnd;
	int count = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		rd_fle(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (statue)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prmpt();
		inpt = _gtlne();
		if (inpt[0] == '\0')
		{
			continue;
		}
		hstry(inpt);
		cmnd = anlyze_cmnd(inpt);
		if (_strcomp(cmnd[0], "exit") == 0)
		{
			exit_shell(cmnd, inpt, argv, count);
		}
		else if (check_shll(cmnd) == 0)
		{
			st = handler_shell(cmnd, st);
			free_allc(cmnd, inpt);
			continue;
		}
		else
		{
			st = test_cmnd(cmnd, inpt, count, argv);

		}
		free_allc(cmnd, inpt);
	}
	return (statue);
}
/**
 * check_shll - check shell
 *
 * @cmnd:command to test
 * Return: 0 Succes -1 Fail
 */
int check_shll(char **cmnd)
{
	cmd_f fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmnd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->cmd)
	{
		if (_strcomp(cmnd[0], (fun + i)->cmd) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 *crt_env - Create list of Enviroment Variable
 * @env: list of Enviroment Variable
 * Return: Void
 */
void crt_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strngdup(environ[i]);
	env[i] = NULL;
}
