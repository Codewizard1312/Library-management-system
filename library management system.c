#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

// Arrays to store book attributes
int bookId[MAX_BOOKS];
char title[MAX_BOOKS][TITLE_LEN];
char author[MAX_BOOKS][AUTHOR_LEN];
int quantity[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void viewBooks();
void searchBook();
void deleteBook();

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &bookId[bookCount]);
    getchar();  // Clear input buffer
    printf("Enter Book Title: ");
    fgets(title[bookCount], TITLE_LEN, stdin);
    printf("Enter Author Name: ");
    fgets(author[bookCount], AUTHOR_LEN, stdin);
    printf("Enter Quantity: ");
    scanf("%d", &quantity[bookCount]);

    // Remove newline character from title and author
    title[bookCount][strcspn(title[bookCount], "\n")] = 0;
    author[bookCount][strcspn(author[bookCount], "\n")] = 0;

    bookCount++;
    printf("Book added successfully!\n");
}

// Function to view all books
void viewBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", 
               bookId[i], title[i], author[i], quantity[i]);
    }
}

// Function to search for a book by ID
void searchBook() {
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (bookId[i] == id) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", 
                   bookId[i], title[i], author[i], quantity[i]);
            found = 1;
            break;
        }
    }

    if (!found) printf("Book not found.\n");
}

// Function to delete a book by ID
void deleteBook() {
    int id, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (bookId[i] == id) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                bookId[j] = bookId[j + 1];
                strcpy(title[j], title[j + 1]);
                strcpy(author[j], author[j + 1]);
                quantity[j] = quantity[j + 1];
            }
            bookCount--;
            printf("Book with ID %d deleted.\n", id);
            break;
        }
    }

    if (!found) printf("Book not found.\n");
}
