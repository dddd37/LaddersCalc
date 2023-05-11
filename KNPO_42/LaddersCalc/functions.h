#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QTextCodec>
class Functions
{
public:
    int unpackIntValue(QFile& input, QString outputFileName);
    int countOfLadders(int prevStep, int cubeCount);
    void outputIntValue(QString outputFileName, int value);
};

/*!
* Распаковывает число N из текстового файла в диапазоне(1<=N<=100).
*\param[in] input – Входной файл.
*\param[in] outputFileName – Путь или имя выходного файла.
*\return – Число от 1 до 100, если оно соответствует условиям, иначе NULL.
*/
int Functions::unpackIntValue(QFile& input, QString outputFileName)
{
    QFile output(outputFileName); // создание или чтение существующего файла
    output.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream in(&input); // создание объекта QTextStream для чтения данных из входного файла

//----------настройка вывода русского текста в формате UTF-8 в файл-----------
    QTextStream out(&output);
    out.setCodec("UTF-8");
    QString inputLine = in.readLine();
    QString russianText = NULL;
//-------------------------проверка содержания входного файла----------------------------
    if (inputLine.isEmpty()) // если входной файл пустой
    {
        // выдать ошибку в выходной файл
        russianText = "Файл с входными данными является пустым!";
        out << russianText;
        output.close();
        return NULL;
    }
    if(inputLine.size() > 3) // если строка длиннее 3ёх символов
    {
        // выдать ошибку в выходной файл
        russianText = "Неверные входные данные! В строке не может быть больше трёх символов!";
        out << russianText;
        output.close();
        return NULL;
    }
    bool areDigits = true; // посимвольная проверка строки на наличие недопустимых символов
    for (const QChar& ch : inputLine) {
            if (!ch.isDigit()) {
                areDigits = false;
            }
        }
    if(areDigits == false) // если строка содержит не только цифры
    {
        // выдать ошибку в выходной файл
        russianText = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
        out << russianText;
        output.close();
        return NULL;
    }
//-----------------преобразование строки в значение int----------------
    int value = inputLine.toInt();
    if(value < 1 || value > 100) // если значение int не лежит в заданном диапазоне
    {
        // выдать ошибку в выходной файл
        russianText = "Неверные входные данные! Число N не лежит в заданном диапазоне (1<=N<=100)";
        out << russianText;
        output.close();
        input.close();
        return NULL;
    }
    else
    {
        // вернуть значение из файла
        input.close();
        return value;
    }
}

/*!
* Cчитает количество лесенок, которые можно сделать из cubeCount.
*\param[in] prevStep - Количество кубиков в предыдущей ступеньке.
*\param[in] cubeCount - Общее количество кубиков (1<=cubeCount<=100).
*\return – Количество лесенок.
*/
int Functions::countOfLadders(int prevStep, int cubeCount)
{
    if(cubeCount==0) // если количество кубиков равно 0
    return 1; // лесенку получилось построить

  int count = 0; // обнулить количество лесенок
  for (int level = 1; level < prevStep; ++level) // для каждой ступеньки лестницы, начиная со второй
  {
    count += countOfLadders(level, cubeCount - level); // прибавить к количеству лесенок результат вызова функции подсчета лесенок
  }

  return count; // вернуть значение количество лесенок
}

/*!
* Выводит число int в txt файл.
*\param[in] outputFileName – Путь или имя выходного файла.
*\param[in] value – Выходное число int.
*/
void Functions::outputIntValue(QString outputFileName, int value)
{
    QFile output(outputFileName); // создание или чтение существующего файла
    output.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&output); // создание объекта QTextStream для записи данных в выходной файл
    out << "" << value << endl; // запись результата в файл
    output.close();
}

#endif // FUNCTIONS_H
