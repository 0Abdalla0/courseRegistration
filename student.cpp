#include "student.h"


student::student(const QString &name, const QString &id, const QString &cgpa, const QString &password)
    : name(name), id(id), cgpa(cgpa), password(password) {}

QString student::getName() const {
    return name;
}

QString student::getId() const {
    return id;
}

QString student::getCgpa() const {
    return cgpa;
}

QString student::getPassword() const {
    return password;
}
