/*Q.No. 1 Banking Record System.
File handling has been effectively used for each feature of this project
Operations ? Add Record: ? Show/List Data: ? Search Record: ? Edit Record: ? Delete Record:*/

#include<iostream>
#include<fstream>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    float price;

    string to_string() const {
        return title + "," + author + "," + isbn + "," + to_string(price);
    }
};

void addBook() {
    Book book;
    cout << "Enter book title: ";
    getline(cin, book.title);
    cout << "Enter author name: ";
    getline(cin, book.author);
    cout << "Enter ISBN: ";
    getline(cin, book.isbn);
    cout << "Enter price: ";
    cin >> book.price;
    cin.ignore(); 

    ofstream file("books.txt", ios::app);
    file << book.to_string() << endl;
    file.close();

    cout << "Book added successfully." << endl;
}

void showBooks() {
    ifstream file("books.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string title, author, isbn;
        float price;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, isbn, ',');
        ss >> price;

        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << ", Price: " << price << endl;
    }
    file.close();
}

void checkAvailability() {
    string searchTerm;
    cout << "Enter book title or ISBN to check availability: ";
    getline(cin, searchTerm);

    ifstream file("books.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(searchTerm) != string::npos) {
            found = true;
            cout << "Book found: " << line << endl;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Book not found." << endl;
    }
}

void modifyBook() {
    string titleToModify;
    cout << "Enter the title of the book to modify: ";
    getline(cin, titleToModify);

    ifstream file("books.txt");
    vector<string> books;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(titleToModify) != string::npos) {
            found = true;
            Book book;
            cout << "Enter new title: ";
            getline(cin, book.title);
            cout << "Enter new author: ";
            getline(cin, book.author);
            cout << "Enter new ISBN: ";
            getline(cin, book.isbn);
            cout << "Enter new price: ";
            cin >> book.price;
            cin.ignore(); 

            books.push_back(book.to_string());
        } else {
            books.push_back(line); 
        }
    }
    file.close();

    ofstream outFile("books.txt");
    for (const auto& b : books) {
        outFile << b << endl;
    }
    outFile.close();

    if (found) {
        cout << "Book modified successfully." << endl;
    } else {
        cout << "Book not found." << endl;
    }
}

void deleteBook() {
    string titleToDelete;
    cout << "Enter the title of the book to delete: ";
    getline(cin, titleToDelete);

    ifstream file("books.txt");
    vector<string> books;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(titleToDelete) != string::npos) {
            found = true;
            cout << "Book deleted successfully." << endl;
            continue; 
        }
        books.push_back(line); 
    }
    file.close();

    ofstream outFile("books.txt");
    for (const auto& b : books) {
        outFile << b << endl;
    }
    outFile.close();

    if (!found) {
        cout << "Book not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Bookshop Management System ---\n";
        cout << "1. Add Book Records\n";
        cout << "2. Show Book Records\n";
        cout << "3. Check Availability\n";
        cout << "4. Modify Book Records\n";
        cout << "5. Delete Book Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                showBooks();
                break;
            case 3:
                checkAvailability();
                break;
            case 4:
                modifyBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	int bank[100];//creat Account type bank array of 100
// 	int accounts=0;
//	int acc_no,flag;
//	double amount;
//	int ch;
//	string n,g;
//	double amt;
//
//private:
//    string name,gender;
//    double amount;
//    int acc_no;
//   
//    static int account_number_generator;
//public:
//    void create_account(string n,string g,double amt)
//    {
//        acc_no=++account_number_generator;
//        name=n;
//        gender=g;
//        amount=amt;
//        cout<<"\n"<<name<<" your account created with number:"<<acc_no;
//    }
//    void deposit(double amt)
//    {
//        if(amt<0)
//            cout<<"\n amount can not be -ve:"<<amt;
//        else
//        {
//            amount=amount+amt;
//            check_balance();
//        }
//    }
//    void withdarw(double amt)
//    {
//        if(amount-amt<5000)
//            cout<<"\ninsufficient balance";
//        else
//        {
//            amount=amount-amt;
//            check_balance();
//        }
//    }
//    void check_balance()
//    {
//        cout<<"\nHi "<<name<<",Your account number:"<<acc_no<<" balance:"<<amount;
//    }
//    int get_account_no()
//    {
//        return acc_no;
//    }
//
//int Account::account_number_generator=19110;
//
//
// Account bank[100];
// int accounts=0;
// int acc_no,flag;
// double amount;
// Account a;
// int ch;
// string n,g;
//double amt;
//do
//{
//    cout<<"\n---------------------------";
//    cout<<"\n---------NDVS BANK---------";
//    cout<<"\n---------------------------";
//    cout<<"\n1. Create Account";
//    cout<<"\n2. Deposite to Account";
//    cout<<"\n3. Withdraw from Account";
//    cout<<"\n4. Check Balance";
//    cout<<"\n0. Exit";
//    cout<<"\n---------------------------";
//    cout<<"\n:";
//    cin>>ch;
//    switch(ch)
//    {
//        case 1:
//           
//            cout<<"\nEnter name:";
//            cin>>n;
//            cout<<"\nEnter gender:";
//            cin>>g;
//            while(1)
//            {
//                cout<<"\nEnter amount>=5000 to open account:";
//                cin>>amt;
//                if(amt>=5000)
//                {
//               
//                    a.create_account(n,g,amt);
//                    break;
//                }
//                cout<<"\nMinimum Amount to open account is 5000";    
//            }
//            bank[accounts++]=a;
//           
//            break;
//            case 2:
//                cout<<"\nEnter Account number:";
//                cin>>acc_no;
//                flag=0;
//                for(int i=0;i<accounts;i++)
//                {
//                    if(bank[i].get_account_no()==acc_no)
//                    {
//                        cout<<"\nAccount found:";
//                        bank[i].check_balance();
//                        cout<<"\nEnter amount to deposit:";
//                        cin>>amount;
//                        bank[i].deposit(amount);
//                        flag=1;
//                        break;
//                    }
//                }
//                if(flag==0)
//                    cout<<"\nAccount "<<acc_no<<" not found";
//                break;
//               
//            case 3:
//                cout<<"\nEnter Account number:";
//                cin>>acc_no;
//                flag=0;
//                for(int i=0;i<accounts;i++)
//                {
//                    if(bank[i].get_account_no()==acc_no)
//                    {
//                        cout<<"\nAccount found:";
//                        bank[i].check_balance();
//                        cout<<"\nEnter amount to withdraw:";
//                        cin>>amount;
//                        bank[i].withdarw(amount);
//                        bank[i].check_balance();
//                        flag=1;
//                        break;
//                    }
//                }
//                if(flag==0)
//                    cout<<"\nAccount "<<acc_no<<" not found";
//                break;
//               
//            case 4:
//                cout<<"\nEnter Account number:";
//                cin>>acc_no;
//                flag=0;
//                for(int i=0;i<accounts;i++)
//                {
//                    if(bank[i].get_account_no()==acc_no)
//                    {
//                        cout<<"\nAccount found:";
//                        bank[i].check_balance();
//                        flag=1;
//                        break;
//                    }
//                }
//              
//            case 0:
//                    cout<<"Thanks for banking with us.....";
//                    break;
//            default:
//                    cout<<"Wrong option selected";
//                    break;
//                }
//   
// } while(ch!=0);
// return 0;
//}
