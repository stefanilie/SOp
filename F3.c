#include <stdio.h>
#include <stdlib.h>

struct prim
{
	int nNumber;
	int nPower;
};

int isPrime(int x)
{
	int d;
	for(d=2; d<=x/2; d++)
	{
		if(x%d == 0)
		{
			return -1;
		}
	}		
	return 1;
}

void main(int argc, char *argv[])
{
	int nNumber, nBackup = 0, i=0;
	struct prim objPrime;
	char *moloz, *endptr; 

	moloz = argv[1];

	nNumber = strtol(moloz, &endptr, 10);

//	printf("Insert numeber:");
//	scanf("%d", &nNumber);
	nBackup = nNumber;

	if (isPrime(nNumber)==1)
	{
		printf("\n\n");
		printf("Numarul este prim! :");
		printf("%d", nNumber);
		printf("\n\n");
	}
	else
	{
		for(i=2; i<nBackup; i++)
		{
			if(isPrime(i))
			{
				objPrime.nNumber = i;
				objPrime.nPower = 0;
				while (nNumber != 1)
				{
					if(nNumber % objPrime.nNumber == 0)
					{
						while(nNumber % objPrime.nNumber == 0)
						{
							nNumber = nNumber / objPrime.nNumber;
							objPrime.nPower ++;
						}
						printf("%d", objPrime.nNumber);
						if(objPrime.nPower != 1)
						{
							printf("^");
							printf("%d", objPrime.nPower);
							if(nNumber != 1)
								printf(" * ");
						}
						else 
						{
							if(nNumber != 1)
								printf(" * ");
						}
					}
					else break;
				}
			}
		}
	}
	printf("\n\n");
}

