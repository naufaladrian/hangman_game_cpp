/*
    class game hangman sederhana v2
    dibuat oleh: M NAUFAL ADRIAN PRATAMA PUTRA
    uploaded on: 12/06/2023
    perubahan terakhir : 15/06/2023
*/

//LIBRARY YANG DIGUNAKAN
#include <iostream> //cout dan cin
#include <string> //menggunakan string
#include <cstdlib> //menggunakan rand() dan srand()
#include <time.h> //menggunakan time()
#include <vector> // menggunakan vector
#include "readFile.h" //header berisi fungsi untuk membaca file

using namespace std;

class Hangman
{
    public:
        string wordList[10]; //list kata yang akan ditebak
        string word; //kata yang diambil dari list
        string theme; //tema tebak2kan
        string hiddenWord; //kata yang sudah disembunyikan
        int wordSize; //panjang karakter variable word
        int tries; //kesempatan mencoba dari 6 - 0
        bool isGameOver; //status apakah game sudah berakhir
        
        //default constructor
        Hangman()
        {
            saveQuestionToArray();
            this->word = randomWord(this->wordList, 10);
            this->hiddenWord = fhiddenWord(this->word);
            this->wordSize = (this->word).length();
            this->isGameOver = false;
            this->tries = 6;
        }



        //fungsi untuk menyimpan kata-kata dari file eksternal ke dalam array
        void saveQuestionToArray()
        {
            //KAMUS
            int i;
            vector<string> readLines = readTextFile("question.txt"); 

            //ALGORITMA
             // Memasukkan elemen vektor ke dalam array wordlist
            i=0;
            while (i < 10) 
            {
                this->wordList[i] = readLines[i];
                i++;
            }
            this->theme = readLines[i]; //baris ke 11 pada file dimasukkan ke theme
        }



        //fungsi untuk memilih kata secara random
        string randomWord(string words[], int size)
        {
            //KAMUS LOKAL
            int randIndex;

            //ALGORITMA
            srand(time(NULL));//menggunakan waktu saat ini sebagai seed untuk generator angka acak
            //https://mathbits.com/MathBits/CompSci/LibraryFunc/Time.htm
            randIndex = rand()% size; //menghasilkan angka acak dari 0 sampai size-1
            return words[randIndex];
        }



        //prosedur untuk menggambar hangman berdasarkan tries
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
            int i;
            //ALGORITMA
            i=0;
            while( i < length)
            {
                if(letter == word[i])
                {
                    return true;
                }
                i=i+1;
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
        void playHangman(string words[], int size) 
        {
            // KAMUS
            char guess;
            
            // ALGORITMA
            while (!isGameOver)
            {
                displayHangman(tries); // Menampilkan gambar Hangman
                cout << "Tema : "<< this->theme << endl;
                cout << "Tebak kata : " << this->hiddenWord << endl;
                cout << "Tersisa " << this->tries << " kesempatan" << endl;
                cout << "Masukkan huruf tebakan: ";
                cin >> guess;
                system("cls"); // Membersihkan layar

                if (isCorrect(guess, this->word))  // Mengecek apakah huruf tebakan benar
                {

                    // Memperbarui kata tersembunyi dengan huruf yang benar
                    for (int i = 0; i < this->word.length(); i++)
                    {
                        if (this->word[i] == guess)
                        {
                            this->hiddenWord[i * 2] = guess;
                        }
                    }

                    // Mengecek apakah pemain telah menebak seluruh kata
                    if (allLettersGuessed(this->hiddenWord))
                    {
                        displayHangman(tries); // Menampilkan gambar Hangman
                        cout << "Selamat, kamu menang!" << endl;
                        cout << "Kata yang berhasil anda tebak adalah adalah: " << this->word << endl;
                        cout << "Jumlah Tebakan Salah:" <<6- (this->tries) << endl;
                        this->isGameOver = true;
                    }
                    
                } 
                else 
                {
                    this->tries--; // Mengurangi jumlah kesempatan jika huruf tebakan salah

                    // Mengecek apakah pemain kehabisan kesempatan
                    if (this->tries == 0) 
                    {
                        displayHangman(this->tries); // Menampilkan gambar Hangman
                        cout << "Kata yang benar adalah: " << this->word << endl;
                        this->isGameOver = true;
                    }
                }
            }
        }
};

