#ifndef _SHELL_H
#define _SHELL_H

/** env var */

extern char **environ;

/** buffersize */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRNTR(c) (write(STDOUT_FILENO, c, _strlnght(c)))

/** Libraries  */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/**  string functions */

char *_strtok(char *str, const char *tok);
char *_strok(char *strng, const char *delimtr);
unsigned int test_delimtr(char ca, const char *strng);
char *_strncpy(char *dest, char *src, int n);

int _strlnght(char *str);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strcomp(char *str1, char *str2);
int _isalphbt(int c);
void array_rvrs(char *arr, int lngth);
int intlngth(int numb);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strngcat(char *dst, char *sorc);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strngcmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
char *_strngdup(char *str);

/** memory mange*/

void free_env(char **env);
void *fll_an_arr(void *a, int el, unsigned int lnght);
char *_memocpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_relloc(void *pntr, unsigned int o_sze, unsigned int n_sze);
void free_all(char **input, char *line);
void free_allc(char **cmnd, char *lne);

/** input function */

void prompt(void);
void prmpt(void);
void signal_to_handel(int sig);
char *_getline(void);
char *_gtlne(void);

/**  Command analyzer */

int path_cmd(char **line);
int pth_cmnd(char **cmnd);
char *_getenv(char *name);

char **anlyze_cmnd(char *inpt);
int handle_builtin(char **cmd, int er);
int handler_shell(char **cmnd, int r);
void read_file(char *filename, char **argv);
void rd_fle(char *flename, char **argv);
char *bld(char *token, char *value);
int check_shll(char **cmnd);
void creat_envi(char **envi);
int test_cmnd(char **cmnd, char *inpt, int c, char **argv);
int check_cmd(char **tokens, char *line, int count, char **argv);
void trt_fle(char *line_f, int count, FILE *flp, char **argv);
void exit_shl_fr_fle(char **cmnd, char *line_f, FILE *fd);

/** shell functions*/

void hshtg_hndl(char *buff);
int history(char *input);
int hstry(char *inpt);
int hstory_ds(char **cmd, int er);

int dsp_env(char **cmd, int er);

int chng_dir(char **cmnd, int r);

int dsp_hlp(char **cmd, int er);
int ech_shll(char **cmd, int er);
void  exit_shell(char **cmnd, char *inpt, char **argv, int ca);
int print_echo(char **cmd);
int prnt_ech(char **cmd);

/** error displays and Print function */
void print_number(unsigned int n);
void prnt_numb(unsigned int uns);
void print_number_in(int n);
void prnt_numb_in(int n);
void print_error(char *line, int c, char **argv);
void prnt_err(char *input, int counter, char **argv);
void _prnterror(char **argv, int c, char **cmnd);


/**
 * struct cmd_finder - finds cmd and execute function
 * @cmd:pointer to charater
 * @func:func to excute if finder true
 */

typedef struct  cmd_finder
{
	char *cmd;
	int (*func)(char **line, int er);
} cmd_f;

#endif
