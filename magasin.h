#ifndef MAGASIN_H_INCLUDED
#define MAGASIN_H_INCLUDED

typedef struct meb
{
    int code;
    char type[10];
    int epoque;
    char description[1024];
    float dimensions[2];
    float prix;
    char vendu[3];
}meuble;
meuble *creer();
meuble rechercher (meuble mbs[],char artc_type[]) ;
void changer( meuble *m);
void ajouter (meuble mbs[], int n, meuble *m);
float afficher(meuble mbs[]);
void supprimer (meuble mbs[], int code);


#endif // MAGASIN_H_INCLUDED
