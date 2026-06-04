#ifndef SECTION_1
#define SECTION_1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Content
{
public:
    enum class Type
    {
        TEXT, VIDEO, QUIZ, WORKSHEET
    };

private:
    std::string title;
    Type type;

public:
    Content(std::string title, Type type)
    : title(title), type(type){}

    std::string getTitle() const;
    Type getType() const;

    void setTitle(std::string title);
    void setType(Type type);

    void displayContent() const;

    static std::string typeToString(Type type);
};

class Lesson
{
private:
    std::string title;
    std::vector<Content> contents; //compostion

public:
    Lesson(std::string title) : title(title){}

    std::string getTitle() const;
    void setTitle(std::string title);

    void addContent(const Content& content);
    void displayLessons() const;
};

class User;

class Course
{
private:
    std::string title;
    std::string description;
    std::vector<Lesson> lessons; //composition
    std::vector<User*> participants; //aggregation

public:
    Course(std::string title, std::string description)
    : title(title), description(description){}

    std::string getTitle() const;
    std::string getDescription() const;

    void addLesson(const Lesson& lesson);
    void enrollUser(User* user);
    void removeUser(User* user);

    void displayCourse() const;
};

class User
{
private:
    std::string name;
    std::string email;
    std::vector<Course*> enrolledCourses; //Association

public:
    User(std::string name, std::string email)
    : name(name), email(email){}

    std::string getName() const;
    std::string getEmail() const;

    void enroll(Course* course);
    void leave(Course* coures);

    void displayUser() const;
};

class Platform
{
private:
    std::string name;
    std::vector<Course> courses;    //composition, max 100
    std::vector<User*> registeredUsers; //aggregation

public:
    Platform(std::string name) : name(name){}

    bool addCourse(const Course& course);
    void registerUser(User* user);

    void displayPlatform() const;
};


#endif