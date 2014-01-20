/*Scrieti o functie C sub forma int myFunct(int *tab, int n), unde tab este o lista de identificatori a n procese fiu. Functia asteapta terminarea tuturor proceselor din tabela. Daca cel putin un proces nu s-a terminat, atunci se returneaza -1. Daca toate procesele s-au terminat, se returneaza media aritmetica a codurilor de retur. */
#include <stdio.h>
#include <sys/wait.h>
int myFunct(int *tab, int n)
{
	int ps, i, cod;
	for (i=0; i<n; i++)
	{
		waitpid(tab[i],&ps,0);
		if (WIFEXITED(ps))
			cod+=WEXITSTATUS(ps);
		else
			return -1;
	}//for i
	return (int)(cod/n);
}//myFunct

int main()
{
	int n, i, p[100];
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &p[i]);
	printf("%d\n", myFunct(p, n));
	return 0;
}//main
