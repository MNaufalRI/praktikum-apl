#include <iostream>
using namespace std;

int main() {
    string nama = "Naufal", input_nama,  password = "034", input_password;
    int salah = 0, pilihan;
    bool program = true;

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

    while (program){
    cout << R"(
=====================================================
                     Menu utama
=====================================================
1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin
2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin
3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin
4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur
5. Keluar dari program
=====================================================
)" << endl;

        float C, F, R, K;
        cout << "\nMasukkan Pilihan : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                program = true;
                cout << "\nMasukkan nilai Celsius : ";
                cin >> C;

                F = (9.0/5.0 * C) + 32;
                R = (4.0/5.0*C);
                K = C + 273;

                cout << "=============================" << endl;
                cout << "   Hasil Konversi Celsius    " << endl;
                cout << "=============================" << endl;
                cout << "Fahrenheit = " << F << endl ;
                cout << "Reamur = " << R << endl ;
                cout << "Kelvin = " << K << endl ;
                cout << "=============================" << endl;
                break;
            case 2:
                cout << "\nMasukkan nilai Fahrenheit ";
                cin >> F;

                C = (F-32)*(5.0/9.0);
                R = (F-32)*4.0/9.0;
                F = (F-32) + 273;

                cout << "=============================" << endl;
                cout << "  Hasil Konversi Fahrenheit  " << endl;
                cout << "=============================" << endl;
                cout << "Celsius = " << C << endl ;
                cout << "Reamur = " << R << endl ;
                cout << "Kelvin = " << K << endl ;
                cout << "=============================" << endl;
                break;
            case 3:
                cout << "\nMasukkan nilai Reamur ";
                cin >> R;

                C = (5.0/4.0)*R;
                F = (9.0/4.0)*R + 32;
                K = C + 273;

                cout << "=============================" << endl;
                cout << "    Hasil Konversi Reamur    " << endl;
                cout << "=============================" << endl;
                cout << "Celsius = " << C << endl ;
                cout << "Fahrenheit = " << F << endl ;
                cout << "Kelvin = " << K << endl ;
                cout << "=============================" << endl;
                break;
            case 4:
                cout << "\nMasukkan nilai Kelvin ";
                cin >> K;

                C = K - 273;
                F = 9.0/5.0*(K-273)+32;
                R = 4.0/5.0*(K-273);

                cout << "=============================" << endl;
                cout << "    Hasil Konversi Kelvin    " << endl;
                cout << "=============================" << endl;
                cout << "Celsius = " << C << endl ;
                cout << "Fahrenheit = " << F << endl ;
                cout << "Reamur = " << R << endl ;
                cout << "=============================" << endl;
                break;
            case 5:
                cout << "\nTerima Kasih telah berkunjung" << endl;
                program = false;
                break;
            default:
                cout << "\nPilihan tidak ada di menu" << endl;
                break;      
        }

    }
    return 0;
}