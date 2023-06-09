#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

class Functions
{
public:
    int unpackIntValue(QFile& input, QString outputFileName);
    int countOfLadders(int prevStep, int cubeCount);
    void outputIntValue(QString outputFileName, int value);
};

/*!
 * Распаковывает число N из текстового файла в диапазоне (1<=N<=100).
 * \param[in] input - Входной файл.
 * \param[in] outputFileName - Путь или имя выходного файла.
 * \return - Число от 1 до 100, если оно соответствует условиям, иначе NULL.
 */
int Functions::unpackIntValue(QFile& input, QString outputFileName)
{
    QFile output(outputFileName); // Создание или чтение существующего файла
    output.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream in(&input); // Создание объекта QTextStream для чтения данных из входного файла

    // Настройка вывода русского текста в формате UTF-8 в файл
    QTextStream out(&output);
    out.setCodec("UTF-8");
    QString inputLine = in.readLine();

    try
    {
        // Проверка содержания входного файла
        if (inputLine.isEmpty()) // Если входной файл пустой
        {
            throw QString("Файл с входными данными является пустым!"); // Выдать ошибку в выходной файл
        }

        if (inputLine.size() > 3) // Если строка длиннее трех символов
        {
            throw QString("Неверные входные данные! В строке не может быть больше трех символов!"); // Выдать ошибку в выходной файл
        }

        bool areDigits = true; // Посимвольная проверка строки на наличие недопустимых символов
        for (const QChar& ch : inputLine) {
            if (!ch.isDigit()) {
                areDigits = false;
            }
        }

        if (!areDigits) // Если строка содержит не только цифры
        {
            throw QString("Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!"); // Выдать ошибку в выходной файл
        }

        // Преобразование строки в значение int
        int value = inputLine.toInt();

        if (value < 1 || value > 100) // Если значение int не лежит в заданном диапазоне
        {
            throw QString("Неверные входные данные! Число N не лежит в заданном диапазоне (1<=N<=100)"); // Выдать ошибку в выходной файл
        }
        else
        {
            input.close();
            return value; // Вернуть значение из файла
        }
    }
    catch (const QString& errorText)
    {
        // Вывести исключение в выходной txt файл
        out << errorText << flush;
        output.close();
        return NULL;
    }
}

/*!
 * Cчитает количество лесенок, которые можно сделать из cubeCount.
 * \param[in] prevStep - Количество кубиков в предыдущей ступеньке.
 * \param[in] cubeCount - Общее количество кубиков (1<=cubeCount<=100).
 * \return - Количество лесенок.
 */
int Functions::countOfLadders(int prevStep, int cubeCount)
{
    if (cubeCount == 0) // Если количество кубиков равно 0
    {
        return 1; // Лесенку получилось построить
    }

    int count = 0; // Обнулить количество лесенок

    for (int level = 1; level < prevStep; ++level) // Для каждой ступеньки лестницы, начиная со второй
    {
        if ((cubeCount - level) < 0) // Если оставшееся количество кубиков на ступеньке меньше нуля
        {
            break; // Прервать цикл
        }

        count += countOfLadders(level, cubeCount - level); // Прибавить к количеству лесенок результат вызова функции подсчета лесенок
    }

    return count; // Вернуть количество лесенок
}

/*!
 * Выводит число int в txt файл.
 * \param[in] outputFileName - Путь или имя выходного файла.
 * \param[in] value - Выходное число int.
 */
void Functions::outputIntValue(QString outputFileName, int value)
{
    QFile output(outputFileName); // Создание или чтение существующего файла
    output.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&output); // Создание объекта QTextStream для записи данных в выходной файл
    out << "" << value << endl; // Запись результата в файл
    output.close();
}

#endif // FUNCTIONS_H
