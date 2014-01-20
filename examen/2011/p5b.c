MYSTR *myFunct(char *dir, int *n)
 {
  DIR *pd;
  if ((pd=opendir (dir))==NULL)
  {
     printf ("Directorul nu exista");
     return NULL;
  }
  
 MYSTR *p=NULL;
 
  
  struct dirent *fiuD;
   while ((fiuD=readdir (pd))!=NULL)//cat timp are fii
   {
    *n+=1;
    char a[100]="asdasdsf";
    p=(MYSTR *)realloc (p,*n*sizeof (MYSTR));
    strcpy (p[(*n)-1].name,fiuD->d_name);
    strcpy (a,dir);
    strcat (a,"\\");
    strcat (a,fiuD->d_name);
    
    if (stat (a,&(p[(*n)-1].st))==-1) 
     return NULL;
     
   
   }
        return p;  
 }
