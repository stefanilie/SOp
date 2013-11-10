#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	if(argc != 3){
		fprintf(stderr, "Utilizare: %s numele caracterului si numele fisierului \n", argv[0]);
		return 1;
	}

	char moloz; 
        FILE *f;
        f = fopen(argv[2], "r");
        if(!f){
           perror(argv[2]);
        }
        
        moloz = argv[1][0];


        	
	int counter = 0, i;
        
        while(!feof(f)){
        char *ceva;
        fscanf(f, "%s\n\n\n", ceva);
        printf("%s", ceva);
	int lenght = strlen(ceva);
	   for(i = 0;i<lenght; i++){
               if(ceva[i] == moloz)
                   counter++;
           }
        }

        fclose(f);           
        printf("Numarul aparitii al lui %c %d", moloz, counter);


	return 0;
}
