#include <stdio.h>
#include <stdlib.h>
#include "convex.h"

POINT MakePOINT(float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;

    Absis(P)=X;
    Ordinat(P)=Y;
    return P;
}

void TulisPOINT(POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

void MakeGARIS (POINT P1, POINT P2, LINE *L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
    PAwal(*L)=P1;
    PAkhir(*L)=P2;
}

int main() {
    int N, i, x;
    scanf("%d", &N);
    for(i=0; i<=N; i++){
        x = rand();
        printf("%d\n", x);
    }

    return 0;
}
