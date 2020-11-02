#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class Booking{
    private:
        
        char confirm[7], mobile[10], movie[100], time[4];
        string email, upi, name;
        void customerInfo(){
            //gather customer info:
            cout<<"Please enter your name: ";
            getline(cin, name, '\n');
            //failsafe:
            mobile[10] = '\0';
            cout<<endl<<"Please enter your mobile number: ";
            cin>>mobile;
            if(mobile[10] != '\0'){
                cout<<"Please enter a 10 digit mobile number: ";
                cin>>mobile;
            }
            cout<<endl<<"Please enter your Email ID: ";
            cin>>email;
            if(email.find("@") == 0 || email.find("@") > 100) {
                cout<<endl<<"Please enter a valid Email ID: ";
                cin>>email;
            }
            if (strcmp(confirm, "no") == 0)
                payment();
        }

        int payment(){
            //display customer details:
            cout<<"Customer Details: "<<endl;
            cout<<endl<<"Name: "<<name<<endl;
            cout<<"Mobile Number: "<<mobile<<endl;
            cout<<"Email ID: "<<email<<endl;
            cout<<"Please type in 'correct' to confirm you details are correct else type 'no': ";
            //exception here: 
            cin>>confirm;
            //confirm details:
            HERE:
            if(strcmp(confirm,"no") == 0){
                cout<<"Please reenter your information: "<<endl;
                cin.ignore();
                customerInfo();
            }
            else if(strcmp(confirm, "correct") == 0){
                cout<<"Please enter you UPI ID: ";
                cin>>upi;
                if(upi.find("@") == 0 || upi.find("@") > 100)
                    return 0;
           }
           else{
               cout<<"Incorrect Input"<<endl;
               cin>>confirm;
               goto HERE;
           }
           return 1;
        }
    public:
        //display menu, starting point: 
        void menu(){
            cout<<"\t\t\tMovie Ticket Booking System"<<endl<<endl;
            cout<<"\t\t\t\tNow Showing"<<endl<<endl;
            ifstream movielist("./TextFiles/movielist.txt");
            while(!movielist.eof()){
                movielist.getline(movie, 100);
                cout<<"\t\t\t\t"<<movie<<endl;
            }
            movielist.close();
        }

        void selection(){
            //selection
            cout<<"Please type the movie title you want to watch: ";
            cin.getline(movie, 100);
            //choose timings
            ifstream timings("./TextFiles/timings.txt");
            while(!timings.eof()){
                timings.getline(time, 10);
                cout<<"\t\t\t\t"<<time<<endl;
            }
            timings.close();
            cout<<endl<<"Please type in your preferred timings: ";
            cin.getline(time, 6);
            //failsafe:
            if(strstr(time, ":") != ":"){
                cout<<endl<<"Please type in the correct format with colon(:) ";
                cin>>time;
            }
            //after selecting movie of choice
            cin.ignore();
            customerInfo();
            if(payment() == 1){
                cout<<"Payment Done"<<endl<<endl;
                //print full details
                cout<<"\t\t\t\tBooking Confirmed for "<<name<<endl;
                cout<<"\t\t\t\tMobile Number: "<<mobile<<endl;
                cout<<"\t\t\t\tEmail ID: "<<email<<endl;
                cout<<"\t\t\t\tShow: "<<movie<<" at "<<time<<endl;
            }
            else{
                cout<<"Payment Failed, please type in a valid UPI ID: ";
                //redirect to payment()
                payment();
            }
        }
}book;

int main(){
    system("clear");
    book.menu();
    book.selection();
    return 0;
}