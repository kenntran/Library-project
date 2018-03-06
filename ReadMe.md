# Library project

Spare-time project 
25/12/2017

## Description
	- This Library project is to simulate basic functions of a library
	- To manage library for Librarian
	- To be used by Student
	- Using C++ and Object-Oriented Programming to build this project
	
## Role	
Role of Librarian and Student:

### Librarian
		- Librarian shall be able to add new book to Library.
		- Librarian shall be able to add new Student member to Library.
		- Librarian shall be able to list all Student members in Library.
		- Librarian shall be able to remove book from Library.
		- Librarian shall be able to remove student from Library.
		- Librarian shall be able to search book in Library.
		- Librarian shall be able to search student in Library.
		- Librarian shall be able to display Librarian account's information.

### Student
		- Student shall be able to search book in Library.
		- Student shall be able to borrow book from Library.
		- Student shall be able to return book to Library.
		- Student shall be able to list all his/her borrowed books.
		- Student shall be able to change account's password.
		- Student shall be able to dispaly his/her account's information.
	
## Note: 
	- Due to lack of time for this project:
		- The Library project does not have full functions of a Library.
		- The Library project has a simple serialization and deserialization. (Using Book.txt and Student.txt to import and export data).
		- The Library project does not have serializationa and deserialization function for Borrowed Books of Student.
		- The Library project does not use many STL libraries as expected. 
		- The Library project still need to be improved with C++ technique.  
		- The Library project uses mostly C programming techniques.

		
## Demo:
	- For demo purpose:
		- Librarian could login by using UserName: librarian - Password: 123
		- Student could login by using different UserName and Password:
			- ID: keith998	-	Password: 123
			- ID: fred772	-	Password: 123
			- ID: timo007	- 	Password: 123
			- ID: abbott119	-	Password: 123
			
## Error while opening executed file:
	- If you get the error about "the procedure entry point __gxx_personality_v0 could not be located...". You should:
		- Go to your MinGW folder (should be C:\MinGW)
		- Open the bin folder.
		- There should be a file called libstdc++-6.dll
		- Copy this into the same directory as your executable.

	- If you get the error about "error while opening file", you should:
		- Copy Student.txt and Book.txt to same directory as executable file.
