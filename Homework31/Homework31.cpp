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
    // ������ 1
    try {
        cout << "������� ��� �����(������ � ����� ���������): " << "\n";
        int N, M;
        cin >> N >> M;
        if (N > M)
            throw - 1;
        cout << "��������� ����� " << returnRandNum(N, M) << endl;
    }
    catch (int ex) {
        cout << "�������� ��������!\n";
    }

    // ������ 2

    try {
        string word;
        //char wordCh[256];
        cout << "������� ������ � ��������� ����:\n";
        cout << "����� �����_�����\n";
        
        cin.ignore(256, '\n'); // ��� ������ ������� getline
        getline(cin, word);

        //word = wordCh;
        int begin = word.find_first_of("0123456789"); // ����� ����� � ������
        int end = word.find_last_of("0123456789"); // ����� ����� � �����

        string number = word.substr(begin, end - begin + 1);
        int string_size = word.find(" ");
        int num2 = stoi(word); // ������ ���
        if (num2 == string_size)
            cout << "�����";
        else
            cout << "�������";

        // ������� ����� �����
        
        int num1 = 0;
       
        int spaces = 0;
        for (int i = 0; i < word.size(); i++) {
            num1++;
            if (word[i] == ' ')
                spaces++;
        }

        cout << "�������: " << num1 << " " << num2 << endl;

        if (num1 > num2)
            throw runtime_error("����� ����� ������ ��������");
    }
    catch (const runtime_error &ex) {
        cout << "Runtime error: " << ex.what() << endl;
    }
    return 0;
}

// ������ 2

//bool(string word) {

//}

// ������ 1

int returnRandNum(int n, int m) {
    int randNum;
    srand(time(NULL));
    //for (int i = n; i < m; i++)
    randNum = rand() % (m + 1 - n) + n;
    return randNum;
}