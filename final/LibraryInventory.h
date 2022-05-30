#ifndef LIBRARYINVENTORY_H
#define LIBRARYINVENTORY_H
#include <iostream>
#include <string>
#include "Book.h"
class LibraryInventory
{
    
public:
    Book *  frontNode ;
    Book *  backNode ;
   
   
    LibraryInventory(){
                        frontNode = nullptr;
                        backNode = nullptr;
        }
    
    
    ~LibraryInventory()
    {
        Book *temp = frontNode;  
        while (temp)
        {
            frontNode = temp->nextBook;
            delete temp; 
            temp=frontNode; 
        }
    }
    
    void stackPushUpcoming(Book upComingBook){
        Book *temp = new Book();
        
        temp->setBookName(upComingBook.getBookName());
        temp->nextBook = frontNode;
        frontNode = temp;
    }
    
    
    void destroyQueue()
    {
        Book *temp = frontNode;  
        while (temp)
        {
            frontNode = temp->nextBook;
            delete temp; 
            temp=frontNode; 
        }
    }
    
    bool isEmpty()
    { 
        return (frontNode==nullptr && backNode==nullptr);
    }
    
    void enQueue(Book newBook)
    {
        Book * Bnode = new Book();
        Bnode->setBookName(newBook.getBookName());
        Bnode->setBookAurthorName(newBook.getBookAurthorName());
        Bnode->setBorrowingPrice(newBook.getBorrowingPrice());
        Bnode->setNumberOfPage(newBook.getNumberOfPage());
        Bnode->setPrice(newBook.getBookPrice());
        Bnode->setPublishYear(newBook.getPublishYear());
        Bnode->setBookDescription(newBook.getBookDescription());
        Bnode->setBookId(newBook.getBookId());
        
        
        if ( isEmpty())
        {
            Bnode->nextBook =nullptr;
            frontNode = backNode = Bnode;
        }
        else
        {
            Bnode->nextBook = nullptr;
            backNode->nextBook = Bnode;
            backNode=Bnode;
        }
    }
    
    
    bool SearchForElement(string bookName)
    {

        Book * temp1 = frontNode;
        bool exist = false;
        
        while(temp1 != NULL)
        {
                if (temp1->getBookName() == bookName)    
                    {
                        exist= true;
                        break;
                    }
            temp1= temp1->nextBook;
        }
        
        return exist;
    }
    
     void deQueue() 
    { 

        if (frontNode == nullptr) 
                return; 
  
        Book* temp = frontNode; 
        frontNode = frontNode->nextBook; 
  
        if (frontNode == nullptr) 
            backNode = nullptr; 
  
        delete (temp); 
    }
    
    
    void afterborrowBuyQueue(string bookName)
    {
                //the idea from this function is to delete from the book the queue without deleting the elements the before the wanted element
                if ( isEmpty())
                {
                cout<<"the inventory is empty"<<endl;    
                }
                else
                {
                    if (SearchForElement(bookName) == false)
                        {
                        cout <<"The Book is not exist in the inventory...\n";    
                        }
                    else
                    {

                            while (frontNode->getBookName() != bookName)
                                {
                                Book  Bnode ;
                                Bnode.setAllAttributesatOnce(frontNode->getBookName(),frontNode->getBookAurthorName(),frontNode->getBookDescription(),frontNode->getBookPrice(),frontNode->getBorrowingPrice(),frontNode->getPublishYear(),frontNode->getNumberOfPage(),frontNode->getBookId());
                                    enQueue(Bnode);
                                    deQueue() ;
                                }
                            cout <<frontNode->getBookName()<<" is now out the Inventory....\n";
                            deQueue() ;

                    }
            
            }
                
    }
    
int TotalBooksIntheInventory () 
    {
            int counter =0;
          Book *temp=frontNode;
              while(temp!=nullptr)
              {
                counter++;
                temp=temp->nextBook;
                }
         return counter;
    }
     
  Book *  returnBookpointer(int bookid) 
          {
         
                    Book *temp=frontNode;
                    bool exist= false;
                    while (temp!= nullptr)
                    {
                        if (temp->getBookId()==bookid)
                                { 
                                exist = true;
                                break; 
                                }
                            temp= temp->nextBook;
                    }
                    if (exist != false) 
                        return temp;
                    else 
                        return nullptr;       
            }
  Book *  returnBookpointer(string bookName) 
          {
         
                    Book *temp=frontNode;
                    bool exist= false;
                    while (temp!= nullptr)
                    {
                        if (temp->getBookName()==bookName)
                                { 
                                exist = true;
                                break; 
                                }
                            temp= temp->nextBook;
                    }
                    if (exist != false) 
                        return temp;
                    else 
                        return nullptr;       
            }
   Book *  getFrontNode()
   {
       if   (isEmpty())
           return nullptr;
       else  
       return frontNode;
    }
    
     void display() 
    {
        
        int internalCounter=0;
         char descision;
        
              if(isEmpty())
              {
                cout << "Inventory is Empty" << endl;
              }
            else
            {
                
                Book *temp=frontNode;
                while(temp!=nullptr)
                {
                    //Sleep(1000);
                    //system ("CLS");
                    cout <<"<<< Information for Book ["<<internalCounter+1<<"] >>>"<<endl;
                    temp->printBookDetails();
                    cout<< endl;
                 
                    cout <<"To go to next book please Enter [y] :";
                    cin >>descision;
                    cout << endl;
                 if (descision=='y' || descision =='Y')
                 {
                     internalCounter++;
                  temp=temp->nextBook;
                  if(temp == nullptr)
                      cout <<"You have reached the end..."<<endl;
                   continue;
                  }
                  else{
                      cout <<"You chose to exit..."<<endl;
                      break;
                      }
                }

            }
    
    }
    
    
   
};

#endif // LIBRARYINVENTORY_H
