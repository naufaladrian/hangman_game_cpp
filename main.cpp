/*
    Fungsi utama game hangman sederhana 
    dibuat oleh: M NAUFAL ADRIAN PRATAMA PUTRA
    uploaded on: 12/06/2023
    perubahan terakhir: 15/06/2023
*/
#include <iostream>
#include <string> 
#include <cstdlib>
#include <time.h>
#include "Hangman.h"
using namespace std;



//KAMUS
Hangman hangman;

int main()
{
    hangman.playHangman(hangman.wordList, 10);

    return 0;
}