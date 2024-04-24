#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magasin.h"
#include <Windows.h>
#define TAILMAX 1024
meuble creer()
{
    meuble m;
    printf("donner le code du meuble:\n");
    scanf("%d",&m.code);

     do
    {
      printf("donner le type:\n ");
      scanf("%s",m.type);
    }while(strcmp(m.type,"meuble")!=0 && strcmp(m.type,"decor")!=0  && strcmp(m.type,"couvert")!=0  && strcmp(m.type,"tableau" )!=0 && strcmp(m.type,"instrument")!=0);
    printf("donner l'epoque:\n");
    scanf("%d",&m.epoque);
    printf("donner la description:\n");
    fgets(m.description,100,stdin);
    printf("donner les dimensions:\n");
    scanf("%f",&m.dimensions[0]);
    scanf("%f",&m.dimensions[1]);
    printf("donner le prix:\n");
    scanf("%f",&m.prix);

    do
    {
      printf("donner l'etat (vendu ou non):\n");
      scanf("%s",m.vendu);
    }while(strcmp(m.vendu,"oui")!=0 && strcmp(m.vendu,"non")!=0);
    return m;
}
meuble rechercher (meuble mbs[], char artc_type[])
{
    int i;
    meuble m;
    for (i=0;i<TAILMAX;i++)
    {
        if (strcmp(mbs[i].type,artc_type)==0)
            {
            m=mbs[i];
            }
        else
           printf (" il n'excite pas un meuble de telle type");
    }
        return m;
}
void changer( meuble *m)
{
    int reponse;
    printf("\nVoulez vous changer le code (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                int nouv;
                printf ("donner le nouveau code:\n");
                scanf ("%d",&nouv);
                m->code=nouv;
            }
    printf("\nVoulez vous changer le type (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                char nouv[10];
                printf ("donner le nouveau type:\n");
                scanf ("%s",nouv);
                strcpy(m->type,nouv);
            }
    printf("\nVoulez vous changer l'epoque (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                int nouv;
                printf ("donner la nouvelle epoque :\n");
                scanf ("%d",&nouv);
                m->epoque=nouv;
            }
    printf("\nVoulez vous changer la description (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                char nouv[1024];
                printf ("donner la nouvelle description:\n");
                scanf ("%s",nouv);
               strcpy( m->description,nouv);
            }
    printf("\nVoulez vous changer la dimension (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                float nouv1,nouv2;
                printf ("donner les nouvelles dimensions:\n");
                scanf ("%f",&nouv1);
                scanf ("%f",&nouv2);
                m->dimensions[0]=nouv1;
                m->dimensions[1]=nouv2;
            }
    printf("\nVoulez vous changer le prix (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
            {
                float nouv;
                printf ("donner le nouveau prix:\n");
                scanf ("%f",&nouv);
                m->prix=nouv;
            }
    printf("\nVoulez vous changer l'etat (non:0 /oui:1)");
    scanf("%d",&reponse);
        if (reponse)
        {
                char nouv[3];
                printf ("donner le nouvel etat:\n");
                scanf ("%s",nouv);
                strcpy(m->vendu,nouv);
        }

}
void ajouter (meuble mbs[],int n, meuble m)
{
    mbs[n+1]=m;
}
float afficher(meuble mbs[])
{
    int i;
    float s=0;
    for (i=0; i<TAILMAX ;i++)
    {
       s+= mbs[i].prix;
    }
    return s;

}
void supprimer (meuble mbs[],int code)
{
    int indice=0,i,j;
    for( i=0; i<TAILMAX;i++)
     {
        if (mbs[i].code==code)
            indice =i;
     }
    for (j=indice;j<TAILMAX-1;j++)
        mbs[j]=mbs[j+1];
}
