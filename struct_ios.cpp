#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

struct tanggal {
    int tanggal;
    int bulan;
    int tahun;
};

struct nilai {
    float Mtk;
    float BIn;
    float Big;
    float IPA;
    float nilaiAkhir;
};

struct siswa {
    string nama;
    string NISN;
    string jurusan;
    int umur;
    tanggal lahir;
    nilai Nilai;
};

float hitungNilaiAkhir(nilai n) {
    return (0.4 * n.Mtk) + (0.3 * n.IPA) + (0.2 * n.BIn) + (0.2 * n.Big);
}

void saveToFile(siswa daftar[], int jumlah) {
    ofstream file("siswa.txt",ios::app);
    if (!file) {
        cout << " Gagal membuka file!" << endl;
        return;
    }
    file << "Jumlah Siswa: " << jumlah << endl;
    for (int i = 0; i < jumlah; i++) {
        file << "=====================================\n";
        file << "Siswa " << (i + 1) << ":\n";
        file << "Nama: " << daftar[i].nama << endl;
        file << "NISN: " << daftar[i].NISN << endl;
        file << "Umur: " << daftar[i].umur << endl;
        file << "Jurusan: " << daftar[i].jurusan << endl;
        file << "Tanggal Lahir: " << daftar[i].lahir.tanggal << endl;
        file << "Bulan Lahir: " << daftar[i].lahir.bulan << endl;
        file << "Tahun Lahir: " << daftar[i].lahir.tahun << endl;
        file << "Nilai MTK: " << daftar[i].Nilai.Mtk << endl;
        file << "Nilai IPA: " << daftar[i].Nilai.IPA << endl;
        file << "Nilai B. Indonesia: " << daftar[i].Nilai.BIn << endl;
        file << "Nilai B. Inggris: " << daftar[i].Nilai.Big << endl;
        file << "Nilai Akhir: " << daftar[i].Nilai.nilaiAkhir << endl;
    }
    file.close();
    cout << " Data siswa disimpan ke 'siswa.txt'." << endl;
}

void tambahDataSiswa(siswa daftar[], int &jumlah) {
    int tambahan;
    cout << "\nBerapa siswa yang ingin ditambahkan? ";
    cin >> tambahan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = jumlah; i < jumlah + tambahan; i++) {
        cout << "\n=== DATA SISWA KE-" << i + 1 << " ===" << endl;
        cout << "Masukkan nama: ";
        getline(cin, daftar[i].nama);
        cout << "Masukkan NISN: ";
        getline(cin, daftar[i].NISN);
        cout << "Masukkan umur: ";
        cin >> daftar[i].umur;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan jurusan: ";
        getline(cin, daftar[i].jurusan);

        cout << "Masukkan tanggal lahir: ";
        cin >> daftar[i].lahir.tanggal;
        cout << "Masukkan bulan lahir: ";
        cin >> daftar[i].lahir.bulan;
        cout << "Masukkan tahun lahir: ";
        cin >> daftar[i].lahir.tahun;

        cout << "Masukkan nilai Matematika: ";
        cin >> daftar[i].Nilai.Mtk;
        cout << "Masukkan nilai IPA: ";
        cin >> daftar[i].Nilai.IPA;
        cout << "Masukkan nilai B. Indonesia: ";
        cin >> daftar[i].Nilai.BIn;
        cout << "Masukkan nilai B. Inggris: ";
        cin >> daftar[i].Nilai.Big;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        daftar[i].Nilai.nilaiAkhir = hitungNilaiAkhir(daftar[i].Nilai);
        cout << " Data siswa ke-" << i + 1 << " berhasil ditambahkan!\n";
    }
    jumlah += tambahan;
    saveToFile(daftar, jumlah);
}

void tampilDataSiswa(siswa daftar[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa.\n";
        return;
    }

    cout << "\n===== DATA SEMUA SISWA =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "-----------------------------------\n";
        cout << "Nama: " << daftar[i].nama << endl;
        cout << "NISN: " << daftar[i].NISN << endl;
        cout << "Jurusan: " << daftar[i].jurusan << endl;
        cout << "Nilai Akhir: " << daftar[i].Nilai.nilaiAkhir << endl;
    }
}

void cariSiswaByNISN(siswa daftar[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa untuk dicari.\n";
        return;
    }

    string cari;
    cout << "\nMasukkan NISN yang ingin dicari: ";
    getline(cin, cari);

    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].NISN == cari) {
            cout << "\n=== DATA DITEMUKAN ===\n";
            cout << "Nama: " << daftar[i].nama << endl;
            cout << "NISN: " << daftar[i].NISN << endl;
            cout << "Umur: " << daftar[i].umur << endl;
            cout << "Jurusan: " << daftar[i].jurusan << endl;
            cout << "Tanggal Lahir: " << daftar[i].lahir.tanggal << "-"
                 << daftar[i].lahir.bulan << "-"
                 << daftar[i].lahir.tahun << endl;
            cout << "Nilai Matematika: " << daftar[i].Nilai.Mtk << endl;
            cout << "Nilai IPA: " << daftar[i].Nilai.IPA << endl;
            cout << "Nilai B. Indonesia: " << daftar[i].Nilai.BIn << endl;
            cout << "Nilai B. Inggris: " << daftar[i].Nilai.Big << endl;
            cout << "Nilai Akhir: " << daftar[i].Nilai.nilaiAkhir << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << " Data dengan NISN " << cari << " tidak ditemukan.\n";
    }
}

void tampilRanking(siswa daftar[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data siswa untuk diranking.\n";
        return;
    }

    siswa urut[100];
    for (int i = 0; i < jumlah; i++) {
        urut[i] = daftar[i];
    }

    sort(urut, urut + jumlah, [](siswa a, siswa b) {
        return a.Nilai.nilaiAkhir > b.Nilai.nilaiAkhir;
    });

    cout << "\n===== RANKING SISWA BERDASARKAN NILAI AKHIR =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << urut[i].nama
             << " (" << urut[i].NISN << ") - Nilai Akhir: "
             << urut[i].Nilai.nilaiAkhir << endl;
    }
}

int main() {
    const int MAX_SISWA = 100;
    siswa daftar[MAX_SISWA];
    int jumlah = 0;
    int pilih;

    do {
        cout << "\n=== MENU DATA SISWA ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Tampilkan Ranking Siswa\n";
        cout << "4. Cari Siswa Berdasarkan NISN\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahDataSiswa(daftar, jumlah); break;
            case 2: tampilDataSiswa(daftar, jumlah); break;
            case 3: tampilRanking(daftar, jumlah); break;
            case 4: cariSiswaByNISN(daftar, jumlah); break;
            case 0: cout << "Keluar program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);

    return 0;
}
