#include "functions.h"

Functions func;

/**
 * Точка входа в программу.
 * \param argc Количество аргументов командной строки.
 * \param argv Массив аргументов командной строки.
 * \return Код возврата (0).
 */
int main(const int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    QTextStream outStream(stdout); // переменная для вывода текста в консоль

    try
    {
        // Проверка правильности запуска программы
        if (argc != 3) // Если количество аргументов в командной строке не 3
        {
            // Выдать ошибку в консоль
            throw QString("Попробуйте ещё раз! Правильный шаблон запуска: LaddersCalc.exe ./input.txt ./output.txt\nТакже можно указать полный путь к файлам.");
            return 0;
        }
        if (argv[1] == NULL || argv[2] == NULL)
        {
            // Выдать ошибку в консоль
            throw QString("Попробуйте ещё раз! Правильный шаблон запуска: LaddersCalc.exe ./input.txt ./output.txt\nТакже можно указать полный путь к файлам.");
            return 0;
        }

        // Путь к входному файлу
        QString inputFileName = argv[1];
        QFile inputFile(inputFileName);

        // Путь к выходному файлу
        QString outputFileName = argv[2];
        QFile outputFile(outputFileName);

        // Проверка входного файла
        if (!inputFileName.endsWith(".txt")) // Если расширение входного файла не .txt
        {
            // Выдать ошибку в консоль
            throw QString("Формат входного файла не поддерживается! Правильный формат: .txt");
        }
        if (!inputFile.exists() || !inputFile.open(QIODevice::ReadOnly)) // Если входной файл не существует или не открыт для чтения
        {
            // Выдать ошибку в консоль
            throw QString("Файл с входными данными не существует или нет доступа для чтения этого файла!");
        }

        // Проверка выходного файла
        if (!outputFile.exists()) // Если выходного файла не существует
        {
            // Задать имя для создания нового выходного файла
            outputFileName = "new_output.txt";
        }
        else
        {
            if (!outputFileName.endsWith(".txt")) // Если расширение выходного файла не .txt
            {
                // Выдать ошибку в консоль
                throw QString("Формат выходного файла не поддерживается! Правильный формат: .txt");
            }
            if (outputFile.exists() && !outputFile.open(QIODevice::WriteOnly)) // Если выходной файл существует, но не открыт для записи
            {
                // Выдать ошибку в консоль
                throw QString("Файл для выходных данных существует, но нет доступа для записи в этот файл!");
            }
        }

        int cubeCount = func.unpackIntValue(inputFile, outputFileName); // Распаковка количества кубиков из входного файла

        if (cubeCount == NULL)
        {
            throw QString("");
        }
        else
        {
            int laddersCount = func.countOfLadders(cubeCount + 1, cubeCount); // Подсчёт количества лесенок
            func.outputIntValue(outputFileName, laddersCount); // Вывод количества лесенок
        }
    }
    // Обработка исключения
    catch (const QString& errorText)
    {
        // Вывести исключение в консоль
        outStream << errorText << flush;
    }

    return 0;
}
