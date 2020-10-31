#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class Booking{
    private:
    
        char name[100], email[100], upi[100], confirm[7], mobile[10];

        void customerInfo(){
            //gather customer info:
            cout<<"Please enter your name: ";
            cin.getline(name, 100);
            cout<<endl<<"Please enter your mobile number: ";
            cin>>mobile;
            cout<<endl<<"Please enter your Email ID: ";
            cin>>email;
            if(strstr(email, "@") <= 0 ) {
                cout<<endl<<"Please enter a valid Email ID: ";
                cin>>email;
            }
        }

        int payment(){
            //display customer details:
            cout<<"Customer Details: "<<endl;
            cout<<endl<<"Name: "<<name<<endl;
            cout<<"Mobile Number: "<<mobile<<endl;
            cout<<"Email ID: "<<email<<endl;
            cout<<"Please type in 'correct' to confirm you details are correct else type 'no': ";
            //Exception in turn of spelling:
            try{
                cin>>confirm;
                //error here*
                throw "Incorrect input, please check the spelling again.";
            }
            catch(const char* error){
                cout<<error<<endl;
                cin>>confirm;
            }
            //confirm details:
            if(strcmp(confirm,"no") == 0){
                cout<<"Please reenter your information again: "<<endl;
                customerInfo();
            }
            else if(strcmp(confirm, "correct") == 0){
                cout<<"Please enter you UPI ID: ";
                cin>>upi;
                if(strstr(upi, "@") > 0)
                    return 1;
           }
           return 0;
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
        //after selecting movie of choice:
        void selection(){
            customerInfo();
            if(payment() == 1){
                cout<<"Payment Done";
                //print full details
            }
            else{
                cout<<"Payment Failed, please retry after some time";
                //redirect to main*
            }
        }
}book;

int main(){
    system("clear");
    book.menu();
    book.selection();
    return 0;
}