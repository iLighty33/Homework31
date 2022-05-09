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
    // ������ 1
    cout << "������ 1.\n";

    try {
        cout << "������� ��� �����(������ � ����� ���������): " << "\n";
        int N, M;
        cin >> N >> M;
       
        cout << "��������� ����� " << returnRandNum(N, M) << endl;
    }
    catch (int ex) {
        cout << "�������� ��������!\n";
    }

    // ������ 2

    cout << "\n������ 2.\n";

    string word;

    cout << "������� ������ � ��������� ����:\n";
    cout << "����� �����_�����\n";

    cin.ignore(256, '\n'); // ��� ������ ������� getline
    getline(cin, word);

    try {
  
        wordAndWordSize(word) == true ? cout << "True" : cout << "False";
    }
    catch (const runtime_error &ex) {
        cout << "Runtime error: " << ex.what() << endl;
    }
    return 0;
}

// ������ 2

bool wordAndWordSize(string& word) {
    if (word.length() == 0)
        throw runtime_error("������� �����");
    if (word[0] == ' ')
        throw runtime_error("����� �� ����� ���������� � �������");

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
        throw runtime_error("�� ��������� ������, ��� 1 ������");

    size_t begin = word.find_first_of("0123456789"); // ����� ����� � ������
    size_t end = word.find_last_of("0123456789"); // ����� ����� � �����

    string number = word.substr(begin, end - begin + 1);
    int string_size = word.find(" ");
    
    int num2 = stoi(number);

    cout << "�������: " << num1 << " " << num2 << endl;

    if (num1 > num2)
        throw runtime_error("����� ����� ������ ��������");

    if (num2 == string_size)
        return true;

    return false;
}

// ������ 1

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