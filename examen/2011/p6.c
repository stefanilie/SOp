/*6. Scrieți o funcție C double myFunct(char *f, double *vec, int n, int *err) unde `f` este numele unui fișier ce conține în format binar elemente de tip double, iar `n` numărul de elemente din `vec`. Funcția returnează produsul scalar dintre `vec` și vectorul format din primele `n` elemente din `f`. Dacă sunt mai puțin de `n` elemente în `f`, atunci elementele lipsă vor fi considerate ca având valoarea `0.0`. `err` este parametru de ieșire și va avea valoarea `0` în caz de success și `-1` în caz de eroare. */
#include <stdio.h>
#include <stdlib.h>
double myFunct(char *f, double *vec, int n, int *err)
{
	FILE *ff;
	int i;
	double prod=0, m;
	if ((ff=fopen(f, "rb"))==NULL)
	{
		*err=-1;
		return -1;
	}//if
	for (i=0; i<n; i++)
	{
		if (fread((void*)(&m), sizeof(m), 1, ff)<1)
		{
			*err=-1;
			return -1;
		}//if
		prod+=m*(*(vec+i));		
	}//for i
	*err=0;
	return prod;
}//myFunct

int main(int argc, char *argv[])
{
	double d, v[100];
	int err, i;
	if (argc<2)
	{
		fprintf(stderr, "Nr insuficient de argumente\n");
		return -1;
	}//if
	for (i=0; i<(argc-1); i++)
		v[i]=atof(argv[i+1]);
	d=myFunct("p6.in", v, argc-1, &err);
	if (err==-1)
		printf("Eroare\n");
	else
		printf("%f\n", d); 
	return 0;
}//main
