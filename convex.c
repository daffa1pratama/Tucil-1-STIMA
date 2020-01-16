#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "convex.h"

POINT MakePOINT(int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;

    Absis(P) = X;
    Ordinat(P) = Y;
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
    A(*L) = Ordinat(P2) - Ordinat(P1);
    B(*L) = Absis(P2) - Absis(P1);
    C(*L) = (Ordinat(P2) * Absis(P1)) - (Ordinat(P1) * Absis(P2));
}

void MakeEmpty(SET *C, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    Tab(*C) = (POINT*)malloc((maxel+1)*sizeof(POINT));
    MaxEl(*C) = maxel;
}

bool isLeft(LINE L, POINT P){
    int D;

    D = (Absis(P) * A(L)) + (Ordinat(P) * B(L));
    if (D <= C(L)) {
        return true;
    }
    
    return false;
}

bool isRight(LINE L, POINT P){
    int D;

    D = (Absis(P) * A(L)) + (Ordinat(P) * B(L));
    if (D >= C(L)) {
        return true;
    }
    
    return false;
}

bool isOneSide(int N, bool Side){
    int i;
    bool OneSide = Side[1];

    for(i=2; i<=N; i++){
        if (Side[i] != OneSide){
            return false;
        }
    }

    return true;
}

int main() {
    int N, i, j, k, ctr;
    SET S, Convex;
    LINE L;
    bool AllLeft, AllRight;

    srand(time(0));
    scanf("%d", &N);
    
    MakeEmpty(&S, N);
    MakeEmpty(&Convex, N);
    ctr = 1;

    bool *Left = (bool*)malloc((N+1)*sizeof(bool));
    bool *Right = (bool*)malloc((N+1)*sizeof(bool));

    for(i=1; i<=N; i++){
        Elmt(S, i) = MakePOINT(rand(), rand());
        TulisPOINT(Elmt(S, i));
        Neff(S) = N;
    }

    for(i=1; i<=N; i++){ /* Looping titik acuan */
        AllLeft = true;
        AllRight = true;

        for(j=1; j<=N && j!=i; j++){ /* Looping titik kemungkinan convex */
            MakeGARIS(Elmt(S, i), Elmt(S, j), &L);
            
            for(k=1; k<=N; k++){ /* Checking titik */
                Left[k] = isLeft(L, Elmt(S, k));
                Right[k] = isRight(L, Elmt(S, k));
            }
        
            if (isOneSide(N, Left) != isOneSide(N, Right)){
                Elmt(Convex, ctr) = Elmt(S, i);
                Neff(Convex) = ctr;
                ctr++;
            }
        }
    }
    printf("%d\n", Neff(Convex));

    for(i=1; i<=Neff(Convex); i++){
        TulisPOINT(Elmt(Convex, i));
        printf("\n");
    }

    return 0;
}

// Buat titik random
// 2 titik dihubungkan menjadi garis
// cek titik titik lain apakah satu sisi atau tidak
//     jika tidak, ganti garis lain dengan mengubah 1 titik
//     jika Ya, lanjut buat garis dengan 2 titik
// didapat convex hull