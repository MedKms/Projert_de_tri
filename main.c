#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Tri1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *f;
	void (*ptr[])(int*,int)={tri_Bulle,tri_insertion,tri_selection,tri_shell,tri_rapide,tri_permutation};
	int i,j,k=0,*t,*a;
	float Table[NTaille/1000][6];
	for(i=1000;i<=NTaille;i+=1000,k++)
	{
		t=(int *)malloc(i*sizeof(int));
		a=(int *)malloc(i*sizeof(int));
		remplire(t,i);
		affecter(t,a,i);
		for(j=0;j<6;j++)
		{
		Table[k][j]=getTemps(ptr[j],a,i);
		affecter(t,a,i);
	    }
	    printf("%d    ",i);
	}
	f=fopen("C:\\Users\\G\\Desktop\\Dossier\\Mini_Projet(MOHAMED & SADIKI)\\data1.txt","w");
	for(i=0;i<NTaille/1000;i++)
	{
		fprintf(f,"%d\t",(i+1)*1000);
		for(j=0;j<6;j++)
		fprintf(f,"%f\t",Table[i][j]);
		fprintf(f,"\n");
	}
	return 0;
}

