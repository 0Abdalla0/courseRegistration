#include "grade.h"
#include <QString>
grade::grade(QString courseGrade, QString semester, double gpa)
{
    this->courseGrade = courseGrade;
    this->semester = semester;
    this->gpa = gpa;
}
