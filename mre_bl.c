#include "shell.h"

/**
 * hstory_ds - show History Of User prompt Simple Shell
 * @c:analyze Command
 * @s:Statue Of Last Exe
 * Return: 0 Succes -1 Fail
 */
int hstory_ds(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *flenme = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t lngth = 0;
	int count = 0;
	char *r;

	fp = fopen(flenme, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &lngth, fp)) != -1)
	{
		count++;
		r = _itoa(count);
		PRNTR(r);
		free(r);
		PRNTR(" ");
		PRNTR(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * prnt_ech - Excute  Echo
 * @cmd: analyze Command
 * Return: 0 Succes -1 Fail
 */
int prnt_ech(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
