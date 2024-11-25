#include <stdio.h>

void main(){

    // membuat array kosong dengan tipe data integer dan panjang 10
    int nama_array[10];

    // Menampilkan elemen dari nama_array
    printf("Elemen nama_array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nama_array[i]);
    }

    // membuat array dengan langsung diisi
    int nama_arr[5] = {0,4,3,2,1};

    // Menampilkan elemen dari nama_arr
    printf("Elemen nama_arr:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", nama_arr[i]);
    }
    printf("%d",nama_array);
}