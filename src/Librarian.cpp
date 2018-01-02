#include "Librarian.h"

/** Default constructor of Librarian class shall take parameters to assign to Librarian's variables.
 *  Librarian inherits form Person class.
*/

Librarian::Librarian():Person("Librarian","librarian","123")
{
    strcpy(Name,"Librarian");
    strcpy(UserName,"librarian");
    strcpy(Passwd,"123");
}

Librarian::~Librarian(){}

/** RemovingStudent function shall be used for deleting student's member according to Student's name
 *  First, RemovingStudent() would call SearchingStudent() to search Student's name
 *  Then, the function shall list all searching results.
 *  Finally, RemovingStudent() shall delete Student's object according to the selection of Librarian
 *  RemovingStudent take the Student's objects in vector as parameters
 */
void Librarian::RemovingStudent(vector<Student>& removingLibStudent)
{
    char Chosen;
    int Selecting;
    do
    {
        SearchingStudent(removingLibStudent);
        cin.ignore();
        cout << "********************************" << endl;
        cout << "**  Removing Student Member   **" << endl;
        cout << "* Please make the selection:  **" << endl;
        cout << "* 0.Exit.                     **" << endl;
        cout << "********************************" << endl;
        cin >> Selecting;
        cout << endl;
        //To exit the do-while loop, user would enter 0 (due to initial declaration Selecting = 0)
        //Must be added 1 more to avoid it.

        Selecting = Selecting + 1;
        if(Selecting != 1)
        {
            cout << "Do you want to this Student member " << removingLibStudent[Selecting - 2].GetName() << " ?(y/n)";
            cin >> Chosen;

            Chosen = toupper(Chosen);

            if(Chosen == 'Y')
            {
                cout << "Student " << removingLibStudent[Selecting - 2].GetName() << " has been deleted!!!" << endl;
                removingLibStudent.erase(removingLibStudent.begin() + (Selecting-2));
            }
            else {}
        }
    }while( Selecting != 1);

}

/** RemovingBook function shall be used for switching searching book function to search library's books according to Book's Titles or Book's Author
 *  First, RemovingBook() would call SearchingBook() to search book - there are two options to search Book (according to book's title or book's author)
 *  Then, in the searching function shall list all searching results.
 *  Finally, RemovingStudent() shall call RemovingLibBook() to delete Book's object according to the selection of Librarian.
 *  RemovingBook take the Book's objects in vector as parameters to pass to children functions
 */
void Librarian::RemovingBook(vector<Book>& LibraryBook)
{
    int Selecting;

    do
    {
        cout << "**********************************" << endl;
        cout << "**      Removing Book           **" << endl;
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
                RemovingLibBook(LibraryBook);
                cin.get();
                break;

            case 2:
                SearchingByAuthor(LibraryBook);
                RemovingLibBook(LibraryBook);
                cin.get();
                break;
        }
    }while(Selecting != 3);
}

/** RemovingLibBook function shall be used for deleting library's books according to Book's Titles or Book's Author
 *  First, RemovingLibBook() would ask for the selection base on searching results or exit.
 *  Then, the function shall ask confirmation of Librarian.
 *  Finally, RemovingLibStudent() shall to delete Book's object according to the selection of Librarian
 *  RemovingLibBook take the Book's objects in vector as parameters.
 *  Using vector.erase() to delete object in vector.
 */
void Librarian::RemovingLibBook(vector<Book>& RemoveLibBook)
{
    char Chosen;
    int Selecting;
    do
    {

        cin.ignore();
        cout << "********************************" << endl;
        cout << "**      Removing Book         **" << endl;
        cout << "* Please make the selection:  **" << endl;
        cout << "* 0.Exit.                     **" << endl;
        cout << "********************************" << endl;
        cin >> Selecting;
        cout << endl;
        //To exit the do-while loop, user would enter 0 (due to initial declaration Selecting = 0)
        //Must be added 1 more to avoid it.

        Selecting = Selecting + 1;
        if(Selecting != 1)
        {
            cout << "Do you want to delete book " << RemoveLibBook[Selecting - 2].GetBookTitle() << " ?(y/n)";
            cin >> Chosen;

            Chosen = toupper(Chosen);

            if(Chosen == 'Y')
            {
                cout << "Book " << RemoveLibBook[Selecting - 2].GetBookTitle() << " has been deleted!!!" << endl;
                RemoveLibBook.erase(RemoveLibBook.begin() + (Selecting-2));
            }
            else {}
        }
        cin.get();
    }while( Selecting != 1);
}

/** GetUser() shall return UserName of Librarian account in string type
 *  Using const keyword to avoid the unintended changing.
*/
string Librarian::GetUser() const
{
    return string(UserName);
}

/** GetPass() shall return Password of Librarian account in string type
 *  Using const keyword to avoid the unintended changing.
*/
string Librarian::GetPass() const
{
    return string(Passwd);
}

/** GetName() shall return Librarian's Name in string type.
 *  Using const keyword to avoid the unintended changing.
*/
string Librarian::GetName() const
{
    return string(Name);
}

/** Display() shall return all information of Librarian account.
 *  Using const keyword to avoid the unintended changing.
*/
void Librarian::Display() const
{
    cout << "Librarian Information:" << endl;
    cout << "Name: " << Name << endl;
    cout << "User Name: " << UserName << endl;
    cout << "Password: " << Passwd << endl;
}

/** AddingBook function shall be used for adding new library's books.
 *  First, AddingBook() would ask for number of books Librarian would like to add to library.
 *  Then, the function shall ask essential information of book (Title, Author, ISBN, Number of this book ).
 *  Finally, AddingBook() shall to add new Book object into Book vector.
 *  AddingBook() take the Book vector as parameters.
 *  Using vector.push_back() to add new object in vector.
 */
void Librarian::AddingBook(vector<Book>& newBook)
{
    char Title[MAX_TITLE], Author[MAX_AUTHOR], ISBN[MAX_ISBN];
    unsigned int Number;
    unsigned int BorrowedNumber = 0;

    cout << "How many Books you want to add: ";
    int AddingSize;
    cin >> AddingSize;

    for(int i = 0; i < AddingSize; i++)
    {
        cin.ignore();
        cout << "Adding new Book" << endl;
        cout << "Book's Title: ";
        cin.getline(Title,MAX_TITLE);
        cout << "Book's Author: ";
        cin.getline(Author,MAX_AUTHOR);
        cout << "Book's ISBN: ";
        cin.getline(ISBN,MAX_ISBN);
        cout << "Book's Number: ";
        cin >> Number;
        cin.get();


        Book newLibraryBook(Title,Author,Number,ISBN,BorrowedNumber);
        newBook.push_back(newLibraryBook);
        cout << "New " << Title<< " books have been add" << endl;
        cout << endl;
    }
    cout << endl;
}

/** AddingStudent function shall be used for adding new library's member - Student.
 *  First, AddingStudent() would ask for number of students Librarian would like to add.
 *  Then, the function shall ask essential information of Student (Name, UserName, Password).
 *  Finally, AddingStudent() shall to add new Student object into Student vector.
 *  AddingStudent() take the Student vector as parameters.
 *  Using vector.push_back() to add new object in vector.
 */
void Librarian::AddingStudent(vector<Student>& newMember)
{
    char Name[MAX_NAME],UN[MAX_USERNAME],Ps[MAX_PASSWD];

    cout << "How many Student you want to add: ";
    int AddingSize;
    cin >> AddingSize;

    for(int i = 0; i < AddingSize; i ++)
    {
        cin.ignore();
        cout << "Adding new Student" << endl;
        cout << "Name: ";
        cin.getline(Name,MAX_NAME);
        cout << "User name: ";
        cin.getline(UN,MAX_USERNAME);
        cout << "Password: ";
        cin.getline(Ps,MAX_PASSWD);
        cin.get();

        Student *newStudent= new Student(Name,UN,Ps);
        newMember.push_back(*newStudent);
        cout << "New Student " << Name << " has been add to library" << endl;
    }
    cout << endl;
}

/** PrintMember() shall print all students - members in Library.
 *  PrintMember() shall print all student's objects in Student vector.
 *  Using const keyword for Book vector to avoid the unintended changing.
*/
void Librarian::PrintMember(const vector<Student>& newMember)
{
    cout << "List all Students" << endl;
    cout << "Student Information:" << endl;
    cout << "Total Student members: " << newMember.size() << endl << endl;
    cout << left << setw(21) << "Name\t" << left << setw(21) << "User name\t" << left << setw(20) << "Password\t" << left << setw(10)<< "Borrowed" << endl;
    for(unsigned int i = 0; i < newMember.size(); i++)
    {
        newMember[i].Display();
    }
    cout << endl;

}

/** SearchingStudent function shall be used for searching student member in library according to student's name.
 *  First, SearchingStudent() would ask for student's name or (exit).
 *  Then, the function shall using for loop and find()(algorithm) to searching student's name according to input searching keywords.
 *  Finally, SearchingStudent() shall print all possible searching results.
 *  SearchingStudent() take the Student vector as parameters.
 *  Using const keyword for Book vector to avoid the unintended changing.
 *  Using string::npos to compare with string in book author's object.
 *  (string::npos = -1, so if condition will be failed if find() cannot find anything related with input keyword)
 */

void Librarian::SearchingStudent(const vector<Student>& SearchLibStudent)
{
    SearchingResult = 0;
    string SearchMember;

    cout << endl;
    cout << "******************************************" << endl;
    cout << "**   Searching Student in Library       **" << endl;
    cout << "* Please enter Student's Name Or (exit) **" << endl;
    cout << endl;
    cin >> SearchMember;
    //cout << endl;

    if(SearchMember != "exit")
    {
        cout <<left << setw(5) << "No." << left << setw(21) << "Name\t" << left << setw(21) << "User name\t" << left << setw(20) << "Password\t" << left << setw(10)<< "Borrowed" << endl;
        for(unsigned int i = 0; i < SearchLibStudent.size(); i++)
        {
            //Compare with string::npos (value -1) if there is no any string matched with GetBookTile then if condition would be failed
            //Take the Book's Title in Book vector and compare to input string.
            if((SearchLibStudent[i].GetName()).find(SearchMember) != string::npos)
            {
                cout << left << setw(5) << i + 1;       //Print No. of Students
                SearchLibStudent[i].Display();
                SearchingResult++;
            }
        }
        if(SearchingResult == 0)
        {
            cout << endl << endl;
            cout << "There is no Student matched to your search" << endl;
        }
        cout << endl;
    }
    cin.get();
}









