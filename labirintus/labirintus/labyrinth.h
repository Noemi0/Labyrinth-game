#ifndef Borton_H_INCLUDED
#define Borton_H_INCLUDED

#define Fel 72
#define Le 80
#define Bal 75
#define Jobb 77



typedef struct Borton {
    int sor, oszlop;
    int **palya;
}*BortonPTR;


typedef struct Rab {
    int sorR;
    int oszlopR;
}*RabPTR;

void menu(); //a menu opcioval indul a jatek, kivalaszthatjuk melyik opciot szeretnenk megnyitni
int ujJatek(); //ha 1-est nyomunk uj jatekot kezdunk
int leiras(); //ha 2-est nyomunk megjelenik a leiras
int szabalyok();//ha 2-est nyomunk a szabalyok jelennek meg

BortonPTR BeolvasBorton(char * filename,  RabPTR m); //beolvassuk a palyat
void freeBorton(BortonPTR l); //felszabaditas
void KirajzolBorton(BortonPTR l); //kirajzoljuk a palyat

int Mozgas(BortonPTR l, RabPTR m, int d);//iranyitas, a nyilak segitsegevel
int MozgasFel(BortonPTR l, RabPTR m);
int MozgasLe(BortonPTR l, RabPTR m);
int MozgasBal(BortonPTR l, RabPTR m);
int MozgasJobb(BortonPTR l, RabPTR m);

#endif // Borton_H_INCLUDED
