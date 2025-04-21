#ifndef REGISTERCOURSE_H
#define REGISTERCOURSE_H

#include "student.h"
#include "course.h"
#include <vector>
using namespace std;
class RegisterCourse {
public:
    RegisterCourse(student* student, vector<Course>* availableCourses);

    void run();

private:
    void displayMenu() const;
    void displayCourses() const;
    void searchCourses() const;
    void registerForCourse();
    void viewCourseDetails() const;
    void displayStudentInfo() const;


    bool checkPrerequisites(const Course& course) const;
    const Course* findCourseById(const string& courseId) const;

    student* m_student;
    vector<Course>* m_availableCourses;
};

#endif // REGISTERCOURSE_H



// #ifndef REGISTERCOURSE_H
// #define REGISTERCOURSE_H

// #include <QDialog>
// #include <QList>
// #include "course.h"
// #include "student.h"

// namespace Ui {
// class RegisterCourse;
// }

// class RegisterCourse : public QDialog
// {
//     Q_OBJECT

// public:
//     explicit RegisterCourse(student* student, QList<Course>* availableCourses, QWidget *parent = nullptr);
//     ~RegisterCourse();

// private slots:
//     void on_searchLineEdit_textChanged(const QString &searchText);
//     void on_registerButton_clicked();
//     void on_viewDetailsButton_clicked();

// private:
//     void populateCoursesTable();
//     void updateStudentInfo();
//     bool checkPrerequisites(const Course& course);

//     Ui::RegisterCourse *ui;
//     student* m_student;
//     QList<Course>* m_availableCourses;
// };

// #endif // REGISTERCOURSE_H
