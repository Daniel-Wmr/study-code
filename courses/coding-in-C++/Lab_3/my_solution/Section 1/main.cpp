#include "Section_1.hpp"

int main()
{
    Platform moodle("Moodle RV");

    User user1("Max Mustermann", "muster@example.de");
    moodle.registerUser(&user1);

    Course cppCourse("C++ Basics", "Introduction to C++ programming");

    Lesson lesson1("Classes and Objects");
    lesson1.addContent(Content("What is a class?", Content::Type::TEXT));
    lesson1.addContent(Content("Class tutorial video", Content::Type::VIDEO));

    Lesson lesson2("UML Relationships");
    lesson2.addContent(Content("Composition vs Aggregation", Content::Type::QUIZ));

    cppCourse.addLesson(lesson1);
    cppCourse.addLesson(lesson2);

    moodle.addCourse(cppCourse);

    user1.enroll(&cppCourse);

    moodle.displayPlatform();
    user1.displayUser();
    cppCourse.displayCourse();

    return 0;
}