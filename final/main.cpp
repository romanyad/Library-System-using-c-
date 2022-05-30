#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#include "LibraryInventory.h"
#include "Book.h"
#include "Librarian.h"
#include "BorrowingRecords.h"
using namespace std;

int main()
{
    Book tempBook;
    Book *temp_node_pointer;
    BorrowingRecords borrowedRecords;
    LibraryInventory * invertory = new LibraryInventory;
    Librarian librarians[3];
    int arrayindex = -1 ;
    int counterforlibrarianarray = 0 ;
    fstream in_out_librarians("D:\\5TH SEM\\Data Structure\\Project & Assignment\\final\\admin.txt", ios::in | ios::out );
    
    //D:\\5TH SEM\\Data Structure\\Project & Assignment\\final\\admin.txt
    
    bool librariansFileIsEmpty = false;
    bool libraryArrayEmpty = false;
        if (!in_out_librarians)
        {
            cout <<"These is no file for librarians"<<endl;
            exit(0);
        }
    
        if ( in_out_librarians.peek() == std::ifstream::traits_type::eof() )
               {librariansFileIsEmpty=true;}
    
    if (librariansFileIsEmpty == false)
    {
        int temcounter =0 ;
        int tempDate;
        string tempstring;
        while(!in_out_librarians.eof())
        {
            getline(in_out_librarians,tempstring,'_');
            librarians[temcounter].setlibrarianName(tempstring);
            
             getline(in_out_librarians,tempstring,'_');
             librarians[temcounter].setLibrarianUsername(tempstring);
             in_out_librarians>>tempDate;
             librarians[temcounter].setLibrarianPassword(tempDate);
             temcounter++;
        }
    }
    int choice = 3;
    do {
        mainPage:
        
        cout <<"<<< Welcome to Book Paradise >>> "<<endl;
        cout <<"Please Enter your Choice"<<endl;
        cout <<"1- Librarian Sign In "<<endl;
        cout <<"2- User"<<endl;
        cout <<"3- Exit"<<endl;
        cout <<"Enter your choice [1 ,2 or 3] :";
        cin>>choice;
        
        if (choice ==1)
        {
                Sleep(1500);
                system ("CLS");
            if (librariansFileIsEmpty == true && libraryArrayEmpty== false)
            {
            char internalChoice;
            cout <<"File is Empty!! No data Stored in Librarians file ..."<<endl;
            cout <<"There should be at least one user account in the file"<<endl;
            cout <<"If you want to add an account please enter [y] :";
            cin >>internalChoice;
                if (internalChoice=='y' || internalChoice == 'Y')
                {
                    libraryArrayEmpty = true;
                    string stringInsertedData;
                    int intInsertedData;

                    bool internalchoice1=true;
                    do{
                        cout <<"Enter Librarian Name :";
                        cin.ignore();
                        getline(cin , stringInsertedData);
                        librarians[counterforlibrarianarray].setlibrarianName(stringInsertedData);
                        
                        cout <<"Please Enter the account username *no spaces :";
                        cin >> stringInsertedData;
                        librarians[counterforlibrarianarray].setLibrarianUsername(stringInsertedData);
                        
                         cout <<"Please Enter the account password *only numbers :";
                         cin >>intInsertedData;
                        librarians[counterforlibrarianarray].setLibrarianPassword(intInsertedData);
                        
                          char internalChoice2;
                        cout <<"Do you want to add another account [y] :";
                        cin>>internalChoice2;
                        if (internalChoice2 =='y' || internalChoice2 =='Y') 
                        {
                            counterforlibrarianarray++;
                            if (counterforlibrarianarray < 3 )
                            {
                                Sleep(1500);
                                system ("CLS");
                            }
                            else 
                            {
                                cout <<"you execsd the limit of accounts !!"<<endl;
                                internalchoice1 = false;
                                break;
                            }
                        }
                        else 
                        {
                            internalchoice1 = false;
                        }
                        
                        }while(internalchoice1);
                }
                else
                {
                    cout <<"you will go to main page after 1.5s"<<endl;    
                    Sleep(1500);
                    system ("CLS");
                }
                
            }
            else 
            {
                string stringInsertedData;
                int intInsertedData;
                bool correctPasswrod = false;
                bool correctUsername = false;
                
                //log in page 
                
                logIn:       
                 cout <<"Please Enter User Name ::";
                  cin >> stringInsertedData;
                    cout <<"Please Enter password ::";
                    cin >>intInsertedData;
                         for (int i = 0 ; i < 3 ; i++)
                        {
                            if (librarians[i].getUserName() == stringInsertedData)
                            {
                                correctUsername= true;
                                arrayindex=i;       
                                break;
                            }                 
                        }

                        if (librarians[arrayindex].getPassword() == intInsertedData)
                        {
                            correctPasswrod= true;
                        }                 
                
                        if (correctPasswrod == false||  correctUsername==false)
                        {
                                int chosenNumber;
                                cout <<"You have entered Worng Data , 1 = true , 0 = falase"<<endl;
                                cout <<"password ["<<correctPasswrod<<"] "<<endl;
                                cout <<"Username ["<<correctUsername<<"] "<<endl;
                                cout<<".... Choose one ..."<<endl;
                                cout <<"1-Go to main page"<<endl;
                                cout <<"2-try again"<<endl;
                                 cout <<"enter any other number to exit from the system..."<<endl;
                                 cout <<"enter a number :";
                                 cin >>chosenNumber;
                                 
                                 if (chosenNumber==1)
                                     goto mainPage;
                                else if (chosenNumber==2)
                                    goto logIn;
                                else 
                                    goto endsystem;
                        }
                        
                     if (correctPasswrod == true && correctUsername==true)
                     {
                        librarians[arrayindex].matchPointers(invertory);
                        
                   
                        int choosenNumber2=0;
                         
                            Sleep(1500);
                            system ("CLS");
                         cout <<"Welcome "  <<librarians[arrayindex].getName()<<" what do you want to do today ?"<<endl;
                         cout<<"1- Add a new book"<<endl;
                         cout<<"2- Edit Book Information"<<endl;
                         cout <<"3- Search for a book"<<endl;
                         cout <<"4- Show the number of books in the inventory"<<endl;
                         cout <<"5- Sort the books in the inventory"<<endl;
                         cout <<"6- Delete a book from inventory"<<endl;
                         cout <<"7- Export the books "<<endl;
                         cout <<"8- Import  books "<<endl;
                         cout <<"9- Display borrowing records"<<endl;
                         cout <<"10- Export borrowing records"<<endl;
                         cout <<"11- Import borrowing records"<<endl;
                         cout <<"12- Go to main page"<<endl;
                         cout <<"Enter any number out of the range to exit from the system"<<endl;
                         
                         do {
                        cout <<"Enter your choice :";
                         cin >>choosenNumber2;
                         
                         string insertedStringDate;
                         int insertedIntData;
                         double insertedDoubleData;
                         
                         if (choosenNumber2==1)
                        {
                            //tempBook
                            cout <<"<<< Add a new Book >>>"<<endl;
                            cin.ignore();
                            cout <<"Enter the Book ID *only numbers:";
                                cin >>insertedIntData;
                                tempBook.setBookId(insertedIntData);
                                
                                 cin.ignore();
                            cout <<"Enter the Book Name : ";
                                getline(cin,insertedStringDate);
                                tempBook.setBookName(insertedStringDate);
                                
                            cout <<"Enter The Book Author Name :";
                                getline(cin,insertedStringDate);
                                tempBook.setBookAurthorName(insertedStringDate);
                                
                            cout <<"Write Book Description *one line only :";
                                getline(cin,insertedStringDate);
                                tempBook.setBookDescription(insertedStringDate);
                            
                            cout <<"Enter the book price :";
                                cin >>insertedDoubleData;
                                tempBook.setPrice(insertedDoubleData);
                                
                            cout <<"Enter the Book Borrowing Price :";
                                cin >>insertedDoubleData;
                                tempBook.setBorrowingPrice(insertedDoubleData);
                            
                            cout <<"Enter number of book pages :"; 
                                cin >>insertedIntData;
                                tempBook.setNumberOfPage(insertedIntData);
                            
                            cout <<"Enter year of publish :";
                                cin >>insertedIntData;
                                tempBook.setPublishYear(insertedIntData);
                            
                           
                            invertory->enQueue(tempBook);  //add the book to the queue

                        }
                        else if (choosenNumber2==2)
                        {
                            cout <<"<<< To Edit the Book information >>>:"<<endl;
                            librarians[arrayindex].EditBookDetails();
                        }
                        
                         else if (choosenNumber2==3)
                        {
                        cout <<"<<< Search for a Book >>>"<<endl;
                        cin.ignore();
                            cout <<"Please Enter The Book Name :";
                                getline(cin,insertedStringDate);
                                
                            if (invertory->SearchForElement(insertedStringDate))
                                {
                                cout <<"The Book is exist in the inventory"<<endl;
                               temp_node_pointer= invertory->returnBookpointer(insertedStringDate);
                               temp_node_pointer->printBookDetails();
                                }
                            else
                                 {cout <<"The Book is not exist in the inventory"<<endl;}
                            
                        }
                        
                        else if (choosenNumber2==4)
                        {
                              cout <<"<<< Number of Books in Inventory >>>:"<<endl;
                              cout <<"There are ["<<invertory->TotalBooksIntheInventory()<<"] Books in the Inventory..."<<endl;
                        }
                        
                        else if (choosenNumber2==5)
                        {
                                cout <<"<<< Sort Books in Inventory >>>:"<<endl;
                                cout <<"the books will be sorted by their price..."<<endl;
                                librarians[arrayindex].SortBooksByPrice();
                        }
                        else if (choosenNumber2==6)
                        {
                                cout <<"<<< Delete a Book From Inventory >>>:"<<endl;
                                cin.ignore();
                                cout <<"Please Enter The Book Name :";
                                    getline(cin,insertedStringDate);
                                invertory->afterborrowBuyQueue(insertedStringDate);

                        }
                        else if (choosenNumber2==7)
                        { 
                            cout <<"<<< Export Books  >>>:"<<endl;
                            cin.ignore();
                            cout <<"exporting the books means you are emptying the inventory..."<<endl;
                            cout <<"Enter the location that you want to export to (note please double each \\ ) :";
                            getline(cin,insertedStringDate);
                                fstream out_books(insertedStringDate,   ios::out );
                             out_books.clear();
                            out_books.seekp(0);
                            
                                temp_node_pointer= invertory->getFrontNode();
                                
                                while(temp_node_pointer)
                                {
                             
                                  out_books<<  temp_node_pointer->getBookAurthorName()<<"_"
                                  << temp_node_pointer->getBookName()<<"_"<<temp_node_pointer->getBookDescription()<<"_"<<
                                  temp_node_pointer->getPublishYear()<<" "<<temp_node_pointer->getNumberOfPage()<<" "<<
                                  temp_node_pointer->getBookPrice()<<" "<<temp_node_pointer->getBorrowingPrice()<<" "
                                  <<temp_node_pointer->getBookId();
                                  
                                  out_books<<endl;
                                    invertory->deQueue();
                                    temp_node_pointer= invertory->getFrontNode();
                                }
                                
                               
                                out_books.close();
                        }
                        else if (choosenNumber2==8)
                        {
                            cout <<"<<< Import Books >>>:"<<endl;
                            cin.ignore();
                            cout <<"Enter the File location that you want to import from (note please double each \\ ) :";
                            getline(cin,insertedStringDate);
                                fstream in_books(insertedStringDate,   ios::in );
                                if (!in_books)
                                {
                                cout <<"there is no file..!!"<<endl;    
                                }
                                else
                                {
                                    while(!in_books.eof())
                                    {
                                        getline(in_books,insertedStringDate,'_');
                                        tempBook.setBookAurthorName(insertedStringDate);
                                        getline(in_books,insertedStringDate,'_');
                                        tempBook.setBookName(insertedStringDate);
                                        getline(in_books,insertedStringDate,'_');
                                        tempBook.setBookDescription(insertedStringDate);
                                        
                                        in_books>>insertedIntData;
                                        tempBook.setPublishYear(insertedIntData);
                                        in_books>>insertedIntData;
                                        tempBook.setNumberOfPage(insertedIntData);
                                        in_books>>insertedDoubleData;
                                        tempBook.setPrice(insertedDoubleData);
                                        in_books>>insertedDoubleData;
                                        tempBook.setBorrowingPrice(insertedDoubleData);
                                         in_books>>insertedIntData;
                                         tempBook.setBookId(insertedIntData);
                                         
                                         invertory->enQueue(tempBook);
                                    }
                                
                                }

                                in_books.close();
                        }
                        else if (choosenNumber2==9)
                        {
                            borrowedRecords.PrintAllRecords();
                        }
                        else if (choosenNumber2==10)
                        {
                            cout <<"<<< Export Borrowing Records >>>:"<<endl;
                            cin.ignore();
                            cout <<"Enter the location that you want to export to (note please double each \\ ) :";
                            getline(cin,insertedStringDate);
                             fstream out_BorrowRecords(insertedStringDate,   ios::out );
                            out_BorrowRecords.clear();
                            out_BorrowRecords.seekp(0);
                            for(int i = 0 ; i < borrowedRecords.getCounter() ; i++)
                            {
                                out_BorrowRecords<<borrowedRecords.getBookId(i)<<" "<<borrowedRecords.getBorrowingDuration(i)<<" "<<borrowedRecords.getProfit(i)<<endl;
                            }
                            out_BorrowRecords.close();
                        }
                        else if (choosenNumber2==11)
                        {
                            cout <<"<<< Import Borrowing Records >>>:"<<endl;
                            cin.ignore();
                              cout <<"There is a space for "<<100 -borrowedRecords.getCounter() <<" records"<<endl;
                            cout <<"Enter the location that you want to Import from (note please double each \\ ) :";
                            getline(cin,insertedStringDate);
                             fstream in_BorrowRecords(insertedStringDate,   ios::in );
                             
                             if (!in_BorrowRecords)
                             {
                                 cout <<"There is no file ...!!"<<endl;
                            }
                            else
                            {
                                     if (borrowedRecords.getCounter() ==0)
                                     {
                                    
                                         for (int i=0; i <100 && !in_BorrowRecords.eof(); i++)
                                         {
                                             in_BorrowRecords>>insertedIntData;
                                             borrowedRecords.setBookId(i,insertedIntData);
                                             in_BorrowRecords>>insertedIntData;
                                             borrowedRecords.setBorrowingDuration(i,insertedIntData);
                                             in_BorrowRecords>>insertedDoubleData;
                                             borrowedRecords.setProfit(i,insertedDoubleData);
                                             borrowedRecords.increaseCounter();
                                        }
                                    }
                                     else 
                                     {
                                          
                                                  for (int i=borrowedRecords.getCounter()  ; i <100 && !in_BorrowRecords.eof();i++)
                                             {
                                                 in_BorrowRecords>>insertedIntData;
                                                 borrowedRecords.setBookId(i,insertedIntData);
                                                 in_BorrowRecords>>insertedIntData;
                                                 borrowedRecords.setBorrowingDuration(i,insertedIntData);
                                                 in_BorrowRecords>>insertedDoubleData;
                                                 borrowedRecords.setProfit(i,insertedDoubleData); 
                                                 borrowedRecords.increaseCounter();
                                            }
                                    }
                            }
                            in_BorrowRecords.close();
                        }
                        else if (choosenNumber2==12)
                        {
                            Sleep(2000);
                            system ("CLS");
                            goto mainPage;
                        }
                        else
                        {
                        cout << "you choose to exit from the system..."<<endl;
                       goto endsystem;
                        }
                        
                         }while(choosenNumber2 >0 && choosenNumber2 < 13);
                    }
                    
                

            }
        }
        
        // User menu starts from here:
        
        else if (choice ==2)
        {
              int choosenNumber3=0;
              string insertedStringData3;
              
              
                 Sleep(2000);
                system ("CLS");
                cout <<"<<< Welcome User >>>"<<endl;
                cout <<"Please Choose one from Menu..."<<endl;
                cout <<"1- Display All the Books In the Inventory"<<endl;
                cout <<"2- Buy a Book"<<endl;
                 cout <<"3- Borrow Books"<<endl;
                cout <<"4- Search Books"<<endl;
                cout <<"5- Donate Books"<<endl;
                cout <<"6-Back to Main menu"<<endl;
                cout <<"Enter any number out of the range to exit from the system"<<endl<<endl<<endl;
                do {
                cout <<"Enter Your Choice :";
                cin >>choosenNumber3;
                
                if (choosenNumber3==1)
                {
                    cout <<"<<< These are all the Books in Inventory >>>:"<<endl;
                    invertory->display();
                }
                
                
                else if (choosenNumber3 == 2)
                {
                    cout <<"<<< Buy a Book From Inventory >>>:"<<endl;
                    cout <<"Please Enter The Book Name :";
                    cin.ignore();
                    getline(cin,insertedStringData3);
                     temp_node_pointer=   invertory->returnBookpointer(insertedStringData3);
                     if (temp_node_pointer !=nullptr)
                     {
                        cout <<"Book Price is :"<<temp_node_pointer->getBookPrice()<<endl;
                    invertory->afterborrowBuyQueue(insertedStringData3);
                     }
                     else
                         cout <<"The book is not exist , please try again....!!"<<endl;
                    }
                
                
                  else if (choosenNumber3 == 3)
                {
                    cout <<"<<< Borrow a Book  >>>:"<<endl;
                    cin.ignore();
                    cout <<"Please Enter The Book Name :";
                    getline(cin,insertedStringData3);
                     temp_node_pointer=   invertory->returnBookpointer(insertedStringData3);

                    if (temp_node_pointer !=nullptr)
                     {
                    borrowedRecords.RecordOperation(temp_node_pointer);
                    invertory->afterborrowBuyQueue(insertedStringData3);
                     }
                     else
                         cout <<"The book is not exist , please try again....!!"<<endl;
                }
                
                
                 else if (choosenNumber3 == 4)
                {
                    cout <<"<<< Search for a Book  >>>:"<<endl;
                        cout <<"Please Enter The Book Name :";
                        cin.ignore();
                        getline(cin,insertedStringData3);
                    temp_node_pointer=   invertory->returnBookpointer(insertedStringData3);
                     if (temp_node_pointer !=nullptr)
                     {
                         temp_node_pointer->printBookDetails();
                     }
                     else
                         cout<<"The Book is not in the inventory..."<<endl;
                }
                
                
                 else if (choosenNumber3 == 5)
                {
                    string temStringData1;
                    int temIntData1;
                    
                     tempBook.setBookId(invertory->TotalBooksIntheInventory() +1);
                      tempBook.setPrice(0.0);
                      tempBook.setBorrowingPrice(0.0);
                    cout <<"<<< Denote a Book  >>>:"<<endl;

                        cout <<"Enter the Book Name : ";
                        cin.ignore();
                        getline(cin,temStringData1);
                        tempBook.setBookName(temStringData1);
                                
                        cout <<"Enter The Book Author Name :";
                        getline(cin,temStringData1);
                        tempBook.setBookAurthorName(temStringData1);
                                
                        cout <<"Write Book Description *one line only :";
                        getline(cin,temStringData1);
                        tempBook.setBookDescription(temStringData1);

                        cout <<"Enter number of book pages :"; 
                        cin >>temIntData1;
                        tempBook.setNumberOfPage(temIntData1);
                            
                        cout <<"Enter year of publish :";
                        cin >>temIntData1;
                        tempBook.setPublishYear(temIntData1);
                            
                            //add the book to the queue
                            invertory->enQueue(tempBook);
                            
                }
                 else if (choosenNumber3 == 6)
                {
                    Sleep(2000);
                    system ("CLS");
                    goto mainPage;    
                }
                else 
                {
               cout << "you choose to exit from the system..."<<endl;
                        goto endsystem;
                }
           
                }while(choosenNumber3 >0 && choosenNumber3 < 7);
        }
        else 
        {
            goto endsystem;
        cout <<    "you chose to exit....\n have a nice day..."<<endl;
        break;
        }
        
        }while(choice >0 && choice < 3);
    
    
    endsystem:
    
    if (librariansFileIsEmpty ==true)
    {
            in_out_librarians.clear();
            in_out_librarians.seekp(0);
      //  counterforlibrarianarray
        for (int i = 0 ; i <=counterforlibrarianarray ; i++)
        {
            in_out_librarians<<librarians[i].getName()<<"_"<<librarians[i].getUserName()<<"_"<<librarians[i].getPassword()<<endl;
      
        }
        
    }
    in_out_librarians.close();
return 0;}