#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QStringList>
#include <map>

using namespace std;
class Course {
public:
    map <int,vector<string>> CourseDiscription; // course id and title
    map <int , vector <int>> prerequisites;// course id and pre courses

    Course();

    QString getId() const;
    QString getTitle() const;
    QString getInstructor() const;
    int getCreditHours() const;
    QStringList getPrerequisites() const;
private:
    QString id;
    QString title;
    QString instructor;
    int creditHours;

};

#endif // COURSE_H

