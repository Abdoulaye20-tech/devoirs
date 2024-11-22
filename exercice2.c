#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void afficher(int matrice[l][c],int l, int c) {
    for (int i=0;i<l;i++) {
        for (int j=0;j<c;j++) {
            printf("%d",matrice[i][j]);
        }
        printf("\n");
    }
}
void aleatoire(int matrice[l][c],int l,int c,int min,int max) {
    for (int i=0;i<l;i++) {
        for (int j=0;j<c;j++) {
            matrice[i][j]=min+rand()%(max-min+1);
        }
    }
}

int main(int argc,char *argv[]){
	int opt;
	int l1,c1,l2,c2,min=1,max=100;
	char *filename1=NULL,*filename2=NULL,filename3=NULL,filename4=NULL;
    int line_number = 1;
	srand(time(NULL));
	while((opt=getopt(argc,argv,"abc:dtf"))!=-1){
		switch(opt){
			case 'c':
				l1=c1=rand()%10;	
			case 'd':
				l2=c2=atoi(optarg);
				break;
			case 'a':
				filename1=optarg;
				break;
			case 'b':
				filename2=optarg;
				break;
			case 't':
				filename3=optarg;
				break;
			case 'f':
				filename4=optarg;
				break;
			case '?':
				fprintf(stderr, "Usage: %s [-f entier] ou [-g entier]\n",argv[0]);
				return 1;	
		}
	}

	if(l1<=0||c1<=0){
		printf("Erreur: veiller saisir de nouveau dimension\n");
		return 1;
	}
	int matrice1[l1][c1];
	aleatoire(matrice1,l1,c1,min,max);
	afficher(matrice[l1][c1],l1,c1);

	if(l2<=0||c2<=0){
		printf("Erreur: veiller saisir de nouveau dimension\n");
		return 1;
	}
	int matrice2[l2][c2];
	aleatoire(matrice2,l2,c2,min,max);
	afficher(matrice[l2][c2],l2,c2);

	if(filename1==NULL){
		fprintf(stderr,"Le fichier n'est pas spécifié\n");
		exit(EXIT_FAILURE);
	}
	FILE*fp1=fopen(filename1,"r");
	if(fp1==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char *line=NULL;
	size_t len=0;
	ssize_t read;
	while((read=getline(&line,&len,fp))!=-1){
		printf("%d: %s",line_number++,line);
	}
	free(line);
	fclose(fp1);

	if(filename2==NULL){
		fprintf(stderr,"Le fichier n'est pas spécifié\n");
		exit(EXIT_FAILURE);		
	}
	FILE*fp2=fopen(filename2,"r");
	if(fp2==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	int c;
	while((c=fgetc(fp2))!=EOF){
		printf("%02x",c);
	}
	fclose(fp2);

	FILE*fp3=fopen(filename3,"r");
	if(fp3==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char ligne[100]; // Tampon pour stocker une ligne
    while (fgets(ligne, sizeof(ligne),fp3) != NULL) {
        printf("%s", ligne);
    }
    fclose(fp3);

    FILE*fp4=fopen(filename4,"r");
	if(fp4==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char ligne[100]; // Tampon pour stocker une ligne
    while (fgets(ligne, sizeof(ligne), fp4) != NULL) {
        printf("%s", ligne);
    }
    fclose(fp4);
	return 0;
}