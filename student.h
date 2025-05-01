#ifndef STUDENT_H
#define STUDENT_H
#include <QFile>
#include <QJsonObject>

class student
{
public:
    student(const QString &name, const QString &id, const QString &cgpa, const QString &password);
    student();
    QString getName() const;
    QString getId() const;
    QString getCgpa() const;
    QString getPassword() const;

    QJsonObject toJson() const
    {
        QJsonObject obj;
        obj["name"] = name;
        obj["id"] = id;
        obj["cgpa"] = cgpa;
        obj["password"] = password;
        return obj;
    }

    static student fromJson(const QJsonObject &obj)
    {
        student s;
        s.name = obj["name"].toString();
        s.id = obj["id"].toString();
        s.cgpa = obj["cgpa"].toString();
        s.password = obj["password"].toString();
        return s;
    }

private:
    QString name;
    QString id;
    QString cgpa;
    QString password;
};

#endif
