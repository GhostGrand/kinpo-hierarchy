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
   int departmentAffiliation;    // принадлежность сотрудника к подразделению
};

// Структура подразделения (отдела)
struct department
{
    int idHead; // ID директора подразделения
    QString departmentName;   // название подразделения
    QList<employee> employeesOfDepartment;  // массив сотрудников подразделения
    QList<department> childDepartments; // нижестоящие подразделения
};


/*! Проверка входных данных (.xml и .txt файлов)
*   \return true, false
*/
bool testInputDatas();

/*! Вывод ошибок входных данных
*   \param[in] error        // ошибка
*   \param[out] int         // номер ошибки
*/
int outputError(int error);

/*! Получение входных данных
 *  \param[in] txt          // входная строка
 */
void getInputDatas(QString txt);


/*! Получение входного ID сотрудника
 *  \param[in] txt          // входная строка
 *  \return int             // ID сотрудника
 */
int getInputID(QString txt);

/*! Получение .xml файла и запись данных в массивы структур
 * \param[in] xml               // .xml файл
 * \param[in] employeeList      // массив структур employeeList
 * \param[in] departmentList    // массив структур departmentList
 */
void getInputXmlDatasToStructs(QString xml, QList<struct structEmployee> &employeeList, QList<struct structDepartment> &departmentList);

/*! Получение ФИО сотрудника по его ID
 * \param[in] idEmployee        // ID сотрудника
 * \param[in] employeeList      // список сотрудников
 * \return                      // строка - ФИО сотрудника
 */
QString getFIOEmployee(int idEmployee, QList<struct structEmployee> &employeeList);
