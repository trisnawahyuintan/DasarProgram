#include<iostream>
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

