#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int halt=0;
int sigstop;

void h(int n)
{
	signal(n, h);
	if(n == 19)
	{
		sigstop = 1;
	}
	else
	{
		halt = ;
	}
}

int main()
{
	signal(SIGALRM, h);
	alarm(2);
	signal(SIGSTOP, h);
	printf("Pending...");
	if(sigstop == 1)
	{
		printf("nu s-a intrat in while");
		return 20;
	} 
	while(!halt)
	{
		printf(".");
	}
	alarm(0);
	return 1;
}
