/**
 * @file NoteClass.cpp
 * @brief Lab_2 Section 2
 * 
 * In this Section a class "Note" is implemented, which has
 * two constructors, one methode "display()" and one destructor.
 * One constructor takes a string in order to allocate the text in the heap-storage, 
 * while the other one takes another object of the class "Note" and 
 * allocates the same storaged text of this other Note in another place of the heap-storage.
 * Both of the created objects do have own pointers to different storage-places,
 * while during the constructor-call the same text is copied from one object to the other.
 * The display methode displayes the text the objects pointers point on in the terminal.
 * The destructor frees the allocated storage of the objects string-attributes.
 */
#include <iostream>
#include <string>

#include "NoteClass.hpp"

Note::Note(const std::string& text)
    : text(new std::string(text))
{}

Note::Note(const Note& otherNote)
    : text(new std::string(*otherNote.text))
{}

Note::~Note()
{
    delete this->text;
    this->text = nullptr;
    std::cout << "Memory released." << std::endl;
}

void Note::display() const
{
    if (this->text != nullptr)
    {
        std::cout << "Text: " << *this->text << std::endl;
    }
    else
    {
        std::cout << "This Note is empty." << std::endl;
    }

}

int main()
{
    Note note1("Daniel ist der King!!!");
    Note note2(note1);
    note1.display();
    note2.display();


    return 0;
}