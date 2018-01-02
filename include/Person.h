/** This Person class is based class for Librarian and Student class
 *  Including some general functions which would be shared for both derived classes (Searching Book, Print Book)
 *  There are four virtual function which will be redefined in derived classes.
 *  Create: Nhut Tran
 *  25/12/2017
 */



#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "string.h"
#include <iomanip>
#include <vector>
#include "Book.h"
#include <stdlib.h>

using namespace std;

#define MAX_NAME 50
#define MAX_USERNAME 20
#define MAX_PASSWD 15


class Person
{
protected:
    char Name[MAX_NAME];
    char UserName[MAX_USERNAME];
    char Passwd[MAX_PASSWD];
    unsigned int SearchingResult = 0;
public:
    Person(char *N, char *UN, char *Pd);
    virtual void Display() const = 0;
    void PrintBook(const vector<Book>& newLibBook);
    void SearchingBook(const vector<Book>&);
    void SearchingByTitle(const vector<Book>&);
    void SearchingByAuthor(const vector<Book>&);
    virtual string GetUser() const = 0;
    virtual string GetPass() const = 0;
    virtual string GetName() const = 0;
    virtual ~Person();
};

#endif // PERSON_H
