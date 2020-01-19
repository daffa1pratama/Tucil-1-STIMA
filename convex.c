#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "convex.h"

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
    else if (C2 == C1) {
        D2 = Jarak(Px, P1);
        printf(" %d %d\n", D2, D1);
        if (D2 > D1) {
            return 0;
        }
        else {
            return 1;
        }
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

int main() {
    /* KAMUS */
    int N, i, j, k, ctr;
    int count;
    SET S, Convex;

    /* ALGORITMA */
    srand(time(0));
    printf("Masukkan jumlah titik : ");
    scanf("%d", &N);
    
    // N = 8;
    MakeEmpty(&S, N);
    MakeEmpty(&Convex, N);

    int *Left = (int*)malloc((N+1)*sizeof(int));

    printf("Titik yang diperoleh : \n");
    for(i=1; i<=N; i++){
        Elmt(S, i) = MakePOINT(rand() % 100, rand() % 100);
        TulisPOINT(Elmt(S, i));
        printf("\n");
    }
    printf("===============\n");

    // Elmt(S, 1) = MakePOINT(2, 0);
    // Elmt(S, 2) = MakePOINT(10, 0);
    // Elmt(S, 3) = MakePOINT(4, 4);
    // Elmt(S, 4) = MakePOINT(4, 1);
    // Elmt(S, 5) = MakePOINT(5, 0);
    // Elmt(S, 1) = MakePOINT(25, 42);
    // Elmt(S, 2) = MakePOINT(45, 98);
    // Elmt(S, 3) = MakePOINT(65, 12);
    // Elmt(S, 4) = MakePOINT(10, 30);
    
    clock_t t;
    t = clock();

    /* Looping titik acuan */
    ctr = 1;
    for(i=1; i<=N; i++){

        /* Looping titik kemungkinan convex */
        for(j=1; j<=N; j++){ 
            if (i!=j){
                // printf("Check : %d , %d\n", i, j);

                /* Checking titik */
                count = 1;
                for(k=1; k<=N; k++){ 
                    if ((k!=i) && (k!=j)){
                        // printf("compare with : %d, ", k);
                        Left[count] = isLeft(Elmt(S, i), Elmt(S, j), Elmt(S, k));
                        // printf("%d\n", Left[count]);
                        count++;
                    }
                }
            
                // printf("%d\n", isOneSide(N,Left));
                /* Apakah satu sisi atau tidak */
                if (isOneSide(N, Left) == 1){
                    if (!Search(Convex, Elmt(S, i))){
                        Elmt(Convex, ctr) = Elmt(S, i);
                        ctr++;
                        // printf("yes\n");
                    }
                }
            }
        }
        // printf("ganti\n");
    }
    // printf("%d\n", ctr);

    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;

    printf("Convex Hull : \n");
    for(i=1; i<=ctr-1; i++){
        TulisPOINT(Elmt(Convex, i));
        printf("\n");
    }
    
    printf("===============\n");

    printf("time taken : %f\n", time);

    return 0;
}

// Buat titik random
// 2 titik dihubungkan menjadi garis
// cek titik titik lain apakah satu sisi atau tidak
//     jika tidak, ganti garis lain dengan mengubah 1 titik
//     jika Ya, lanjut buat garis dengan 2 titik
// didapat convex hull