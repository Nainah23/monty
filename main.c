#include "monty.h"

char **op_toks = NULL;
/**
 * main - entry point
 * @argc: argument count
 * @argv: array pointer of char *args
 * Return: (EXIT_SUCCESS) success, (EXIT_FAILURE) fail
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (err_usage());
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (err_fileOpen(argv[1]));
	exit_code = monty_exec(fd);
	fclose(fd);
	return (exit_code);
}
