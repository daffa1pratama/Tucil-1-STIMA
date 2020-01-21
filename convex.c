#include "convex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

POINT MakePOINT(int X, int Y)
/* Membentuk POINT dari komponen X dan Y */
{
    /* KAMUS */
    POINT P;

    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
}

void TulisPOINT(POINT P)
/* Menuliskan POINT dalam format (X,Y) */              
{
    /* KAMUS */

    /* ALGORITMA */
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

int Jarak (POINT P1, POINT P2)
/* Menghitung jarak antara 2 titik */
{
    /* KAMUS */

    /* ALGORITMA */
    return sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
}

void MakeEmpty(SET *S, int maxel)
/* Membuat array dinamis POINT dengan elemen sejumlah N+1 */
{
    /* KAMUS */

    /* ALGORITMA */
    Tab(*S) = (POINT*)malloc((maxel+1)*sizeof(POINT));
    MaxEl(*S) = maxel;
}

bool EQ(POINT P1, POINT P2)
/* Mengecek apakah P1 dan P2 adalah titik yang sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

int isLeft(POINT P1, POINT P2, POINT Px)
/* Mengecek apakah titik Px berada di sebelah "kiri" dari garis L */
{
    /* KAMUS */
    int A, B, C1, C2, D1, D2;

    /* ALGORITMA */
    A = Ordinat(P2) - Ordinat(P1);
    B = Absis(P1) - Absis(P2);
    C1 = (Ordinat(P2) * Absis(P1)) - (Ordinat(P1) * Absis(P2));
    D1 = Jarak(P1, P2);
    
    C2 = (Absis(Px) * A) + (Ordinat(Px) * B);
    
    if (C2 < C1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isOneSide(int N, int *Side)
/* Mengecek apakah semua titik yang dicek */
/* berada di salah satu sisi atau tidak */
{
    /* KAMUS */
    int i;
    int OneSide; 
    
    /* ALGORITMA */
    OneSide= Side[1];

    for(i=2; i<=N-2; i++){
        if (Side[i] != OneSide){
            return 0;
        }
    }

    return 1;
}

bool Search(SET S, POINT P)
/* Mencari apakah P merupakan elemen dari list */
{
    /* KAMUS */
    bool found;
    int i;

    /* ALGORITMA */
    i = 1;
    found = false;
    while(i<=MaxEl(S)&&(!found)){
        if(EQ(Elmt(S,i), P)){
            found=true;
        }
        else{
            i++;
        }
    }
    return(found);
}