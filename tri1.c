#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "Tri1.h"
void affiche(int *t,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",*(t+i));
};
void tri_insertion(int* t,int n)
{
    int i, j;
    int en_cours;
 
    for (i = 1; i < n; i++) {
        en_cours = t[i];
        for (j = i; j > 0 && t[j - 1] > en_cours; j--) {
            t[j] = t[j - 1];
        }
        t[j] = en_cours;
    }
};
void tri_selection(int *tableau, int n)
{
     int en_cours, plus_petit, j, temp;
 
     for (en_cours = 0; en_cours <n- 1; en_cours++)
     {
         plus_petit = en_cours;
         for (j = en_cours ; j < n; j++)
              if (tableau[j] < tableau[plus_petit])
                  plus_petit = j;
          temp = tableau[en_cours];
          tableau[en_cours] = tableau[plus_petit];
          tableau[plus_petit] = temp;
     }
};
void tri_Bulle(int *tab,int N)
{
	int i,j,aux;
    for (i = 0;i<N-1;i ++ )
     for ( j = 0;j<N-i-1; j++ )
      if (tab[j] > tab[j+1])
        {
        aux= tab[j] ;
        tab [j]= tab [j+1] ;
        tab [j+1]=aux ;
       };
};
void tri_shell(int tableau[],int longueur)
     {
     int n, i, j, valeur;
     n=0;
     while(n<longueur)
         {
         n=3*n+1;
         }
     while(n!=0)
         {
         n=n/3;
         for (i=n;i<longueur;i++)
             {
             valeur=tableau[i];
             j=i;
             while((j>(n-1)) && (tableau[j-n]>valeur))
                 {
                 tableau[j]=tableau[j-n];
                 j=j-n;
                 }
             tableau[j]=valeur;
             }
         }
     };
void tri_rapide (int *tableau, int taille) {
    int mur, courant, pivot, tmp;
    if (taille < 2) return;
    // On prend comme pivot l element le plus a droite
    pivot = tableau[taille - 1];
    mur  = courant = 0;
    while (courant<taille) {
        if (tableau[courant] <= pivot) {
            if (mur != courant) {
                tmp=tableau[courant];
                tableau[courant]=tableau[mur];
                tableau[mur]=tmp;              
            }
            mur ++;
        }
        courant ++;
    }
    tri_rapide(tableau, mur - 1);
    tri_rapide(tableau + mur - 1, taille - mur + 1);
}
float getTemps(void (*pftc)(int*,int),int *t,int n)
{
     float temp;
     clock_t start,end;
     start=clock();
     pftc(t,n);
     end=clock();
     temp=(float)(end-start)/1000;
     return temp;
};   
void remplire(int *t,int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	*(t+i)=rand()%1001;
	
};
void affecter(int *t,int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	a[i]=t[i]; 
};

