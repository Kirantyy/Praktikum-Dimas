#include <stdio.h>

typedef struct {
    float indikator; // Input nilai indikator
    float bobot;     // Bobot untuk indikator
} Kriteria;

// Fungsi untuk menghitung nilai total
float hitungNilai(Kriteria kriteria[], int jumlahKriteria) {
    float totalNilai = 0.0;
    for (int i = 0; i < jumlahKriteria; i++) {
        totalNilai += kriteria[i].indikator * kriteria[i].bobot;
    }
    return totalNilai;
}

// Fungsi untuk menghitung total skor indikator
float hitungTotalSkorIndikator(Kriteria kriteria[], int jumlahKriteria) {
    float totalSkor = 0.0;
    for (int i = 0; i < jumlahKriteria; i++) {
        totalSkor += kriteria[i].indikator;
    }
    return totalSkor;
}

int main() {
    const int jumlahKriteria = 4;

    Kriteria kriteria[jumlahKriteria];

    printf("Penilaian Program Studi Magister\n");

    // Input data untuk setiap kriteria
    printf("\n1. Masukkan nilai indikator untuk dosen tetap di DTPS (0-4): ");
    scanf("%f", &kriteria[0].indikator);
    printf("   Masukkan bobot untuk dosen tetap di DTPS: ");
    scanf("%f", &kriteria[0].bobot);

    printf("\n2. Masukkan nilai indikator untuk kurikulum di level KNNI (0-4): ");
    scanf("%f", &kriteria[1].indikator);
    printf("   Masukkan bobot untuk kurikulum di level KNNI: ");
    scanf("%f", &kriteria[1].bobot);

    printf("\n3. Masukkan nilai indikator untuk penjaminan mutu pelampauan SN-DIKTI di UPPS (0-4): ");
    scanf("%f", &kriteria[2].indikator);
    printf("   Masukkan bobot untuk penjaminan mutu pelampauan SN-DIKTI di UPPS: ");
    scanf("%f", &kriteria[2].bobot);

    printf("\n4. Masukkan nilai indikator untuk publikasi ilmiah mahasiswa (0-4): ");
    scanf("%f", &kriteria[3].indikator);
    printf("   Masukkan bobot untuk publikasi ilmiah mahasiswa: ");
    scanf("%f", &kriteria[3].bobot);

    // Hitung dan tampilkan hasil
    float totalNilai = hitungNilai(kriteria, jumlahKriteria);
    float totalSkorIndikator = hitungTotalSkorIndikator(kriteria, jumlahKriteria);

    printf("\nNilai total program studi: %.2f\n", totalNilai);
    printf("Total skor indikator: %.2f\n", totalSkorIndikator);

    // Penilaian berdasarkan total nilai
    if (totalNilai >= 3.61) {
        printf("Peringkat Akreditasi: A\n");
    } else if (totalNilai >= 3.01) {
        printf("Peringkat Akreditasi: B\n");
    } else if (totalNilai >= 2.00) {
        printf("Peringkat Akreditasi: C\n");
    } else {
        printf("Peringkat Akreditasi: Tidak Terakreditasi\n");
    }
return 0;
}