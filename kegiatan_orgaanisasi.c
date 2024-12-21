#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Union untuk menyimpan jenis kegiatan
typedef union {
    char jenisSeminar[30];
    char jenisEvent[30]; 
    char jenisRapat[30];
} JenisKegiatan;

// Struktur untuk menyimpan data kegiatan
typedef struct {
    char namaKegiatan[50];
    char tanggal[11]; 
    char lokasi[50];
    JenisKegiatan jenis; 
    int tipe; 
} Kegiatan;

// Fungsi untuk menambahkan kegiatan
Kegiatan* tambahKegiatan(Kegiatan *kegiatan, int *jumlahKegiatan) {
    // Mengalokasikan memori untuk array kegiatan yang baru
    Kegiatan *baru = malloc((*jumlahKegiatan + 1) * sizeof(Kegiatan));
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }

    // Jika sebelumnya ada kegiatan, salin data ke array baru
    if (*jumlahKegiatan > 0) {
        memcpy(baru, kegiatan, (*jumlahKegiatan) * sizeof(Kegiatan));
        free(kegiatan); // Lepaskan memori dari array lama
    }

    // Mengupdate data kegiatan yang baru
    printf("Masukkan Nama Kegiatan: ");
    scanf(" %[^\n]", baru[*jumlahKegiatan].namaKegiatan);
    printf("Masukkan Tanggal Kegiatan (DD-MM-YYYY): ");
    scanf("%s", baru[*jumlahKegiatan].tanggal);
    printf("Masukkan Lokasi Kegiatan: ");
    scanf(" %[^\n]", baru[*jumlahKegiatan].lokasi);

    // Memilih jenis kegiatan
    printf("Pilih jenis kegiatan:\n");
    printf("1. Seminar\n");
    printf("2. Event\n");
    printf("3. Rapat\n");
    printf("Pilih opsi: ");
    scanf("%d", &baru[*jumlahKegiatan].tipe);

    switch (baru[*jumlahKegiatan].tipe) {
        case 1:
            printf("Masukkan jenis seminar: ");
            scanf(" %[^\n]", baru[*jumlahKegiatan].jenis.jenisSeminar);
            break;
        case 2:
            printf("Masukkan jenis event: ");
            scanf(" %[^\n]", baru[*jumlahKegiatan].jenis.jenisEvent);
            break;
        case 3:
            printf("Masukkan jenis rapat: ");
            scanf(" %[^\n]", baru[*jumlahKegiatan].jenis.jenisRapat);
            break;
        default:
            printf("Jenis kegiatan tidak valid!\n");
            break;
    }

    (*jumlahKegiatan)++;
    return baru; // Kembalikan pointer array baru
}

// Fungsi untuk menampilkan semua kegiatan
void tampilkanKegiatan(Kegiatan *kegiatan, int jumlahKegiatan) {
    printf("\nDaftar Kegiatan Organisasi:\n");
    for (int i = 0; i < jumlahKegiatan; i++) {
        printf("%d. ", i + 1); // Menampilkan nomor urut
        printf("Nama Kegiatan: %s, Tanggal: %s, Lokasi: %s, ", 
               kegiatan[i].namaKegiatan, kegiatan[i].tanggal, kegiatan[i].lokasi);
        switch (kegiatan[i].tipe) {
            case 1:
                printf("Jenis: Seminar (%s)\n", kegiatan[i].jenis.jenisSeminar);
                break;
            case 2:
                printf("Jenis: Event (%s)\n", kegiatan[i].jenis.jenisEvent);
                break;
            case 3:
                printf("Jenis: Rapat (%s)\n", kegiatan[i].jenis.jenisRapat);
                break;
            default:
                printf("Jenis kegiatan tidak valid!\n");
                break;
        }
    }
}

// Fungsi utama
int main() {
    Kegiatan *kegiatan = NULL;
    int jumlahKegiatan = 0;
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kegiatan\n");
        printf("2. Tampilkan Kegiatan\n");
        printf("3. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                kegiatan = tambahKegiatan(kegiatan, &jumlahKegiatan);
                break;
            case 2:
                tampilkanKegiatan(kegiatan, jumlahKegiatan);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    // Menghapus alokasi memori
    free(kegiatan);

    return 0;
}