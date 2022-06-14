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

    // объявление входного .xml файла
    QString locationXml = QDir::currentPath();  // расположение входного .xml файла
    QFile inputXml(locationXml + "..\\..\\kinpo-hierarchy\\input.xml");

    // объявление входного .txt файла
    QString locationTxt = QDir::currentPath();  // расположение входного .txt файла
    QFile inputTxt(locationTxt + "..\\..\\kinpo-hierarchy\\input2.txt");

    QList<struct employee> employeeList;    // массив структур сотрудников
    QList<struct department> departmentList;    // массив структур подразделений


    // выполнение проверки входных данных
    try {
        testInputDatas(locationXml, inputXml, locationTxt, inputTxt);


    }  catch (int error) {
        qDebug() << outputError(error);
        closeInputDatas(inputXml, inputTxt);
        return 0;

    }

//    closeInputDatas(inputXml, inputTxt);

    qDebug() << "work, no input errors";

//    getInputID(inputTxt);

    // получить ID пользователя
    if (getInputID(inputTxt) == 0)  // если ID отсутствует - завершить программу и вернуть ошибку
    {
        return 0;
    }

    // запарсить .xml файл
    getAllContentFromXml(inputXml, employeeList, departmentList);
    qDebug() << " ";
    qDebug() << employeeList[0].fioEmployee;
    qDebug() << employeeList[0].idEmployee;
    qDebug() << employeeList[0].departmentAffiliation;
    qDebug() << " ";

    qDebug() << employeeList[1].fioEmployee;
    qDebug() << employeeList[1].idEmployee;
    qDebug() << employeeList[1].departmentAffiliation;
    qDebug() << " ";
    qDebug() << employeeList[2].fioEmployee;
    qDebug() << employeeList[2].idEmployee;
    qDebug() << employeeList[2].departmentAffiliation;
    qDebug() << " ";
    qDebug() << employeeList[3].fioEmployee;
    qDebug() << employeeList[3].idEmployee;
    qDebug() << employeeList[3].departmentAffiliation;
    qDebug() << " ";
    qDebug() << employeeList[4].fioEmployee;
    qDebug() << employeeList[4].idEmployee;
    qDebug() << employeeList[4].departmentAffiliation;
    qDebug() << " ";
    qDebug() << employeeList[5].fioEmployee;
    qDebug() << employeeList[5].idEmployee;
    qDebug() << employeeList[5].departmentAffiliation;
    qDebug() << " ";
    qDebug() << employeeList[6].fioEmployee;
    qDebug() << employeeList[6].idEmployee;
    qDebug() << employeeList[6].departmentAffiliation;
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

        inputXml.close();   // закрыть .xml файл
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
    QFile inputXml(locationXml + "..\\..\\kinpo-hierarchy\\input.xml");                          // использовать алгоритм Дейкстры:? глубь или ширина

    // Объявление входного .txt файла
    QString locationTxt = QDir::currentPath();  // Расположение входного .txt файла             // сунуть в отдельную функцию input
    QFile inputTxt(locationTxt + "..\\..\\kinpo-hierarchy\\input2.txt");

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

void getAllContentFromXml(QFile& inputXml, QList<struct employee> &employeeList, QList<struct department> &departmentList)
{
    if (!inputXml.open(QIODevice::ReadOnly))    // проверяем, возможно ли открыть .xml файл для чтения
        qDebug() << "Error: can't read .xml file";  // вывести в консоль ошибку, что файл открыть невозможно

    QByteArray buff = inputXml.readAll();
    QDomDocument doc;

    // проверить, что .xml файл не пустой
    if (doc.setContent(buff) == false)
        qDebug() << "bad XML-file: setContent";

    QDomElement root = doc.documentElement();
    if (root.tagName() != "Department")
        qDebug() << "bad XML-file: tagname() != Department";

    QDomNode record_node = root.firstChild();
    while (record_node.isNull() == false)
    {

        getInputXmlDatasToStructs(record_node, root, employeeList, departmentList);

        record_node = record_node.nextSibling();    //тут реализовать проход по всем <Employee>
    }
}

void getInputXmlDatasToStructs(QDomNode record_node, QDomNode root, QList<struct employee> &employeeList, QList<struct department> &departmentList)
{
//    QDomNode record_node = root.firstChild();

    if (record_node.toElement().tagName() == "Employee")
    {
        employee employeeInfo;

        // получить ФИО
        employeeInfo.fioEmployee = QString::fromStdString(record_node.firstChild().nodeValue().toStdString());

        // получить ID сотрудника
        employeeInfo.idEmployee = QString::fromStdString(record_node.attributes().namedItem("id").nodeValue().toStdString()).toInt();

        // получить название отдела | чтобы определить принадлежность к отделу
        employeeInfo.departmentAffiliation = QString::fromStdString(root.attributes().namedItem("name").nodeValue().toStdString());

        // записать полученные ФИО, ID, название отдела в структуру employeeList
        employeeList.append(employeeInfo);


    }
    else if(record_node.toElement().tagName() == "Department")
    {
        getInputXmlDatasToStructs(record_node.firstChild(), record_node, employeeList, departmentList);
    }
}


