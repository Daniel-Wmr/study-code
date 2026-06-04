#include "Section_1.hpp"

//Content

std::string Content::getTitle() const
{
    return this->title;
}

Content::Type Content::getType() const
{
    return this->type;
}

void Content::setTitle(std::string title)
{
    this->title = title;
}

void Content::setType(Type type)
{
    this->type = type;
}

void Content::displayContent() const
{
    std::cout << "Content: " << this->title << std::endl;
    std::cout << "Type: " << typeToString(this->type) << std::endl;
}

std::string Content::typeToString(Type type)
{
    switch(type)
    {
        case Type::TEXT: return "Text";
        case Type::VIDEO: return "Video";
        case Type::QUIZ: return "Quiz";
        case Type::WORKSHEET: return "Worksheet";
        default: return "Unknown";
    }
}

//Lesson

std::string Lesson::getTitle() const
{
    return this->title;
}

void Lesson::setTitle(std::string title)
{
    this->title = title;
}

void Lesson::addContent(const Content& content)
{
    this->contents.push_back(content);
}

void Lesson::displayLessons() const
{
    std::cout << "Lesson: " << this->title << std::endl;

    for (const Content& content : contents)
    {
        content.displayContent();
    }
}

// Course

std::string Course::getTitle() const
{
    return this->title;
}

std::string Course::getDescription() const
{
    return this->description;
}

void Course::addLesson(const Lesson& lesson)
{
    this->lessons.push_back(lesson);
}

void Course::enrollUser(User* user)
{
    if (user != nullptr)
    {
        this->participants.push_back(user);
    }
}

void Course::removeUser(User* user)
{
    this->participants.erase(
        std::remove(participants.begin(), participants.end(), user),
        participants.end()
    );
}

void Course::displayCourse() const
{
    std::cout << "\nCourse: " << this->title << std::endl;
    std::cout << "Description: " << this->description << std::endl;

    for (const Lesson& lesson : this->lessons)
    {
        lesson.displayLessons();
    }
}

// User

std::string User::getName() const
{
    return this->name;
}

std::string User::getEmail() const
{
    return this->email;
}

void User::enroll(Course* course)
{
    if (course != nullptr)
    {
        this->enrolledCourses.push_back(course);
        course->enrollUser(this);
    }
}

void User::leave(Course* course)
{
    this->enrolledCourses.erase(
        std::remove(enrolledCourses.begin(), enrolledCourses.end(), course),
        enrolledCourses.end()
    );

    if (course != nullptr)
    {
        course->removeUser(this);
    }
}

void User::displayUser() const
{
    std::cout << "\nUser: " << this->name << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Enrolled courses: " << this->enrolledCourses.size() << std::endl;
}

// Platform

bool Platform::addCourse(const Course& course)
{
    if (this->courses.size() >= 100)
    {
        std::cout << "Course limit reached!" << std::endl;
        return false;
    }

    this->courses.push_back(course);
    return true;
}

void Platform::registerUser(User* user)
{
    if (user != nullptr)
    {
        this->registeredUsers.push_back(user);
    }
}

void Platform::displayPlatform() const
{
    std::cout << "\nPlatform: " << this->name << std::endl;
    std::cout << "Courses: " << this->courses.size() << std::endl;
    std::cout << "Registered users: " << this->registeredUsers.size() <<std::endl;
}