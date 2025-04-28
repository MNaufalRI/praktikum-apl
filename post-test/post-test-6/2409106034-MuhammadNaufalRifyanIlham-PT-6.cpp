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


void QuickSortKoleksi(Koleksi koleksi[], int kiri, int kanan) {
    if (kiri >= kanan) return;

    int tengah = kiri + (kanan - kiri) / 2;
    string pivot = koleksi[tengah].Judul_karya;
    int i = kiri, j = kanan;

    while (i <= j) {

        while (koleksi[i].Judul_karya > pivot) {
            i++;
        }

        while (koleksi[j].Judul_karya < pivot) {
            j--;
        }

        if (i <= j) {
            swap(koleksi[i], koleksi[j]);
            i++;
            j--;
        }
    }

    if (kiri < j) {
        QuickSortKoleksi(koleksi, kiri, j);
    }
    if (i < kanan) {
        QuickSortKoleksi(koleksi, i, kanan);
    }
}

void SelectionSortTanggal(Koleksi koleksi[], int panjang) {
    for (int i = 0; i < panjang - 1; i++) {
        int min = i;
        for (int j = i + 1; j < panjang; j++) {
            string tanggal_j1 = koleksi[j].detail.tahun + koleksi[j].detail.bulan + koleksi[j].detail.hari;
            string tanggal_min = koleksi[min].detail.tahun + koleksi[min].detail.bulan + koleksi[min].detail.hari;
            
            if (tanggal_j1 < tanggal_min) {
                min = j;
            }
        }
        
        if (min != i) {
            swap(koleksi[i], koleksi[min]);
        }
    }
}

void InsertionSortSeniman(Koleksi koleksi[], int panjang) {
    for (int i = 1; i < panjang; i++) {
        Koleksi nilai = koleksi[i];
        int j = i - 1;

        while (j >= 0 && koleksi[j].Nama_seniman > nilai.Nama_seniman) {
            koleksi[j + 1] = koleksi[j]; 
            j = j - 1;
        }
        koleksi[j + 1] = nilai;
    }
}

void menu_awal(string pilihan_menu){
    if (pilihan_menu == "menu_pertama"){
        cout << R"(
            =====================================================
                      Selamat datang di Museum Louvre
            =====================================================
            1. Registrasi User Baru
            2. Login ke Museum Louvre
            3. Keluar dari Program
            =====================================================
            )" << endl;
        }
    
    else{
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
    }
}

void registrasi_user(registrasi regis[], int &jumlah_regis){
    cout << "Silahkan isi prosedur berikut!" << endl; 
    cout << "Masukkan nama anda : ";
    cin.ignore();
    getline(cin, regis[jumlah_regis].nama_user);
    cout << "Masukkan password anda : ";
    getline(cin, regis[jumlah_regis].pass_user);
    jumlah_regis++;
    cout << "Registrasi Berhasil!" << endl;
}

bool login_user(khusus Admin[], int jumlah_admin, registrasi regis[], int jumlah_regis, bool *user){
    string input_nama, input_password;
    int salah = 0;
    bool login_sukses = false;
    do {
        cout << "Masukkan Nama anda : ";
        cin.ignore();
        getline(cin, input_nama);
        cout << "Masukkan Password anda : ";
        getline(cin, input_password);
    
        for (int i = 0; i < jumlah_admin; i++) {
            if (input_nama == Admin[i].nama_admin && input_password == Admin[i].pass_admin) {
                cout << "Berhasil Login Sebagai Admin!" << endl;
                *user = false;
                login_sukses = true;
            }
        }
            
        for (int i = 0; i < jumlah_regis; i++) {
            if (input_nama == regis[i].nama_user && input_password == regis[i].pass_user) {
                cout << "Berhasil Login Sebagai User!" << endl;
                *user = true;
                login_sukses = true;
                }
            }
        
    
        if(!login_sukses) {
            salah++;
            cout << "Nama atau Password salah! Percobaan tersisa " << 3 - salah << endl;
            }
        
    } while (!login_sukses && salah < 3);

    return login_sukses;
}

bool tambah_koleksi(Koleksi koleksi[], int *jumlah_elemen){
    if (*jumlah_elemen >= MAX_JUMLAH) {
        return false;
    }
    
    else{

        cout << "Masukkan Judul Karya: ";
        cin.ignore();
        getline(cin, koleksi[*jumlah_elemen].Judul_karya);
        cout << "Masukkan Tanggal Dibuat (Angka): ";
        cin >> koleksi[*jumlah_elemen].detail.hari;
        cout << "Masukkan Bulan Dibuat (Angka): ";
        cin >> koleksi[*jumlah_elemen].detail.bulan;
        cout << "Masukkan Tahun Dibuat : ";
        cin >> koleksi[*jumlah_elemen].detail.tahun;
        cout << "Masukkan Nama Seniman: ";
        cin.ignore();
        getline(cin, koleksi[*jumlah_elemen].Nama_seniman);
        (*jumlah_elemen)++;
        return true;
    }      
}

bool lihat_koleksi(Koleksi koleksi[], int *jumlah_elemen){
    if (*jumlah_elemen > 0){
        cout << "Daftar Koleksi" << endl;
        for (int i = 0; i < *jumlah_elemen; i++) {
            cout << i+1 << ". " << koleksi[i].Judul_karya << endl;
        }
        return true;
    } else{
        return false;
    }
}


bool lihat_koleksi_descending(Koleksi koleksi[], int *jumlah_elemen, bool lengkap){
    if(*jumlah_elemen > 0){
        QuickSortKoleksi(koleksi, 0, *jumlah_elemen - 1);
        cout << "=======================================================================" << endl;
        cout << "| No | " << left << setw(26) << "Judul Karya" << " | " << setw(7) << "Waktu Dibuat" << " | " << setw(18) << "Seniman" << " |"<< endl;
        cout << "=======================================================================" << endl;
        
        for (int i = 0; i < *jumlah_elemen; i++){
            cout << "| " << setw(2) << i+1 << " | " << left << setw(26) 
            << koleksi[i].Judul_karya << " | " 
            << setw(2) << koleksi[i].detail.hari << "/" 
            << setw(2) << koleksi[i].detail.bulan << "/" 
            << setw(5) << koleksi[i].detail.tahun << "  | " 
            << setw(18) << koleksi[i].Nama_seniman << " |" << endl;
        }
        
        cout << "=======================================================================" << endl;
        return true;
    } else{
        return false;
    }
}

bool lihat_koleksi_tanggal(Koleksi koleksi[], int *jumlah_elemen, bool lengkap){
    if(*jumlah_elemen > 0){
        SelectionSortTanggal(koleksi, *jumlah_elemen);
        cout << "=======================================================================" << endl;
        cout << "| No | " << left << setw(26) << "Judul Karya" << " | " << setw(7) << "Waktu Dibuat" << " | " << setw(18) << "Seniman" << " |"<< endl;
        cout << "=======================================================================" << endl;
        
        for (int i = 0; i < *jumlah_elemen; i++){
            cout << "| " << setw(2) << i+1 << " | " << left << setw(26) 
            << koleksi[i].Judul_karya << " | " 
            << setw(2) << koleksi[i].detail.hari << "/" 
            << setw(2) << koleksi[i].detail.bulan << "/" 
            << setw(5) << koleksi[i].detail.tahun << "  | " 
            << setw(18) << koleksi[i].Nama_seniman << " |" << endl;
        }
        
        cout << "=======================================================================" << endl;
        return true;
    } else{
        return false;
    }
}

bool lihat_koleksi_seniman(Koleksi koleksi[], int *jumlah_elemen, bool lengkap){
    if(*jumlah_elemen > 0){
        InsertionSortSeniman(koleksi, *jumlah_elemen);
        cout << "=======================================================================" << endl;
        cout << "| No | " << left << setw(26) << "Judul Karya" << " | " << setw(7) << "Waktu Dibuat" << " | " << setw(18) << "Seniman" << " |"<< endl;
        cout << "=======================================================================" << endl;
        
        for (int i = 0; i < *jumlah_elemen; i++){
            cout << "| " << setw(2) << i+1 << " | " << left << setw(26) 
            << koleksi[i].Judul_karya << " | " 
            << setw(2) << koleksi[i].detail.hari << "/" 
            << setw(2) << koleksi[i].detail.bulan << "/" 
            << setw(5) << koleksi[i].detail.tahun << "  | " 
            << setw(18) << koleksi[i].Nama_seniman << " |" << endl;
        }
        
        cout << "=======================================================================" << endl;
        return true;
    } else{
        return false;
    }
}

bool ubah_koleksi(Koleksi koleksi[], int &jumlah_elemen){
    int index;
    if (!lihat_koleksi(koleksi, &jumlah_elemen)){
        cout << "Tidak ada koleksi di Museum" << endl;
    }
    
    cout << "Masukkan nomor koleksi yang ingin diubah/perbarui : ";
    cin >> index;
    
    if (index < 1 || index > jumlah_elemen) {
        return false;
    }
    
    else {
        index--;
        
        cout << "Masukkan Judul Karya Baru: ";
        cin.ignore();
        getline(cin, koleksi[index].Judul_karya);
        
        cout << "Masukkan Tahun Dibuat yang Baru!" << endl;
        cout << "Masukkan Tanggal Dibuat yang baru (Angka): ";
        cin >> koleksi[index].detail.hari;
        cout << "Masukkan Bulan Dibuat yang baru (Angka): ";
        cin >> koleksi[index].detail.bulan;
        cout << "Masukkan Tahun Dibuat yang baru : ";
        cin >> koleksi[index].detail.tahun;
        
        cout << "Masukkan Nama Seniman Baru: ";
        cin.ignore();
        getline(cin, koleksi[index].Nama_seniman);
        return true;
    }
}

bool hapus_koleksi(Koleksi koleksi[], int &jumlah_elemen){
    int index;
    if (!lihat_koleksi(koleksi, &jumlah_elemen)){
        cout << "Tidak ada koleksi di Museum" << endl;
    }
    
    cout << "Masukkan nomor koleksi yang ingin dihapus : ";
    cin >> index;
    
    if (index < 1 || index > jumlah_elemen) {
        return false;
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
        return true;
    }
}

bool hapus_semua_koleksi(Koleksi koleksi[], int &jumlah_elemen){
    if (jumlah_elemen > 0){
        jumlah_elemen--;
        hapus_semua_koleksi(koleksi, jumlah_elemen);
        return true;
    } else{
        return false;
    }
}

Koleksi koleksi[MAX_JUMLAH];
registrasi regis[MAX_JUMLAH];
khusus Admin[MAX_JUMLAH];

int main() {
    string input_nama, input_password;
    int salah = 0, pilihan, pilihan_hapus, pilihan_koleksi, jumlah_elemen = 0 , jumlah_regis = 0, jumlah_admin = 0, index;
    bool user = false, ulang = true, login_sukses = false, login_ulang = false;


    Admin[jumlah_admin].nama_admin = "Naufal";
    Admin[jumlah_admin].pass_admin = "034";
    jumlah_admin++;

    do{
        user = false;
        login_sukses = false;
        salah = 0;
        menu_awal("menu_pertama");


        cout << "\nMasukkan Pilihan : ";
        cin >> pilihan;
        system("cls");
            
        switch(pilihan){
            case 1:
                login_sukses = true;
                login_ulang = true;
                registrasi_user(regis, jumlah_regis);
                break;
            
            case 2:
                login_ulang = false;
                login_sukses = login_user(Admin, jumlah_admin, regis, jumlah_regis, &user);
                break;
        
        }
                
        if(login_sukses && !login_ulang){

                do {
                    menu_awal("menu_kedua");
                        
                    cout << "\nMasukkan Pilihan : ";
                    cin >> pilihan;
                    system("cls");

                    switch(pilihan) {
                            case 1:
                                if (user){
                                    cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;
                                }
                                else{

                                    if (tambah_koleksi(koleksi, &jumlah_elemen)){
                                        cout << "Karya berhasil ditambahkan" << endl;
                                    }
                                    
                                    else {
                                        cout << "Koleksi Sudah Penuh." << endl;
                                    }
                                }
                                break;
                            
                            case 2:
                                cout << "1. Urutkan Berdasarkan Descending (Huruf)\n2. Urutkan Berdasarkan Tanggal Waktu Pembuatan (Ascending)" << endl;
                                cout << "3. Urutkan Berdasarkan Nama Seniman (Ascending)" << endl;
                                cout << "\nMasukkan Pilihan : ";
                                cin >> pilihan_koleksi;
                                system("cls");
                                
                                switch(pilihan_koleksi){

                                    case 1:
                                    if(!lihat_koleksi_descending(koleksi, &jumlah_elemen, true)){
                                        cout << "Tidak ada koleksi di Museum" << endl;
                                    }
                                    break;

                                    case 2:
                                    if(!lihat_koleksi_tanggal(koleksi, &jumlah_elemen, true)){
                                        cout << "Tidak ada koleksi di Museum" << endl;
                                    }
                                    break;
                            
                                    case 3:
                                    if(!lihat_koleksi_seniman(koleksi, &jumlah_elemen, true)){
                                        cout << "Tidak ada koleksi di Museum" << endl;
                                    }
                                    break;

                                    default:
                                        cout << "Pilihan tidak valid" << endl;\
                                        break;
                                }
                                break;
                    
                            case 3:
                                if(user){
                                    cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;
                                }
                                else {
                                    if(ubah_koleksi(koleksi, jumlah_elemen)){
                                        cout << "Koleksi berhasil diperbarui" << endl;
                                    }
                                    else{
                                        cout << "Nomor tidak Valid" << endl;
                                    }
                                }
                                break;
                            
                            case 4:
                                if(user){
                                    cout << "Fitur ini hanya bisa digunakan oleh Admin" << endl;

                                }
                                else {
                                    cout << "1. Hapus salah satu koleksi di Museum" << endl;
                                    cout << "2. Hapus semua koleksi di Museum" << endl;

                                    cout << "\nMasukkan Pilihan : ";
                                    cin >> pilihan_hapus;
                                    system("cls");

                                    switch(pilihan_hapus){
                                        case 1:
                                            if(hapus_koleksi(koleksi, jumlah_elemen)){
                                                cout << "Koleksi Berhasil di Hapus" << endl;
                                            }
                                            else{
                                                cout << "Koleksi di Museum belum ada" << endl;
                                            }
                                            break;

                                        case 2:
                                            if(hapus_semua_koleksi(koleksi, jumlah_elemen)){
                                                cout << "Semua koleksi Berhasil di Hapus" << endl;
                                            }
                                            else{
                                                cout << "Koleksi di Museum belum ada" << endl;
                                            }
                                            break;

                                        default:
                                            cout << "Pilihan tidak valid" << endl;
                                            break;

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
                
    }while(pilihan!=3 && login_sukses);
            
    return 0;
}