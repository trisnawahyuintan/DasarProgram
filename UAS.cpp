#include<iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Kamar {
    int nomorKamar;
    string kelas;
    int kapasitas;
    int harga;
    bool tersedia;
};

Kamar hotel[10];
int jumlahkamar=10;

void tampilkanDataKamar(){
    cout<<"      PROGRAM SEWA KAMAR HOTEL      "<<endl<<endl;
    for(int i=0;i<jumlahKamar;i++){
        cout<<"Nomor Kamar : "<<hotel[i].nomorKamar<<endl;
        cout<<"Kelas : "<<hotel[i].kelas<<endl;
        cout<<"Kapasitas : "<<hotel[i].kapasitas<<" orang"<<endl;
        cout<<"Harga : Rp"<<hotel[i].harga<<endl;
        cout<<"Status : "<<(hotel[i].tersedia?"Tersedia" : "Tidak Tersedia")<<endl;
        cout<<"-------------------------------------------"<<endl;
    }
}

bool kamarTersedia(int nomorKamar) {
    for (int i = 0; i < jumlahKamar; i++) {
        if (hotel[i].nomorKamar == nomorKamar && hotel[i].tersedia) {
            return true;
        }
    }
    return false;
}

void sewaKamar(int nomorKamar) {
    for (int i = 0; i < jumlahKamar; i++) {
        if (hotel[i].nomorKamar == nomorKamar && hotel[i].tersedia) {
            hotel[i].tersedia = false;
            cout << "Kamar dengan Nomor " << nomorKamar << " berhasil disewa.";
            return;
        }
    }
    cout << "Kamar dengan Nomor " << nomorKamar << " tidak tersedia atau tidak ditemukan.";
}

void tampilkanKamarDenganKapasitas(int kapasitas) {
    cout << "Data Kamar dengan Kapasitas " << kapasitas << " orang: " ;
    for (int i = 0; i < jumlahKamar; i++) {
        if (hotel[i].kapasitas == kapasitas) {
            cout << "Nomor Kamar : " << hotel[i].nomorKamar << endl;
            cout << "Kelas       : " << hotel[i].kelas << endl;
            cout << "Kapasitas   : " << hotel[i].kapasitas << " orang" << endl;
            cout << "Harga       : Rp " << hotel[i].harga << endl;
            cout << "Status      : " << (hotel[i].tersedia ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "---------------------------------" << endl;
        }
    }
}

void tampilkanKamarDenganKelas(string kelas) {
    cout << "Data Kamar dengan Kelas " << kelas << ":" <<endl<<endl;
    for (int i = 0; i < jumlahKamar; i++) {
        if (hotel[i].kelas == kelas) {
            cout << "Nomor Kamar: " << hotel[i].nomorKamar << endl;
            cout << "Kelas: " << hotel[i].kelas << endl;
            cout << "Kapasitas: " << hotel[i].kapasitas << " orang" << endl;
            cout << "Harga: Rp " << hotel[i].harga << endl;
            cout << "Status: " << (hotel[i].tersedia ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "---------------------------------" << endl;
        }
    }
}

bool compareByHarga(const Kamar& a, const Kamar& b) {
    return a.harga < b.harga;
}

void tampilkanKamarDenganHargaRendahKeTinggi() {
    cout << "Data Kamar dengan Harga dari Rendah ke Tinggi: " << endl;
    sort(hotel, hotel + jumlahKamar, compareByHarga);
    for (int i = 0; i < jumlahKamar; i++) {
        cout << "Nomor Kamar: " << hotel[i].nomorKamar << endl;
        cout << "Kelas: " << hotel[i].kelas << endl;
        cout << "Kapasitas: " << hotel[i].kapasitas << " orang" << endl;
        cout << "Harga: Rp " << hotel[i].harga << endl;
        cout << "Status: " << (hotel[i].tersedia ? "Tersedia" : "Tidak Tersedia") << endl;
        cout << "-------------------------------------" << endl;
    }
}

int main() {
    // Inisialisasi data kamar
    hotel[0] = {101, "Standart", 2, 500000, true};
    hotel[1] = {102, "Standart", 2, 500000, false};
    hotel[2] = {201, "Deluxe", 4, 1000000, true};
    hotel[3] = {202, "Deluxe", 4, 1000000, true};
    hotel[4] = {301, "Luxury", 6, 1500000, false};
    hotel[5] = {302, "Luxury", 6, 1500000, false};
    hotel[6] = {401, "Standart", 2, 500000, true};
    hotel[7] = {402, "Deluxe", 4, 1000000, true};
    hotel[8] = {501, "Deluxe", 4, 1000000, false};
    hotel[9] = {502, "Luxury", 6, 1500000, true};

    bool ulang = true;
    while (ulang) {
        tampilkanDataKamar();
    
        int pilihan;
        cout << "Pilihan Menu:" << endl;
        cout << "1. Sewa Kamar" << endl;
        cout << "2. Tampilkan Kamar dengan Kapasitas Tertentu" << endl;
        cout << "3. Tampilkan Kamar dengan Kelas Tertentu" << endl;
        cout << "4. Tampilkan Kamar dengan Harga Rendah ke Tinggi" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int nomorKamar;
            cout << "Masukkan Nomor Kamar yang ingin disewa: ";
            cin >> nomorKamar;
            cout<<endl;

            if (kamarTersedia(nomorKamar)) {
                sewaKamar(nomorKamar);
            } else {
                cout << "Kamar dengan Nomor " << nomorKamar << " tidak tersedia atau tidak ditemukan." <<endl;
            }
        } else if (pilihan == 2) {
            int kapasitas;
            cout << "Masukkan Kapasitas Kamar yang ingin ditampilkan: ";
            cin >> kapasitas;
            cout<<endl;

            tampilkanKamarDenganKapasitas(kapasitas);
        } else if (pilihan == 3) {
            string kelas;
            cout << "Masukkan Kelas Kamar yang ingin ditampilkan (Standart/Deluxe/Luxury): ";
            cin >> kelas;
            cout<<endl;

            tampilkanKamarDenganKelas(kelas);
        } else if (pilihan == 4) {
            tampilkanKamarDenganHargaRendahKeTinggi();
        } 
        else {
            cout << "Pilihan tidak valid." << endl;
        }
        cout<<endl<<endl;
