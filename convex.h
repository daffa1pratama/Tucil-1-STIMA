#ifndef CONVEX_H
#define CONVEX_H

#include <stdbool.h>

typedef struct { 
	int X; /* Absis   */
	int Y; /* Ordinat */;
} POINT;

typedef struct {
    POINT *Tab; /* Container menyimpan elemen */
    int MaxEl;  /* Jumlah maksimum elemen */
} SET;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Elmt(S, i) (S).Tab[(i)]
#define Tab(S) (S).Tab
#define MaxEl(S) (S).MaxEl

POINT MakePOINT (int X, int Y);
/* Membentuk POINT dari komponen X dan Y */

void TulisPOINT (POINT P);
/* Menuliskan POINT dalam format (X,Y) */              

int Jarak (POINT P1, POINT P2);
/* Menghitung jarak antara 2 titik */

void MakeEmpty(SET *S, int maxel);
/* Membuat array dinamis POINT dengan elemen sejumlah N+1 */

bool EQ (POINT P1, POINT P2);
/* Mengecek apakah P1 dan P2 adalah titik yang sama */

int isLeft(POINT Pa, POINT Pb, POINT Px);
/* Mengecek apakah titik Px berada di sebelah "kiri" dari garis L */
// int isLeft(LINE L, POINT Pa, POINT Px);
// /* Mengecek apakah titik Px berada di sebelah "kiri" dari garis L */

int isOneSide(int N, int *Side);
/* Mengecek apakah semua titik yang dicek */
/* berada di salah satu sisi atau tidak */

bool Search(SET S, POINT P);
/* Mencari apakah P merupakan elemen dari list */

#endif