#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_JUMLAH 100

int main() {
    string nama = "Naufal", input_nama,  password = "034", input_password;
    int salah = 0, pilihan, jumlah_elemen = 0, index;
    bool program = true;
    string koleksi[MAX_JUMLAH][3];

    do {
        cout << "Masukkan Nama anda : ";
        cin >> input_nama;
        cout << "Masukkan Password anda : ";
        cin >> input_password;

        if(input_nama == nama && input_password == password){
            program = true;
        }
        else {
            program = false;
            salah += 1;
        }

    } while (program == false && salah < 3);

    if(program) {
    do {
            cout << R"(
=====================================================
           Selamat datang di Museum Louvre
=====================================================
1. Menambah Koleksi di Museum Louvre
2. Lihat Koleksi di Museum Louvre
3. Memperbarui Koleksi di Museum Louvre
4. Menghapus Koleksi di Museum Louvre
5. Keluar dari program
=====================================================
)" << endl;
    
    cout << "\nMasukkan Pilihan : ";
    cin >> pilihan;
    system("cls");
    
    switch(pilihan) {
        case 1:
        if (jumlah_elemen < MAX_JUMLAH) {

            cout << "Masukkan Judul Karya: ";
            cin.ignore();
            getline(cin, koleksi[jumlah_elemen][0]);
            
            cout << "Masukkan Tahun Dibuat : ";
            cin >> koleksi[jumlah_elemen][1];
            
            cout << "Masukkan Nama Seniman: ";
            cin.ignore();
            getline(cin, koleksi[jumlah_elemen][2]);

            jumlah_elemen++;
            cout << "Karya berhasil ditambahkan" << endl;
            }
        
        else {
            cout << "Koleksi Sudah Penuh." << endl;
            }
        break;

        case 2:
        if (jumlah_elemen < MAX_JUMLAH) {
            cout << "===================================================================" << endl;
            cout << "| No | " << left << setw(26) << "Judul Karya" << " | " << setw(8) << "Tahun" << " | " << setw(18) << "Seniman" << " |"<< endl;
            cout << "===================================================================" << endl;
            
            for (int i = 0; i < jumlah_elemen; i++){
                cout << "| " << setw(2) << i+1 << " | " << left << setw(26) << koleksi[i][0] << " | " << setw(8) << koleksi[i][1] << " | " << setw(18) << koleksi[i][2] << " |" << endl;
            }
            
            cout << "===================================================================" << endl;
        } 
        
        else {
            cout << "Tidak Ada Koleksi di Museum Louvre" << endl;
        }
        break;

        case 3:
        for (int i = 0; i < jumlah_elemen; i++) {
            cout << "Daftar Koleksi\n" <<i+1 << ". " << koleksi[i][0] << endl;
        }

        cout << "Masukkan nomor koleksi yang ingin diubah/perbarui : ";
        cin >> index;

        if (index < 1 || index > jumlah_elemen) {
            cout << "Nomor tidak Valid" << endl;
        }

        else {
            index--;

            cout << "Masukkan Judul Karya Baru: ";
            cin.ignore();
            getline(cin, koleksi[index][0]);

            cout << "Masukkan Tahun Dibuat yang Baru : ";
            cin >> koleksi[index][1];

            cout << "Masukkan Nama Seniman Baru: ";
            cin.ignore();
            getline(cin, koleksi[index][2]);

             cout << "Koleksi berhasil diperbarui" << endl;
                
        }
        break;

        case 4:
        for (int i = 0; i < jumlah_elemen; i++) {
            cout << "Daftar Koleksi\n" <<i+1 << ". " << koleksi[i][0] << endl;
        }

        cout << "Masukkan nomor koleksi yang ingin dihapus : ";
        cin >> index;

        if (index < 1 || index > jumlah_elemen) {
            cout << "Nomor tidak Valid" << endl;
        }

        else {
            index--;

            for (int i = index; i < jumlah_elemen - 1; i++) {
                koleksi[i][0] = koleksi[i+1][0];
                koleksi[i][1] = koleksi[i+1][1];
                koleksi[i][2] = koleksi[i+1][2];
            }
            jumlah_elemen--;
            cout << "Koleksi Berhasil di Hapus" << endl;
        }

        break;

        case 5:
            cout << "\nTerima Kasih telah berkunjung" << endl;
        break;

        default:
            cout << "\nPilihan tidak ada di menu" << endl;
        break;  

    }
    
    } while (pilihan != 5);

}

    else{
        cout << "Anda telah salah 3 kali" << endl;
    }
     
    return 0;
    
}