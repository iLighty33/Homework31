#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

int returnRandNum(int n, int m);
bool wordAndWordSize(string &word);

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задача 1
    cout << "Задача 1.\n";

    try {
        cout << "Введите два числа(начало и конец диапазона): " << "\n";
        int N, M;
        cin >> N >> M;
       
        cout << "Случайное число " << returnRandNum(N, M) << endl;
    }
    catch (int ex) {
        cout << "Неверное значение!\n";
    }

    // Задача 2

    cout << "\nЗадача 2.\n";

    string word;

    cout << "Введите строку в следующем виде:\n";
    cout << "слово длина_слова\n";

    cin.ignore(256, '\n'); // для работы функции getline
    getline(cin, word);

    try {
  
        wordAndWordSize(word) == true ? cout << "True" : cout << "False";
    }
    catch (const runtime_error &ex) {
        cout << "Runtime error: " << ex.what() << endl;
    }
    return 0;
}

// Задача 2

bool wordAndWordSize(string& word) {
    if (word.length() == 0)
        throw runtime_error("Введите слово");
    if (word[0] == ' ')
        throw runtime_error("Слово не может начинаться с пробела");

    int num1 = 0;
    int spaces = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ' ') {
            spaces++;
            break;
        }
        num1++;
    }

    if (spaces > 1)
        throw runtime_error("Не разрешено больше, чем 1 пробел");

    size_t begin = word.find_first_of("0123456789"); // поиск цифры с начала
    size_t end = word.find_last_of("0123456789"); // поиск цифры с конца

    string number = word.substr(begin, end - begin + 1);
    int string_size = word.find(" ");
    
    int num2 = stoi(number);

    cout << "Введено: " << num1 << " " << num2 << endl;

    if (num1 > num2)
        throw runtime_error("Длина числа больше значения");

    if (num2 == string_size)
        return true;

    return false;
}

// Задача 1

int returnRandNum(int n, int m) {
    int randNum;
    srand(time(NULL));
    //for (int i = n; i < m; i++)
    randNum = rand() % (m + 1 - n) + n;
    if (n > m)
        throw invalid_argument("N > M");
    if (n == m)
        throw invalid_argument("N = M");
    return randNum;
}