#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QDomDocument>
#include <QDir>
#include "header.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Объявление входного .xml файла
    QString locationXml = QDir::currentPath();  // Расположение входного .xml файла
    QFile inputXml(locationXml + "..\\..\\kinpohierarchy\\input.xml");

    // Объявление входного .txt файла
    QString locationTxt = QDir::currentPath();  // Расположение входного .txt файла
    QFile inputTxt(locationTxt + "..\\..\\kinpohierarchy\\input2.txt");

    employee fioElmployee;
    employee idEmployee;
    employee departmentAffiliation;

    // Выполнение проверки входных данных
    try {
        testInputDatas(locationXml, inputXml, locationTxt, inputTxt);


    }  catch (int error) {
        qDebug() << outputError(error);
        closeInputDatas(inputXml, inputTxt);
        return 0;

    }


//    closeInputDatas(inputXml, inputTxt);

    qDebug() << "work";

    getInputID(inputTxt);

    // получить ID пользователя
    if (getInputID(inputTxt) == 0)  //если ID отсутствует - завершить программу и вернуть ошибку
    {
        return 0;
    }


    // запарсить .xml файл
    getInputXmlDatasToStructs(inputXml, fioElmployee, idEmployee, departmentAffiliation);

}


bool testInputDatas(QString& locationXml, QFile& inputXml, QString& locationTxt, QFile& inputTxt)
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

int getInputID(QFile& inputTxt)
{

    // входной ID
    int inputID;
    // объект класса, который хранит получившиеся строки
    QString idDatas;
    if (!inputTxt.open(QIODevice::ReadOnly))    // проверяем, возможно ли открыть .txt файл для чтения
        return 0;
    idDatas = inputTxt.readAll();   // записать полученную строку в idDatas
    qDebug() << idDatas;    // вывести в консоль idDatas

    // проверить корректность входных данных
    for (int i = 0; i < idDatas.length(); i++)
    {
        if (!idDatas[i].isDigit())  // если символ не число
        {
            qDebug() << "incorrect ID";
            return 0;   // вернуть 0 и вывести ошибку
        }
    }


    inputID = idDatas.toInt();
    return inputID;

}

void closeInputDatas(QFile& inputXml, QFile& inputTxt)
{
    inputXml.close();
    inputTxt.close();
}


void getInputXmlDatasToStructs(QString xml, QList<struct structEmployee> &employeeList, QList<struct structDepartment> &departmentList)
{

}
