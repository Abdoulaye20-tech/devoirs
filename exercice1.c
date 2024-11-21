#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
	int n,m,opt;
	while((opt=getopt(argc,argv,"f:g"))!=-1){
		switch(opt){
		case'f':
			n=atoi(optarg);
			break;
		case 'g':
			m=atoi(optarg);
			break;
		case '?':
			fprintf(stderr, "Usage: %s -f entier ou -g entier\n",argv[0]);
			return 1;
		}
	}

	if(optind>=argc){
		fprintf(stderr,"Erreur :Aucun entier n'a été fourni");
		return 1;
	}

	int resultat=1;
	if(n!=0){
		for(int i=0;i<n;i++){
			resultat=resultat^2;
		}
		printf("f(%d)=%d\n",n,resultat);
	}
	if(m!=0){
		resultat=2*m;
		printf("f(%d)=%d\n",m,resultat);
	}
	return 0;
}