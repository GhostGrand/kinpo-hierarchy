#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H
#include <QString>
#include <QList>

struct employee
{
   QString fioEmployee; // ФИО сотрудника
   int idEmployee;  // ID сотрудника
};

struct department
{
    int idHead; // ID директора подразделения
    QList<employee> employeesOfDepartment;  // Массив сотрудников подразделения
};


