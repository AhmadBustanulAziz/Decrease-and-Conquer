/*
Nama      : Ahmad Bustanul Aziz
NIM       : 24060118120022
Matkul    : Analisis dan Strategi Algoritma
Tanggal   : 10 Oktober 2021
Deskripsi : Mencari mencari Faktor Persekutuan Terbesar dengan pendekatan Decrease and Conquer
            yang hasilnya terletak di antara dari 2 bilangan integer x dan y (x <= FPB <= y),
            Dimungkinkan tidak ada faktor persekutuan dari bilangan A dan B di dalam batasan tersebut
*/

#include <iostream>
using namespace std;

int iterasi (int i);

//Fungsi untuk mencari FPB, kemudian FPB tersebut dimasukkan ke array
int FPB(int num1, int num2, int factor2, int facArray[]) {
    //Kamus Lokal
    static int i = 0;
    //Algoritma
    if (num1 == 0 && num2 == 0) {
        return 0;
    } else if (factor2 > 0) {
        if (num1%factor2 == 0 && num2%factor2 == 0) {
            facArray[i] = factor2;
            i++;
            return FPB(num1, num2, factor2-1, facArray);
        } else {
            return FPB(num1, num2, factor2-1, facArray);
        }
    }
}

//Fungsi menentukan panjang array
int jumlahArray (int facArray[]) {
    static int j = 0;
    while (facArray[j] > 0) {
        j++;
    }
    return j;
}

int main() {
    //Kamus
    /*
        A : Bilangan 1, B : Bilangan 2, x : Batas bawah, y : Batas atas
        length : panjang array, hasil : output FPBdenganBatasan
    */
    int A, B, x, y, factor, temp, faktorArray[100], length, hasil;
    //Algoritma
    cin >> A;
    cin >> B;
    cin >> x;
    cin >> y;

    //Inisialisasi faktor yang mana dicari yang terkecil dari 2 bilangan tersebut
    if (A < B) {
        factor = A;
    } else {
        factor = B;
    }

    FPB(A, B, factor, faktorArray);
    length = jumlahArray(faktorArray);

    //Mengecek apakah FPB berada pada batasan yang ditentukan
    for (int i = 0; i<length; i++) {
        if (x <= faktorArray[i] && y >= faktorArray[i]) {
            hasil = faktorArray[i];
            break;
        }
    }

    //Apabila hasil lebih dari 0, maka terdapat FPB yang berada pada batasan yang ditentukan
    //Apabila tidak ada maka mengeluarkan nilai -1
    if (hasil > 0) {
        cout << hasil;
    } else {
        cout << -1;
    }
}
