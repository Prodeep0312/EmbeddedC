#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2
#define SUCCESS 1
#define FAILURE 0


typedef struct Book {
    int bid;
    char bName[50];
    char authorName[50];
    char publisherName[50];
    int numofCopies;
} Book;

int addBook(Book* mybooks, int* cnt) {
    if (*cnt >= MAX) {
        printf("FAILURE: Maximum Limit reached. Cannot add more books.\n");
        return FAILURE;
    }

    printf("Enter Book Id: ");
    scanf("%d", &mybooks[*cnt].bid);
    getchar(); 
    printf("Enter Book Name: ");
    gets(mybooks[*cnt].bName);

    printf("Enter Author Name: ");
    gets(mybooks[*cnt].authorName);

    printf("Enter Publisher Name: ");
    gets(mybooks[*cnt].publisherName);

    printf("Enter Number of Copies of Book: ");
    scanf("%d", &mybooks[*cnt].numofCopies);

    (*cnt)++;
    printf("Book added successfully.\n");
    return SUCCESS;
}

int displayAllBooks(Book* mybooks, int* cnt) {
    if (*cnt == 0) {
        printf("No books to display\n");
        return FAILURE;
    }

    printf("Book Details:\n");
    for (int i = 0; i < *cnt; ++i) {
        printf("Book Id: %d\n", mybooks[i].bid);
        printf("Book Name: %s\n", mybooks[i].bName);
        printf("Author Name: %s\n", mybooks[i].authorName);
        printf("Publisher Name: %s\n", mybooks[i].publisherName);
        printf("Number of Copies: %d\n", mybooks[i].numofCopies);
        printf("----------------------\n");
    }
    return SUCCESS;
}

int searchBook(Book* mybooks, int* cnt, int searchId) {
    for (int i = 0; i < *cnt; i++) {
        if (mybooks[i].bid == searchId) {
            printf("Book Found:\n");
            printf("Book Id: %d\n", mybooks[i].bid);
            printf("Book Name: %s\n", mybooks[i].bName);
            printf("Author Name: %s\n", mybooks[i].authorName);
            printf("Publisher Name: %s\n", mybooks[i].publisherName);
            printf("Number of Copies: %d\n", mybooks[i].numofCopies);
            return SUCCESS;
        }
    }

    printf("Book not found.\n");
    return FAILURE;
}

int issueBook(Book* mybooks, int* cnt, int issueId) {
    for (int i = 0; i < *cnt; i++) {
        if (mybooks[i].bid == issueId) {
            if (mybooks[i].numofCopies > 0) {
                (mybooks[i].numofCopies)--;
                printf("Book issued successfully and decremented count by 1.\n");
                return SUCCESS;
            } else {
                printf("No more book left for that issueId.\n");
                return FAILURE;
            }
        }
    }

    printf("Book not found.\n");
    return SUCCESS;
}

int returnBook(Book* mybooks, int* cnt, int returnId) {
    for (int i = 0; i < *cnt; i++) {
        if (mybooks[i].bid == returnId) {
            mybooks[i].numofCopies++;
            printf("Book returned successfully and incremented count by 1.\n");
            return SUCCESS;
        }
    }

    printf("Book not found.\n");
    return FAILURE;
}

int deleteBook(Book* mybooks, int* cnt, int deleteId) {
    for (int i = 0; i < *cnt; i++) {
        if (mybooks[i].bid == deleteId) {
            
            mybooks[i] = mybooks[*cnt - 1];
            (*cnt)--;
            printf("Book deleted successfully.\n");
            return SUCCESS;
        }
    }

    printf("Book not found.\n");
    return FAILURE;
}

int main() {
    Book mybooks[MAX];
    int cnt = 0;

    while (1) {
        printf("----------------------------------\n");
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Display all book details\n");
        printf("3. Search for a book\n");
        printf("4. Issue a book\n");
        printf("5. Return a book\n");
        printf("6. Delete book details\n");
        printf("7. Exit\n");
        printf("----------------------------------\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(mybooks, &cnt);
                break;
            case 2:
                displayAllBooks(mybooks, &cnt);
                break;
            case 3: {
                int searchId;
                printf("Enter Book Id  to search: ");
                scanf("%d", &searchId);
                searchBook(mybooks, &cnt, searchId);
                break;
            }
            case 4: {
                int issueId;
                printf("Enter Book Id to issue: ");
                scanf("%d", &issueId);
                issueBook(mybooks, &cnt, issueId);
                break;
            }
            case 5: {
                int returnId;
                printf("Enter Book Id to return: ");
                scanf("%d", &returnId);
                returnBook(mybooks, &cnt, returnId);
                break;
            }

            case 6: {
                int deleteId;
                printf("Enter Book Id to delete: ");
                scanf("%d", &deleteId);
                deleteBook(mybooks, &cnt, deleteId);
                break;
            }
            case 7:
                printf("Exiting from the program.....\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option from the menu...\n");
        }
    }

    return 0;
}