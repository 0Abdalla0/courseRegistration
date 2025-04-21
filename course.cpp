#include "course.h"
#include"uploadcourse.h"
#include"ui_uploadcourse.h"
Course::Course()
    : id(""),
    title(""),
    instructor(""),
    creditHours(0)
{}
// Course::Course(const QString& id, const QString& title, const QString& instructor,
//                int creditHours)
//     : id(id),
//     title(title),
//     instructor(instructor),
//     creditHours(creditHours)
// {}


QString Course::getId() const {
    return id;
}

QString Course::getTitle() const {
    return title;
}

QString Course::getInstructor() const {
    return instructor;
}

int Course::getCreditHours() const {
    return creditHours;
}


