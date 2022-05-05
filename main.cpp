#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QDomDocument>
#include "header.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Объявление входного .xml файла
    QFile inputXml("input.xml");

    // Проверка наличия входного файла .xml
    if (!inputXml.exists())
    {
        puts("error: no input .xml");
        return 0;
    }

    // Проверка корректности входного .xml файла
    if (!inputXml.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        puts("invalid input data: unable to read .xml file");
        return 0;
    }



    // Объявление входного .txt файла
    QFile inputTxt("input2.txt");

    // Проверка наличия входного файла .txt
    if (!inputTxt.exists())
    {
        puts("error: no input .txt");
        return 0;
    }
}


