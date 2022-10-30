#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void opred_matr();
int opred_2  (int *);
int opred    (int *, int);
void out_matr(int *, int);

int main() {
    opred_matr();
}

void opred_matr(){
    int n;
    srand(time(NULL));

    printf("Input n:");
    scanf("%d",&n);

    int * b = (int *)malloc(n * n * sizeof(int));
    for(int i = 0; i < n * n; i++)
        *(b + i) = rand() % 10;

    out_matr(b, n);

    printf("%d",opred(b, n));
}

void out_matr(int * p, int n){
    int i, j;
    for(i = 0; i < n * n; i++){
        if(!(i % n) && i) printf("\n");
        printf("%2d ", *(p + i));
    }
    printf("\n\n");
}

int opred_2(int * p){
    int a[2] = {*(p + 0) * *(p + 3),
                *(p + 1) * *(p + 2)};
    free(a);
    return *a - a[1];
}

int opred(int * p, int n){
    int * op = (int *)malloc(n * sizeof(int));
    for(int i = 1; i <= n; i++){
        int ip = 0, * a=(int *)malloc((n - 1) * (n - 1) * sizeof(int));

        for(int j = n; j < n * n; j++)
            if((j - i + 1) % n)
                a[ip++] = *(p + j);

        //out_matr(a, n-1);

        if((n - 1) == 2) *(op + i - 1) = opred_2(a);
        else *(op + i - 1) = opred(a, n - 1);
    }

    int h = 0;
    for(int i = 0; i < n; i++)
        if(i&1) h -= p[i] * op[i];
        else h += p[i] * op[i];

    free(p);
    return h;
}
