#include <stdio.h>
int main(int argc, char* argv[])
{
  FILE *f;
  FILE *g;
  double x;
  int i;
  if (argc!=3)
  {
    fprintf(stderr, "Numar incorect de parametri.  Utilizare : %s fisier1 fisier2\n", argv[0]);
    return 1;
  }//if
  f=fopen(argv[1], "r");
  if (f==NULL)
  {
    perror(argv[1]);
    return 1;
  }//if
  g=fopen(argv[2], "wb");
  if (g==NULL)
  {
    perror(argv[2]);
    fclose(f);
    return 1;
  }//if
  //while (!feof(f))
  for (i=0; i<4; i++)
  {
  	fscanf(f, "%lf", &x);
  	printf("%lf ", x);
  	fwrite((void*)(&x), sizeof(x), 1, g); 
	}//while
	printf("\n");
	fclose(f);
  fclose(g);
  g=fopen(argv[2], "rb");
	for (i=0; i<4; i++)
	{
		fread((void*)(&x), sizeof(x), 1, g);
		printf("%f ", x);
  }//for i
  printf("\n");
  fclose(g);  
}//main
