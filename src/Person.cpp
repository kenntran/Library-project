#include "Person.h"
#include "string.h"

/** Constructor of Person shall take three parameters to assign for it's variables (Name, UserName and Password) */

Person::Person(char *N, char *UN, char *Pd)
{
    strcpy(Name,N);
    strcpy(UserName,UN);
    strcpy(Passwd,Pd);
}

Person::~Person(){};

/** PrintBook() shall print all books in Library.
 *  PrintBook() shall print all book's objects in Book vector.
 *  Using const keyword for Book vector to avoid the unintended changing.
*/
void Person::PrintBook(const vector<Book>& newLibBook)
{
    cout << "List all Books" << endl;
    cout << "Book Information:" << endl;
    cout << "Total Book in Library: " << newLibBook.size() << endl << endl;
    cout << left << setw(30) << "Name\t" << left << setw(25) << "Author\t" << left << setw(20) << "ISBN\t" << left << setw(9) << "Number\t" << left << setw(9)<< "Borrowed" << endl;
    for(unsigned int i = 0; i < newLibBook.size(); i++)
    {
        newLibBook[i].Display();
    }
    cout << endl;
}

/** SearchingBook function shall be used for searching books in library according to book's title or author.
 *  First, SearchingBook() would ask for selection (searching by Title or Author).
 *  Then, the function shall switch to appropriate searching function.
 *  Finally, SearchingBook() shall clear all terminal after searching.
 *  SearchingBook() take the Book vector as parameters to pass to children functions.
 *  Using const keyword for Book vector to avoid the unintended changing.
 */
void Person::SearchingBook(const vector<Book>& LibraryBook)
{
    int Selecting;

    //do
   // {
        cout << "**********************************" << endl;
        cout << "**      Searching Book          **" << endl;
        cout << "* Please make the selection:    **" << endl;
        cout << "* 1.Searching by Book's Title.  **" << endl;
        cout << "* 2.Searching by Book's Author. **" << endl;
        cout << "* 3.Exit.                       **" << endl;
        cout << "**********************************" << endl;
        cin >> Selecting;

        switch(Selecting)
        {
            case 1:
                SearchingByTitle(LibraryBook);
                //cin.get();
                //system("cls");
                break;

            case 2:
                SearchingByAuthor(LibraryBook);
                //cin.get();
                //system("cls");
                break;


        }
    //}while(Selecting != 3);
}

/** SearchingByTitle function shall be used for searching books in library according to book's title.
 *  First, SearchingByTitle() would ask for book's title or (exit).
 *  Then, the function shall using for loop and find()(algorithm) to searching book's title according to input searching keywords.
 *  Finally, SearchingByTitle() shall print all possible searching results.
 *  SearchingByTitle() take the Book vector as parameters.
 *  Using const keyword for Book vector to avoid the unintended changing.
 *  Using string::npos to compare with string in book title's object.
 *  (string::npos = -1, so if condition will be failed if find() cannot find anything related with input keyword)
 */
void Person::SearchingByTitle(const vector<Book>& SearchingTil)
{
    string SearchingTitle;
    SearchingResult = 0;
    //Ignore the previous input value in buffer memory
    cin.ignore();
    cout << "******************************************" << endl;
    cout << "**        Searching Book By Title       **" << endl;
    cout << "* Please enter Book's Title             **" << endl;
    cin >> SearchingTitle;
    cin.get(); //Stop the terminal to read the result
    cout << endl;

    cout <<left << setw(5) << "No." << left << setw(30) << "Name\t" << left << setw(25) << "Author\t" << left << setw(20) << "ISBN\t" << left << setw(9) << "Number\t" << left << setw(9)<< "Borrowed" << endl;
    for(unsigned int i = 0; i < SearchingTil.size(); i++)
    {
        //Compare with string::npos (value -1) if there is no any string matched with GetBookTile then if condition would be failed
        //Take the Book's Title in Book vector and compare to input string.
        if((SearchingTil[i].GetBookTitle()).find(SearchingTitle) != string::npos)
        {
            cout << left << setw(5) << i + 1;
            SearchingTil[i].Display();
            SearchingResult++;
        }
    }
    if(SearchingResult == 0)
    {
        cout << endl;
        cout << "There is no Book matched to your search" << endl;
    }
    cout << endl;
}

/** SearchingByAuthor function shall be used for searching books in library according to book's author.
 *  First, SearchingByAuthor() would ask for book's author or (exit).
 *  Then, the function shall using for loop and find()(algorithm) to searching book's author according to input searching keywords.
 *  Finally, SearchingByAuthor() shall print all possible searching results.
 *  SearchingByAuthor() take the Book vector as parameters.
 *  Using const keyword for Book vector to avoid the unintended changing.
 *  Using string::npos to compare with string in book author's object.
 *  (string::npos = -1, so if condition will be failed if find() cannot find anything related with input keyword)
 */
void Person::SearchingByAuthor(const vector<Book>& SearchingAuthor)
{

    string SearchAuthor;
    //Ignore the previous input value in buffer memory
    cin.ignore();
    cout << endl;
    cout << "******************************************" << endl;
    cout << "**      Searching Book By Author        **" << endl;
    cout << "* Please enter Book's Title             **" << endl;
    cout << endl;
    cin >> SearchAuthor;
    cin.get(); //Stop the terminal to read the result
    cout << endl;

    cout <<left << setw(5) << "No." << left << setw(30) << "Name\t" << left << setw(25) << "Author\t" << left << setw(20) << "ISBN\t" << left << setw(9) << "Number\t" << left << setw(9)<< "Borrowed" << endl;
    for(unsigned int i = 0; i < SearchingAuthor.size(); i++)
    {
        //Compare with string::npos (value -1) if there is no any string matched with GetBookTile then if condition would be failed
        //Take the Book's Title in Book vector and compare to input string.
        if((SearchingAuthor[i].GetBookAuthor()).find(SearchAuthor) != string::npos)
        {
            cout << left << setw(5) << i + 1;
            SearchingAuthor[i].Display();
            SearchingResult++;
        }
    }
    if(SearchingResult == 0)
    {
        cout << endl;
        cout << "There is no Book matched to your search" << endl;
    }
    cout << endl;
}

