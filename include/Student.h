/** This Student class is derived class of Person class.
 *  Including general functions which would be used by Student.
 *  Create: Nhut Tran
 *  25/12/2017
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>
#include "Book.h"
#include "ctime"

class Student : public Person
{
public:
    Student(char *N, char *UN, char *Pd);
    void PassingChangedPasswd(char *Pd);
    void ChangingPassword();
    virtual void Display() const;
    virtual ~Student();
    virtual string GetUser() const;
    virtual string GetPass() const;
    virtual string GetName() const;
    unsigned int GetBorrowedNum() const;
    void SetBorrowedNum(unsigned int B);
    void BorrowingBook(const vector<Book>&, vector<Book>&);
    void ReturningBook(vector<Book>&);
    void PrintBorrowedBook();
    void Borrowing(vector<Book>&,vector<Book>&);
    vector<Book> &GetBorrowedBook();                //function used to access vector<Book> BorrowedBook (private variable)
protected:
    unsigned int Borrowed = 0;
private:
    int Selection = 0;
    vector<Book> BorrowedBook;
};

#endif // STUDENT_H
