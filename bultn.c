#include "shell.h"
/**
 * exit_shell - Exit Statue Shell
 * @cmnd: analyze Command
 * @inpt: User prompt
 * @argv:Name ofProgram
 * @ca:do Counter
 * Return: Void (Exit Statue)
 */
void  exit_shell(char **cmnd, char *inpt, char **argv, int ca)
{
	int statue, i = 0;

	if (cmnd[1] == NULL)
	{
		free(inpt);
		free(cmnd);
		exit(EXIT_SUCCESS);
	}
	while (cmnd[1][i])
	{
		if (_isalphbt(cmnd[1][i++]) != 0)
		{
			_prnterror(argv, ca, cmnd);
			break;
		}
		else
		{
			statue = _atoi(cmnd[1]);
			free(inpt);
			free(cmnd);
			exit(statue);
		}
	}
}


/**
 * chng_dir - Change Dirctory
 * @cmnd: analyze Command
 * @r: Statue Last Command that Exe
 * Return: 0 for Succes 1 for Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int chng_dir(char **cmnd, __attribute__((unused))int r)
{
	int val = -1;
	char cw[PATH_MAX];

	if (cmnd[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strcomp(cmnd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmnd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cw, sizeof(cw));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cw, 1);
	}
	return (0);
}
/**
 * dsp_env - show Enviroment Var
 * @cmnd:analyze Command
 * @r:Statue of Last command Exe
 * Return:Always 0
 */
int dsp_env(__attribute__((unused)) char **cmnd, __attribute__((unused)) int r)
{
size_t b;
	int lnght;

	for (b = 0; environ[b] != NULL; b++)
	{
		lnght = _strlnght(environ[b]);
		write(1, environ[b], lnght);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * dsp_hlp - show Help For shell
 * @cmnd:analyze Command
 * @r: Statue  Last Command Exe
 * Return: 0 Succes -1 Fail
 */
int dsp_hlp(char **cmnd, __attribute__((unused))int r)
{
	int f, w, d = 1;
	char c;

	f = open(cmnd[1], O_RDONLY);
	if (f < 0)
	{
		perror("Error");
		return (0);
	}
	while (d > 0)
	{
		d = read(f, &c, 1);
		w = write(STDOUT_FILENO, &c, d);
		if (w < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * ech_shll - Exe Cases of Echo
 * @st:Statue Of Last Command Exe
 * @cmnd: analyze Command
 * Return: Always 0 Or Excute Normal Echo
 */
int ech_shll(char **cmnd, int st)
{
	char *pth;
	unsigned int  pid = getppid();

	if (_strngcmp(cmnd[1], "$?", 2) == 0)
	{
		prnt_numb_in(st);
		PRNTR("\n");
	}
	else if (_strngcmp(cmnd[1], "$$", 2) == 0)
	{
		prnt_numb(pid);
		PRNTR("\n");

	}
	else if (_strngcmp(cmnd[1], "$PATH", 5) == 0)
	{
		pth = _getenv("PATH");
		PRNTR(pth);
		PRNTR("\n");
		free(pth);

	}
	else
		return (prnt_ech(cmnd));

	return (1);
}
