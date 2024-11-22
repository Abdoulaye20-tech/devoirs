#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//Pour la fonction ./split nomfichcier taille
int main(int argc,char *argv[]){
	char *argvbis;
	if(argc<3){
		printf("Erreur: Nombre d'arguments insuffisants\n");
		printf("Usage: %s <nomfichier> <taille>\n",argv[0]);
		return 0;
	}
	int n=atoi(argv[2]);
	FILE *f=fopen(argv[1],"r");
	if(f==NULL){
		printf("Erreur de lecture du fichier\n");
		return 1;
	}
	char buff[n];
	while(fgets(buff,n,f)){
		argvbis=strtok(strdup(buff)," ");
		while(argvbis!=NULL){
			printf("%s\n",argvbis);
			argvbis=strtok(NULL," ");
		}
	}
	close(f);
	return 0;
}

//Pour la fonction ./split nomfichcier part1 part2 part3 part4
int main(int argc,char *argv[]){
	char buff[1024];
	if(argc<3){
		printf("Erreur: Nombre d'arguments insuffisants");
		printf("Usage: %s <nomfichier> <taille>\n",argv[0]);
		return 0;
	}
	FILE *f=fopen(argv[1],"wt");
	if(f==NULL){
		printf("Erreur d'écrire du fichier\n");
		return 1;
	}
	int i;
	for(i=2;i<argc;i++){
		FILE*fi=fopen(argv[i],"rt");
		if(fi==NULL){
			printf("Erreur de lire du fichier\n");
			fclose(f);
			return 1;
		}
		while(fgets(buff,255,fi)!=NULL){
			fputs(buff,f);
		}
		fclose(fi);
	}
	fclose(fp);
	return 0;
}