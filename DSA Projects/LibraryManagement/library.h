#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rent
{
    char *name, *address, *number;
    int dueDate;
    struct rent *next;
};
struct library
{
    char *book;
    char *author;
    int no_book_available;
    struct rent *people;
    struct library *next;
};

struct library *createBook(char *book, char *author, int no_book_available)
{
    struct library *temp = (struct library *)malloc(sizeof(struct library));
    temp->author = author;
    temp->book = book;
    temp->no_book_available = no_book_available;
    temp->next = NULL;
    temp->people = NULL;
    return temp;
}

struct rent *createPeople(char *name, char *address, char *number, int dueDate)
{
    struct rent *temp = (struct rent *)malloc(sizeof(struct rent));
    temp->name = name;
    temp->address = address;
    temp->number = number;
    temp->dueDate = dueDate;
    temp->next = NULL;
    return temp;
}

struct rent *searchPerson(struct library *first, struct rent *people, char *person)
{
    if (first == NULL || people == NULL)
    {
        return NULL;
    }
    else if (!(strcmp(people->name, person)))
    {
        return people;
    }
    searchPerson(first, people->next, person);
    searchPerson(first->next, first->next->people, person);
}

struct library *searchBook(struct library *first, char *bookName)
{
    if (first == NULL)
    {
        return NULL;
    }
    else if (!(strcmp(first->book, bookName)))
    {
        return first;
    }
    searchBook(first->next, bookName);
}

void displayPerson(struct rent *first) // displaying peoples  who rented that book
{
    if (first == NULL)
    {
        return;
    }
    printf("Name : %s || address : %s || Phone Number : %s || Due Date : %d\n", first->name, first->address, first->number, first->dueDate);
}

void displayAllPerson(struct rent *first)
{

    if (first == NULL)
    {
        return;
    }
    displayPerson(first);
    displayAllPerson(first->next);
}

void displayBook(struct library *first, struct rent *person)
{ // showing info of the book

    if (first == NULL)
    {
        return;
    }
    printf("\nBook Name : %s || Author Name : %s || Available book count : %d", first->book, first->author, first->no_book_available);
    if (person != NULL)
    {
        puts("\npeoples who rented these book -> ");
        displayAllPerson(person);
    }
}
void displayAllBook(struct library *first)
{

    if (first == NULL)
    {
        return;
    }
    displayBook(first, first->people);
    displayAllBook(first->next);
}

struct library *InsertBook(struct library *first, char *book, char *author, int no_book_available)
{
    struct library *temp = createBook(strdup(book), strdup(author), no_book_available);

    if (first == NULL)
    {
        return temp;
    }

    if ((strcmp(first->book, book)) >= 0)
    {
        if (strcmp(first->book, book) == 0)
        {
            first->no_book_available = first->no_book_available + no_book_available;
            return first;
        }
        temp->next = first;
        return temp;
    }

    struct library *ptr = first;
    while (ptr->next != NULL && (strcmp(ptr->next->book, book)) <= 0)
    {
        if (strcmp(ptr->next->book, book) == 0)
        {
            ptr->next->no_book_available = ptr->next->no_book_available + no_book_available;
            return first;
        }
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;

    return first;
}

void deletePeoples(struct rent *people)
{
    if (people == NULL)
    {
        return;
    }
    if (people->next == NULL)
    {
        free(people);
        return;
    }
    deletePeoples(people->next);
    free(people);
}

struct library *deleteBook(struct library *first, char *book)
{
    struct library *ptr = first;
    struct library *temp;

    if (first == NULL)
    {
        printf("Book does not exits.");
        return first;
    }
    if (first->next == NULL)
    {
        if (strcmp(first->book, book) == 0)
        {
            deletePeoples(first->people);
            free(first);
            return NULL;
        }
    }
    if (strcmp(first->book, book) == 0)
    {
        temp = first->next;
        deletePeoples(first->people);
        free(first);
        return temp;
    }

    while (ptr->next != NULL && (strcmp(ptr->next->book, book)) != 0)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("Book does not exits.");
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        deletePeoples(temp->people);
        free(temp);
    }
    return first;
}

void rentBook(struct library *first, char *bookName, char *name, char *address, char *number, int dueDate)
{
    struct rent *people = createPeople(name, address, number, dueDate);
    struct library *Book = searchBook(first, bookName);

    if (Book->no_book_available > 0)
    {
        Book->no_book_available -= 1;
        people->next = Book->people;
        Book->people = people;
    }
    else
    {
        printf("out of stock");
    }
}

void returnBook(struct library *first, char *bookname, char *name)
{
    struct library *book = searchBook(first, bookname);

    if (book == NULL)
    {
        printf("no book is available of these name\n");
        return;
    }
    book->no_book_available += 1;
    struct rent *prev = book->people;

    if (prev->next == NULL)
    {
        if (!strcmp(prev->name, name))
        {
            book->people = NULL;
            return;
        }
    }
    while (prev->next != NULL)
    {
        if (!strcmp(prev->next->name, name))
        {
            struct rent *temp = prev->next;
            prev->next = prev->next->next;
            free(temp);
            return;
        }
        prev = prev->next;
    }
}