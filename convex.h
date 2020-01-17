#ifndef CONVEX_H
#define CONVEX_H

#include <stdbool.h>

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */;
} POINT;

typedef struct {
    // Ax + By = C
    int A;    /* Koefisien A */
    int B;    /* Koefisien B */
    int C;    /* Koefisien C */
} LINE;

typedef struct {
    POINT *Tab;
    int MaxEl;
} SET;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define A(L) (L).A
#define B(L) (L).B
#define C(L) (L).C
#define Elmt(S, i) (S).Tab[(i)]
#define Tab(S) (S).Tab
#define MaxEl(S) (S).MaxEl

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

bool EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

int isLeft(LINE L, POINT P);

int isRight(LINE L, POINT P);

int isOneSide(int N, int *Side);

void Dealokasi(SET *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

bool SearchB(SET S, POINT P);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */


#endif

// 1 2
// 1 3
// 1 4
// 1 5
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5