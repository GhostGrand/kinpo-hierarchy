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

void tests::testGetInputID()
{
    int ID = getInputID("25");
    int expectedID = 25;
    QVERIFY2(ID == expectedID, "work");
}

void tests::testGetInputXmlDatasToStructs()
{

}



void tests::testGetFIOEmployee()
{

}



