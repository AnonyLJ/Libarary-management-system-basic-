#include <stdio.h>
#include <string.h>

// Struct definitions
struct addmember
{
    char name[100];
    int age;
    int number; // Assuming this is the phone number
    int memberID; // New member ID field
};

struct addmember members[1000];
//int totalMembers = 0;
struct issuedbooks
{
    int bookid;
    char booktitle[100];
    char author[100];
    int day;
    int month;
    int year;
};

struct addbook
{
    char booktitle[100];
    int B_id;
    char author[100];
    int copies;
};

// Global variables to store data
struct addmember members[1000];
struct addbook books[1000];
struct issuedbooks issued[1000];
int totalMembers = 0;
int totalBooks = 0;
int totalIssued = 0;

// Function prototypes
void librarian();
void member();
void regismemb();
void addbook();
void viewBooks();
void issueBook();
void returnBook();
void payFine();
void viewMembers();
void viewIssuedBooks();

int main()
{
    int choice;
    printf("-----------------------\n");
    printf("Enter Your Choice \n");
    printf("1. To enter as librarian \n");
    printf("2. To enter as a member  \n");
    printf("3. To exit \n");
    printf("-----------------------\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        librarian();
        break;
    case 2:
        member();
        break;
    case 3:
        printf("-----------------------\n");
        printf(" You chose to exit \n Thank You \n");
        printf("-----------------------\n");
        break;
    default:
        printf("-----------------------\n");
        printf("Wrong choice \n");
        printf("-----------------------\n");
    }
    return 0;
}

// Update the librarian function
void librarian()
{
    int choice;
    printf("-----------------------\n");
    printf("Librarian function \n");
    printf("-----------------------\n");
    printf("Enter your choice \n");
    printf("1. TO REGISTER A MEMBER \n");
    printf("2. ADD A BOOK \n");
    printf("3. VIEW AVAILABLE BOOKS \n");
    printf("4. VIEW MEMBERS \n");
    printf("5. VIEW ISSUED BOOKS \n");  // Added option for viewing issued books
    printf("6. BACK \n");
    printf("-----------------------\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        regismemb();
        break;
    case 2:
        addbook();
        break;
    case 3:
        viewBooks();
        break;
    case 4:
        viewMembers();
        break;
    case 5:
        viewIssuedBooks();  // Call the new function for viewing issued books
        break;
    case 6:
        main();
        break;
    default:
        printf("-----------------------\n");
        printf("Wrong choice \n");
        printf("-----------------------\n");
    }
}
void regismemb()
{
    printf("Enter number of members to be added: ");
    int n;
    scanf("%d", &n);

    for (int i = totalMembers; i < totalMembers + n; i++)
    {
        printf("-----------------------\n");
        printf("Member number: %d\n", i + 1);

        // Assigning member ID
        members[i].memberID = i + 1;

        printf("Enter name: ");
        scanf("%s", members[i].name);
        printf("Enter age: ");
        scanf("%d", &members[i].age);
        printf("Enter phone number: ");
        scanf("%d", &members[i].number);
        printf("-----------------------\n");
        printf("Thank you\nDetails of the member are stored successfully\nMEMBER REGISTERED\n");
        printf("-----------------------\n");
    }

    totalMembers += n;
    printf("Returning to the main menu \n");
    librarian(); // Assuming you want to return to the librarian menu after registering members
}

void viewMembers()
{
    printf("Registered Members:\n");
    for (int i = 0; i < totalMembers; i++)
    {
        printf("Member ID : %d\n", members[i].memberID);
        printf("Name : %s\n", members[i].name);
        printf("Age : %d\n", members[i].age);
        printf("Phone Number : %d\n", members[i].number);
        printf("-----------------------\n");
    }

    librarian(); // Return to the librarian menu
}


void addbook()
{
    printf("Enter number of books to be added: ");
    int n;
    scanf("%d", &n);
    for (int i = totalBooks; i < totalBooks + n; i++)
    {
        printf("-----------------------\n");
        printf("Book Number : %d \n ", i + 1);
        printf("Enter book title : ");
        scanf("%s", books[i].booktitle);
        printf("Enter book author : ");
        scanf("%s", books[i].author);
        printf("Enter book id: ");
        scanf("%d", &books[i].B_id);
        printf("Enter total copies  : ");
        scanf("%d", &books[i].copies);
        printf("-----------------------\n");
        printf("Thank you\nDetails of the Book are stored successfully\nBOOK REGISTERED\n");
        printf("-----------------------\n");
    }
    totalBooks += n;
    printf("Returning to the main menu \n");
    main();
}

void viewBooks()
{
    printf("Available Books:\n");
    for (int i = 0; i < totalBooks; i++)
    {
        printf("Book ID : %d\n", books[i].B_id);
        printf("Title : %s\n", books[i].booktitle);
        printf("Author : %s\n", books[i].author);
        printf("Available Copies : %d\n", books[i].copies);
        printf("-----------------------\n");
    }
    main();
}

void member()
{
    int choice;
    printf("-----------------------\n");
    printf("Member function \n");
    printf("-----------------------\n");
    printf("Enter your choice \n");
    printf("1. VIEW AVAILABLE BOOKS \n");
    printf("2. ISSUE A BOOK \n");
    printf("3. RETURN A BOOK \n");
    printf("4. PAY FINE \n");
    printf("5. BACK \n");
    printf("-----------------------\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        viewBooks();
        break;
    case 2:
        issueBook();
        break;
    case 3:
        returnBook();
        break;
    case 4:
        payFine();
        break;
    case 5:
        main();
        break;
    default:
        printf("-----------------------\n");
        printf("Wrong choice \n");
        printf("-----------------------\n");
    }
}

void issueBook()
{
    int memberID, bookID;
    printf("Enter your Member ID: ");
    scanf("%d", &memberID);
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);

    // Check if the book is available
    int bookIndex = -1;
    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].B_id == bookID)
        {
            bookIndex = i;
            break;
        }
    }

    // Check if the member exists
    int memberIndex = -1;
    for (int i = 0; i < totalMembers; i++)
    {
        if (i == memberID - 1)
        {
            memberIndex = i;
            break;
        }
    }

    if (bookIndex != -1 && memberIndex != -1)
    {
        if (books[bookIndex].copies > 0)
        {
            // Issue the book
            issued[totalIssued].bookid = bookID;
            strcpy(issued[totalIssued].booktitle, books[bookIndex].booktitle);
            strcpy(issued[totalIssued].author, books[bookIndex].author);

            // Decrease the available copies
            books[bookIndex].copies--;

            printf("Book issued successfully\n");
            printf("Study hard! ALL THE BEST\n");
            totalIssued++;
        }
        else
        {
            printf("Sorry, the book is not available\n");
        }
    }
    else
    {
        printf("Invalid Member ID or Book ID\n");
    }

    member();
}

void returnBook()
{
    int bookID;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);

    int bookIndex = -1;
    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].B_id == bookID)
        {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex != -1)
    {
        // Increase the available copies
        books[bookIndex].copies++;
        printf("Book returned successfully\n");
    }
    else
    {
        printf("Book ID is invalid\n");
    }

    member();
}

void payFine()
{
    // Implement fine payment logic here
    printf("Fine payment functionality to be implemented\n");

    member();
}
void viewIssuedBooks()
{
    printf("Issued Books:\n");
    for (int i = 0; i < totalIssued; i++)
    {
        printf("Book ID : %d\n", issued[i].bookid);
        printf("Title : %s\n", issued[i].booktitle);
        printf("Author : %s\n", issued[i].author);
        printf("-----------------------\n");
    }

    librarian();  // Return to the librarian menu
}
