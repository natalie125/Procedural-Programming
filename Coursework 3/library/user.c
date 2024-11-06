#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

////
// Code module for the library user
// They can look for available books,
// borrow and return books

// List the books that are available to borrow
// Input
// bookList - the array of Book structures
// numBooks - the number of books

void listAvailableBooks( Book *bookList, int numBooks ) {

  // TO DO :  

  // print out available books with format "list number - author - title" on each line
  
 for(int i = 0;i<numBooks; i++){
    if(bookList[i].available == 1){
        printf("%d - %s -%s\n",i,bookList[i].author, bookList[i].title);
    }
  }  
  return;
}

// Borrow a book 
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void borrowBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :  

  // For any error message you should return to the menu

  // check that the user can borrow a book
  if((theUser -> numBorrowed) >= maxBorrowed){
    printf("You have to return a book before you can borrow another\n");
    return;
  }

  // request the choice of book 
  else{
    int choice = optionChoice();
    
  
  // check that the choice is valid 
  // error messages
      if(bookList[choice].available == 0){
        printf("Book is not available\n");
      }else if((choice<0 )||( choice > numBooks)){
        printf("Error\nInvalid choice\n");
        return;
      }else{  

// borrow the book, update the data structures
      theUser -> borrowed[theUser->numBorrowed++] = &bookList[choice];
      bookList[choice].available = 0;
      return;
    }
  }
} 

// List books I have borrowed 
// Input
// theUser - user data structure
// bookList - the array of Book structures
// maxBorrowed - max books we can borrow

void listMyBooks( User *theUser, Book *bookList, int maxBorrowed ) {

  // TO DO :  

  // list my books in format "number - author - title"
    if((theUser ->numBorrowed)==0){
      return;
    }else{
      for(int i=0; i < (theUser ->numBorrowed);i++){
        printf("%d - %s\n", i, theUser -> borrowed[i] -> author, theUser -> borrowed[i] -> title);
        return;
     } 
    }
}
    



// Return a book 
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void returnBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :  

  // For any error message you should return to the menu

  // check that we have borrowed books 
  // error messages
    if(theUser-> numBorrowed == 0){
      
        printf("Error\nYou have not borrowed any books\n");
        return;
    }
    else{

      // request the choice of book 
      // message
      printf("Which book? (number):");
      int choice;
      scanf("%d",choice);

      // check the choice is valid
      // error messages
        if((choice > (theUser -> numBorrowed ))|| (choice<0)){
          printf("Error\nInvalid choice\n");
          return;
        }
        else{


       

      // return the book and update data structures 
          int i;
          for(i = choice; i<3 ;i++){
            theUser -> borrowed[i] = theUser -> borrowed[i+1];
            bookList[choice].available = 1;
            return;
        }
          
        
      } 
    }
}
void userCLI( Library *theLibrary ) {
    int userLoggedIn = 1;
    int option;

    while( userLoggedIn ){
        printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nList available books:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 2 ) {
            printf("\nBorrow book from library:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
            borrowBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 3 ) {
            printf("\nReturn book from my list:\n");
            listMyBooks( &(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed );
            returnBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 4 ) {
            userLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}

