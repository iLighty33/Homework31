#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

int returnRandNum(int n, int m);
//bool(string word);

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задача 1
    try {
        cout << "Введите два числа(начало и конец диапазона): " << "\n";
        int N, M;
        cin >> N >> M;
        if (N > M)
            throw - 1;
        cout << "Случайное число " << returnRandNum(N, M) << endl;
    }
    catch (int ex) {
        cout << "Неверное значение!\n";
    }

    // Задача 2

    try {
        string word;
        //char wordCh[256];
        cout << "Введите строку в следующем виде:\n";
        cout << "слово длина_слова\n";
        
        cin.ignore(256, '\n'); // для работы функции getline
        getline(cin, word);

        //word = wordCh;
        int begin = word.find_first_of("0123456789"); // поиск цифры с начала
        int end = word.find_last_of("0123456789"); // поиск цифры с конца

        string number = word.substr(begin, end - begin + 1);
        int string_size = word.find(" ");
        int num2 = stoi(word); // ошибка тут
        if (num2 == string_size)
            cout << "Верно";
        else
            cout << "Неверно";

        // Счётчик длины слова
        
        int num1 = 0;
       
        int spaces = 0;
        for (int i = 0; i < word.size(); i++) {
            num1++;
            if (word[i] == ' ')
                spaces++;
        }

        cout << "Введено: " << num1 << " " << num2 << endl;

        if (num1 > num2)
            throw runtime_error("Длина числа больше значения");
    }
    catch (const runtime_error &ex) {
        cout << "Runtime error: " << ex.what() << endl;
    }
    return 0;
}

// Задача 2

//bool(string word) {

//}

// Задача 1

int returnRandNum(int n, int m) {
    int randNum;
    srand(time(NULL));
    //for (int i = n; i < m; i++)
    randNum = rand() % (m + 1 - n) + n;
    return randNum;
}