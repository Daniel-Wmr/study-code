#ifndef NOTE_CLASS_HPP
#define NOTE_CLASS_HPP

#include <string>


class Note
{
private:
    std::string* text;

public:
    /**
     * @brief constructor
     * 
     * This constructor takes a string and allocates it in the
     * heap-storage, while the attribute "text" of the object 
     * contains the pointer to this allocated storage-place
     * @param[in] text is a reference to a string which will be allocated
     */
    Note(const std::string& text);
    
    /**
     * @brief constructor
     * 
     * This constructor takes another object of the class "Note" 
     * and allocates the string the objects attribute points to.
     * The pointer of the new allocated string is stored in the created objects attribute
     * and, therefore, points to a copy of the text of the passed on object.
     * @param[in] otherNode is a reference to onother object of class "Note"
     */
    Note(const Note& otherNote);

    /**
     * @brief Displays the text the objects pointer refers to
     * 
     * This function displayes the string an objects pointer refers to 
     * in the terminal.
     */
    void display() const;

    /**
     * @brief Destructor
     * 
     * Frees the storage of the allocated string the objects pointer refers to.
     * The dangling pointer is set to nullptr to avoid undefined behaviour.
     */
    ~Note();
};

#endif