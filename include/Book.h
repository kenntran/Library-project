/** This Book class is class shall contain variables, functions of Book class.
 *  Including some functions which would be called by Student and Librarian.
 *  Create: Nhut Tran
 *  25/12/2017
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iomanip>
#include "string.h"

using namespace std;

#define MAX_TITLE 50
#define MAX_AUTHOR 50
#define MAX_ISBN 50

class Book
{
protected:
    char Title[MAX_TITLE];
    char Author[MAX_AUTHOR];
    char ISBN[MAX_ISBN];
    unsigned int Number;
    unsigned int Borrowed;
public:
    Book(char *T, char *A, unsigned int Num, char *I, unsigned int B);
    void Display() const;
    void DisplayForUser() const;
    string GetBookTitle() const;
    string GetBookAuthor() const;
    void UpdateBorrowingBook();
    void UpdateReturningBook();
    virtual ~Book();
};

#endif // BOOK_H
