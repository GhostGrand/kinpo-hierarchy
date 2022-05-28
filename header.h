#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H
#include <QString>
#include <QList>
#include <QFile>



// Структура сотрудника
struct employee
{
   QString fioEmployee; // ФИО сотрудника
   int idEmployee;  // ID сотрудника
};

// Структура подразделения
struct department
{
    int idHead; // ID директора подразделения
    QList<employee> employeesOfDepartment;  // Массив сотрудников подразделения
};

/*! Проверка входных данных (.xml и .txt файлов)
*   \return true, false
*/
bool testInputDatas();

/*! Ошибки входных данных
*   \param[in] error        // ошибка
*   \param[out] int         // номер ошибки
*/
int outputError(int error);

/*! Получение входных данных
 *
 *
 */
void getInputDatas(QString txt);

int getInputID(QString txt);
