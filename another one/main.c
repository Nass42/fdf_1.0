#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigststp(int sig)
{
	printf("Intercept signal\n");
}

int main(int ac, char **av)
{
	signal(SIGINT, handle_sigststp);
	while (1);
	return 0;
}