#include <stdio.h>
#include <stdlib.h>
#include "labyrinth.h"

int Mozgas(BortonPTR l, RabPTR m, int d)
{

    switch (d)
    {
    case Fel:
    {
        return MozgasFel(l, m);
    }
    case Le :
    {
        return MozgasLe(l, m);
    }
    case Jobb :
    {
        return MozgasJobb(l, m);
    }
    case Bal :
    {
        return MozgasBal(l, m);
    }
    default:
    {
        // semmi
    }

    }
    return 0;
}

void menu()
{
    system("@cls||clear");
    printf("Main menu\n");
    printf("1.Uj jatek\n");
    printf("2.Leiras\n");
    printf("3.Szabalyok\n");
    printf("4.Kilepes\n");
}


int ujJatek()
{
    BortonPTR l;
    RabPTR m = (RabPTR)malloc(sizeof(struct Rab));
    int status = 0;
    int irany;
    int kulcs=0;

    l = BeolvasBorton("palya3.txt", m);
    KirajzolBorton(l);

    while (!status || !kulcs)
    {
        irany = getch();
        status = Mozgas(l, m, irany);
        if(status == 2)
        {
            kulcs =1;
            status=0;
        }
        system("@cls||clear");
        KirajzolBorton(l);

    }
    printf("Gratulalok!\nSikeresen megszoktel a bortonbol!\n");
    getchar();
    freeBorton(l);
    free(m);
}

int szabalyok()
{
    int opcio;

    printf("A rabot egy 'R' betu jelkepezi,\naz ajtot pedig egy 'A' betu jeloli.\nA rabot a nyilak segitsegevel iranyuthatod fel, le, jobbra es balra.");

    printf("\n\n1-Menu / 2- kilepes\n");
    opcio=getchar();
    getchar();
    return opcio;

}


int leiras()
{
    int opcio;

    printf("Egy rab szokest tervez a bortonbol,\nsegits neki, hogy minel rovidebb ido\nalatt megtalalja a kivezeto utat!");

    printf("\n\n1-Menu / 2- kilepes\n");
    opcio=getchar();
    getchar();
    return opcio;
}


int MozgasFel(BortonPTR l, RabPTR m)
{
    int ret = 0;

    int i= m->sorR;
    int j= m->oszlopR;

    if(l->palya[i-1][j]==5) //ha megvan a kulcs akkor mehet ki az ajton
    {
        ret=2;
    }

    if(l->palya[i-1][j]==0 || l->palya[i-1][j]==5 )
    {
        l->palya[i][j]=0;
        l->palya[i-1][j]=3;
        m->sorR=i-1;

    }

    if(l->palya[i+1][j]==2)  //ha elerte az ajtot vege a jateknak
        ret=1;

    return ret;
}
int MozgasLe(BortonPTR l, RabPTR m)
{
    int ret = 0;

    int i= m->sorR;
    int j= m->oszlopR;

    if(l->palya[i+1][j]==5)
    {
        ret=2;
    }

    if(l->palya[i+1][j]==0 || l->palya[i+1][j]==5)
    {
        l->palya[i][j]=0;
        l->palya[i+1][j]=3;
        m->sorR=i+1;

    }

    if(l->palya[i+1][j]==2)
        ret= 1;

    return ret;

}
int MozgasBal(BortonPTR l, RabPTR m)
{
    int ret = 0;

    int i= m->sorR;
    int j= m->oszlopR;

    if( l->palya[i][j-1]==5)
    {
        ret=2;
    }

    if(l->palya[i][j-1]==0 || l->palya[i][j-1]==5 )
    {
        l->palya[i][j-1]=3;
        l->palya[i][j]=0;
        m->oszlopR=j-1;

    }

    if(l->palya[i][j-1]==2)
        ret= 1;

    return ret;

}
int MozgasJobb(BortonPTR l, RabPTR m)
{
    int ret = 0;

    int i= m->sorR;
    int j= m->oszlopR;

    if( l->palya[i][j+1]==5)
    {
        ret=2;
    }

    if(l->palya[i][j+1]==0 || l->palya[i][j+1]==5)
    {
        l->palya[i][j+1]=3;
        l->palya[i][j]=0;
        m->oszlopR=j+1;

    }

    if(l->palya[i][j+1]==2 )
        ret= 1;

    return ret;


}

BortonPTR BeolvasBorton(char * filename, RabPTR m)
{
    FILE *in = fopen(filename, "r");
    BortonPTR l = (BortonPTR)malloc(sizeof(struct Borton));
    int i, j;
    int a,b;

    fscanf(in, "%i",&l->sor);
    fscanf(in, "%i",&l->oszlop);


    l->palya=(int**)malloc(l->sor*sizeof(int*));
    for (i=0; i < l->sor; i++)
        l->palya[i]=(int*)malloc(l->oszlop*sizeof(int));

    for (i=0; i< l->sor; i++)
        for (j=0; j< l->oszlop; j++)
        {
            fscanf(in, "%i",&l->palya[i][j]);
        }

    fscanf(in, "%i",&a);
    fscanf(in, "%i",&b);

    l->palya[a-1][b-1]=3; // rab

    fscanf(in, "%i",&m->sorR);
    fscanf(in, "%i",&m->oszlopR);

    l->palya[m->sorR-1][m->oszlopR-1]=2; // ajto

    m->sorR=a-1;
    m->oszlopR=b-1;

    fclose(in);

    return l;
}

void freeBorton(BortonPTR l)
{
    for(int i = 0; i < l->sor; i++)
    {
        free(l->palya[i]);
    }
    free(l->palya);
}

void KirajzolBorton(BortonPTR l)
{
    int i, j;

    for (i=0; i < l->sor; ++i)
    {
        for (j=0; j < l->oszlop; ++j)
        {
            if (l->palya[i][j] == 8 && (i == 0 || i == l->oszlop-1 )) //palya szele fent es lent
            {
                printf("#");
            }
            else if (l->palya[i][j] == 8) //palya szele oldalt
            {
                printf("#");
            }

            if (l->palya[i][j] == 0) //ahol lehet menni
            {
                printf(" ");
            }
            if (l->palya[i][j] == 1) //fal
            {
                printf("\033[0;34m");
                printf("@");
                printf("\033[0m");
            }
            if (l->palya[i][j] == 2) //ajto
            {
                printf("\033[1;31m");
                printf("A");
                printf("\033[0m");
            }
            if (l->palya[i][j] == 3) //rab
            {
                printf("R");
            }
            if (l->palya[i][j] == 5) //kulcs
            {
                printf("\033[01;33m");
                printf("K");
                printf("\033[0m");
            }

        }
        printf("\n");
    }
    printf("\n");
}
