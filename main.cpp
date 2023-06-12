/*
    game hangman sederhana v1.0
    dibuat oleh: M NAUFAL ADRIAN PRATAMA PUTRA
    uploaded on: 12/06/2021

*/
#include <iostream>
#include <string> 
#include <cstdlib>
#include <time.h>
using namespace std;

//fungsi untuk memilih kata secara random
string randomWord(string words[], int size)
{
    //KAMUS LOKAL
    int randIndex;

    //ALGORITMA
    srand(time(NULL));//menggunakan waktu saat ini sebagai seed untuk generator angka acak
    randIndex = rand()% size; //menghasilkan angka acak dari 0 sampai size-1
    return words[randIndex];
}

//prosedur untuk menggambar hangman
void displayHangman(int tries)
{
    switch(tries)
    {
        case 6:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 5:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 4:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 3:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 2:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 1:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 0:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "GAME OVER" << endl;
            break;        

    }
}

//fungsi untuk mengubah kata menjadi _ _ _ _ _
string fhiddenWord(string word)
{
    //KAMUS LOKAL
    string hiddenWord;
    int length = word.length();

    //ALGORITMA
    for(int i = 0; i < length; i++)
    {
        hiddenWord+="_ ";
    }
    return hiddenWord;
}



//linear search untuk mengecek apakah huruf ada di kata yang ditebak
bool isCorrect(char letter, string word)
{
    //KAMUS LOKAL
    int length = word.length();

    //ALGORITMA
    for(int i = 0; i < length; i++)
    {
        if(letter == word[i])
        {
            return true;
        }
    }
    return false;
}

// Mengecek apakah pemain telah menebak seluruh kata
bool allLettersGuessed(string hiddenWord) 
{
    for (int i = 0; i < hiddenWord.length(); i += 2) 
    {
        if (hiddenWord[i] == '_') 
        {
            return false;
        }
    }
    return true;
}



// Fungsi utama untuk menjalankan permainan Hangman
void hangman(string words[], int size) 
{
    // KAMUS
    string word = randomWord(words, size); // Memilih kata secara acak
    string hiddenWord = fhiddenWord(word); // Mengubah kata menjadi _ _ _ _ _
    int tries = 6; // Jumlah kesempatan yang diberikan kepada pemain
    bool gameOver = false; // Menandakan apakah permainan telah berakhir
    char guess;
    
    // ALGORITMA
    while (!gameOver)
    {

        cout << "Tebak kata: " << hiddenWord << endl;
        cout << "Tersisa " << tries << " kesempatan" << endl;
        cout << "Masukkan huruf tebakan: ";
        cin >> guess;
        system("cls"); // Membersihkan layar

        if (isCorrect(guess, word))  // Mengecek apakah huruf tebakan benar
        {

            displayHangman(tries); // Menampilkan gambar Hangman

            // Memperbarui kata tersembunyi dengan huruf yang benar
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == guess)
                {
                    hiddenWord[i * 2] = guess;
                }
            }

            // Mengecek apakah pemain telah menebak seluruh kata
            if (allLettersGuessed(hiddenWord))
            {
                cout << "Selamat, kamu menang!" << endl;
                gameOver = true;
            }
            
        } 
        else 
        {
            tries--; // Mengurangi jumlah kesempatan jika huruf tebakan salah
            displayHangman(tries); // Menampilkan gambar Hangman

            // Mengecek apakah pemain kehabisan kesempatan
            if (tries == 0) 
            {
                cout << "Yahhhhh.... digantung....." << endl;
                cout << "Kata yang benar adalah: " << word << endl;
                gameOver = true;
            }
        }
    }
}

int main()
{
    //KAMUS
    string words[] = {"kucing", "anjing", "kelinci", "kuda", "kambing", "sapi", "ayam", "bebek", "ikan", "burung", "ular", "buaya", "katak", "kodok", "tikus", "monyet", "beruang", "harimau", "singa", "serigala", "rusa", "kanguru", "jerapah", "kadal", "babi", "kurakura", "kupukupu", "labalaba", "lalat", "nyamuk", "semut", "belalang", "cicak", "kadal", "kumbang", "kecoa", "capung", "lebah", "tawon", "kalajengking", "ularcobra", "ularpiton", "ularsanca"};
    int size = sizeof(words) / sizeof(words[0]);
    hangman(words, size);

    return 0;
}