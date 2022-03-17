#define MAX_TERMS 1000
#include<stdio.h>
#include<time.h>
typedef struct{
    int col;
    int row;
    int value;
}term;

void FAST_TRANS(term a[], term b[]){
    int row_terms[MAX_TERMS];
    int starting_pos[MAX_TERMS];
    int i,j;
    int num_cols = b[0].row = a[0].col;
    int num_terms = b[0].value = a[0].value;
    b[0].col = a[0].row;
    if(num_terms >0){
        for(i=0;i<num_cols;i++)
            row_terms[i]=0;
        for(i=1;i<=num_terms;i++)
            row_terms[a[i].col]++;
        starting_pos[0] =1;
        for(i=1;i<num_cols;i++)
            starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
        for(i=1;i<=num_terms;i++){
            j=starting_pos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value=a[i].value;
        }
    }
}

void SIMPLE_TRANS(term a[], term b[]){
    int n,i,j,currentb;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if(n>0){
        currentb = 1;
        for(i=0;i<a[0].col;i++)
            for(j=1;j<=n;j++)
            if(a[j].col == i){
                b[currentb].row = a[j].col;
                b[currentb].col = a[j].row;
                b[currentb].value = a[j].value;
                currentb++;
            }
    }
}

int main(void)
{
    clock_t start_clock, end_clock;
    double n, y, duration;
    start_clock = clock();
    term b[11];
    term a[11] =  {{8,7,10}, {0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31}, {4,1,14}, {4,5,25}, {5,6,6}, {6,0,52}, {7,4,11}};

    SIMPLE_TRANS(a, b);
    
    end_clock = clock();
    duration = (double)(end_clock - start_clock)/CLOCKS_PER_SEC;
    printf("duration = %lf\n", duration);

    return 0;
}
