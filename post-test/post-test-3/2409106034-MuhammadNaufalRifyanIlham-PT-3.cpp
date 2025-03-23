#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_JUMLAH 100

struct detail_waktu{
    string hari, bulan, tahun;
};

struct Koleksi{
    string Judul_karya, Nama_seniman;
    detail_waktu detail;
};

struct registrasi{
    string nama_user, pass_user;
};

struct khusus{
    string nama_admin, pass_admin;
};

Koleksi koleksi[MAX_JUMLAH];
registrasi regis[MAX_JUMLAH];
khusus Admin[MAX_JUMLAH];

int main() {
    string input_nama, input_password;
    int salah = 0, pilihan, jumlah_elemen = 0 , jumlah_regis = 0, jumlah_admin = 0, index;
    bool user = false, ulang = true, login_sukses = false;


    Admin[jumlah_admin].nama_admin = "Naufal";
    Admin[jumlah_admin].pass_admin = "034";
    jumlah_admin++;

    do{
        user = false;
        login_sukses = false;
        salah = 0;
        cout << R"(
=====================================================
          Selamat datang di Museum Louvre
=====================================================
1. Registrasi User Baru
2. Login ke Museum Louvre
3. Keluar dari Program
=====================================================
)" << endl;


        cout << "\nMasukkan Pilihan : ";
        cin >> pilihan;
        system("cls");
            
        switch(pilihan){
            
            case 1:
            login_sukses = true;
                cout << "Silahkan isi prosedur berikut!" << endl; 
                cout << "Masukkan nama anda : ";
                cin.ignore();
                getline(cin, regis[jumlah_regis].nama_user);
                cout << "Masukkan password anda : ";
                getline(cin, regis[jumlah_regis].pass_user);
                jumlah_regis++;
                cout << "Registrasi Berhasil!" << endl;
                break;
            
            case 2:
            do {
                cout << "Masukkan Nama anda : ";
                cin.ignore();
                getline(cin, input_nama);
                cout << "Masukkan Password anda : ";
                getline(cin, input_password);
            
                for (int i = 0; i < jumlah_admin; i++) {
                    if (input_nama == Admin[i].nama_admin && input_password == Admin[i].pass_admin) {
                        cout << "Berhasil Login Sebagai Admin!" << endl;
                        user = false;
                        login_sukses = true;
                    }
                }
                    
                for (int i = 0; i < jumlah_regis; i++) {
                    if (input_nama == regis[i].nama_user && input_password == regis[i].pass_user) {
                        cout << "Berhasil Login Sebagai User!" << endl;
                        user = true;
                        login_sukses = true;
                        }
                    }
                
            
                if(!login_sukses) {
                    salah++;
                    cout << "Nama atau Password salah! Percobaan tersisa " << 3 - salah << endl;
                    }
                
            } while (!login_sukses && salah < 3);

            if(login_sukses){

                do {
                    cout << R"(
=====================================================
           Selamat datang di Museum Louvre
=====================================================
1. Menambah Koleksi di Museum Louvre
2. Lihat Koleksi di Museum Louvre
3. Memperbarui Koleksi di Museum Louvre
4. Menghapus Koleksi di Museum Louvre
5. Kembali ke menu sebelumnya
=====================================================
)" << endl;
                        
                    cout << "\nMasukkan Pilihan : ";
                    cin >> pilihan;
                    system("cls");

                    switch(pilihan) {
                            case 1:
                            if (user){
                                cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;
                            }
                            else{

                                if (jumlah_elemen < MAX_JUMLAH) {
                                    
                                    cout << "Masukkan Judul Karya: ";
                                    cin.ignore();
                                    getline(cin, koleksi[jumlah_elemen].Judul_karya);
                                    cout << "Masukkan Tanggal Dibuat (Angka): ";
                                    cin >> koleksi[jumlah_elemen].detail.hari;
                                    cout << "Masukkan Bulan Dibuat (Angka): ";
                                    cin >> koleksi[jumlah_elemen].detail.bulan;
                                    cout << "Masukkan Tahun Dibuat : ";
                                    cin >> koleksi[jumlah_elemen].detail.tahun;
                                    
                                    cout << "Masukkan Nama Seniman: ";
                                    cin.ignore();
                                    getline(cin, koleksi[jumlah_elemen].Nama_seniman);
                                    
                                    jumlah_elemen++;
                                    cout << "Karya berhasil ditambahkan" << endl;
                                }
                                
                                else {
                                    cout << "Koleksi Sudah Penuh." << endl;
                                }
                            }
                            break;
                            
                            case 2:
                            if (jumlah_elemen < MAX_JUMLAH) {
                                cout << "=======================================================================" << endl;
                                cout << "| No | " << left << setw(26) << "Judul Karya" << " | " << setw(7) << "Waktu Dibuat" << " | " << setw(18) << "Seniman" << " |"<< endl;
                                cout << "=======================================================================" << endl;
                                
                                for (int i = 0; i < jumlah_elemen; i++){
                                    cout << "| " << setw(2) << i+1 << " | " << left << setw(26) 
                                    << koleksi[i].Judul_karya << " | " 
                                    << setw(2) << koleksi[i].detail.hari << "/" 
                                    << setw(2) << koleksi[i].detail.bulan << "/" 
                                    << setw(5) << koleksi[i].detail.tahun << "  | " 
                                    << setw(18) << koleksi[i].Nama_seniman << " |" << endl;
                                }
                                
                                cout << "=======================================================================" << endl;
                            } 
                            
                            else {
                                cout << "Tidak Ada Koleksi di Museum Louvre" << endl;
                            }
                            break;
                    
                            case 3:
                            if(user){
                                cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;
                            }
                            else {
                                for (int i = 0; i < jumlah_elemen; i++) {
                                    cout << "Daftar Koleksi\n" <<i+1 << ". " << koleksi[i].Judul_karya << endl;
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
                                    getline(cin, koleksi[index].Judul_karya);
                                    
                                    cout << "Masukkan Tahun Dibuat yang Baru!" << endl;
                                    cout << "Masukkan Tanggal Dibuat yang baru (Angka): ";
                                    cin >> koleksi[jumlah_elemen].detail.hari;
                                    cout << "Masukkan Bulan Dibuat yang baru (Angka): ";
                                    cin >> koleksi[jumlah_elemen].detail.bulan;
                                    cout << "Masukkan Tahun Dibuat yang baru : ";
                                    cin >> koleksi[jumlah_elemen].detail.tahun;
                                    
                                    cout << "Masukkan Nama Seniman Baru: ";
                                    cin.ignore();
                                    getline(cin, koleksi[index].Nama_seniman);
                                    
                                    cout << "Koleksi berhasil diperbarui" << endl;
                                }
                            }
                            break;
                            
                            case 4:
                            if(user){
                                cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;

                            }
                            else {
                                for (int i = 0; i < jumlah_elemen; i++) {
                                    cout << "Daftar Koleksi\n" <<i+1 << ". " << koleksi[i].Judul_karya << endl;
                                }
                                
                                cout << "Masukkan nomor koleksi yang ingin dihapus : ";
                                cin >> index;
                                
                                if (index < 1 || index > jumlah_elemen) {
                                    cout << "Nomor tidak Valid" << endl;
                                }
                                
                                else {
                                    index--;
                                    
                                    for (int i = index; i < jumlah_elemen - 1; i++) {
                                        koleksi[i].Judul_karya = koleksi[i+1].Judul_karya;
                                        koleksi[i].detail.hari = koleksi[i+1].detail.hari;
                                        koleksi[i].detail.bulan = koleksi[i+1].detail.bulan;
                                        koleksi[i].detail.tahun = koleksi[i+1].detail.tahun;
                                        koleksi[i].Nama_seniman = koleksi[i+1].Nama_seniman;
                                    }
                                    jumlah_elemen--;
                                    cout << "Koleksi Berhasil di Hapus" << endl;
                                }
                            }
                            
                            break;
                            
                            case 5:
                            user = false;
                            cout << "\nTelah kembali ke beranda" << endl;
                            break;
                            
                            default:
                            cout << "\nPilihan tidak ada di menu" << endl;
                            break;
                        }
                        
                    }while(pilihan!=5);
                    
                }
            }
                
        }while(pilihan!=3 && login_sukses);
            
    return 0;
}