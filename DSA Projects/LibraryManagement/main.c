#include "library.h"

int main()
{
    struct library *books = NULL;
    int choice = 0;
    do
    {
        printf("Enter 1 to Insert Book\nEnter 2 To display Book Info\nEnter 3 To display all Book in store\nEnter 4 To delete Book\nEnter 5 to rent Book\nEnter 6 to return the book :  \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char book[20], author[20];
            int available;
            printf("\nEnter Book Name: ");
            scanf("%s", book);
            printf("\nEnter Author Name: ");
            scanf("%s", author);
            printf("\nEnter No. of book available: ");
            scanf("%d", &available);
            books = InsertBook(books, book, author, available);
            break;
        }
        case 2:
        {
            char name[20];
            printf("\nEnter Book name: ");
            scanf("%s", name);
            struct library *newbook = searchBook(books, name);
            if (newbook != NULL)
            {
                displayBook(newbook, newbook->people);
            }
            else
            {
                printf("No book is available\n");
            }
            break;
        }
        case 3:
        {
            if (books != NULL)
            {
                displayAllBook(books);
            }
            else
            {
                printf("Library is empty.\n");
            }
            break;
        }
        case 4:
        {
            char name[20];
            printf("\nEnter Book name: ");
            scanf("%s", name);
            books = deleteBook(books, name);
            break;
        }
        case 5:
        {
            char Bookname[20];
            printf("\nEnter Book name: ");
            scanf("%s", Bookname);
            char name[20];
            printf("\nEnter person name: ");
            scanf("%s", name);

            char address[20];
            printf("\nEnter person address: ");
            scanf("%s", address);
            char number[20];
            printf("\nEnter person number: ");
            scanf("%s", number);

            int date;
            printf("\nEnter due date: ");
            scanf("%d", &date);

            rentBook(books, Bookname, name, address, number, date);
            break;
        }
        case 6:
        {
            char Bookname[20];
            printf("\nEnter Book name: ");
            scanf("%s", Bookname);
            char name[20];
            printf("\nEnter person name: ");
            scanf("%s", name);

            returnBook(books, Bookname, name);
            break;
        }
        }
    } while (choice != -1);
}