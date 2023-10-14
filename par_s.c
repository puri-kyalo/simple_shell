#include "shell.h"

/**
 * is_cmd - write a function that determines if a file
 * is an executable command
 * @info: info struct
 * @path: is the path to the file.
 * Return: 1 if true, else 0.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - function that duplicates chars
 * @pathstr: PATH string.
 * @start: the starting index
 * @stop: the stopping index.
 * Return: a pointer to new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, b = 0;

	for (b = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[a++] = pathstr[a];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - function that finds this cmd in the PATH string
 * @info: is the info struct.
 * @pathstr: the PATH string.
 * @cmd: cmd to find.
 * Return: full path of cmd if found or NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
