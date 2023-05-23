#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
	char *_lineptr = NULL, *mytoken;
	char prompt_sign[] = "$ ";
	size_t n = 0;
	ssize_t ret_getline;

	while (1)
	{
		printf("%s", prompt_sign);
		ret_getline =  getline(&_lineptr, &n, stdin);
		if (ret_getline == -1)
			break;
		if (ret_getline == 1)
			continue;
		
		mytoken = strtok(_lineptr, " ");
		printf("%s\n",mytoken);
	}

	return (0);
}
