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
#include <fstream> //operasi file
#include <time.h> //menggunakan time()
#include <vector> // menggunakan vector

using namespace std;

class Hangman
{
    public:
        string player; //nama pemain
        vector<string> wordList; //list kata yang akan ditebak
        string word; //kata yang diambil dari list
        string theme; //tema tebak2kan
        string hiddenWord; //kata yang sudah disembunyikan
        int wordSize; //panjang karakter variable word
        int tries; //kesempatan mencoba
        bool isGameOver; //status apakah game sudah berakhir
        
        //default constructor
        Hangman()
        {
            this->wordList = readTextFile("question.txt");
            this->theme = "Algoritma Sorting";
            this->word = randomWord(this->wordList,10);
            this->hiddenWord = fhiddenWord(this->word);
            this->wordSize = (this->word).length();
            this->isGameOver = false;
            this->tries = this->wordSize<=6 ? 6 : 9;
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

        
        
        vector<string> readTextFile(string filename) 
        {
            //KAMUS LOKAL
            //vector mirip array tapi lebih dinamis(tidak terpaku panjang)
            vector<string> dataQuestion; 
            ifstream myFile(filename);
            string line;

            //ALGORITMA
            if (myFile.is_open()) //kondisi jika file berhasil di buka
            {
                while (!myFile.eof()) //berulang selama belum mencapai akhir file
                {
                    getline(myFile, line);
                    //isi baris ke paling belakang vector
                    dataQuestion.push_back(line);
                }
                //setelah selesai tutup file
                myFile.close();
            } 
            else 
            {
                //pesan jika file tidak ada/tidak bisa dibuka
                cout << "Failed to open the file." << endl;
            }
            return dataQuestion;
        }



        //fungsi untuk memilih kata secara random
        string randomWord(vector<string> words, int size)
        {
            //KAMUS LOKAL
            int randIndex;
            //ALGORITMA
            srand(time(NULL));//menggunakan waktu saat ini sebagai seed untuk generator angka acak
            randIndex = rand()% size; //menghasilkan angka acak dari 0 sampai size-1
            return words[randIndex];
        }



        //prosedur untuk menggambar hangman berdasarkan tries
        void displayHangman(int tries)
        {
            switch(tries)
            {
                case 6:
                case 7:
                case 8:
                case 9:
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


        
        void inputTxtSkor(string nama, string kata, int kesempatan, int salah)
        {
            //KAMUS
            ofstream myFile("skor.txt", ios::app);

            myFile << "=====================================" <<endl;
            myFile << "Nama Pemain : " <<nama <<endl;
            myFile << "Kata yang Ditebak : " <<kata <<endl;
            myFile << "Kesempatan : " <<kesempatan <<endl;
            myFile << "Salah Menebak : " <<salah <<endl;
            myFile << "Sisa Kesempatan : " <<kesempatan-salah <<endl;
            myFile << "=====================================" <<endl;
            myFile.close();
        }



        // Fungsi utama untuk menjalankan permainan Hangman
        void playHangman(vector<string> words, int size) 
        {
            // KAMUS
            char guess;
            int wrongGuess = 0;
            int kesempatanTotal = this->tries;
            
            // ALGORITMA
            cout<<"Masukkan nama pemain : ";
            cin>>this->player;
            system("cls");
            while (!isGameOver)
            {
                cout<<"Selamat Bermain : "<<this->player<<endl;
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
                        cout << "Jumlah Tebakan Salah:" <<wrongGuess << endl;
                        this->isGameOver = true;
                        inputTxtSkor(this->player, this->word, this->tries, wrongGuess);
                    }
                    
                } 
                else 
                {
                    this->tries=this->tries - 1; // Mengurangi jumlah kesempatan jika huruf tebakan salah
                    wrongGuess=wrongGuess + 1;
                    // Mengecek apakah pemain kehabisan kesempatan
                    if (this->tries == 0) 
                    {
                        displayHangman(this->tries); // Menampilkan gambar Hangman
                        cout << "Kata yang benar adalah: " << this->word << endl;
                        this->isGameOver = true;
                        inputTxtSkor(this->player, this->word, kesempatanTotal, wrongGuess);
                    }
                }
            }
        }


};

