#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
    printf("(%d,%d)", Absis(P), Ordinat(P));
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

bool EQ(POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

int isLeft(LINE L, POINT P){
    int D;

    D = (Absis(P) * A(L)) + (Ordinat(P) * B(L));
    if (D <= C(L)) {
        return 1;
    }
    
    return 0;
}

int isRight(LINE L, POINT P){
    int D;

    D = (Absis(P) * A(L)) + (Ordinat(P) * B(L));
    if (D >= C(L)) {
        return 1;
    }
    
    return 0;
}

int isOneSide(int N, int *Side){
    int i;
    int OneSide = Side[1];

    for(i=2; i<=N; i++){
        if (Side[i] != OneSide){
            return 0;
        }
    }

    return 1;
}

void Dealokasi(SET *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(Tab(*T));
}

bool SearchB(SET S, POINT P)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
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

int main() {
    int N, i, j, k, ctr;
    int count;
    SET S, Convex;
    LINE L;

    srand(time(0));
    // scanf("%d", &N);
    
    N = 4;
    MakeEmpty(&S, N);
    MakeEmpty(&Convex, pow(N,N));

    int *Left = (int*)malloc((N+1)*sizeof(int));

    for(i=1; i<=N; i++){
        Elmt(S, i) = MakePOINT(rand(), rand());
        TulisPOINT(Elmt(S, i));
    }
    printf("\n");

    Elmt(S, 1) = MakePOINT(2, 0);
    Elmt(S, 2) = MakePOINT(6, 0);
    Elmt(S, 3) = MakePOINT(4, 4);
    Elmt(S, 4) = MakePOINT(4, 1);
    // Elmt(S, 1) = MakePOINT(25, 42);
    // Elmt(S, 2) = MakePOINT(45, 98);
    // Elmt(S, 3) = MakePOINT(65, 12);
    // Elmt(S, 4) = MakePOINT(10, 30);
    
    /* Looping titik acuan */
    ctr = 1;
    for(i=1; i<=N; i++){
        printf("ini i : %d\n", i);

        /* Looping titik kemungkinan convex */
        for(j=1; j<=N; j++){ 
            if (i!=j){
                MakeGARIS(Elmt(S, i), Elmt(S, j), &L);
                printf("Check : %d , %d\n", i, j);
                /* Checking titik */
                for(k=1; k<=N; k++){ 
                    printf("compare with : %d, ", k);
                    Left[k] = isLeft(L, Elmt(S, k));
                    printf("%d\n", Left[k]);
                }
            
                printf("%d\n", isOneSide(N,Left));
                /* Apakah satu sisi atau tidak */
                if (isOneSide(N, Left) == 1){
                    if (!SearchB(Convex, Elmt(S, i))){
                        Elmt(Convex, ctr) = Elmt(S, i);
                        ctr++;
                        printf("yes\n");
                    }
                }
            }
        }
        printf("ganti\n");
    }
    printf("%d\n", ctr);

    // printf("==================\n");
    // TulisPOINT(Elmt(Convex, 5));
    // printf("\n");
    // TulisPOINT(Elmt(Convex, 6));
    // printf("\n");
    // printf("==================\n");
    for(i=1; i<=ctr-1; i++){
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