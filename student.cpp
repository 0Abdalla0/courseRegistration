#include "student.h"
#include "loginwindow.h"
using namespace std;
student::student(const QString &name,
                 const QString &id,
                 const QString &cgpa,
                 const QString &password,
                 const map<int, QString> &grades)
    : name(name)
    , id(id)
    , cgpa(cgpa)
    , password(password)
    , grades(grades)
{}

student::student() {}

QString student::getName() const
{
    return name;
}

QString student::getId() const
{
    return id;
}

QString student::getCgpa() const
{
    return cgpa;
}

QString student::getPassword() const
{
    return password;
}
const map<int, QString> &student::getGrades() const
{
    return grades;
}
void student::setGrades(const std::map<int, QString> &newGrades)
{
    grades = newGrades;
}

void student::viewGrades() const
{
    if (grades.empty()) {
        qDebug() << "No grades available.";
        return;
    }

    for (const auto &entry : grades) {
        qDebug() << "Course ID:" << entry.first << "Grade:" << entry.second;
    }
}
