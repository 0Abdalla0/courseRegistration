#include "course.h"
#include"uploadcourse.h"
#include"ui_uploadcourse.h"
#include<iostream>
Course::Course()
    : id(0),
    title(""),
    instructorName(""),
    instructorEmail(""),
    syllabus(""),
    creditHours(0)
{cnt++;}
Course::Course(const int& id, const QString& title, const QString& instructorName, QString& instructorEmail,QString& syllabus,int& creditHours)
    : id(id),
    title(title),
    instructorName(instructorName),
    instructorEmail(instructorEmail),
    syllabus(syllabus),
    creditHours(creditHours)
{cnt++;}


int Course::getId() const {
    return id;
}

QString Course::getTitle() const {
    return title;
}

QString Course::getInstructorName() const {
    return instructorName;
}
QString Course::getInstructorEmail() const {
    return instructorEmail;
}
QString Course::getSyllabus() const {
    return syllabus;
}

int Course::getCreditHours() const {
    return creditHours;
}

// ostream& operator<<(ostream& out,Course c){
//     out<<c.getId()<<endl
//     <<c.getTitle().toStdString()<<endl
//     <<c.getInstructorName().toStdString()<<endl
//     <<c.getInstructorEmail().toStdString()<<endl
//     <<c.getSyllabus().toStdString()<<endl
//         <<c.getCreditHours()<<endl;
//         return out;
// }
