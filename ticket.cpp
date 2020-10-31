#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class Booking{
    private:
    
        char name[100], email[100], upi[100], confirm[100] = "no";
        int mobile = 0;

        void customerInfo(){
            //gather customer info:
            cout<<"Please enter your name: ";
            cin.getline(name, 100);
            cout<<endl<<"Please enter your mobile number: ";
            cin>>mobile;
            cout<<endl<<"Please enter your email number: ";
            cin.getline(email, 100);
        }

        int payment(){
            //display customer details:
            cout<<"Customer Details: "<<endl;
            cout<<endl<<"Name: "<<name<<endl;
            cout<<"Mobile Number: "<<mobile<<endl;
            cout<<"Email ID: "<<email<<endl;
            cout<<"Please type in 'correct' to confirm you details are correct else type 'no': ";
            cin>>confirm;
            //confirm details:
            if(strcmp(confirm,"no") == 0){
                cout<<"Please reenter your information again: "<<endl;
                customerInfo();
            }
            else if(strcmp(confirm, "correct") == 0){
                cout<<"Please enter you UPI ID: ";
                cin>>upi;
                if(strstr(email, "@") < 0)
                    return 0;
                else
                    return 1;
            }
        }

    public:
        //display menu, starting point: 
        void menu(){
            char movie[100];
            cout<<"\t\t\tMovie Ticket Booking System"<<endl<<endl;
            cout<<"\t\t\t\tNow Showing"<<endl<<endl;
            ifstream movielist("./TextFiles/movielist.txt");
            while(!movielist.eof()){
                movielist.getline(movie, 100);
                cout<<"\t\t\t\t"<<movie<<endl;
            }
            movielist.close();
        }
}book;

int main(){
    system("clear");
    book.menu();
    return 0;
}