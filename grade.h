#ifndef GRADE_H
#define GRADE_H

#include <QString>
#include <QStringList>
#include <iostream>
class grade
{
public:
    QString courseGrade;
    QString semester;
    double gpa;
    grade(QString, QString, double);
};

#endif // GRADE_H
