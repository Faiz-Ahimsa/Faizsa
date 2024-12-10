#include <stdio.h>

int main() {
    // Variabel untuk bagian pertama;
    int NDTPS;
    float skor1;

    // Variael untuk bagian kedua;
    float PGBLK;
    float skor2;

    // Variael untuk bagian ketiga;
    float PBS, PrminC, skorC, skor3, PJc;
    int NLc, NJc;



    // Variabel skor total;
    float totalSkor;

    // Variael untuk bagian ketiga kelima;
    float skor5;
    int NA1;
    int NB1;
    int NC1;
    int NA2;
    int NA3;
    int NB2;
    int NC2;
    int NA4;
    int NB3;
    int NC3;
    int NM;

    double RL = ((NA1 + NB1 + NC1) * 100.0) / NM;
    double RN = ((NA2 + NA3 + NB2 + NC2) * 100.0) / NM;
    double RI = ((NA4 + NB3 + NC3) * 100.0) / NM;
    double a = 2.0, b = 20.0, c = 70.0;


    printf("### SELAMAT DATANG DI APK ISK BAN PT MAGISTER ###\n");

    // Bagian pertama: Perhitungan NDTPS
    printf("\n--- BAGIAN 1: Perhitungan NDTPS ---\n");

    printf("Masukkan jumlah NDTPS (Dosen Tetap Pengampu): ");
    scanf("%d", &NDTPS);

    // Perhitungan skor1 (NDTPS)
    if (NDTPS >= 6) {
        skor1 = 4.0;
    } else if (NDTPS >= 3 && NDTPS < 6) {
        skor1 = (2.0 * NDTPS) / 3.0;
    } else {
        skor1 = 0.0;
    }

    printf("\n### HASIL BAGIAN 1 ###\n");
    printf("Skor NDTPS: %.2f\n", skor1);

    // Bagian kedua: Perhitungan lulusan dan bidang kerja
    printf("\n--- BAGIAN 2: Perhitungan PGBLK ---\n");

    printf("Masukkan persentase PGBLK (tanpa %%): ");
    scanf ("%f", &PGBLK);

    // Perhitungan skor2 (PGBLK)
    if( PGBLK >= 70){
        skor2 = 4.0;
    } else {
        skor2 = 2.0 + ((2.0 * PGBLK / 100.0) / 7.0);
    }

    printf("\n### HASIL BAGIAN 2 ###\n");
    printf("Skor : %.2f\n", skor2);

    // Bagian ketiga: Perhitungan lulusan dan bidang kerja
    printf("\n--- BAGIAN 3: Perhitungan Lulusan dan Bidang Kerja ---\n");

    printf("Masukkan jumlah lulusan dalam 3 tahun (NL): ");
    scanf("%d", &NLc);
    printf("Masukkan jumlah lulusan dalam 3 tahun yang terlacak (NJ): ");
    scanf("%d", &NJc);
    printf("Masukkan persentase kesesuaian bidang kerja lulusan (PBS): ");
    scanf("%f", &PBS);

    // Validasi dan perhitungan PJ
    if (NJc > 0) {
        PJc = ((float)NJc / NLc) * 100.0;
    } else {
        printf("Error: NJ tidak boleh 0.\n");
        return 1;
    }

    // Perhitungan Prmin
    if (NLc >= 300) {
        PrminC = 30.0;
    } else {
        PrminC = 50.0 - (((float)NLc / 300.0) * 20.0);
    }

    // Perhitungan skor
    if (PBS >= 60.0) {
        skorC = 4.0;
    } else {
        skorC = (20.0 * PBS / 100.0) / 3.0;
    }

    // Penyesuaian skor akhir
    if (PJc >= PrminC) {
        skor3 = skorC;
    } else {
        skor3 = (PJc / PrminC) * skorC;
    }

    printf("\n### HASIL BAGIAN 3 ###\n");
    printf("Persentase lulusan terlacak (PJ): %.2f%%\n", PJc );
    printf("Persentase responden minimum (Prmin): %.2f%%\n", PrminC);
    printf("Skor akhir: %.2f\n", skor3);

    // Bagian keempat: Perhitungan kepuasan



    printf("\n--- BAGIAN 4: Perhitungan Skor Kepuasan ---\n");


float hitungTKi(float ai, float bi, float ci, float di) {
    return (4.0 * ai) + (3.0 * bi) + (2.0 * ci) + di;
}

float hitungSkorKepuasan(float TKi[], int jumlahAspek, float PJ, float Prmin) {
    float totalTK = 0.0;
    for (int i = 0; i < jumlahAspek; i++) {
        totalTK += TKi[i];
    }
    float skor = totalTK / jumlahAspek;

    if (PJ >= Prmin) {
        return skor;
    } else {
        return (PJ / Prmin) * skor;
    }
}

    float ai, bi, ci, di, skor, PJ, Prmin;
    int NL, NJ;
    int jumlahAspek = 7;
    float TKi[jumlahAspek];

    printf(" Masukkan jumlah lulusan dalam 3 tahun (NL): ");
    scanf (" %d", &NL);
    printf(" Masukkan jumlah lulusan dalam 3 tahun terlacak (NJ): ");
    scanf (" %d", &NJ);

    for (int i = 0; i < jumlahAspek; i++) {
        printf("\nAspek %d:\n", i + 1);
        printf("Masukkan persentase 'sangat baik' (ai): ");
        scanf("%f", &ai);
        printf("Masukkan persentase 'baik' (bi): ");
        scanf("%f", &bi);
        printf("Masukkan persentase 'cukup' (ci): ");
        scanf("%f", &ci);
        printf("Masukkan persentase 'kurang' (di): ");
        scanf("%f", &di);

        TKi[i] = hitungTKi(ai, bi, ci, di);
    }

     float skorAkhir = hitungSkorKepuasan(TKi, jumlahAspek, PJ, Prmin);

    if ( NJ > 0){
        PJ = ((float)NJ / NL)* 100.0;
    } else {
        printf ( " NJ ga boleh 0 bro!\n");
         return 1;
    }
    if( NL >= 300){
        Prmin = 30;
    }else {
        Prmin = 50.0 - (((float)NL / 300.0) * 20.0);
    }

    if( PJ >= Prmin){
        skorAkhir = skor;
    } else {
        skorAkhir = (PJ / Prmin) * skor;
    }

    printf("\n### HASIL ###\n");
    printf("Persentase lulusan terlacak (PJ): %.2f%%\n", PJ);
    printf("Persentase responden minimum (Prmin): %.2f%%\n", Prmin);
    printf("Skor Tingkat Kepuasan Pengguna: %.2f\n", skorAkhir);


    // Bagian kelima: Perhitungan publikasi;
    printf("\n--- BAGIAN 5: Perhitungan Skor Publikasi ---\n");
    printf(" Masukkan data publikasi mahasiswa untuk nomor 9:\n");

    printf("1. Jumlah publikasi mahasiswa di jurnal nasional tidak terakreditasi (NA1): ");
    scanf("%d", &NA1);

    printf("2. Jumlah publikasi mahasiswa di seminar wilayah/lokal/PT (NB1): ");
    scanf("%d", &NB1);

    printf("3. Jumlah publikasi mahasiswa di media massa wilayah (NC1): ");
    scanf("%d", &NC1);

    printf("4. Jumlah publikasi mahasiswa di jurnal nasional terakreditasi (NA2): ");
    scanf("%d", &NA2);

    printf("5. Jumlah publikasi mahasiswa di jurnal internasional (NA3): ");
    scanf("%d", &NA3);

    printf("6. Jumlah publikasi mahasiswa di seminar nasional (NB2): ");
    scanf("%d", &NB2);

    printf("7. Jumlah publikasi mahasiswa di media massa nasional (NC2): ");
    scanf("%d", &NC2);

    printf("8. Jumlah publikasi mahasiswa di jurnal internasional bereputasi (NA4): ");
    scanf("%d", &NA4);

    printf("9. Jumlah publikasi mahasiswa di seminar internasional (NB3): ");
    scanf("%d", &NB3);

    printf("10. Jumlah publikasi mahasiswa di media massa internasional (NC3): ");
    scanf("%d", &NC3);

    printf("11. Total jumlah mahasiswa (NM): ");
    scanf("%d", &NM);

RL = ((NA1 + NB1 + NC1) * 100.0) / NM;
RN = ((NA2 + NA3 + NB2 + NC2) * 100.0) / NM;
RI = ((NA4 + NB3 + NC3) * 100.0) / NM;

if (RI >= a) {
    skor5 = 4.0;
} else if (RI < a && RN >= b) {
    skor5 = 3.0 + (RI / a);
} else if (RI == 0 && RN == 0 && RL >= c) {
    skor5 = 2.0;
} else if (RI > 0 && RI < a && RN > 0 && RN < b) {
    skor5 = 2.0 + (2.0 * (RI / a)) + (RN / b) - ((RI * RN) / (a * b));
} else if (RI == 0 && RN == 0 && RL < c) {
    skor5 = (2.0 * RL) / c;
} else {
    skor5 = 0.0;
}


    printf("\n### HASIL  BAGIAN 5 ###\n");

    printf("[HASIL]--Skor nomor 9: %.2f\n", skor5 );

    // Hitung total skor akhir;
    totalSkor = skor1 + skor2 + skor3 + skorAkhir + skor5;
    printf("### Total Skor Akhir: %.2f ###\n", totalSkor);

    return 0;
}
