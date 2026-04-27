/*
* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
* Modul : 3 - Structure and Dynamics Arrays
* Hari dan Tanggal : Senin, 27 April 2026
* Pembuat : Farras Fuady Hakim
* Nama File : 13224047.c
* Deskripsi : Menerima data kecapatan angin N buah dan mengeluarkan jumlah, data yang sudah diurut, dan median.
*/

#include <stdio.h>
#include <stdlib.h>

void inputVelocity(int *arr, int *count);

// Source Code from pooja210603, link : https://github.com/pooja210603/Bubble_Sort/blob/main/bubble_sort.c
void Bubblesort(int *arr,int n);
void medianVelocity(int *arr, int count, float *median);

void inputVelocity(int *arr, int *count) {
  int input, i=0;
  while (1) {
    i++;
    scanf("%d", &input);
    if (input == -1 ) break;

    arr = realloc(arr, (i)*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    arr[i-1] = input;
  }

  *count = i-1;
}

void Bubblesort(int *arr,int n) {
    int passes=n-1;
    int comparisons=n-1;
    int i,j,temp;
    for(i=0;i<passes;i++)
    {
        for(j=0;j<comparisons-i;j++)
        {
          if(arr[j]>arr[j+1])
          {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }  
        }
    }
}

void medianVelocity(int *arr, int count, float *median) {
    int idx;
    if (count % 2 == 0){
        idx = count/2;
        *median = (float)(arr[idx] + arr[idx-1])/2;
    } else {
        idx = (count-1)/2;
        *median = arr[idx];
    }
}

int main() {
    int *arr = malloc(sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int count;
    float median;

    inputVelocity(arr, &count);
    Bubblesort(arr, count);
    medianVelocity(arr, count, &median);


    printf("COUNT %d ", count);
    printf("SORTED ");
    for (int i=0; i<count; i++) {
        printf("%d ", arr[i]);
    }
    if (count % 2 == 0) {
        printf("MEDIAN %.2f\n", median);
    } else {
        printf("MEDIAN %.0f\n", median);
    }

    return 0;
}
