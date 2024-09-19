#include <iostream>  
#include <string>  
#include <vector>  
#include <Windows.h>  
#include <algorithm> 
#include <sstream>
#include <math.h>
using namespace std;

//Метод для заповнення матриці символами з повідомлення
void fillMatrixWithMessageR(const string& message, vector<vector<char>>& matrix, int row, int columns) {
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            if (k < message.size()) {
                matrix[i][j] = message[k];
                k++;
            }
        }
    }
}
void fillMatrixWithMessageC(const string& message, vector<vector<char>>& matrix, int columns, int row) {
    int k = 0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < row; j++) {
            if (k < message.size()) {
                matrix[j][i] = message[k];
                k++;
            }
        }
    }
}

//Метод розбиття рядка на цілі числа
vector<int> splitStringToInt(const string& str) {
    vector<int> numbers;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        try {
            int number = stoi(item);
            numbers.push_back(number);
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid number format: " << item << endl;
        }
    }
    return numbers;
}

//Метод заповнення по стовпцям
string fillRowByColumns(const vector<vector<char>>& matrix, int row, int columns) {
    std::string result;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < row; j++) {
            result += matrix[j][i];
        }
    }
    return result;
}

//Метод заповнення по рядкам
string fillColumnsByRow(const vector<vector<char>>& matrix, int row, int columns) {
    string result;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            result += matrix[i][j];
        }
    }
    return result;
}

//Метод визначення стовпців для матриці
int getMatrixColumns(string key) {
    int columns = key.length();
    return columns;
}

//Метод отримання рядків для матриці
int getMatrixRow(string message, string key) {
    int columns = getMatrixColumns(key);
    int row = message.length() / columns;
    if (message.length() % columns == 0) {
        return row;  
    }
    else {
        return row + 1;
    }
}

//Метод для видалення пробілів в рядку 
string trimming(string str) {
    string result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
    }
    return result;
}

//Метод доповнення рядка символами 
string padMessage(string message, int row, int columns) {
    int totalSize = row * columns;
    if (message.length() < totalSize) {
        message.append(totalSize - message.length(), '_');
    }
    return message;
}

//Метод розбиття рядка 
string splitStringIntoChunks(string input, int n) {
    string result;
    for (int i = 0; i < input.length(); i++) {
        result += input[i];
        if ((i + 1) % n == 0 && (i + 1) != input.length()) {
            result += ' ';
        }
    }
    return result;
}

//Метод для видалення повторюваних символів в рядку 
string removeDuplicates(string str) {
    string result;
    for (int i = 0; i < str.length(); i++) {
        int count = 0;
        for (int j = 0; j < result.length(); j++) {
            if (str[i] == result[j]) {
                count++;
            }
        }
        if (count < 1) {
            result += str[i];
        }
    }
    return result;
}

//Метод сортування рядка кирилицею 
string sortString(string str) {
    string result;
    string alphabet = "АаБбВвГгҐґДдЕеЄєЖжЗзИиІіЇїЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЬьЮюЯя";
    for (int i = 0; i < alphabet.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == alphabet[i]) {
                result += str[j];
            }
        }
    }
    return result;
}

//Метод шифрування простою перестановкою 
string simplePermutationEncryption(string message, int row, int columns) {
    message = trimming(message);
    message = padMessage(message, row, columns);
    int size = message.length();
    int k = 0;
    vector<vector<char>> string1(row, vector<char>(columns));
    string result;
    fillMatrixWithMessageR(message, string1, row, columns);
    result = fillRowByColumns(string1, row, columns);
    return splitStringIntoChunks(result, row);
}

//Метод дешифрування простою перестановкою 
string simplePermutationDecryption(string message, int row, int columns) {
    message = trimming(message);
    int size = message.length();
    int k = 0;
    vector<vector<char>> string1(row, vector<char>(columns));
    string result;
    fillMatrixWithMessageC(message, string1, columns, row);
    result = fillColumnsByRow(string1, row, columns);
    return result;
}

//Метод шифрування oдиночною перестановкою по ключу 
string singlePermutationEncryption(string message, string key) {
    message = trimming(message);
    int columns = getMatrixColumns(key);
    int row = getMatrixRow(message, key);
    message = padMessage(message, row, columns);
    int size = message.length();
    string sortedString;
    if (key[0] >= 'A' && key[0] >= 'z') {
        sortedString = key;
        sort(sortedString.begin(), sortedString.end());
    }
    else {
        sortedString = sortString(key);
    }
    string result;
    int k = 0;
    const int sizeArray = key.length();
    vector<vector<char>> string1(row, vector<char>(columns));
    vector<vector<char>> string2(row, vector<char>(columns));
    fillMatrixWithMessageR(message, string1, row, columns);
    int countColumn = 0;
    for (int i = 0; i < sortedString.length(); i++) {
        for (int j = 0; j < key.length(); j++) {
            if (key[j] == sortedString[i]) {
                for (int g = 0; g < row; g++) {
                    string2[g][countColumn] = string1[g][j];
                }
                countColumn++;
                break;
            }
        }
    }
    result = fillRowByColumns(string2, row, columns);
    return splitStringIntoChunks(result, columns);
}

//Метод дешифрування одиночною перестановкою по ключу
string singlePermutationDecryption(string message, string key) {
    int row, columns;
    message = trimming(message);
    columns = getMatrixColumns(key);
    row = getMatrixRow(message, key);
    message = padMessage(message, row, columns);
    int size = message.length();
    string sortedString;
    if (key[0] >= 'A' && key[0] >= 'z') {
        sortedString = key;
        sort(sortedString.begin(), sortedString.end());
    }
    else {
        sortedString = sortString(key);
    }
    string result;
    int k = 0;
    const int sizeArray = key.length();
    vector<vector<char>> string1(row, vector<char>(columns));
    vector<vector<char>> string2(row, vector<char>(columns));
    fillMatrixWithMessageC(message, string1, columns, row);
    int countColumn = 0;
    for (int i = 0; i < key.length(); i++) {
        for (int j = 0; j < sortedString.length(); j++) {
            if (sortedString[j] == key[i]) {
                for (int g = 0; g < row; g++) {
                    string2[g][countColumn] = string1[g][j];
                }
                countColumn++;
                break;
            }
        }
    }
    result = fillColumnsByRow(string2, row, columns);
    return result;
}

//Метод шифрування подвійною перестановокою 
string doublePermutationEncryption(string message, string keyColumns, string keyRow) {
    string result;
    vector<int> keyR = splitStringToInt(trimming(keyRow));
    vector<int> keyC = splitStringToInt(trimming(keyColumns));
    int row = keyR.size();
    int columns = keyC.size();
    vector<int> sortKeyR = splitStringToInt(trimming(keyRow));
    sort(sortKeyR.begin(), sortKeyR.end());
    vector<int> sortKeyC = splitStringToInt(trimming(keyColumns));
    sort(sortKeyC.begin(), sortKeyC.end());
    message = trimming(message);
    message = padMessage(message, row, columns);
    int k = 0;
    vector<vector<char>> string1(row, vector<char>(columns));
    vector<vector<char>> string2(row, vector<char>(columns));
    fillMatrixWithMessageR(message, string1, row, columns);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            string1[i][j] = message[k];
            k++;
        }
    }
    int countColumn = 0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < columns; j++) {
            if (keyC[j] == sortKeyC[i]) {
                for (int g = 0; g < row; g++) {
                    string2[g][countColumn] = string1[g][j];
                }
                countColumn++;
                break;
            }
        }
    }
    int countRow = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (keyR[j] == sortKeyR[i]) {
                for (int g = 0; g < columns; g++) {
                    string1[countRow][g] = string2[j][g];
                }
                countRow++;
                break;
            }
        }
    }
    result = fillColumnsByRow(string1, row, columns);
    return splitStringIntoChunks(result, 5);
}

//Метод дешифрування подвійною перестановокою 
string doublePermutationDecryption(string message, string keyColumns, string keyRow) {
    string result;
    vector<int> keyR = splitStringToInt(trimming(keyRow));
    vector<int> keyC = splitStringToInt(trimming(keyColumns));
    int row = keyR.size();
    int columns = keyC.size();
    vector<int> sortKeyR = splitStringToInt(trimming(keyRow));
    sort(sortKeyR.begin(), sortKeyR.end());
    vector<int> sortKeyC = splitStringToInt(trimming(keyColumns));
    sort(sortKeyC.begin(), sortKeyC.end());
    message = trimming(message);
    message = padMessage(message, row, columns);
    int k = 0;
    vector<vector<char>> string1(row, vector<char>(columns));
    vector<vector<char>> string2(row, vector<char>(columns));
    fillMatrixWithMessageR(message, string1, row, columns);
    int countRow = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (sortKeyR[j] == keyR[i]) {
                for (int g = 0; g < columns; g++) {
                    string2[countRow][g] = string1[j][g];
                }
                countRow++;
                break;
            }
        }
    }
    int countColumn = 0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < columns; j++) {
            if (sortKeyC[j] == keyC[i]) {
                for (int g = 0; g < row; g++) {
                    string1[g][countColumn] = string2[g][j];
                }
                countColumn++;
                break;
            }
        }
    }

    result = fillColumnsByRow(string1, row, columns);
    return result;
}

//Метод шифрування магічних квадратів
string magicSquareEncryption(const vector<vector<int>>& square, string message) {
    string result;
    message = trimming(message);
    int n = sqrt(message.length());
    vector<vector<char>> string1(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string1[i][j] = message[square[i][j] - 1];
        }
    }
    result = fillColumnsByRow(string1, n, n);
    return splitStringIntoChunks(result, n);
}

//Метод дешифрування магічних квадратів
string magicSquareDecryption(const vector<vector<int>>& square, string message) {
    string result;
    message = trimming(message);
    int n = sqrt(message.length());
    vector<vector<char>> string1(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string1[i][j] = message[square[i][j] - 1];
        }
    }
    result = fillColumnsByRow(string1, n, n);
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*ПРОСТА ПЕРЕСТАНОВКА*/
    //Приклад шифрування повідомлення простою перестановкою 
    cout << "Шифрування повідомлення простою перестановкою:" << endl;
    string mess1 = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
    string pass1 = simplePermutationEncryption(mess1, 4, 6);
    cout << "\t" << pass1 << endl;
    //Приклад дешифрування повідомлення простою перестановкою 
    cout << "Дешифрування повідомлення простою перестановкою:" << endl;
    cout << "\t" << simplePermutationDecryption(pass1, 4, 6) << endl;

    /*ОДИНОЧНА ПЕРЕСТАНОВКА ПО КЛЮЧУ*/
    //Приклад шифрування повідомлення oдиночною перестановкою по ключу  
    cout << "\nШифрування повідомлення  oдиночною перестановкою по ключу:" << endl;
    string mess2 = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
    string pass2 = singlePermutationEncryption(mess2, "ЗАХИСТ");
    cout << "\t" << pass2 << endl;
    cout << "Дешифрування повідомлення  oдиночною перестановкою по ключу:" << endl;
    cout << "\t" << singlePermutationDecryption(pass2, "ЗАХИСТ") << endl;

    /*ПОДВІЙНА ПЕРЕСТАНОВКА*/
    //Приклад шифрування повідомлення подвійною перестановокою 
    cout << "\nШифрування повідомлення подвійною перестановокою:" << endl;
    string mess3 = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
    string pass3 = doublePermutationEncryption(mess3, "4,1,6,3,2,5", "2,4,3,1");
    cout << "\t" << pass3 << endl;
    cout << "Дешифрування повідомлення подвійною перестановокою:" << endl;
    cout << "\t" << doublePermutationDecryption(pass3, "4,1,6,3,2,5", "2,4,3,1") << endl;

    /*МАГІЧНІ КВАДРАТИ*/
    //Приклад шифрування повідомлення магічними квадратами
    vector<vector<int>> square = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}
    };
    string mess4 = "ВІРТУАЛЬНИЙ КАНАЛ";
    string pass4 = magicSquareEncryption(square, mess4);
    cout << "\nШифрування повідомлення магічними квадратами:" << endl;
    cout << "\t" << pass4 << endl;
    cout << "Дешифрування повідомлення магічними квадратами:" << endl;
    cout << "\t" << magicSquareDecryption(square, pass4) << endl;

    string ex1 = "ШЮБИАВ АТЛІБН ЕДЛОНН АГІЕКО";
    cout << "\n Завдання №1 ЛР1" << endl;
    cout << "\t" << simplePermutationDecryption(ex1, 4, 6);
    string ex2 = "ШАЛЕНІЮ ВІД НЕБА БЛАКИТНОГО, ВІД ЛАСКАВОГО ШЕПОТУ ТРАВ";
    cout << "\n Завдання №2 ЛР1" << endl;
    cout << "\t" << singlePermutationEncryption(ex2, "ЧЕРНІГІВ");
    string ex3 = "СКІОРДНО,УЯДЯИЗЧ О.ЮАНРГА ЮМЦМИНІА ЛОЕТНСТЬ НАЇГОИВГ АІ,НРДТЛ НО.МДИІ_ ОІЯЮСЬЬЕ ЛТФДАМУО ДНЯКДІ,С";
    cout << "\n Завдання №3 ЛР1" << endl;
    cout << "\t" << doublePermutationDecryption(ex3, "11, 2, 8, 5, 3, 1, 10, 6, 7, 4, 9", "4, 1, 3, 2, 8, 5, 7, 6");
    return 0;
}