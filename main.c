#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include "magasin.h"
#define TAILMAX 1024

int main()
{
    meuble m, mbs[TAILMAX];
    int reponse,i,n,choix, code;
    char type[10];
    float ca;
    FILE *f=NULL;
    f=fopen("magasin.txt","rt");
    if (f==NULL)
        printf("fichier_inexistant");
    else
        while (!feof(f))
        {
            fscanf(f,"%d %s %d %s %f %f %f %s",&mbs[i].code,mbs[i].type,&mbs[i].epoque,mbs[i].description,&mbs[i].dimensions[0],&mbs[i].dimensions[1],&mbs[i].prix, mbs[i].vendu );
            n++;
        }
    fclose(f);

    while(1)
        {
        system("cls");
        time_t timestamp=time(NULL);
        struct tm * timeInfos = localtime(&timestamp);
        int h, min, s, day, mois, an;
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        h = local->tm_hour;
        min = local->tm_min;
        s = local->tm_sec;
        day = local->tm_mday;
        mois = local->tm_mon + 1;
        an = local->tm_year + 1900;
        printf("\n**********************************************************************");
        printf("\n***                                                                ***");
        printf("\n***%02d:%02d:%02d            Menu                              %02d/%02d/%d*** " ,h, min,s, day, mois, an);
        printf("\n***                                                                ***");
        printf("\n**********************************************************************");
        printf("\n1) creer  une fiche pour un meuble\n");
        printf("\n2) rechercher un article selon son type\n");
        printf("\n3) changer une information pour un meuble \n");
        printf("\n4) ajouter une nouvelle vente\n");
        printf("\n5) afficher le chiffre d'affaire du magasin\n");
        printf("\n6) supprimer la fiche d'un meuble\n");
        printf("\n7) Quitter\n");
        printf("\nChoisir une option ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1: // creer une fiche
            printf("\n Combien d'article voulez vous saisir >>> \n");
            scanf("%d",&n);
            for (i=0;i<n;i++)
                mbs[i]=creer();
            break;

        case 2: // rechercher un article selon son type
           do
           {
           printf("donner le type:\n ");
           scanf("%s",type);
           }while(strcmp(type,"Meuble")==0 || strcmp(type,"decor")==0  || strcmp(type,"couvert")==0  || strcmp(type,"tableau" )==0 || strcmp(type,"instrument")==0);
            m=rechercher (mbs,type);
            break;
        case 3: //changer une information pour un meuble
            printf("\ndonner le code d'article que vous voulez changer \n");
            scanf("%d",&code);
            for (i=0;i<TAILMAX;i++)
            {
                 if (strcmp(mbs[i].code,code)==0)
                 {
                    m=mbs[i];
                    changer(&m);
                 }
                 else
                     printf("l'article a rechercher n'existe pas");
                    }

            break;
        case 4: // ajouter une nouvelle vente
            printf("donner les coordonnees de la nouvelle vente que vous voulez ajouter");
            m=creer();
            ajouter(mbs,TAILMAX,m);
            break;
        case 5:// Afficher le chiffre d'affaires
            ca=afficher(mbs);
            printf("le chiffre d'affaire est %f",ca);
            break;
        case 6:
            printf("\n donner le code d'article qui vous voulez supprimer \n");
            scanf("%d",&code);
            for (i=0;i<TAILMAX;i++)
            {
                if (strcmp(mbs[i].code,code))
                    m=mbs[i];
            }
            printf("\nVoulez vous supprimer cet article (non:0 /oui:1) >>>>>");
            scanf("%d",&reponse);
            if (reponse)
                supprimer( mbs,m.code);
                else
                    printf("l'article recherche n'existe pas");
            break;
         case 7:
            f=fopen("magasin.txt","wt");
            for (i=0;i<n;i++)
                fprintf(f,"%d %s %d %s %f %f %f %s",mbs[i].code,mbs[i].type,mbs[i].epoque,mbs[i].description,mbs[i].dimensions[0],mbs[i].dimensions[1],mbs[i].prix, mbs[i].vendu );
            fclose(f);
            exit(0);
         default:
            printf("\nEntree invalide");
            break;
        }
    }
    return 0;
}
