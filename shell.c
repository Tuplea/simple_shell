#include "main.h"

/**
 *  * main - Entry point
 *   * @ac: Argument count
 *    * @argv: Argument vector
 *     *
 *      * Return: 0 on success, otherwise 1
 *       */
int main(int ac, char **argv)
{
	char *user_input, **receive_argv;
	ssize_t fd_check;
	int i, execution_status, cd_result;
	data_shell shell_data;

	shell_data._environ = environ;
	(void)ac;
	(void)argv;

	while (1 == 1)
	{
	user_input = NULL;
	fd_check = 0;
	user_input = prompt_read(&fd_check);
	receive_argv = tokenization(user_input, receive_argv, fd_check);													if (receive_argv[0] == NULL)
	continue;
	if (_strcmp(receive_argv[0], "env") == 0)
	{
	free(user_input);
	_env(&shell_data);
	continue;
	}
	if (_strcmp(receive_argv[0], "exit") == 0)
	handle_exit(user_input, receive_argv);
	if (_strcmp(receive_argv[0], "cd") == 0)
	{
		cd_result = cd_command(receive_argv);
		if (cd_result == -1)
			print_error(receive_argv, "cd failed\n");
		continue;
	}
	i = handle_env_commands(receive_argv);
	if (i != 0)
	{
		free(user_input);
		free_array(receive_argv);
		continue;
	}
	execution_status = execute_command(receive_argv);
	if (execution_status == 1)
		print_error(receive_argv, "Command not found\n");
	free(user_input);
	free_array(receive_argv);
	}
	return (0);
}
