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
    cout<<"Nomor Kamar : "<<hotel[i].nomorKamar<<endl
