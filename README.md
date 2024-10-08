# Encryption-Methods
# Шифрування повідомлень за допомогою перестановок

## Опис проєкту

Цей проєкт реалізує різні методи шифрування та дешифрування повідомлень на основі перестановок. Метою є демонстрація роботи алгоритмів перестановки символів у повідомленнях для забезпечення їхньої безпеки.

### Основні методи шифрування та дешифрування:
1. **Проста перестановка** – шифрування/дешифрування повідомлення шляхом переміщення символів за допомогою матриці.
2. **Одиночна перестановка по ключу** – шифрування повідомлень на основі заданого ключа з використанням перестановки.
3. **Подвійна перестановка** – використовує два ключі (по рядках і стовпцях) для шифрування/дешифрування.
4. **Магічні квадрати** – метод шифрування з використанням магічного квадрата, що перемішує символи повідомлення відповідно до порядкових чисел у квадраті.

## Вимоги

### Для успішного запуску проєкту потрібно:
- **Операційна система**: Windows
- **Комп'ютерна середа розробки**: Visual Studio 2022
- **Компілятор**: C++ компилятор, підтримуваний Visual Studio 2022

### Запуск проєкту в Visual Studio 2022
1. Склонуйте або завантажте проєкт на ваш комп'ютер.
2. Відкрийте Visual Studio 2022.
3. Виберіть File > Open > Project/Solution і відкрийте .sln файл проєкту.
4. Переконайтеся, що у вас вибрано правильне середовище компіляції (наприклад, Debug або Release).
5. Натисніть Build > Build Solution для компіляції проєкту.
6. Щоб запустити проєкт, натисніть Debug > Start Debugging або натисніть клавішу F5.

## Приклади використання
### 1. **Проста перестановка**
string message = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
string encrypted = simplePermutationEncryption(message, 4, 6);
string decrypted = simplePermutationDecryption(encrypted, 4, 6);
### 2. **Одиночна перестановка по ключу**
string message = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
string key = "ЗАХИСТ";
string encrypted = singlePermutationEncryption(message, key);
string decrypted = singlePermutationDecryption(encrypted, key);
### 3. **Подвійна перестановка**
string message = "ЗАГРОЗА ІСНУЄ ЗАВЖДИ І ВСЮДИ";
string keyColumns = "4,1,6,3,2,5";
string keyRows = "2,4,3,1";
string encrypted = doublePermutationEncryption(message, keyColumns, keyRows);
string decrypted = doublePermutationDecryption(encrypted, keyColumns, keyRows);
### 4. **Магічні квадрати**
vector<vector<int>> magicSquare = {
    {16, 3, 2, 13},
    {5, 10, 11, 8},
    {9, 6, 7, 12},
    {4, 15, 14, 1}
};
string message = "ВІРТУАЛЬНИЙ КАНАЛ";
string encrypted = magicSquareEncryption(magicSquare, message);
string decrypted = magicSquareDecryption(magicSquare, encrypted);