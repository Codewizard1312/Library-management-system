

Library Management System - C Program

Overview

This C program implements a simple Library Management System that allows users to add book details, display book details, and check the total number of books in the library. The user can interact with the system via a menu-driven interface.

Features

1. Add Book Details: Allows the user to enter details of a new book, including the book name, author name, and the date of issue.


2. Display Book Details: Displays the list of books in the library, including the book name, author name, and the date of issue.


3. Display Total Number of Books: Displays the total number of books in the library.


4. Exit: Exits the program.



Menu Options

1. Add Book Details: Prompts the user to enter book details (book name, author name, and date of issue).

2. Display the List of Books and Its Details: Displays all stored books with their respective details.

3. Display the Total Number of Books: Displays the total number of books in the library.

4. Exit: Terminates the program.


Code Explanation

Struct Definition

The program uses a struct called library to store information about a book. The structure contains:

book_name: A string (character array) to store the name of the book.

author_name: A string (character array) to store the name of the author.

date_of_issue: A floating-point number to store the date of issue of the book.


Main Program Flow

Menu System: The program operates in a loop that continuously displays a menu for the user to choose an action. The loop exits when the user selects option 4 (Exit).

Adding Books: In case 1, the program asks for the book's name, author's name, and the date of issue, storing these details in the lib[] array.

Displaying Books: In case 2, it displays the stored book information in the lib[] array.

Counting Books: In case 3, it prints the total number of books stored in the library.

Exiting: In case 4, the program terminates using exit(0).


