#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QStringList>
#include <map>

using namespace std;
class Course {
public:
    map <int,QString> CourseTitle;
    map <int , vector <int>[]> prerequisites;

    Course();
    Course(const QString& id, const QString& title, const QString& instructor,
           int creditHours);

    QString getId() const;
    QString getTitle() const;
    QString getInstructor() const;
    int getCreditHours() const;
    QStringList getPrerequisites() const;

    void setPrerequisites(const QStringList& newPrereqs);

private:
    QString id;
    QString title;
    QString instructor;
    int creditHours;
};

#endif // COURSE_H

