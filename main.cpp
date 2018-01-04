/** Library project
 *  This project is free-time project.
 *  Library project is to simulate a very basic functions to manage library for Librarian and to be used by Student.
 *  Library project shall ask for UserName and Password to switch roles between Librarian and Students.
 *  Firstly, call initialization functions to initialize LibraryUser and LibraryBook. (due to lack of Serialization and Deserialization).
 *  Secondly, main() function shall call login for checking UserName and Password, then switching roles.
 *  Finally, main() shall execute in infinite while loop.
 *  Create: Nhut Tran
 *  25/12/2017
 */


#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "Person.h"
#include "Student.h"
#include "conio.h"
#include "Librarian.h"
#include <sstream>                      // To use istringstream


static vector<Student> LibraryUser;
static vector<Book> LibraryBook;
static vector<Book> DemoBook;           //For demo deserialization purpose.
unsigned int IsLibrarian;
unsigned int OrderEle;                  //To specify the Student's object in LibraryUser vector

void LibrarianTask();
void StudentTask(Student& Task);                    //StudentTask() shall take Student object as referenced
void InitialzationBook(vector<Book>&);
void InitialzationStudent(vector<Student>&);
void Login(vector<Student>&);                       //Passing the Student vector to check the UserName, Password of all Student accounts in Library
void SerializationBook(const vector<Book>&);        //To export all Books in Library to file
void SerializationStudent(const vector<Student>&);  //To export all Students in Library to file
void DeserializationBook(vector<Book>&);            //To import Books from file to Book vector
void DeserializationStudent(vector<Student>&);      //To import Students from file to Student vector

int main()
{
    //InitialzationBook(LibraryBook);				//Don't need anymore because of having DeserializationBook()
    //InitialzationStudent(LibraryUser);			//Don't need anymore because of having DeserializationStudent()

    DeserializationBook(LibraryBook);
    DeserializationStudent(LibraryUser);

    do
    {

        Login(LibraryUser);
        if(IsLibrarian == 999)                  //For demo purpose only - Instead of this, this condition could be replaced by char or string.
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

        SerializationBook(LibraryBook);
        SerializationStudent(LibraryUser);
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
 *  First, InitialzationBook() would call default constructor of Book and passing values, to create new object.
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
 *  First, InitialzationStudent() would call default constructor of Student and passing values, to create new object.
 *  Then, the function shall use vector.push_back to add objects into Student vector.
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

/** SerializationBook function shall be used write data in Book vector to Book.txt file.
 *  SerializationBook() shall open the file "Book.txt" and append the text file in Book.txt.
 *  SerializationBook() shall take Book vector to write out data.
 */
void SerializationBook(const vector<Book>& Serialization)
{

    ofstream Outfile("Book.txt", std::ios_base::ate | std::ios_base::out | std::ios_base::trunc);
    if(!Outfile.is_open())
    {
        cout << "error while opening file";
    }
    else
    {
        for(unsigned int i = 0; i < Serialization.size(); i++)
        {
            Outfile << Serialization[i].GetBookTitle() << "\t";
            Outfile << Serialization[i].GetBookAuthor() << "\t";
            Outfile << Serialization[i].GetBookISBN() << "\t";
            Outfile << Serialization[i].GetBookNumber() << "\t";
            Outfile << Serialization[i].GetBookBorrowed();
            Outfile << "\n";
        }
    }
    Outfile.close();

}

/** SerializationStudent() function shall be used write data in Student vector to Student.txt file.
 *  SerializationStudent() shall open the file "Student.txt" and append the text file in Student.txt.
 *  SerializationStudent() shall take Student vector to write out data.
 */
void SerializationStudent(const vector<Student>& Serialization)
{

    ofstream Outfile("Student.txt", std::ios_base::ate | std::ios_base::out | std::ios_base::trunc);
    if(!Outfile.is_open())
    {
        cout << "error while opening file";
    }
    else
    {
        for(unsigned int i = 0; i < Serialization.size(); i++)
        {
            Outfile << Serialization[i].GetName() << "\t";
            Outfile << Serialization[i].GetUser() << "\t";
            Outfile << Serialization[i].GetPass() << "\t";
            Outfile << Serialization[i].GetBorrowedNum()  << "\t";
            Outfile << "\n";
        }
    }
    Outfile.close();
}


/** DeserializationBook() function shall be used read data from Book.txt file and push_bach to Book vector. 
 *  DeserializationBook() shall open the file "Book.txt".
 *  DeserializationBook() shall read until the end of file.
 *  DeserializationBook() shall get line by line by using getline(Inputfile,[a string]).
 *  DeserializationBook() shall separate each line into strings by determine the "tab" delimiter in file ("\t"). 
 *  DeserializationBook() shall copy those string to temporary strings and convert them to char.
 *  DeserializationBook() shall create new objects with the constructor and those char value.
 *  DeserializationBook() shall use vector.push_bash to add new object into Book's vector. 
 *  DeserializationBook() shall take Book vector to add new data into it.
 */
void DeserializationBook(vector<Book>& Deserialization)
{
    string Title;
    string Author;
    string ISBN;
    string Converting[100][100];
    string GetLine;
    unsigned int Number;
    unsigned int Borrowed;

    ifstream Inputfile("Book.txt",std::ios_base::in);               //Input file name: Book.txt
    if(!Inputfile.is_open())
    {
        cout << "error while opening file" << endl;
    }
    else
    {
        while(!Inputfile.eof())                                     //To End Of File
        {
            for(int z = 0; getline(Inputfile, GetLine); z++ )       //For each line,
            {
                std::istringstream iss(GetLine);                   //iss takes the string from GetLine
                std::string token;
                for(int t = 0; getline(iss, token, '\t'); t++)      //to detect the \t in iss string - for each line + each string before "tab" delimiter
                {
                    Converting[z][t] = token;                       //To takes that string and store in Converting[z][t]
                }
            }
        }
    }

    for(int x = 0; x < 10; x++ )
    {
        for(int y = 0; y < 10; y++)
        {
            if(Converting[x][0] != "")                  //Check the element in string array whether it is empty or not.
            {
                Title = Converting[x][0];
                Author = Converting[x][1];
                ISBN = Converting[x][2];
                istringstream iss(Converting[x][3]);
                iss >> Number;
                istringstream iss1(Converting[x][4]);
                iss1 >> Borrowed;

                char TitleChr[Title.length()+1];
                strcpy(TitleChr,Title.c_str());         //Convert the string of Title get from file to char to create new object of Book

                char AuthorChr[Author.length()+1];
                strcpy(AuthorChr,Author.c_str());       //Convert the string of Author get from file to char to create new object of Book

                char ISBNChr[ISBN.length()+1];
                strcpy(ISBNChr,ISBN.c_str());           //Convert the string of ISBN get from file to char to create new object of Book

                Book deserialzBook(TitleChr,AuthorChr,Number,ISBNChr,Borrowed);
                Deserialization.push_back(deserialzBook);
                break;                                  //Only do this once. - break the for loop of y
            }
        }
    }
    Inputfile.close();
}


/** DeserializationStudent() function shall be used read data from Student.txt file and push_bach to Student vector. 
 *  DeserializationStudent() shall open the file "Student.txt".
 *  DeserializationStudent() shall read until the end of file.
 *  DeserializationStudent() shall get line by line by using getline(Inputfile,[a string]).
 *  DeserializationStudent() shall separate each line into strings by determine the "tab" delimiter in file ("\t"). 
 *  DeserializationStudent() shall copy those string to temporary strings and convert them to char.
 *  DeserializationStudent() shall create new objects with the constructor and those char value.
 *  DeserializationStudent() shall use vector.push_bash to add new object into Student's vector. 
 *  DeserializationStudent() shall take Student vector to add new data into it.
 */
void DeserializationStudent(vector<Student>& Deserialization)
{
    string Name;
    string UserName;
    string Password;
    string Converting[100][100];
    string GetLine;
    unsigned int BorrowedNum;

    ifstream Inputfile("Student.txt",std::ios_base::in);               //Input file name: Book.txt
    if(!Inputfile.is_open())
    {
        cout << "error while opening file" << endl;
    }
    else
    {
        while(!Inputfile.eof())                                     //To End Of File
        {
            for(int z = 0; getline(Inputfile, GetLine); z++ )       //For each line,
            {
                std::istringstream iss(GetLine);                   //iss takes the string from GetLine
                std::string token;
                for(int t = 0; getline(iss, token, '\t'); t++)      //to detect the \t in iss string - for each line + each string before "tab" delimiter
                {
                    Converting[z][t] = token;                       //To takes that string and store in Converting[z][t]
                }
            }
        }
    }

    for(int x = 0; x < 10; x++ )
    {
        for(int y = 0; y < 10; y++)
        {
            if(Converting[x][0] != "")                  //Check the element in string array whether it is empty or not.
            {
                Name = Converting[x][0];
                UserName = Converting[x][1];
                Password = Converting[x][2];
                istringstream iss(Converting[x][3]);
                iss >> BorrowedNum;

                char NameChr[Name.length()+1];
                strcpy(NameChr,Name.c_str());         //Convert the string of Title get from file to char to create new object of Book

                char UserNameChr[UserName.length()+1];
                strcpy(UserNameChr,UserName.c_str());       //Convert the string of Author get from file to char to create new object of Book

                char PasswordChr[Password.length()+1];
                strcpy(PasswordChr,Password.c_str());           //Convert the string of ISBN get from file to char to create new object of Book

                Student deserialzStudent(NameChr,UserNameChr,PasswordChr);
                deserialzStudent.SetBorrowedNum(BorrowedNum);
                Deserialization.push_back(deserialzStudent);
                break;                                  //Only do this once. - break the for loop of y
            }
        }
    }
    Inputfile.close();
}
