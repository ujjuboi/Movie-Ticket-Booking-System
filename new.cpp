#include<iostream>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

short bookingid;
char seattype;

class Theater{
    protected:
        char hallid;
        int movieid;
        short time=0;    
        char movie[100];
        char seats[100];
        short seatno;
        ifstream movielist;
        const char *timing[9] = {"8:00", "10:30", "12:00", "14:30", "17:00", "18:30", "19:30", "20:00", "00:00"};
    private:
        void Seat_Arrangement(){
            ofstream seats;
            seats.open("./TextFiles/h1.txt");
            seats<<"\tScreen this side"<<endl;
            for(int i=0; i<10;i++){
                for(int j=0; j<10; j++){
                    seats<<i<<j<<" ";
                    if(j == 9)
                        seats<<endl;
                    }
            }
            seats.close();
        }
        char Assign_Hallid(int id){
            switch (id)
            {
            case 1:
                return 'A';
                break;
            case 2:
                return 'B';
                break;
            case 3:
                return 'C';
                break;
            case 4:
                return 'A';
                break;
            case 5:
                return 'B';
                break;
            case 6:
                return 'C';
                break;
            default:
                return '\0';
                break;
            }
        }    

    public:
        int success(){
            hallid = Assign_Hallid(movieid);
            if(hallid == '\0')
                return 1;
            else
                return 0;
        }
        
};

class Movie: protected Theater{
    private:
        void SelectMovie(){
            cout<<"Please enter the Movie ID: ";
            cin>>movieid;
            cin.ignore();
            while(success() == 1){
                cout<<"Please enter a valid Movie ID: ";
                cin>>movieid;
                cin.ignore();
                success();
            }
            Timing();
        }

        void Timing(){
            cout<<endl<<"Timings"<<endl<<endl;
            if(movieid<=3){
                for(int i=0; i<9; i++){
                    if(i%2 == 0)
                        cout<<i<<" "<<timing[i]<<endl;
                }
            }
            else{
                for(int i=0; i<9; i++){
                    if(i%2 != 0)   
                        cout<<i<<" "<<timing[i]<<endl;
                }
            }    
            cout<<endl<<"Please enter your show timings: ";
            cin>>time;
            cin.ignore();
            Seatmap();
        } 

        void Seatmap(){
            switch(hallid){
                case 'A':
                    {
                    ifstream h1("./TextFiles/h1.txt");
                    cout<<endl;
                    while(!h1.eof()){
                        h1.getline(seats, 100);
                        cout<<" "<<seats<<endl;
                    }
                    h1.close();
                    ofstream hall1("./TextFiles/h1.txt", ios::app);
                    cout<<endl<<"Enter your seat number: ";
                    cin>>seatno;
                    cin.ignore();
                    hall1<<" "<<seatno<<" ";
                    hall1.close();
                    }
                    break;

                case 'B':
                    {
                    ifstream h2("./TextFiles/h2.txt");
                    while(!h2.eof()){
                        h2.getline(seats, 100);
                        cout<<" "<<seats<<endl;
                    }
                    h2.close();
                    ofstream hall2("./TextFiles/h2.txt", ios::app);
                    cout<<endl<<"Enter your seat number: ";
                    cin>>seatno;
                    cin.ignore();
                    hall2<<" "<<seatno<<" ";
                    hall2.close();
                    }
                    break;

                case 'C':
                    {
                    ifstream h3("./TextFiles/h3.txt");
                    while(!h3.eof()){
                        h3.getline(seats, 100);
                        cout<<" "<<seats<<endl;
                    }
                    h3.close();
                    ofstream hall3("./TextFiles/h3.txt", ios::app);
                    cout<<endl<<"Enter your seat number: ";
                    cin>>seatno;
                    cin.ignore();
                    hall3<<" "<<seatno<<" ";
                    hall3.close();
                    }
                    break;

                default:
                    break;
            }
            if(0<=seatno<20)
                seattype = 'N';
            else if(20<=seatno<60)
                seattype = 'P';
            else if(60<=seatno<80)
                seattype = 'E';
            else if(80<=seatno<100)
                seattype = 'V';
        }
    
    public:
        void DisplayMenu(){
            system("clear");
            cout<<"Welcome User"<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"Now Showing"<<endl<<endl;
            movielist.open("./TextFiles/movielist.txt");
            while(!movielist.eof()){
                movieid++;                
                movielist.getline(movie,100);
                cout<<movieid<<" "<<movie<<endl<<endl;
            }
            movielist.close();
            SelectMovie();
        }
        void DisplaySlip(){
            string mname;
            switch (movieid)
            {
            case 1:
                mname = "Tenet";
                break;

            case 2: 
                mname = "The Intern";
                break;
            
            case 3:
                mname = "3 Idiots";
                break;
            
            case 4:
                mname = "Carvaan";
                break;

            case 5:
                mname = "Bloodshot";
                break;

            case 6:
                mname = "Godfather";
                break;
            
            default:
                break;
            }
            cout<<"\nShow: "<<movie<<" "<<timing[time];
            cout<<"\nSeat: "<<hallid<<" "<<seatno;
            cout<<"\nBooking ID: "<<bookingid;
        }
}movobj;

class User{
    private:
        short userid;
        string name;
        string mobno;
        string emailid;
        char gender;

        void updatefile(){
            ofstream usertxt;
            usertxt.open("./TextFiles/user.txt", ios::app);
            usertxt<<userid<<" "<<name;
            usertxt.close();
            displayprompt();
        }

    protected:
        void userprompt(){
            userid = rand();
            cout<<endl<<"Please enter your Name: ";
            getline(cin, name, '\n');
            cout<<"\nPlease enter your Mobile Number: ";
            cin>>mobno;
            cout<<"\nPlease enter your Email ID: ";
            cin>>emailid;
            cout<<"\nPlease select you Gender (M, F, O): ";
            cin>>gender;
            failsafe();
        }

        void failsafe(){
            while(mobno.size() != 10)
            {
                cout<<"\nXX Please a 10 digit Mobile Number: ";
                cin>>mobno;
            }
            while(emailid.find('@') == string::npos || emailid.find('.') == string::npos){
                cout<<"\nXX Please enter a valid Emaild ID: ";
                cin>>emailid;
            }
            while(gender != 'M' && gender != 'F' && gender != 'O'){
                cout<<"\nXX Please select a Gender from the given options: ";
                cin>>gender;
            }
            updatefile();
        }

        public:
            void displayprompt(){
                if(gender == '\0')
                    userprompt();
                else{
                    cout<<"\nUserID: "<<userid;
                    cout<<"\nName: "<<name;
                    cout<<"\nMobile Number: "<<mobno;
                    cout<<"\nEmail ID: "<<emailid;
                    cout<<"\nGender: "<<gender;
                }
            }
}user;

class Payment {
    private:
        short amount;
        string upi;
    public:
        bool paymentGateway(){
            switch (seattype)
            {
            case 'N':
                amount = 300;
                cout<<"\nTotal Amount $"<<amount<<endl;
                break;
            case 'P':
                amount = 500;
                cout<<"\nTotal Amount $"<<amount<<endl;
                break;
            case 'E':
                amount = 700;
                cout<<"\nTotal Amount $"<<amount<<endl;
                break;
            case 'V':
                amount = 1000;
                cout<<"Total Amount $"<<amount<<endl;
                break;
            default:
                break;
            }
            bookingid = rand();
            cout<<"\nPlease enter your UPI ID: ";
            cin>>upi;
            if(upi.find('@') == string::npos || upi.find('.') == string::npos){
                cout<<"\nXX Please enter a valid UPI ID: ";
                cin>>upi;
                return false;
            }
            else
                return true;
        }
}booking;

int main(){
    movobj.DisplayMenu();
    user.displayprompt();    
    if(booking.paymentGateway()){
        user.displayprompt();
        movobj.DisplaySlip();
    }
    return 0;
}