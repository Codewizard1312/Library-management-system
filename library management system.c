 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100

// Structure to store book details
struct Book {
    int bookID;
    char title[100];
    int totalBooks;
    int borrowedBooks;
};

// Structure to store borrower details
struct Borrower {
    int bookID;
    char borrowerName[50];
    struct tm dueDate;
    int isReturned; // 0 = not returned, 1 = returned
};

// Library structure containing books and borrower data
struct Library {
    struct Book books[MAX_BOOKS];
    struct Borrower borrowers[MAX_BOOKS];
    int bookCount;
    int borrowerCount;
};

// Function to initialize the library
void initializeLibrary(struct Library *lib) {
    lib->bookCount = 0;
    lib->borrowerCount = 0;
}

// Function to add a book to the library
void addBook(struct Library *lib, int bookID, const char *title, int totalBooks) {
    struct Book newBook = {bookID, "", totalBooks, 0};
    strcpy(newBook.title, title);
    lib->books[lib->bookCount++] = newBook;
}

// Function to borrow a book
void borrowBook(struct Library *lib) {
    int bookID, dueDay, dueMonth, dueYear;
    char borrowerName[50];

    printf("Enter Book ID to borrow: ");
    scanf("%d", &bookID);

    // Find the book in the library
    for (int i = 0; i < lib->bookCount; i++) {
        if (lib->books[i].bookID == bookID) {
            if (lib->books[i].borrowedBooks < lib->books[i].totalBooks) {
                printf("Enter Borrower's Name: ");
                scanf(" %[^\n]%*c", borrowerName); // Read a full line (with spaces)

                printf("Enter Due Date (DD MM YYYY): ");
                scanf("%d %d %d", &dueDay, &dueMonth, &dueYear);

                // Add borrower information
                struct Borrower newBorrower = {bookID, "", {0}};
                strcpy(newBorrower.borrowerName, borrowerName);
                newBorrower.dueDate.tm_mday = dueDay;
                newBorrower.dueDate.tm_mon = dueMonth - 1;  // Months are 0-based
                newBorrower.dueDate.tm_year = dueYear - 1900; // tm_year is years since 1900
                newBorrower.isReturned = 0; // Book not yet returned

                lib->borrowers[lib->borrowerCount++] = newBorrower;
                lib->books[i].borrowedBooks++;
                printf("Book '%s' borrowed successfully by %s.\n", lib->books[i].title, borrowerName);
                return;
            } else {
                printf("No copies of this book are available for borrowing.\n");
                return;
            }
        }
    }
    printf("Book with ID %d not found in the library.\n", bookID);
}

// Function to return a book and calculate late fee
void returnBook(struct Library *lib) {
    int bookID, returnDay, returnMonth, returnYear;
    char borrowerName[50];

    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);
    printf("Enter Borrower's Name: ");
    scanf(" %[^\n]%*c", borrowerName); // Read a full line (with spaces)

    for (int i = 0; i < lib->borrowerCount; i++) {
        if (lib->borrowers[i].bookID == bookID && strcmp(lib->borrowers[i].borrowerName, borrowerName) == 0 && lib->borrowers[i].isReturned == 0) {
            printf("Enter Return Date (DD MM YYYY): ");
            scanf("%d %d %d", &returnDay, &returnMonth, &returnYear);

            struct tm due = lib->borrowers[i].dueDate;
            struct tm returned = {0};
            returned.tm_mday = returnDay;
            returned.tm_mon = returnMonth - 1;
            returned.tm_year = returnYear - 1900;
            time_t dueTime = mktime(&due);
            time_t returnTime = mktime(&returned);

            // Calculate the difference in days
            double diffInSeconds = difftime(returnTime, dueTime);
            int diffInDays = diffInSeconds / (60 * 60 * 24);

            if (diffInDays > 0) {
                int lateFee = diffInDays * 5;
                printf("Book '%s' returned late. Late fee: %d rupees.\n", lib->books[bookID - 1].title, lateFee);
            } else {
                printf("Book '%s' returned on time.\n", lib->books[bookID - 1].title);
            }

            // Mark the book as returned
            lib->borrowers[i].isReturned = 1;
            lib->books[bookID - 1].borrowedBooks--;
            return;
        }
    }
    printf("No record found for this book borrowing.\n");
}

// Function to display available books
void displayBooks(struct Library *lib) {
    printf("\nBooks in the Library:\n");
    for (int i = 0; i < lib->bookCount; i++) {
        printf("ID: %d, Title: %s, Total Books: %d, Borrowed: %d, Available: %d\n", lib->books[i].bookID, lib->books[i].title, lib->books[i].totalBooks, lib->books[i].borrowedBooks, lib->books[i].totalBooks - lib->books[i].borrowedBooks);
    }
}

int main() {
    struct Library lib;
    initializeLibrary(&lib);

    // Adding books to the library
    addBook(&lib, 1, "The C Programming Language", 5);
    addBook(&lib, 2, "Data Structures and Algorithms", 3);
    addBook(&lib, 3, "Operating Systems Concepts", 4);

    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Display Available Books\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(&lib);
                break;
            case 2:
                borrowBook(&lib);
                break;
            case 3:
                returnBook(&lib);
                break;
            case 4:
                printf("Exiting the Library Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
