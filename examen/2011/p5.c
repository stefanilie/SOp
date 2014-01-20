/*
    Se consideră definiția de mai jos. Scrieți o funcție C MYSTR *myFunct(char *dir, int *n) care construiește un vector de structuri `MYSTR` ce conțin fiecare numele fișierelor și caracteristicile i-nodurilor din directorul cu numele `dir`. `n` comtinre (sic) numărul de elemente din `vec`. Se întoarce `NULL` în caz de eroare. (in `n` se va afla numarul de fisiere. Tu trebuie sa il aflii, nu iti este dat.) 

 typedef struct  
 {  
     char name[NAME_MAX];  
     struct stat st;  
 } MYSTR;  
*/
#define NAME_MAX 50
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
typedef struct  
 {  
     char name[NAME_MAX];  
     struct stat st;  
 } MYSTR;  
 
MYSTR *myFunct(char *dir, int *n)
{
	MYSTR **rez;
	struct stat s;
	DIR *d;
	struct dirent *dd;
	char cale[256], specificator[256];
	*n=0;
	if ((d=opendir(dir))==NULL)
		return NULL;
	strcpy(cale, dir);
	if (cale[strlen(cale)-1]!='/')
		strcat(cale, "/");
	while ((dd=readdir(d))!=NULL)
	{
		strcpy(specificator, cale);
		strcat(specificator, dd->d_name);
		if (stat(specificator, &s)==-1)
		{
			closedir(d);
			return NULL;
		}//if
		if (!S_ISDIR(s.st_mode))
		{
			strcpy(((*rez+*n))->name, dd->d_name);
			(*rez+*n)->st=s;
			(*n)++;
		}//if
	}//while
	return *rez;
}//myFunct
 
int main(int argc, char *argv[])
{
  if (argc!=2)
  {
    fprintf(stderr, "Numar incorect de parametri. Utilizare : %s director\n", argv[0]);
    return -1;
  }//if
  MYSTR *m;
  int n, i;
  if ((m=myFunct(argv[1], &n))==NULL)
  	printf("EROARE\n");
  else
  {
  	MYSTR **mm=&m;	
  	printf("%d\n", n);
    for (i=0; i<n; i++)
  	  printf("%s %d\n", (*mm+i)->name, (*mm+i)->st.st_size);
  }//else
  return 0;
}//main
