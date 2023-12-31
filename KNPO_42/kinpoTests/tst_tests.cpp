#include <QtTest>
#include "C:/Qt/Projects/KNPO_42/LaddersCalc/functions.h"

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests();
    ~Tests();

private slots:
    // Тесты функции unpackIntValue
    void inputFileIsEmpty();
    void inputValueMore100();
    void inputTextLengthMore3();
    void inputTextLengthMore3AndNotAllDigits();
    void inputTextNotAllDigits();
    void inputTextAllNotDigits();
    void inputValueNotInStartBecauseSpace();
    void inputValueNotInStartBecauseTab();
    void inputValueInRangeOnlyAbs();
    void inputValueIsNotInRangeIsNull();
    void inputValueIsInRange();
    // Тесты функции countOfLadders
    void minCountOfCubes();
    void sevCountOfCubes();
    void maxCountOfCubes();
    void nullCountOfCubes();
    // Тесты функции outputIntValue
    void outputNegative();
    void outputNull();
    void outputPositive();
};

Tests::Tests()
{

}

Tests::~Tests()
{

}

//---------------------------------------unpackIntValue-------------------------------------------------
void Tests::inputFileIsEmpty()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest1.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes1.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Файл с входными данными является пустым!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes1.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueMore100()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest2.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes2.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! Число N не лежит в заданном диапазоне (1<=N<=100)";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes2.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputTextLengthMore3()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest3.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes3.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не может быть больше трёх символов!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes3.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputTextLengthMore3AndNotAllDigits()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest4.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes4.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не может быть больше трёх символов!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes4.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputTextNotAllDigits()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest5.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes5.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes5.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputTextAllNotDigits()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest6.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes6.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes6.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueNotInStartBecauseSpace()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest7.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes7.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes7.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueNotInStartBecauseTab()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest8.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes8.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes8.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueInRangeOnlyAbs()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest9.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes9.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! В строке не должно быть символов, не являющихся цифрами!";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes9.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueIsNotInRangeIsNull()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest10.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes10.txt");
    int expValue = NULL;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "Неверные входные данные! Число N не лежит в заданном диапазоне (1<=N<=100)";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes10.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

void Tests::inputValueIsInRange()
{
    Functions func;
    // Проверка возвращаемого значения unpackIntValue
    QFile inputFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTest11.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    int value = func.unpackIntValue(inputFile, "C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes11.txt");
    int expValue = 13;
    QCOMPARE(expValue, value);

    // Проверка выводимой ошибки в выходной файл
    QString expError = "";
    QFile errFile("C:/Qt/Projects/KNPO_42/kinpoTests/unpackTestRes11.txt");
    errFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&errFile);
    in.setCodec("UTF-8");
    QString actError = in.readAll();
    QCOMPARE(actError, expError);
}

//-------------------------------------------countOfLadders-----------------------------------------------
void Tests::minCountOfCubes()
{
    Functions func;
    int expCountOfLadders = 1;
    int actCountOfLadders = func.countOfLadders(2,1);
    QCOMPARE(actCountOfLadders, expCountOfLadders);
}

void Tests::sevCountOfCubes()
{
    Functions func;
    int expCountOfLadders = 4;
    int actCountOfLadders = func.countOfLadders(7,6);
    QCOMPARE(actCountOfLadders, expCountOfLadders);
}

void Tests::maxCountOfCubes()
{
    Functions func;
    int expCountOfLadders = 444793;
    int actCountOfLadders = func.countOfLadders(101,100);
    QCOMPARE(actCountOfLadders, expCountOfLadders);
}

void Tests::nullCountOfCubes()
{
    Functions func;
    int expCountOfLadders = 0;
    int actCountOfLadders = func.countOfLadders(-1,0);
    QCOMPARE(actCountOfLadders, expCountOfLadders);
}

//-----------------------------------------outputIntValue-----------------------------------------------
void Tests::outputNegative()
{
    Functions func;
    func.outputIntValue("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest1.txt", -3);
    QString expStr = "-3\n";
    QFile outputFile("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest1.txt");
    outputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&outputFile);
    in.setCodec("UTF-8");
    QString actStr = in.readAll();
    QCOMPARE(actStr, expStr);
}

void Tests::outputNull()
{
    Functions func;
    func.outputIntValue("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest2.txt", 0);
    QString expStr = "0\n";
    QFile outputFile("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest2.txt");
    outputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&outputFile);
    in.setCodec("UTF-8");
    QString actStr = in.readAll();
    QCOMPARE(actStr, expStr);
}

void Tests::outputPositive()
{
    Functions func;
    func.outputIntValue("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest3.txt", 1111);
    QString expStr = "1111\n";
    QFile outputFile("C:/Qt/Projects/KNPO_42/kinpoTests/outputTest3.txt");
    outputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&outputFile);
    in.setCodec("UTF-8");
    QString actStr = in.readAll();
    QCOMPARE(actStr, expStr);
}


QTEST_APPLESS_MAIN(Tests)

#include "tst_tests.moc"
