#ifndef BORROWINGRECORDS_H
#define BORROWINGRECORDS_H
#include <string>
#include "Book.h"

class BorrowingRecords
{
private:
    int BorrowedbookId[100];
    int counter;
    double ProfitFromBorrowing[100];
    int BorrowingDuration [100];
    Book *book;
public:
    BorrowingRecords()
    {
        counter=0;
        BorrowedbookId[0]=0;
        ProfitFromBorrowing[0]=0;
        BorrowingDuration[0]=0;
    }

    
    int getBookId(int  x)
        {return BorrowedbookId[x];}
        
    int getProfit(int x)
        {  return ProfitFromBorrowing[x];}
        
    int getBorrowingDuration(int x )
        {return BorrowingDuration[x];}
        
    void setBookId(int x, int value)
    {
        BorrowedbookId[x] = value;
    }
    
        void setProfit(int x, int value)
    {
        ProfitFromBorrowing[x] = value;
    }
    
        void setBorrowingDuration(int x, int value)
    {
        BorrowingDuration[x] = value;
    }
    int getCounter() {return counter;}
    void increaseCounter() {counter++;}
                
   void RecordOperation (Book * recordBook)
   {
       book= recordBook;
       
       BorrowedbookId[counter] =book->getBookId();
       cout <<"For How many days You want to borrow for : ";
       cin >> BorrowingDuration[counter];
       ProfitFromBorrowing[counter]= book->getBorrowingPrice() * BorrowingDuration[counter];
       cout <<"Total cost : " << ProfitFromBorrowing[counter] <<endl;
       cout <<"Thank You!! Remember..A reader lives a thousand lives before he dies ....."<<endl;
       counter++;
    }
    
    void PrintAllRecords()
    {
    cout <<"<<<<< THE Borrowing Records >>>>>"    <<endl;
        if (counter ==0)
            cout <<"There are no records...!!"<<endl;
        for (int i=0 ; i < counter ; i++)
        {
        cout<<i+1<<"- " <<"Book ID ["<<    BorrowedbookId[i]<<"]   Borrowing Duration ["<<BorrowingDuration[i]<<"] Total Cost ["<<ProfitFromBorrowing[i]<<"] "<<endl;
        }
    }
};

#endif 
