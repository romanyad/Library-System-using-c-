#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Book.h"
#include "LibraryInventory.h"
#include <string>
    using namespace std;
class Librarian
{
private:
    string librarianName ;
    int librarianPassword ;
    string librarianUsername;
    Book *book;
LibraryInventory *Inventory ;

public:
    Librarian()    {}

    Librarian(LibraryInventory * x)
    {
        Inventory = x;
    }
    
    void matchPointers(LibraryInventory * x)
    {
         Inventory = x;
    }
   string getName() 
   {return librarianName;}
    int getPassword ()
    {return librarianPassword;}
    
    string getUserName ()
    {return librarianUsername;}
    
        void setlibrarianName (string x ) 
        {
            librarianName =x;
        }
        void setLibrarianPassword (int x ) 
        {
            librarianPassword = x;
        }
        void setLibrarianUsername(string x )
        {
            librarianUsername=x;
        }
        
    void EditBookDetails () 
    {
        double insertedDoubleData;
          int insertedIntData;
          string insertedStringData;
        cout <<"Enter the Book ID :";
        cin>>insertedIntData;
        book=Inventory->returnBookpointer(insertedIntData);
        if (book ==nullptr)
        {
            cout <<"The book is not exist..."<<endl;
        }
        int choice = 1;
    
        while (choice <8 && choice > 0 && book !=nullptr)
        {

            cout <<"*** Choose one From the options ***"<<endl<<endl;
            cout <<"1-Edit The Book Name" <<endl;
            cout <<"2-Edit The Author Name" <<endl;
            cout <<"3-Edit The Book Description" <<endl;
            cout <<"4-Edit The Book Price" <<endl;
            cout <<"5-Edit The Book Publish Year" <<endl;
            cout <<"6-Edit The Number of Pages for the Book" <<endl;    
            cout <<"7-Edit The Borrowing price" <<endl;   
            cout <<"8-Exit" <<endl;     
            cout <<"Your Choice : ";
            cin >>choice;
            
            cin.ignore();
            switch (choice)
            {
            case 1 :
                    cout <<"Enter the Book Name :";
                     getline(cin,insertedStringData);
                     book->setBookName(insertedStringData);
                    break;
            case 2 :
                    cout <<"Enter the Author Name :";
                    getline(cin,insertedStringData);
                    book->setBookAurthorName(insertedStringData);
                    break;
            case 3 :
                    cout <<"Enter the Book Description :";
                    getline(cin,insertedStringData);
                    book->setBookDescription(insertedStringData);
                    break;
              case 4 :
                    cout <<"Enter the Price :";
                    cin>>insertedDoubleData;
                    book->setPrice(insertedDoubleData);              
                    break;
              case 5 :
                    cout <<"Enter the Publish Year :";
                    cin>>insertedIntData;
                    book->setPublishYear(insertedIntData);              
                    break;
              case 6 :
                    cout <<"Enter the Number of Pages :";
                    cin>>insertedIntData;
                    book->setNumberOfPage(insertedIntData);              
                    break;
            case 7 :
                    cout <<"Enter the Borrowing price :";
                    cin>>insertedDoubleData;
                    book->setBorrowingPrice(insertedDoubleData);              
                    break;
                    
            default :
                cout <<"You Chose to Exit from the menu..."<<endl;
            }
        }
    }
    
  void  SortBooksByPrice() 
  {
      Book *current = Inventory->frontNode, *index = nullptr;  
        Book temp;  
        int typeofOrder;
        
          if(Inventory->isEmpty()) {  
            cout <<"The Inventory is empty" <<endl;
        }

        else 
        {
             readData:
            cout <<"Enter opiton number \n";
            cout <<"Ascending Order --> Enter [0]\n";
            cout <<"Descending Order --> Enter [1]\n";
            cout <<"Enter number for preferred Sorting Order :";
            cin >>typeofOrder;
            
            
            
                if (typeofOrder == 0 || typeofOrder == 1) {  
            while(current != nullptr) {  

                index = current->nextBook;  
                  
                while(index != nullptr) {  

                    if(current->getBookPrice() > index->getBookPrice() && typeofOrder == 0) {  
                        temp.setAllAttributesatOnce(current->getBookName(),current->getBookAurthorName(),current->getBookDescription(),current->getBookPrice(),current->getBorrowingPrice(),current->getPublishYear(),current->getNumberOfPage(),current->getBookId());
                        current->setAllAttributesatOnce(index->getBookName(),index->getBookAurthorName(),index->getBookDescription(),index->getBookPrice(),index->getBorrowingPrice(),index->getPublishYear(),index->getNumberOfPage(),index->getBookId());
                        index->setAllAttributesatOnce(temp.getBookName(),temp.getBookAurthorName(),temp.getBookDescription(),temp.getBookPrice(),temp.getBorrowingPrice(),temp.getPublishYear(),temp.getNumberOfPage(),temp.getBookId());                 
                    }

                    if(current->getBookPrice() < index->getBookPrice() && typeofOrder == 1) {  
                        temp.setAllAttributesatOnce(current->getBookName(),current->getBookAurthorName(),current->getBookDescription(),current->getBookPrice(),current->getBorrowingPrice(),current->getPublishYear(),current->getNumberOfPage(),current->getBookId());
                        current->setAllAttributesatOnce(index->getBookName(),index->getBookAurthorName(),index->getBookDescription(),index->getBookPrice(),index->getBorrowingPrice(),index->getPublishYear(),index->getNumberOfPage(),index->getBookId());
                        index->setAllAttributesatOnce(temp.getBookName(),temp.getBookAurthorName(),temp.getBookDescription(),temp.getBookPrice(),temp.getBorrowingPrice(),temp.getPublishYear(),temp.getNumberOfPage(),temp.getBookId());                 
                    }
                    
                    
                    index = index->nextBook;  
                }  
                current = current->nextBook;  
            }
        cout <<"the invenrtory has been sorted successfully"<<endl;
        }
        else {
           
            char enteredChar;
            cout <<"You Have entered a wrong number ...";
            cout <<"To Enter a new number write [Y] :";
            cin >>enteredChar;
                if (enteredChar == 'y' || enteredChar == 'Y')
                {
                    goto readData;
                }
                else 
                {
                cout <<"You choose to exit..."<<endl;    
                }
            }
        }
        
        }
  
      
    
    
    

};

#endif // LIBRARIAN_H
