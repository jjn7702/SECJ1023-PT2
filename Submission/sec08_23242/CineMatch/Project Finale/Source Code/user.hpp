#ifndef USER_H
#define USER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Movie.hpp"
#include "fMovie.hpp"
#include "NC17Movie.hpp"
using namespace std;

class User{
    string username;
    string password;
    vector<Movie> watchlist;
    int watchlistcnt=0;
    int age;
    fMovie *favouriteMovies;
    public:
    //static int userCount = 0;
    
    User(){
        username="";
        password="";
        favouriteMovies=NULL;
        
    }

    /*~User(){
        delete favouriteMovies;
    }*/

    string getName(){
        return username;
    }
    int getAge(){
        return age;
    }
    
    void PointfMovies(fMovie *fm){
        favouriteMovies=fm;
    }

    void setUsername(string uname) {
        username = uname;
    }

    void setPassword(string pwd) {
        password = pwd;
    }

    void setAge(int userAge) {
        age = userAge;
    }
   
    int getWlistCnt(){
        return watchlistcnt;
    }

    int getfMovieCnt(){
        return favouriteMovies->getMoviesCnt();
    }

   void createAccount(vector <User> users,int count) {
        string uname, pwd;
        int age;
        bool repeatname=0;
        do{
        cout << "Enter a username: ";
        cin >> uname;
        repeatname=0;
        for(int i=0;i<count;i++){
            if(uname==users[i].getName()){
            repeatname=1;
            cout<<"Repeated user's name!Please enter another ID.\n";}
        }}while(repeatname);

        cout << "Enter a password: ";
        cin >> pwd;
        cout << "Enter your age: ";
        cin >> age;

        setUsername(uname);
        setPassword(pwd);
        setAge(age);

        ofstream outFile("users.txt", ios::app);
        if (outFile.is_open()) {
            outFile << uname << "\n" << pwd << " " << age << "\n";
            outFile.close();
            cout << "Account created successfully!" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    friend int readID(vector<User>& users,int &usersCount) {

        string str;
        string pass;
        string choice;
        int passwordtry=0,idtry=0;
        bool correctid=0;
    
        do{
        cin.ignore();
        passwordtry=0;
        idtry=0;
        correctid=0;
        do{
        cout << "Enter ID:";
        getline(cin, str);
        idtry++;
        for (int i = 0; i < users.size(); i++){
            if(str == users[i].username)
            correctid=1;
        }
        if(!correctid&&idtry<5) cout<<"No ID exist,please try again"<<endl;

        }while(!correctid&&idtry<5);

        for (int i = 0; i < users.size(); i++) {
            if (str == users[i].username) {
                while(passwordtry<5){
                cout << "Enter password: ";
                getline(cin, pass);
                if (pass == users[i].password) {
                    return i;
                } else {
                    cout << "False password, Please enter again...\n";
                    passwordtry++;
                }
            }
            }
        }
        if(idtry==5){
        cout<<"No account exist,If you want to create new account press Y:";
        cin>>choice;
        if(choice=="y"||choice=="Y"){
        User newUser;
        newUser.createAccount(users,usersCount);
        users.push_back(newUser);
        return usersCount++;}}

        if(passwordtry==5){
            cout<<"\nEntered 5 times password,terminated..\n";
            return -1;
        }
        }while(true);
        return -1;
    }

    /*friend int readID(vector<User>& users,int &usersCount) {

        string str;
        string pass;
        int passwordtry=0,idtry=0;
        bool correctid=0;
        cin.ignore();
        do{
        cout << "Enter ID:";
        getline(cin, str);
        idtry++;
        for (int i = 0; i < users.size(); i++){
            if(str == users[i].username)
            correctid=1;
        }
        if(!correctid&&idtry<5) cout<<"No ID exist,please try again"<<endl;

        }while(!correctid&&idtry<5);

        for (int i = 0; i < users.size(); i++) {
            if (str == users[i].username) {
                while(passwordtry<5){
                cout << "Enter password: ";
                getline(cin, pass);
                if (pass == users[i].password) {
                    return i;
                } else {
                    cout << "False password, Please enter again...\n";
                    passwordtry++;
                }
            }
            }
        }
        if(idtry==5){
        cout<<"No account exist,please create new account\n";
        User newUser;
        newUser.createAccount(users,usersCount);
        users.push_back(newUser);
        return usersCount++;}

        if(passwordtry==5){
            cout<<"\nEntered 5 times password,terminated..\n";
            return -1;
        }
        return -1;
    }*/

    void readWatchlist() {
        ifstream watchfin(username + "_watchlist.txt");

        /*try {
    if (!watchfin.is_open()) {
        throw runtime_error("Failed to open the file.");
    }*/
        
        while (!watchfin.eof()) {
        string name;
        int year;
        double rating;
        string classification;
        int ratingNum;
        string genre;
        getline(watchfin, name);
        if (name=="") 
        break;
        watchfin >> year >> ratingNum >> rating >> classification >> genre;
        watchfin.ignore(); // Ignore the newline character after genre
        Movie newMovie;
        newMovie.setName(name);
        newMovie.setYear(year);
        newMovie.setRating(rating);
        newMovie.setClassification(classification);
        newMovie.setRatingNum(ratingNum);
        newMovie.setGenre(genre);
        watchlist.push_back(newMovie);
        watchlistcnt++;
        
        }
        /*}
    catch (const exception& e) {
    cerr << "Exception: " << e.what() << endl;
    if (watchfin.is_open()) {
        watchfin.close();
    }
    system("pause");
    return ; // Return with an error code
}*/
        watchfin.close();
        
    }
    
    void readfavouritelist(){
        ifstream favfin("users_recommended_movies.txt");
        while (!favfin.eof()) {
        string name;
        int year;
        double rating;
        string classification;
        int ratingNum;
        string genre;
        getline(favfin, name);
        if (name=="") 
        break;
        favfin >> year >> ratingNum >> rating >> classification >> genre;
        favfin.ignore(); // Ignore the newline character after genre
        Movie newMovie;
        newMovie.setName(name);
        newMovie.setYear(year);
        newMovie.setRating(rating);
        newMovie.setClassification(classification);
        newMovie.setRatingNum(ratingNum);
        newMovie.setGenre(genre);
        setfavouriteMovie(newMovie);
        
        //cout<<name<<" "<<year <<ratingNum << rating << classification << genre<<endl;
        //cout<<watchlistcnt<<endl;
        }
        favfin.close();
    }

    void addToWatchlist(Movie &movie) {
        //void readWatchlist();
        for (int i = 0; i < watchlistcnt; i++) {
            if (movie.getName() == watchlist[i].getName()) {
                cout << "Movie already exists in watchlist!" << endl<<endl;
                return;
            }
        }
        string filename = username + "_watchlist.txt";
        ofstream fout(filename, ios::app);
        if (fout.is_open()) {
            fout << movie.getName() << endl
                 << movie.year << " " << movie.ratingNum << " " << movie.rating << " " << movie.classification << " " << movie.genre<<endl;
            fout.close();
            watchlist.push_back(movie);
            watchlistcnt++;
            //cout<<watchlistcnt<<endl;
            cout << "Added successfully!" << endl<<endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void removeFromWatchlist(int num) {
       watchlist.erase(watchlist.begin() + num-1); 
       cout<<"Delete successfully!"<<endl;
        watchlistcnt--;
       ofstream fout(username+"_watchlist.txt");
        for(int i=0;i<watchlistcnt;i++){
            fout<< watchlist[i].getName() << endl
                 << watchlist[i].getYear() << " " << watchlist[i].getRatingNum() << " " << watchlist[i].getRating() << " " << watchlist[i].getClassification() << " " << watchlist[i].getGenre()<<endl;
    }
    fout.close();
    }

    void removeFromfMovielist(int num){
        favouriteMovies->deletefavouritemovielist(num,username);
    }

    void displayfmovielist(){
        favouriteMovies->moviedisplay();
    }

    bool setfavouriteMovie(Movie &movie){
        return favouriteMovies->setMovies(movie);
    }

    void printfavouriteMovieintxt(){
        favouriteMovies->txtfavouriteMovies(username);
    }

    friend void viewWatchlist(vector<User>& users, int userIndex);
};

#endif