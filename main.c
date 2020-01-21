#include "convex.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    /* KAMUS */
    int N, i, j, k, ctr, count, x1, x2, y1, y2;
    SET S, Convex;

    /* ALGORITMA */

    /* Interface */
    printf("=====================================\n");
    printf("* CONVEX HULL BRUTE FORCE ALGORITHM *\n");
    printf("=====================================\n");

    /* Input N */
    srand(time(0));
    printf("Masukkan jumlah titik : ");
    scanf("%d", &N);
    printf("=====================================\n");
    
    /* Inisialisasi SET */
    MakeEmpty(&S, N);
    MakeEmpty(&Convex, N);
    int *Left = (int*)malloc((N+1)*sizeof(int));

    /* Random N titik */
    printf("Titik yang diperoleh : \n");
    for(i=1; i<=N; i++){
        Elmt(S, i) = MakePOINT(rand() % 100, rand() % 100);
        TulisPOINT(Elmt(S, i));
        printf("\n");
    }
    printf("=====================================\n");

    /* Starting time */
    clock_t t;
    t = clock();

    /* Looping titik acuan */
    ctr = 1;
    for(i=1; i<=N; i++){

        /* Looping titik kemungkinan convex */
        for(j=1; j<=N; j++){ 
            if (i!=j){

                /* Checking titik */
                count = 1;
                for(k=1; k<=N; k++){ 
                    if ((k!=i) && (k!=j)){
                        Left[count] = isLeft(Elmt(S, i), Elmt(S, j), Elmt(S, k));
                        count++;
                    }
                }
            
                /* Apakah satu sisi atau tidak */
                if (isOneSide(N, Left) == 1){
                    if (!Search(Convex, Elmt(S, i))){
                        Elmt(Convex, ctr) = Elmt(S, i);
                        ctr++;
                    }
                }
            }
        }
    }

    /* End of time */
    t = clock() - t;
    double time = (double)t;

    /* Print titik convex hull */
    printf("Convex Hull : \n");
    printf("{");
    for(i=1; i<=ctr-1; i++){
        TulisPOINT(Elmt(Convex, i));
        if (i != ctr-1){
            printf(",");
        }
    }
    printf("}\n");
    printf("=====================================\n");

    /* Print execution time */
    printf("time taken : %f microseconds\n", time);

    return 0;
}