/** Library project
 *  This project is free-time project.
 *  Library project is to simulate a very basic functions to manage library for Librarian and to be used by Student.
 *  Library project shall ask for UserName and Password to switch roles between Librarian and Students.
 *  Firstly, call initialization functions to initialize LibraryUser and LibraryBook. (due to lack of Serialization and Deserialization).
 *  Secondly, main() function shall call login for checking UserName and Password, then switching roles.
 *  Finally, main() shall execute in infinite while loop.
 *  Author: Nhut Tran
 *  25/12/2017
 */

#include <fstream>
#include <stdlib.h>
#include "Person.h"
#include "Student.h"
#include "conio.h"
#include "Librarian.h"


static vector<Student> LibraryUser;
static vector<Book> LibraryBook;
unsigned int IsLibrarian;
unsigned int OrderEle;                  //To specify the Student's object in LibraryUser vector

void LibrarianTask();
void StudentTask(Student& Task);        //StudentTask() shall take Student object as referenced
void InitialzationBook(vector<Book>&);
void InitialzationStudent(vector<Student>&);
void Login(vector<Student>&);


int main()
{
    InitialzationBook(LibraryBook);
    InitialzationStudent(LibraryUser);

    do
    {
        Login(LibraryUser);
        if(IsLibrarian == 999)          //For demo purpose - this could be replace by char or string.
        {
            system("cls");
            LibrarianTask();
            system("cls");
        }
        else if(IsLibrarian == 111)
        {
            system("cls");
            StudentTask(LibraryUser[OrderEle]); //Passing Library User's object StudentTask
            system("cls");
        }

    }while(1);
    return 0;
}

/** Login function shall be used to login.
 *  Login() shall ask for username and password.
 *  Login() shall change the IsLibrarian variable (true for Librarian jobs and false for Student jobs).
 *  Login() shall check the InUserName is "librarian" or one of Student's username.
 *  Login() shall check password after the username of Librarian or Student is correct.
 *  For demo purpose, account of Librarian would be (Username: librarian - password: 123).
 */
void Login(vector<Student>& LoginStudent)
{
    int CheckingNum = 0;
    IsLibrarian = 0;
    OrderEle = 0;
    Librarian Lib;                       //instance Librarian object to call it's functions

    string InUserName, InPasswd;

    cout << "User Name: ";
    cin >> InUserName;
    if(Lib.GetUser() == InUserName)
    {
        cin.ignore();
        cout << "Password: ";
        cin >> InPasswd;
        CheckingNum++;
        if(Lib.GetPass() == InPasswd)
        {
            IsLibrarian = 999;
            cin.ignore();
        }
        else
        {
            cout << "Wrong password" << endl << endl;
            cin.ignore();
        }
    }
    else if(Lib.GetPass() != InPasswd)
    {
        for(unsigned int i = 0;i < LoginStudent.size(); i++)
        {
            if(LoginStudent[i].GetUser() == InUserName)
            {
                cin.ignore();
                cout << "Password: ";
                cin >> InPasswd;
                CheckingNum++;

                if(LoginStudent[i].GetPass() == InPasswd)
                {
                    IsLibrarian = 111;
                    OrderEle = i;               //To specify the Student's object in LibraryUser vector
                    cin.ignore();
                }
                else
                {
                    cout << "Wrong password" << endl << endl;
                    cin.ignore();
                }
            }
        }
    }
    if(CheckingNum == 0)
    {
        cout << "Invalid user name" << endl << endl;
        cin.ignore();
    }
}

/** LibrarianTask function shall be used by Librarian.
 *  LibrarianTask() shall show the menu Librarian's jobs.
 *  LibrarianTask() shall be used to call functions in Librarian class.
 *  LibrarianTask() shall switch between functions by selection of Librarian.
 *  LibrarianTask() shall include Adding new Student, Adding new Book, List all Books, List all Students,...
 *  ...Removing Book, Removing Student, Searching Book, Searching Student and print Librarian information function.
 *  For demo purpose, account of Librarian would be (Username: librarian - password: 123).
 */

void LibrarianTask()
{
    int Selection = 0;

    Librarian lib;                                  //instance Librarian object
    do
    {
        cout << "********************************" << endl;
        cout << "*  Making Selection:           *" << endl;
        cout << "*  1. Adding new Student       *" << endl;
        cout << "*  2. Adding new Book          *" << endl;
        cout << "*  3. List all Books           *" << endl;
        cout << "*  4. List all Students        *" << endl;
        cout << "*  5. Removing Book            *" << endl;
        cout << "*  6. Removing Student         *" << endl;
        cout << "*  7. Searching Book           *" << endl;
        cout << "*  8. Searching Student        *" << endl;
        cout << "*  9. Librarian Information    *" << endl;
        cout << "*  10.Exit                     *" << endl;
        cout << "********************************" << endl;
        cin >> Selection;
        cin.get();

        switch(Selection)
        {
            case 1:
                lib.AddingStudent(LibraryUser);     //Adding new Student to Library
                cin.get();
                system("cls");
                break;
            case 2:
                lib.AddingBook(LibraryBook);        //Adding new Books to Library
                cin.get();
                system("cls");
                break;
            case 3:
                lib.PrintBook(LibraryBook);         //Print all Books in Library
                cin.get();
                system("cls");
                break;
            case 4:
                lib.PrintMember(LibraryUser);       //Print all Student members in Library
                cin.get();
                system("cls");
                break;
            case 5:
                lib.RemovingBook(LibraryBook);      //Removing book in Book's vector
                cin.get();
                system("cls");
                break;
            case 6:
                lib.RemovingStudent(LibraryUser);   //Removing Student member in Student vector
                cin.get();
                system("cls");
                break;
            case 7:
                lib.SearchingBook(LibraryBook);     //Searching Book in Book vector
                cin.get();
                system("cls");
                break;
            case 8:
                lib.SearchingStudent(LibraryUser);  //Searching Student member in Student vector
                cin.get();
                system("cls");
                break;
            case 9:
                lib.Display();                      //Show Librarian information
                cin.get();
                system("cls");
                break;
        }
    }
    while(Selection != 10);
}

/** StudentTask function shall be used by Student.
 *  StudentTask() shall show the menu Student's jobs.
 *  StudentTask() shall be used to call functions in Student class.
 *  StudentTask() shall switch between functions by selection of Student.
 *  StudentTask() shall include Searching Book, Borrowing Book, Returning Book,...
 *  ...,List all Borrowed Book, Print Student's account information.
 */
void StudentTask(Student& StuTask)              //StudentTask() shall take referenced Student object as StuTask
{
    int Selection = 0;
    Librarian lib;


    do
    {
        cout << "Welcome " << StuTask.GetName() << " to library" << endl << endl;
        cout << "********************************" << endl;
        cout << "*  Making Selection:           *" << endl;
        cout << "*  1. Searching Book           *" << endl;
        cout << "*  2. Borrowing Book           *" << endl;
        cout << "*  3. Returning Book           *" << endl;
        cout << "*  4. List all Borrowed Books  *" << endl;
        cout << "*  5. Changing Password        *" << endl;
        cout << "*  6. Student Information      *" << endl;
        cout << "*  7. Exit                     *" << endl;
        cout << "********************************" << endl;
        cin >> Selection;
        cin.get();

        switch(Selection)
        {
            case 1:
                StuTask.SearchingBook(LibraryBook);                 //Searching Book in Book's vector
                cin.get();
                system("cls");
                break;
            case 2:
                StuTask.BorrowingBook(LibraryBook,LibraryBook);     //Borrowing Book from Library Book vector (first vector is used for Searching, second vector is used for updating Library Book vector)
                cin.get();
                system("cls");
                break;
            case 3:
                StuTask.ReturningBook(StuTask.GetBorrowedBook());   //Call GetBorrowedBook() to get access the BorrowedBook vector and pass it to ReturningBook()
                cin.get();
                system("cls");
                break;
            case 4:
                StuTask.PrintBorrowedBook();                        //Print all Student members in Library
                cin.get();
                system("cls");
                break;
            case 5:
                StuTask.ChangingPassword();                         //Changing password of Student account (object)
                cin.get();
                system("cls");
                break;
            case 6:
                cout << left << setw(21) << "Name\t" << left << setw(25) << "User name\t" << left << setw(25) << "Password\t" << left << setw(10)<< "Borrowed" << endl;
                StuTask.Display();                                  //Print the Information of Librarian
                cin.get();
                system("cls");
                break;
        }
    }
    while(Selection != 7);
}

/** InitialzationBook function shall be used for initialize new book's objects and store into Book vector
 *  First, InitialzationBook() would call default constructor of Book and passing values, to creating new object.
 *  Then, the function shall use vector.push_back to add objects into Book vector.
 */
void InitialzationBook(vector<Book>& newListBook)
{
    Book newBook1("Embedded Multitasking","Keith",10,"9780750679183",0);
    newListBook.push_back(newBook1);
    Book newBook2("Embedded System","Westcott",15,"9780080475899",0);
    newListBook.push_back(newBook2);
    Book newBook3("RealTime Workshop","Douglass",12,"9780080492230",0);
    newListBook.push_back(newBook3);
    Book newBook4("Embedded Linux","Abbott",10,"9780123914330",0);
    newListBook.push_back(newBook4);
    Book newBook5("Embedded Microprocessor","Stuart",20,"9780080469973",0);
    newListBook.push_back(newBook5);
    Book newBook6("Practical Embedded","Timothy",25,"9780080551319",0);
    newListBook.push_back(newBook6);
    Book newBook7("DSP Software","Oshana, Robert",7,"9780080491196",0);
    newListBook.push_back(newBook7);
    Book newBook8("Embedded System Designers","Eady, Fred",5,"9780080457284",0);
    newListBook.push_back(newBook8);
}

/** InitialzationStudent function shall be used for initialize new student's objects and store into Student vector
 *  First, InitialzationStudent() would call default constructor of Student and passing values, to creating new object.
 *  Then, the function shall use vector.push_back to add objects into Book vector.
 */
void InitialzationStudent(vector<Student>& newListStudent)
{
    Student newStudent1("Keith","keith998","123");
    newListStudent.push_back(newStudent1);
    Student newStudent2("Stuart","stuart556","123");
    newListStudent.push_back(newStudent2);
    Student newStudent3("Oshana","oshana223","123");
    newListStudent.push_back(newStudent3);
    Student newStudent4("Fred","fred772","123");
    newListStudent.push_back(newStudent4);
    Student newStudent5("Timothy","timo007","123");
    newListStudent.push_back(newStudent5);
    Student newStudent6("Abbott","abbott119","123");
    newListStudent.push_back(newStudent6);

}


