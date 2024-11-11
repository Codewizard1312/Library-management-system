# Library Management System in C

This is a simple **Library Management System** written in **C**. It allows users to:
- Add books to the library.
- Borrow books from the library.
- Return books and calculate late fees based on the return date.
- View available books in the library.

### Features:
- Track available books, borrowed books, and due dates.
- Calculate late fees (5 rupees per day) for overdue books.
- Borrower details (name, book ID, issue date, due date) are stored.
- Supports basic operations like adding books, borrowing books, and returning books.

---

### **How the System Works:**

1. **Adding Books**: 
   - New books can be added to the system with their title, ID, and total number of copies.
   
2. **Borrowing Books**:
   - The user can borrow a book by providing the book ID and the borrower's name.
   - The issue date is recorded and a due date (14 days from the issue date) is automatically assigned.

3. **Returning Books**:
   - The user can return a book, and the system will check if it is returned late.
   - Late fees of 5 rupees per day will be applied if the book is returned after the due date.

4. **Displaying Available Books**:
   - The user can see all available books in the library, along with how many copies are available for borrowing.

---

### **Code Explanation**:

This is the implementation of a simple library system where we use structures to store the details of books and borrowers.

#### Structure Definitions:
- **Book**: Contains details about each book such as ID, title, total number of books, and the number of borrowed books.
- **Borrower**: Stores information about each borrowing transaction, including the borrower's name, issue date, due date, and whether the book has been returned.
- **Library**: Holds the entire library system, including arrays of books and borrowers, as well as counters for the number of books and borrowers.

#### Functions:
1. `initializeLibrary()`: Initializes the library with no books and no borrowers.
2. `addBook()`: Adds a new book to the library.
3. `borrowBook()`: Handles the borrowing of a book, including setting the issue and due dates.
4. `returnBook()`: Allows the user to return a book and calculate late fees based on the return date.
5. `displayBooks()`: Displays all the books in the library, including how many are available for borrowing.

#### Main Function:
The `main()` function provides a simple menu-based interface for interacting with the library system. The user can choose to display available books, borrow a book, return a book, or exit the system.

---

### **Instructions to Run:**

1. **Compiling the Code**:
   - Save the code to a file named `library_system.c`.
   - Open a terminal and navigate to the directory where the file is saved.
   - Run the following command to compile:
     ```bash
     gcc library_system.c -o library_system
     ```

2. **Running the Program**:
   - After compiling, run the program by typing:
     ```bash
     ./library_system
     ```
   - The program will prompt you with a menu to interact with the library system.

---
