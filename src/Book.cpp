#include "Book.h"

/** Default constructor of Book class shall take parameters to assign to Book's variables.*/
Book::Book(char *T, char *A, unsigned int Num, char *I, unsigned int B)
{
    strcpy(Title,T);
    strcpy(Author,A);
    strcpy(ISBN,I);
    Number = Num;
    Borrowed = B;
}
Book::~Book(){}

/** GetBookTitle() shall return Book's Title.
 *  Using const keyword to avoid the unintended changing.
*/
string Book::GetBookTitle() const
{
    return string(Title);
}

/** GetBookAuthor() shall return Book's Author.
 *  Using const keyword to avoid the unintended changing.
*/
string Book::GetBookAuthor() const
{
    return string(Author);
}

string Book::GetBookISBN() const
{
    return string(ISBN);
}

unsigned int Book::GetBookNumber() const
{
    return Number;
}

unsigned int Book::GetBookBorrowed() const
{
    return Borrowed;
}
/** Display() shall return all information of book.
 *  Using const keyword to avoid the unintended changing.
*/
void Book::Display() const
{
    cout << left << setw(30);                       //Print from left - there are 30 elements
    cout << left << Title << "\t" << setw(22);
    cout << left << Author << "\t" << setw(21);
    cout << left << ISBN << "\t" << setw(9);
    cout << left << Number << "\t" << setw(9);
    cout << left << Borrowed  << endl;
}

void Book::DisplayForUser() const
{
    cout << left << setw(30);                       //Print from left - there are 30 elements
    cout << left << Title << "\t" << setw(22);
    cout << left << Author << "\t" << setw(21);
    cout << left << ISBN << "\t" << setw(9) << endl;
}

void Book::UpdateBorrowingBook()
{
    Number--;
    Borrowed++;
}

void Book::UpdateReturningBook()
{
    Number++;
    Borrowed--;
}


