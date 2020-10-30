#include <iostream>
#include <fstream>

using namespace std;

class Ticket{
    public:
        char name[100];
        int code;
};

void menu(){
    char movie[100];
    cout<<"\t\t\tMovie Ticket Booking System"<<endl<<endl;
    cout<<"\t\t\t\tNow Showing"<<endl<<endl;
    ifstream movielist("movielist.txt");
    while(!movielist.eof()){
        movielist.getline(movie, 100);
        cout<<"\t\t\t\t"<<movie<<endl;
    }
    movielist.close();
}

int main(){
    system("clear");
    menu();
    int time;
    Ticket t;
    return 0;
}
