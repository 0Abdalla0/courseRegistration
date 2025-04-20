#ifndef STUDENT_H
#define STUDENT_H
#include <QFile>

class student {
public:
    student(const QString &name, const QString &id, const QString &cgpa, const QString &password);

    QString getName() const;
    QString getId() const;
    QString getCgpa() const;
    QString getPassword() const;

private:
    QString name;
    QString id;
    QString cgpa;
    QString password;
};

#endif
