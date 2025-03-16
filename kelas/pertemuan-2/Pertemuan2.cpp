#include <iostream>
using namespace std;

int main (int argc, char const *argv[])
{
    // int number[] = {1,2,3,4,5,6,7,8,9};
    // int number[9] = {1,2};
    int number[3] = {1,2,9};

    for (int i = 1; i < 3; i++)
    {
        number[i] = number[i+1];

    }
    
    // for (auto i = 1; i < 2; i++)
    // {
    //     number[i] = number[i+1];

    // }


    // number[2] = 10;

    // int totalByte = sizeof(number);
    // int singleByte = sizeof(number[0]);
    // int panjangarray = sizeof(number)/ sizeof(number[0]);

    // for (int i = 0; i < panjangarray; i++)
    // {
    //     cout << "Nikai array : " << number[i] << endl;

    // }
    
    for (int i : number)
    {
        cout << "Nikai array : " << i << endl;

    }

    // cout << totalByte << "\n"
    //      << singleByte << "\n"
    //      << panjangarray << "\n";
    
    // cout << "Versi c++ saya : " << __cplusplus; 
    


    return 0;
}
