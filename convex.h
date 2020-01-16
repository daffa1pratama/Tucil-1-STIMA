#ifndef CONVEX_H
#define CONVEX_H

#include <stdbool.h>

typedef struct { 
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

typedef struct {
    POINT PAw;  /* Titik Awal  */
    POINT PAkh; /* Titik Akhir */
} LINE;

typedef struct {
    POINT *Container;
    int MaxEl;
} CONVEX;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh
#define Container(C) (C).Container

POINT MakePOINT (float X, float Y);
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


#endif