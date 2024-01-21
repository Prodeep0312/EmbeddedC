Write a program to simulate the **Library Management System** using Array of objects and structure pointers
The program should support the following operations :

**a. Add a book**.
	- This module should add a new book to inventory/array.
	- The book details should contain Book id, book Name , author Name,Publisher name and no of copies

**b. Display All book details**
	- This module should display details of all books

**c. Search for a book**
	-This module should accept the bookId/name from user and display details of the corresponding book

**d.Issue a book**
	-This module should accept the book Id/name from user and issue the book (decrement number of copies by 1)
	if book is found

**e. Return a book**
	-This module should accept the book Id/name from the user and return the book (increment number of copies 
		by 1) if book is found

**f. Delete Book details**

	-This module should accept the book Id/name from the User and deletes that book information for that book
		from array.

Write separate function for each operation .Each function should take struct pointer as argument and perform 
operation .Function should return SUCCESS and Failure.




