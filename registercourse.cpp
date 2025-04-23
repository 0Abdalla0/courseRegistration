#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course
{
public:
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getInstructor() const { return instructor; }
    int getCreditHours() const { return creditHours; }

private:
    string id;
    string title;
    string instructor;
    int creditHours;
};

class Student
{
public:
    string getName() const { return name; }
    string getId() const { return id; }
    string getCgpa() const { return cgpa; }

private:
    string name;
    string id;
    string cgpa;
};

class RegisterCourse
{
public:
    RegisterCourse(Student *student, vector<Course> *availableCourses)
        : m_student(student)
        , m_availableCourses(availableCourses)
    {}

    void run()
    {
        while (true) {
            displayMenu();
            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                displayCourses();
                break;
            case 2:
                searchCourses();
                break;
            case 3:
                registerForCourse();
                break;
            case 4:
                viewCourseDetails();
                break;
            case 5:
                displayStudentInfo();
                break;
            case 6:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

private:
    void displayMenu()
    {
        cout << "\nCourse Registration System\n";
        cout << "1. View All Courses\n";
        cout << "2. Search Courses\n";
        cout << "3. Register for Course\n";
        cout << "4. View Course Details\n";
        cout << "5. View Student Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }

    void displayCourses()
    {
        cout << "\nAvailable Courses:\n";
        cout << "-------------------------------------------------\n";
        cout << "ID\tTitle\tInstructor\tCredits\n";
        cout << "-------------------------------------------------\n";

        for (const auto &course : *m_availableCourses) {
            cout << course.getId() << "\t" << course.getTitle() << "\t" << course.getInstructor()
                 << "\t" << course.getCreditHours() << "\n";
        }
    }

    void searchCourses()
    {
        cout << "Enter search term: ";
        string searchTerm;
        getline(cin, searchTerm);

        transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

        cout << "\nSearch Results:\n";
        cout << "-------------------------------------------------\n";
        cout << "ID\tTitle\tInstructor\tCredits\n";
        cout << "-------------------------------------------------\n";

        for (const auto &course : *m_availableCourses) {
            string id = course.getId();
            string title = course.getTitle();
            string instructor = course.getInstructor();

            // Convert to lowercase for comparison
            string lowerId = id;
            string lowerTitle = title;
            string lowerInstructor = instructor;
            transform(lowerId.begin(), lowerId.end(), lowerId.begin(), ::tolower);
            transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
            transform(lowerInstructor.begin(),
                      lowerInstructor.end(),
                      lowerInstructor.begin(),
                      ::tolower);

            if (lowerId.find(searchTerm) != string::npos
                || lowerTitle.find(searchTerm) != string::npos
                || lowerInstructor.find(searchTerm) != string::npos) {
                cout << id << "\t" << title << "\t" << instructor << "\t" << course.getCreditHours()
                     << "\n";
            }
        }
    }

    void registerForCourse()
    {
        cout << "Enter Course ID to register: ";
        string courseId;
        getline(cin, courseId);

        // Find the course
        auto it = find_if(m_availableCourses->begin(),
                          m_availableCourses->end(),
                          [&courseId](const Course &c) { return c.getId() == courseId; });

        if (it == m_availableCourses->end()) {
            cout << "Course not found.\n";
            return;
        }

        if (!checkPrerequisites(*it)) {
            cout << "You don't meet the prerequisites for this course.\n";
            return;
        }

        // Here you would normally add the course to the student's registered courses
        cout << "Successfully registered for " << it->getTitle() << "\n";
    }

    void viewCourseDetails()
    {
        cout << "Enter Course ID to view details: ";
        string courseId;
        getline(cin, courseId);

        auto it = find_if(m_availableCourses->begin(),
                          m_availableCourses->end(),
                          [&courseId](const Course &c) { return c.getId() == courseId; });

        if (it == m_availableCourses->end()) {
            cout << "Course not found.\n";
            return;
        }

        cout << "\nCourse Details:\n";
        cout << "-------------------------------------------------\n";
        cout << "ID: " << it->getId() << "\n";
        cout << "Title: " << it->getTitle() << "\n";
        cout << "Instructor: " << it->getInstructor() << "\n";
        cout << "Credits: " << it->getCreditHours() << "\n";
    }

    void displayStudentInfo()
    {
        cout << "\nStudent Information:\n";
        cout << "-------------------------------------------------\n";
        cout << "Name: " << m_student->getName() << "\n";
        cout << "ID: " << m_student->getId() << "\n";
        cout << "CGPA: " << m_student->getCgpa() << "\n";
    }

    bool checkPrerequisites(const Course &course)
    {
        // Implementation depends on how prerequisites are stored
        // This is a placeholder - adjust according to your actual data structure
        return true; // Assuming all prerequisites are met for this example
    }

    Student *m_student;
    vector<Course> *m_availableCourses;
};
