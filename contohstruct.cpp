#include <iostream>
#include <string>  

using namespace std;


struct tanggal {
    int tanggal;
    int bulan;
    int tahun;
};

struct nilai {
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;  
};


struct siswa {
    string nama;
    int umur;
    string jurusan;
    tanggal lahir;
    nilai nilaiSiswa;  
};

void tampilan(siswa s[], int& jumlah) {
    cout << "MASUKKAN JUMLAH SISWA (maksimal 36): ";
    cin >> jumlah;
    
    
    if (jumlah > 36) {
        cout << "Jumlah siswa melebihi batas (36). Mengatur ke 36." << endl;
        jumlah = 36;
    } else if (jumlah < 1) {
        cout << "Jumlah siswa minimal 1. Mengatur ke 1." << endl;
        jumlah = 1;
    }
    
    for(int i = 0; i < jumlah; i++) {
        cout << "==========DATA SISWA " << (i+1) << "============" << endl;
        cout << "Masukkan nama: ";
        cin >> s[i].nama;
        cout << "Masukkan umur: ";
        cin >> s[i].umur;
        cout << "Masukkan jurusan: ";
        cin >> s[i].jurusan;
        cout << "Masukkan tanggal lahir (tanggal): ";
        cin >> s[i].lahir.tanggal;
        cout << "Masukkan bulan lahir: ";
        cin >> s[i].lahir.bulan;
        cout << "Masukkan tahun lahir: ";
        cin >> s[i].lahir.tahun;
        
        cout << "===NILAI===" << endl;
        cout << "Masukkan nilai UAS: ";
        cin >> s[i].nilaiSiswa.uas;
        cout << "Masukkan nilai UTS: ";
        cin >> s[i].nilaiSiswa.uts;
        cout << "Masukkan nilai tugas: ";
        cin >> s[i].nilaiSiswa.tugas;
    }
}

void hasil(siswa s[], int jumlah) {
    for(int i = 0; i < jumlah; i++) {
        cout << "====================================" << endl;
        cout << "nama: " << s[i].nama << endl;
        cout << "umur: " << s[i].umur << endl;
        cout << "jurusan: " << s[i].jurusan << endl;
        cout << "kelahiran: " << s[i].lahir.tanggal << "-"
             << s[i].lahir.bulan << "-"
             << s[i].lahir.tahun << endl;
        
        float nilaiUas(s[i].nilaiSiswa.uas);{

        }
        float nilaiUts(s[i].nilaiSiswa.uts);{

        }
        float nilaiTugas(s[i].nilaiSiswa.tugas);{

        }
        float nilaiAkhir((s[i].nilaiSiswa.uas * 0.40) +  (s[i].nilaiSiswa.uts * 0.35) + (s[i].nilaiSiswa.tugas * 0.25));{

        }
            
            
        
        cout << "===NILAI SISWA===" << endl;
        cout << "NILAI UAS: " << nilaiUas << endl;
        cout << "NILAI UTS: " << nilaiUts << endl;
        cout << "NILAI TUGAS: " << nilaiTugas << endl;
        cout << "NILAI AKHIR: " << nilaiAkhir << endl;
    }
}

int main() {
    int MAX_SISWA = 36;  
    siswa daftarSiswa[MAX_SISWA];  
    int jumlah;  
    
    tampilan(daftarSiswa, jumlah);  
    hasil(daftarSiswa, jumlah);     
    
    return 0;  
}
