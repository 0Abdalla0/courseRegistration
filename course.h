#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QStringList>
#include <iostream>
#include <map>
using namespace std;
class Course
{
public:
    map<int, vector<string>> CourseDiscription; // course id and title
    map<int, vector<int>> prerequisites;        // course id and pre courses
    int cnt = 0;
    Course();
    Course(const int &id,
           const QString &title,
           const QString &instructorName,
           QString &instructorEmail,
           QString &syllabus,
           int &creditHours);
    int getId() const;
    QString getTitle() const;
    QString getInstructorName() const;
    QString getInstructorEmail() const;
    QString getSyllabus() const;
    int getCreditHours() const;
    // friend ostream& operator<<(ostream& out,Course& c);
private:
    int id;
    QString title;
    QString instructorName;
    QString instructorEmail;
    QString syllabus;
    int creditHours;
};

#endif // COURSE_H
