#include "functions.h"
Functions func;

/**
 * Точка входа в программу.
 *\param argc Количество аргументов командной строки.
 *\param argv Массив аргументов командной строки.
 *\return Код возврата (0).
 */
int main(const int argc, char **argv)
{
    QTextStream outStream(stdout);
    outStream.setCodec(QTextCodec::codecForName("cp866"));

//-------------проверка правильности запуска программы-----------------
   if (argc != 3) // если количество аргументов в командной строке не 3
   {
       // выдать ошибку в консоль
       outStream << QString("Попробуйте ещё раз! Правильный шаблон запуска: LaddersCalc.exe ./input.txt ./output.txt\nТакже можно указать полный путь к файлам.") << flush;
       return 0;
   }
   if (argv[1] == NULL || argv[2] == NULL)
   {
       // выдать ошибку в консоль
       outStream << QString("Попробуйте ещё раз! Правильный шаблон запуска: LaddersCalc.exe ./input.txt ./output.txt\nТакже можно указать полный путь к файлам.") << flush;
       return 0;
   }
//-------------путь к входному файлу--------------
    QString inputFileName = argv[1];
    QFile inputFile(inputFileName);
//-------------путь к выходному файлу-------------
    QString outputFileName = argv[2];
    QFile outputFile(outputFileName);
//-----------------проверка входного файла-------------------------
   if(!inputFileName.endsWith(".txt")) // если расширение входного файла не .txt
   {
       // выдать ошибку в консоль
       outStream << QString("Формат входного файла не поддерживается! Правильный формат: .txt") << flush;
       return 0;
   }
   if(!inputFile.exists() || !inputFile.open(QIODevice::ReadOnly)) // если входной файл не существует или не открыт для чтения
   {
       // выдать ошибку в консоль
       outStream << QString("Файл с входными данными не существует или нет доступа для чтения этого файла!") << flush;
       return 0;
   }
//-----------------проверка выходного файла------------------------
   if(!outputFile.exists()) // если выходного файла не существует
   {
       // задать имя для создания нового выходного файла
       outputFileName = "new_output.txt";
   }
   else
   {
       if(!outputFileName.endsWith(".txt")) // если расширение выходного файла не .txt
       {
           // выдать ошибку в консоль
           outStream << QString("Формат выходного файла не поддерживается! Правильный формат: .txt") << flush;
           return 0;
       }
       if(outputFile.exists() && !outputFile.open(QIODevice::WriteOnly)) // если выходной файл существует, но не открыт для записи
       {
           // выдать ошибку в консоль
           outStream << QString("Файл для выходных данных существует, но нет доступа для записи в этот файл!") << flush;
           return 0;
       }
   }
    int cubeCount =  func.unpackIntValue(inputFile, outputFileName); // распаковка количества кубиков из входного файла
    if(cubeCount == NULL)
    {
        return 0;
    }
    else
    {
        int laddersCount = func.countOfLadders(cubeCount+1, cubeCount); // подсчёт количества лесенок
        func.outputIntValue(outputFileName,laddersCount); // вывод количества лесенок
    }
    return 0;
}
