#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QDomDocument>
#include <QDir>
#include "header.h"


// Объявление входного .xml файла
QString locationXml = QDir::currentPath();  // Расположение входного .xml файла             // сунуть в глобальные переменные  inputXml и inputTxt
QFile inputXml(locationXml + "..\\..\\kinpohierarchy\\input.xml");                          // использовать алгоритм Дейкстры:? глубь или ширина

// Объявление входного .txt файла
QString locationTxt = QDir::currentPath();  // Расположение входного .txt файла             // сунуть в отдельную функцию input
QFile inputTxt(locationTxt + "..\\..\\kinpohierarchy\\input2.txt");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    getInputDatas();
    getInputID("dfdf");

    // Выполнение проверки входных данных
    try {
        testInputDatas();


    }  catch (int error) {
        qDebug() << outputError(error);
        inputXml.close();
        inputTxt.close();
        return 0;

    }


    {
        inputXml.close();
        inputTxt.close();
        qDebug() << "work";
    }

}


bool testInputDatas()           //через try catch
{
        // Проверка наличия входного файла .xml
        if (!inputXml.exists())
        {
            //puts("error: no input .xml");
            throw 1;
        }

        // Проверка корректности входного .xml файла
        if (!inputXml.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //puts("invalid input data: unable to read .xml file");
            throw 2;
        }

        // Проверка наличия входного файла .txt
        if (!inputTxt.exists())
        {
            //puts("error: no input .txt");
            throw 3;
        }

        // Проверка наличия ID во входном .txt файле
        if(inputTxt.size() == 0)
        {
            //puts("invalid input data: .txt file is empty");
            throw 4;
        }
}

int outputError(int error)
{
    if(error == 1)
        qDebug() << "error: no input .xml";
    if(error == 2)
        qDebug() << "invalid input data: unable to read .xml file";
    if(error == 3)
        qDebug() << "error: no input .txt";
    if(error == 4)
        qDebug() << "invalid input data: .txt file is empty";
}

void getInputDatas()
{
    // Объявление входного .xml файла
    QString locationXml = QDir::currentPath();  // Расположение входного .xml файла             // сунуть в глобальные переменные  inputXml и inputTxt
    QFile inputXml(locationXml + "..\\..\\kinpohierarchy\\input.xml");                          // использовать алгоритм Дейкстры:? глубь или ширина

    // Объявление входного .txt файла
    QString locationTxt = QDir::currentPath();  // Расположение входного .txt файла             // сунуть в отдельную функцию input
    QFile inputTxt(locationTxt + "..\\..\\kinpohierarchy\\input2.txt");

}

int getInputId(QString txt)
{

}
