#include <iostream>
using namespace std;


// typedef struct Mahasiswa{
//     int nim;
//     string nama;
//     int nim;
//     string gender;
// };
struct Tanggal{
    int hari;
    int bulan;
    int tahun;
};


struct Mahasiswa {
    string nama;
    int nim;
    string gender;
    Tanggal tanggallahir;
};


int main() {
    
    Mahasiswa mhsbaru;
    Mahasiswa mhslama;

    mhsbaru.nama = "Naufal";
    mhsbaru.nim = 34;
    mhsbaru.gender = "Laki";
    mhsbaru.tanggallahir.hari = 13;
    mhsbaru.tanggallahir.bulan = 12;
    mhsbaru.tanggallahir.tahun = 2006;


    cout << mhsbaru.nama << endl;
    cout << mhsbaru.nim << endl;
    cout << mhsbaru.gender << endl;
    cout << "Tanggal Lahir : " << mhsbaru.tanggallahir.hari << "/" << mhsbaru.tanggallahir.bulan << "/" << mhsbaru.tanggallahir.tahun << endl;
    
    cout << mhslama.nama << endl;

    Mahasiswa mhsAbadi [5];
    mhsAbadi[0].nama = "Ifnu";
    mhsAbadi[1].nama = "Amad";
    mhsAbadi[2].nama = "Nashrul";
    mhsAbadi[3].nama = "Rava";

    for (int i = 0; i < size(mhsAbadi); i++){
        cout << mhsAbadi[i].nama << endl;
    }
    
    return 0;
}
