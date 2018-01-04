#include "Student.h"

/** Student's constructor of Student class shall take parameters to assign to Student's variables.
 *  Student inherits form Person class.
*/
Student::Student(char *N, char *UN, char *Pd):Person(N,UN,Pd){}

Student::~Student(){}

/** ChangingPassword() function shall be used for changing password of Student account
 *  First, ChangingPassword() shall ask for new password.
 *  Then, the ChangingPassword() function shall ask for confirmation of Student.
 *  Finally, ChangingPassword() shall delete Student's object according to the selection of Librarian
 *  RemovingStudent take the Student's objects in vector as parameters
 */
void Student::ChangingPassword()
{
    char Pd[MAX_PASSWD];
    char choosen;

    cout << "Please Enter your new password: ";
    cin.getline(Pd,MAX_PASSWD);
    cout << "Do you want to change your password?(y/n)";
    cin >> choosen;

    choosen = toupper(choosen);
    if(choosen == 'Y')
    {
        strcpy(Passwd,Pd);
    }
    else{}
}

/** GetBorrowedBook() of BorrowedBook vector shall return BorrowedBook vector.
 *  GetBorrowedBook() shall be used to access the private variable BorrowedBook vector.
 */
vector<Book> &Student::GetBorrowedBook()
{
    return this->BorrowedBook;              //point to BorrowedBook of this class
}

/** ReturningBook() function shall be used for deleting Book's object in BorrowedBook vector
 *  First, ReturningBook() shall call PrintBorrowedBook() to list all borrowed books.
 *  Then, the ReturningBook() shall ask for the selection.
 *  Finally, RemovingStudent() shall remove that Book's object from BorrowedBook vector.
 *  RemovingStudent take the it's own BorrowedBook vector as parameters for updating.
 */
void Student::ReturningBook(vector<Book>& Returning)
{

    char Chosen;
    int Selecting = 0;
    do
    {
        PrintBorrowedBook();
        cin.ignore();
        cout << "********************************" << endl;
        cout << "**   Returning Book Member    **" << endl;
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
            cout << "Do you want to return Book " << Returning[Selecting - 2].GetBookTitle() << " ?(y/n)";
            cin >> Chosen;

            Chosen = toupper(Chosen);

            if(Chosen == 'Y')
            {
                cout << "Book " << Returning[Selecting - 2].GetBookTitle() << " has been returned!!!" << endl << endl;
                Returning.erase(Returning.begin() + (Selecting-2));
                Returning[Selecting - 2].UpdateReturningBook();
                Borrowed--;
            }
            else{}
        }
        else{}



    }while( Selecting != 1);
}

/** BorrowingBook() function shall be used for borrowing
 *  First, BorrowingBook() shall call SearchingBook().
 *  Then, the BorrowingBook() shall ask the selection from Student.
 *  Finally, BorrowingBook() shall call the Borrowing() to ask for confirmation and adding borrowed book to Borrowed vector
 *  BorrowingBook take two parameters are two vector
 *  The first vector would be Book's vector (using const keyword), to be used for SearchingBook.
 *  The second vector would be also Book's vector, but shall be used for update borrowed number in Book's object
 */
void Student::BorrowingBook(const vector<Book>& ListBook,vector<Book>& UpdateBook)
{
    int Selecting = 0;
    do
    {
        SearchingBook(ListBook);
        cin.ignore();
        cout << "********************************" << endl;
        cout << "**   Borrowing Book Member    **" << endl;
        cout << "* Please make the selection:  **" << endl;
        cout << "* 0.Exit.                     **" << endl;
        cout << "********************************" << endl;
        cin >> Selecting;
        cout << endl;

        //To exit the do-while loop, user would enter 0 (due to initial declaration Selecting = 0)
        //Must be added 1 more to avoid it.
        Selecting = Selecting + 1;
        Selection = Selecting;

        if(Selecting != 1)
        {
            Borrowing(UpdateBook,BorrowedBook);
            cin.ignore();
            cin.get();
        }
        else{}

    }while( Selecting != 1);
}

/** Borrowing function is a child function, would be called from BorrowingBook().
 *  Borrowing() shall be used for borrowing book.
 *  First, Borrowing() shall ask for confirmation of Student.
 *  Then, the function shall add new Book's object into Borrowing vector.
 *  Finally, Borrowing() shall update the borrowed number that book in Book's vector.
 *  Borrowing take the two Book's vector.
 *  The first vector (ListBook) shall be used for getting book's tile for the confirmation.
 *  The second vector (Borrowing) shall be used to store the borrowed book in Student's object. (It's private field(variable) of Student class)
 */
void Student::Borrowing(vector<Book>& ListBook,vector<Book>& Borrwing)
{
    char Chosen;
    cout << "Do you want to borrow Book " << ListBook[Selection - 2].GetBookTitle() << " ?(y/n)";
    cin >> Chosen;

    Chosen = toupper(Chosen);           //To make sure that the confirmation from User would be in correct form.

    if(Chosen == 'Y')
    {
        cout << "Book " << ListBook[Selection - 2].GetBookTitle() << " has been added to your collection!!!" << endl;
        Borrwing.push_back(ListBook[Selection - 2]);
        ListBook[Selection - 2].UpdateBorrowingBook();
        Borrowed++;
    }
    else {}
}

/** PrintBorrowedBook function shall be used for list all borrowed books of that Student in his/her collection.
 *  First, PrintBorrowedBook() shall access the BorrowedBook vector.
 *  Finally, PrintBorrowedBook() shall print all borrowed books and it's short information.
 */
void Student::PrintBorrowedBook()
{
    cout << "List all Borrowed Books" << endl;
    cout << "Book Information:" << endl;
    cout << "Total Book in your collection: " << BorrowedBook.size() << endl << endl;
    cout <<left << setw(5) << "No." << left << setw(30) << "Name\t" << left << setw(25) << "Author\t" << left << setw(20) << "ISBN\t" << endl;
    for(unsigned int i = 0; i < BorrowedBook.size(); i++)
    {
        cout << left << setw(5) << i + 1;
        BorrowedBook[i].DisplayForUser();
    }
    cout << endl;
}

/** GetName() shall return Student's Name in string type.
 *  Using const keyword to avoid the unintended changing.
*/
string Student::GetName() const
{
    return string(Name);
}

/** Display() shall return all information of student object.
 *  Using const keyword to avoid the unintended changing.
*/
void Student::Display() const
{
    cout << setw(21) << left;
    cout << left << Name  << "\t"<< setw(24);
    cout << left << UserName  << "\t" << setw(23);
    cout << left << Passwd  << "\t" << setw(10);
    cout << left << Borrowed   << endl;
}

/** GetUser() shall return UserName of Student account in string type
 *  Using const keyword to avoid the unintended changing.
*/
string Student::GetUser() const
{
    return string(UserName);
}

/** GetPass() shall return Password of Student account in string type
 *  Using const keyword to avoid the unintended changing.
*/
string Student::GetPass() const
{
    return string(Passwd);
}


unsigned int Student::GetBorrowedNum() const
{
    return Borrowed;
}

void Student::SetBorrowedNum(unsigned int B)
{
    this->Borrowed = B;
}
