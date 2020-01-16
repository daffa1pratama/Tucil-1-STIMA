#ifndef CONVEX_H
#define CONVEX_H

#include <stdbool.h>

typedef struct { 
	float X; /* absis   */
	float Y; /* ordinat */;
} POINT;

typedef struct {
    // Ax + By = C
    float A;    /* Koefisien A */
    float B;    /* Koefisien B */
    float C;    /* Koefisien C */
} LINE;

typedef struct {
    POINT *Tab;
    int MaxEl;
    int Neff;
} SET;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define A(L) (L).A
#define B(L) (L).B
#define C(L) (L).C
#define Elmt(S, i) (S).Tab[(i)]
#define Tab(S) (S).Tab
#define MaxEl(S) (S).MaxEl
#define Neff(S) (S).Neff

POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

void MakeGARIS (POINT P1, POINT P2, LINE * L);
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

void MakeEmpty(SET *S, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

bool isLeft(LINE L, POINT P);

bool isRight(LINE L, POINT P);

bool isOneSide(int N, bool Side);

#endif