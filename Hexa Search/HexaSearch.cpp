/*
Nama      : Ahmad Bustanul Aziz
NIM       : 24060118120022
Matkul    : Analisis dan Strategi Algoritma
Tanggal   : 09 Oktober 2021
Deskripsi : Mencari index bilangan hexadecimal yang dicari dalam sebuah array
            dengan pendekatan Decrease and Conquer
*/

#include <iostream>
#include <cstring>

using namespace std;

//Fungsi untuk mengkonversi array hexadecimal menjadi decimal
int convertHex(string num) {
    //Kamus Lokal
    int len = sizeof(num);
    int base = 1;
    int temp = 0;
    char num2[len];
    //Algoritma
    strcpy(num2, num.c_str());
    for (int k=len-1; k>=0; k--) {
        if (num2[k] >= '0' && num2[k]<='9') {
            temp += (int(num2[k]-48))*base;
            base = base * 16;
        } else if (num2[k]>='A' && num2[k]<='F') {
            temp += (int(num2[k]-55))*base;
            base = base*16;
        }
    }
    return temp;
}

/*Fungsi mencari bilangan hexadecimal dalam array
  (untuk mempermudah, bilangan hexadecimal yang dicari diconvert dulu ke decimal (ada di fungsi main),
   kemudian dicari di array yang sudah diconvert menjadi decimal juga)
*/
int searchHex(int desArray2[], int indexMin, int indexMax, int Hex) {
    //Kamus Lokal
    int mid;
    //Algoritma
    if (indexMin>indexMax) {
        return -1;
    } else {
        mid = (indexMin+indexMax)/2;
        if (desArray2[mid] == Hex) {
            //cout << mid;
            return mid;
        } else {
            if (Hex < desArray2[mid]) {
                searchHex(desArray2, indexMin, mid-1, Hex);
            } else {
                searchHex(desArray2, mid+1, indexMax, Hex);
            }
        }
    }
}

int main () {
    //Kamus
    int N, idxMax, Hexa;
    string hexArray[100], X;
    int desArray[100];

    //Algoritma
    cin >> N;
    cin >> X;
    for (int i=0; i<N; i++) {
        cin >> hexArray[i];
        desArray[i] = convertHex(hexArray[i]);
    }
    Hexa = convertHex(X);
    if (searchHex(desArray, 0, N, Hexa) == -1) {
        cout << "Tidak Ada";
    } else {
        cout << searchHex(desArray, 0, N, Hexa);
    }
}

