/*
    fungsi membaca file external 
    dibuat oleh: M NAUFAL ADRIAN PRATAMA PUTRA
    perubahan terakhir : 15/06/2023
*/


//LIBRARY YANG DIGUNAKAN
#include <iostream>//cin dan cout
#include <fstream> //operasi file
#include <string> //string
#include <vector> //menggunakan vector

using namespace std;

vector<string> readTextFile(string filename) {
    //KAMUS LOKAL

    //vector mirip array tapi lebih dinamis(tidak terpaku panjang)
    vector<string> lines; 
    ifstream myFile(filename);
    string line;

    //ALGORITMA
    if (myFile.is_open()) //kondisi jika file berhasil di buka
    {
        while (getline(myFile, line)) 
        {
            //jika baris pada file ada isinya, isi ke paling belakang vector
            lines.push_back(line);
        }

        //setelah selesai tutup file
        myFile.close();
    } 
    else 
    {
        //pesan jika file tidak ada/tidak bisa dibuka
        cout << "Failed to open the file." << endl;
    }

    return lines;
}
