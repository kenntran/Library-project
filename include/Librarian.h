/** This Librarian class is derived class of Person class.
 *  Including general functions which would be used by Librarian.
 *  Create: Nhut Tran
 *  25/12/2017
 */

#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "string.h"
#include <Person.h>
#include "Student.h"

class Librarian : public Person
{
public:
    Librarian();
    ~Librarian();
    virtual void Display() const;
    void AddingBook(vector<Book>&);
    void AddingStudent(vector<Student>&);
    void PrintMember(const vector<Student>&);
    void RemovingStudent(vector<Student>&);
    void RemovingBook(vector<Book>&);
    void RemovingLibBook(vector<Book>&);
    void SearchingStudent(const vector<Student>&);
    virtual string GetUser() const;
    virtual string GetPass() const;
    virtual string GetName() const;
private:
};

#endif // LIBRARIAN_H
