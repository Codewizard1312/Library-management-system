Library Management System in C
Overview
This is a simple console-based library management system written in C. It allows users to perform basic operations on a collection of books, such as adding, viewing, searching, and deleting books. The system uses arrays to store information about each book, such as the book's ID, title, author, and quantity.

Features:
Add a new book to the library
View all books in the library
Search for a book by its ID
Delete a book by its ID

Usage
After running the program, you'll be presented with a simple text-based menu. You can choose from the following options:

Add Book: Allows you to input the details (ID, title, author, quantity) of a new book.
View Books: Displays a list of all books in the library.
Search Book: Lets you search for a book by its unique ID and shows the book's details.
Delete Book: Allows you to remove a book from the library by its ID.
Exit: Exits the program


Functions
addBook()
Adds a new book to the system. It prompts the user to enter:

Book ID: A unique identifier for the book.
Title: The title of the book.
Author: The name of the author.
Quantity: The number of copies available.
After the details are entered, the book is added to the system, and the total book count is updated.

viewBooks()
Displays a list of all books in the library. It shows:

ID: The book's unique identifier.
Title: The title of the book.
Author: The name of the author.
Quantity: The number of copies available.
If no books are available, it notifies the user.

searchBook()
Prompts the user to enter a Book ID to search for. If the book with that ID exists, its details are displayed. If not, a "Book not found" message is shown.

deleteBook()
Prompts the user to enter a Book ID to delete. If the book is found, it is removed from the system by shifting the data of all subsequent books one position to the left. The book count is decremented.

Code Explanation
Book Data Storage:

The library system uses arrays to store the attributes of each book:
bookId[]: Stores the unique ID of each book.
title[][]: Stores the title of each book.
author[][]: Stores the author of each book.
quantity[]: Stores the available quantity of each book.
User Input and Output:

The system interacts with the user through the console using printf() to display menus and scanf()/fgets() to read user inputs.
Memory Management:

