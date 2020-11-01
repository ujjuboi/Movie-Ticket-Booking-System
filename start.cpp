#include <iostream>
#include <fstream>

using namespace std;

class Admin{
    private:
    int halls = 3, premiers = 5, timeslots = 9;

    public:
    int assigner(){
        struct Movie mov1;
        struct Movie mov2;
        struct Movie mov3;
        struct Movie mov4;
        struct Movie mov5;
        ifstream movielist("movielist.txt");
        while (!movielist.eof())
        {
            movielist.getline(mov1.name, 100);
            movielist.getline(mov2.name, 100);
            movielist.getline(mov3.name, 100);
            movielist.getline(mov4.name, 100);
            movielist.getline(mov5.name, 100);
        }

    }
};

struct Movie
{
    char name[100];
    char code[9];
    int ratings = 0;
};

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

int main(){
    system("clear");
    menu();
    int time;
    return 0;
}
