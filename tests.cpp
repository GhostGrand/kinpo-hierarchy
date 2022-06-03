#include "tests.h"
#include "header.h"
#include <QtTest/QTest>
tests::tests(QObject *parent) : QObject(parent)
{

}

//void tests::getOutputError()
//{
//    outputError(1)
//}

//Проверка входного ID на корректность
void tests::testGetInputID()
{
    int ID = getInputID("25");
    int expectedID = 25;
    QVERIFY2(ID == expectedID, "work");
    QVERIFY2(ID != expectedID, "not work");

}

void tests::testGetInputXmlDatasToStructs()
{

}



void tests::testGetFIOEmployee()
{

}



