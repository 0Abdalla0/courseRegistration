#ifndef STUDENT_H
#define STUDENT_H
#include <QFile>
#include <QJsonObject>
#include <map>
using namespace std;
class student
{
public:
    student(const QString &name, const QString &id, const QString &cgpa, const QString &password, const map<int, QString> &grades = {});
    student();
    QString getName() const;
    QString getId() const;
    QString getCgpa() const;
    QString getPassword() const;
    void viewGrades() const;
    void setGrades(const map<int, QString> &newGrades);
    const map<int, QString>& getGrades() const;


private:
    QString name;
    QString id;
    QString cgpa;
    QString password;
    map<int, QString> grades;
};

#endif
