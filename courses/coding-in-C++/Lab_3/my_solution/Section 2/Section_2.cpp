#include <iostream>
#include <string>

class User
{
protected:
    std::string name;
    int id;

public: 
    User(std::string name, int id)
    : name(name), id(id) {}

    void printInfo()
    {
        std::cout << "User name: " << this->name << std::endl;
        std::cout << "User-ID: " << this->id << std::endl;
    }
};


class Student : public User
{
private: 
    int grade;

public:
    Student(std::string name, int id, int grade) 
    : User(name, id), grade(grade) {}

    void printRole()
    {
        this->printInfo();
        std::cout << "Students grade: " << this->grade << std::endl; 
    }
};


class Instructor : public User
{
private:
    std::string course;

public: 
    Instructor(std::string name, int id, std::string course) 
    : User(name, id), course(course){}

    void printRole()
    {
        this->printInfo();
        std::cout << "Instructors course: " << this->course << std::endl;
    }
};

int main()
{
    Student student1("Sir William Masurtschak", 77, 12);
    Instructor instructor1("Master Zhornik", 97, "Behaviour");

    student1.printRole();
    instructor1.printRole();

    return 0;
}