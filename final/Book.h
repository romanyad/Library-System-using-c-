#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;

class Book
{
    
private:
    string bookName;
    string bookAuthorName ;
    double bookPrice;
   double bookBorrowingPrice;
    int publishYear;
    int numberOfPages ;
    string bookDescription;
    int bookId;
public:

     Book * nextBook;
     Book()
     {
        bookName =bookAuthorName= bookDescription ="NULL";
        bookPrice = bookId=bookBorrowingPrice= publishYear = numberOfPages = 0;
    }
    
    string getBookName()
        {return bookName;}
        
    string getBookAurthorName()
        {return bookAuthorName ;}
        
    double getBookPrice()
        {return bookPrice;}
        
    double getBorrowingPrice()
        {return bookBorrowingPrice;}
        
    int getPublishYear()
        {return publishYear;}
        
    int getNumberOfPage ()
        {return numberOfPages ;}
    
    string getBookDescription()
        {return bookDescription;}
    
    int getBookId()
        {return bookId;}
    
    void setBookId(int x )
        {bookId = x;}
        
    void setBookName(string BookName)
        {this->bookName =BookName; }
        
    void setBookAurthorName (string BookAurthorName ) 
        {this->bookAuthorName = BookAurthorName ;}
        
    void setPrice (double price) 
        {bookPrice= price;}
        
    void setBorrowingPrice (double BorrowingPrice)
        {this->bookBorrowingPrice = BorrowingPrice;}
        
    void setPublishYear(int x)
        {publishYear = x;}
        
    void setNumberOfPage (int x)
        {numberOfPages =x;}
        
    void setBookDescription(string description)
        {bookDescription=description;}
    
    void setAllAttributesatOnce(string BookName, string BookAurthorName , string description ,double price , double BorrowingPrice, int year , int pages, int Bookid)
    {
        this->bookName=BookName;
        this->bookAuthorName = BookAurthorName ;
        this->bookDescription=description;
        this->bookPrice= price;
        this->bookBorrowingPrice = BorrowingPrice;
        publishYear = year;
        numberOfPages=pages;
        this->bookId = Bookid;
    }
    void printBookDetails()
    {
    cout <<"***** Book Information for [" <<bookName  <<"] *****" <<endl;
    cout <<"Book ID :"<<bookId<<endl;
    cout <<"Book Name :"<<bookName<<endl;
    cout <<"About The Book :"<<bookDescription<<endl;
    cout <<"Author Name :"<<bookAuthorName <<endl;
    cout <<"Year of publishing :"<<publishYear<<endl;
    cout <<"Number of Pages :"<<numberOfPages <<endl;
    cout <<"Book Price :" << bookPrice <<" RM"<<endl;
    cout <<"Borrowing Price : "<<bookBorrowingPrice<<"   daily/price"<<endl;

    }

    
};

#endif // BOOK_H
