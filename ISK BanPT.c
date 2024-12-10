#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float hitungskorDTPS(int jumlahDTPS){    
    if(jumlahDTPS >= 6){
        return 4.0;
    } else if(jumlahDTPS >= 3){
        return (2.0 * jumlahDTPS) / 3;
    } else {
        return 0.0;
    }
}

float hitungskorPGLBK(int jumlahDGB, int jumlahDLK, int totalDTPS){
    if(totalDTPS == 0) return 0.0;
    float persentase = ((float)(jumlahDGB + jumlahDLK) / totalDTPS) *100;
    if(persentase >= 70){
        return 4.0;
    } else {
        return 2.0 + ((20.0 * persentase) / 7.0);
    }
}

float hitungnilaikurikulum(int keterlibatan_internal, int keterlibatan_eksternal, int frekuensi_evaluasi){
    if (keterlibatan_internal && keterlibatan_eksternal && frekuensi_evaluasi >= 4) 
        return 4.0;
    else if (keterlibatan_eksternal && keterlibatan_internal)
        return 3.0;
    else if (keterlibatan_internal)
        return 2.0;
    else 
        return 0.0;
}

float hitungnilaicapaianpembelajaran(int tracerstudy, int profillulusan, int relevansilapanganpekerjaan){
    if (tracerstudy == 5) return 4.0;
    else if (tracerstudy == 4) return 3.0;
    else if (tracerstudy == 3) return 2.0;
    else if (tracerstudy == 2) return 1.0;
    else return 0.0;
}

float hitungrelevansilapanganpekerjaan(int kecocokan_lapangan_pekerjaan){
    if (kecocokan_lapangan_pekerjaan >= 60) return 4.0;
    return fmax(0.0, (20.0 * kecocokan_lapangan_pekerjaan) / 3.0);
}

float calculate_publication_score(int publikasi_nasional, int publikasi_internasional, int jumlah_mahasiswa) {
    float rl = (publikasi_nasional / (float)jumlah_mahasiswa) * 100.0;
    float rn = (publikasi_internasional / (float)jumlah_mahasiswa) * 100.0;
    
    if (rn >= 20.0) return 4.0;
    if (rl >= 70.0) return 2.0;
    
    return fmin(4.0, 2.0 + rn/10.0);
}
