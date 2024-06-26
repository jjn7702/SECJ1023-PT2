#include<iostream>
#include"fMovie.hpp"
#include "Movie.hpp"
#include "GMovie.hpp"
#include "NC17Movie.hpp"
#include "PG13Movie.hpp"
#include "PGMovie.hpp"
#include "RMovie.hpp"
#include "user.hpp"
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

int userinput(vector<User>& users, int& userCount) {
    int x = 0;
    int id;
    cout << "Login or create account?\n";
    cout << "Press 1 to login\nPress 2 to create account\n";
    while (x != 1 && x != 2) {
        cout << "Enter: ";
        cin >> x;
        switch (x){
                case 1:id = readID(users,userCount);
                break;
        case 2: {
                    User newUser;
                    newUser.createAccount(users,userCount);
                    users.push_back(newUser);  // Add the new user to the vector
                    id = userCount++;
                    break;  // Increment userCount after adding the new user
                }
        default:{
            cout << "Invalid input..\n";
        }
    }
    }
    return id;
};

int searchMovie(vector<Movie>& movies,int movieCount){
    string str;
    //cin.ignore();
    cout<<"Enter movie name: ";
    getline(cin,str);
    for(int i=0;i<movieCount;i++){
        string name=movies[i].getName();
        for(int j=0;j<name.length();j++)
        name[j]=tolower(name[j]);

        for(int q=0;q<str.length();q++)
        str[q]=tolower(str[q]);
        if(str==name){
            return i;
        }
    }
    return -1;
}

void searchclassification(vector<User> &users,int userIndex,vector<GMovie> gmovies,vector<NC17Movie> nc17movies,vector<PG13Movie> pg13movies,vector<PGMovie> pgmovies,vector<RMovie> rmovies){
    int choice=0;
    int filmNum;
    bool legal;
    string descend;
    vector<GMovie> tempgmovies=gmovies;
    vector<PGMovie> temppgmovies=pgmovies;
    vector<PG13Movie> temppg13movies=pg13movies;
    vector<NC17Movie> tempnc17movies=nc17movies;
    vector<RMovie> temprmovies=rmovies;

    do{
    cout<<"Enter 1 for General rated film\n";
    cout<<"Enter 2 for PG rated film\n";
    cout<<"Enter 3 for PG-13 rated film\n";
    cout<<"Enter 4 for NC-17 rated film\n";
    cout<<"Enter 5 for R rated film\nEnter: ";
    cin>>choice;
     cout<<"Enter Y or y if you want to see movie list in descending order:";
    cin>>descend;
    switch(choice){
        case 1:{
            if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < tempgmovies.size() - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < tempgmovies.size() ; j++) {  
      if (tempgmovies[j].getRating() > tempgmovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    GMovie temp = tempgmovies[i];  
    tempgmovies[i] = tempgmovies[minIndex];  
    tempgmovies[minIndex] = temp;  
  }  
            }

            legal=tempgmovies[0].displayClassification(users[userIndex].getAge());
        if(legal){
        for(int i=0;i<tempgmovies[0].getCnt();i++){
            cout<<i+1<<".";
            tempgmovies[i].display();
        }
        }
        else
            return;
        break;}

        case 2:{
            if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < temppgmovies.size() - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < temppgmovies.size() ; j++) {  
      if (temppgmovies[j].getRating() > temppgmovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    PGMovie temp = temppgmovies[i];  
    temppgmovies[i] = temppgmovies[minIndex];  
    temppgmovies[minIndex] = temp;  
  }  
            }

        legal=temppgmovies[0].displayClassification(users[userIndex].getAge());
        if(legal){
        for(int i=0;i<temppgmovies[0].getCnt();i++){
            cout<<i+1<<".";
            temppgmovies[i].display();
        }
        }
        else
            return;
        break;}

        case 3:{
            if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < temppg13movies.size() - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < temppg13movies.size() ; j++) {  
      if (temppg13movies[j].getRating() > temppg13movies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    PG13Movie temp = temppg13movies[i];  
    temppg13movies[i] = temppg13movies[minIndex];  
    temppg13movies[minIndex] = temp;  
  }  
            }

            legal=temppg13movies[0].displayClassification(users[userIndex].getAge());
        if(legal){
        for(int i=0;i<temppg13movies[0].getCnt();i++){
            cout<<i+1<<".";
            temppg13movies[i].display();
        }
        }
        else
            return;
        break;}

        case 4:{
            if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < tempnc17movies.size() - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < tempnc17movies.size() ; j++) {  
      if (tempnc17movies[j].getRating() > tempnc17movies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    NC17Movie temp = tempnc17movies[i];  
    tempnc17movies[i] = tempnc17movies[minIndex];  
    tempnc17movies[minIndex] = temp;  
  }  
            }

            legal=tempnc17movies[0].displayClassification(users[userIndex].getAge());
        if(legal){
        for(int i=0;i<tempnc17movies[0].getCnt();i++){
            cout<<i+1<<".";
            tempnc17movies[i].display();
        }
        }
        else
            return;
        break;}
        case 5:{
            if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < temprmovies.size() - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < temprmovies.size() ; j++) {  
      if (temprmovies[j].getRating() > temprmovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    RMovie temp = temprmovies[i];  
    temprmovies[i] = temprmovies[minIndex];  
    temprmovies[minIndex] = temp;  
  }  
            }

            legal=temprmovies[0].displayClassification(users[userIndex].getAge());
        if(legal){
        for(int i=0;i<temprmovies[0].getCnt();i++){
            cout<<i+1<<".";
            temprmovies[i].display();
        }
        }
        else
            return;
        break;}
        default:
        cout<<"Invalid input,Enter again..\n";
    }}while(choice<1||choice>5);

    do{
    switch(choice){

        case 1:{
        cout<<"Enter the number of film to add to watchlist(Enter -1 to exit):";
        cin>>filmNum;
        if(filmNum>tempgmovies[0].getCnt()||filmNum<1){
        cout<<"Exit..."<<endl;
        return;}
        else
        users[userIndex].addToWatchlist(tempgmovies[filmNum-1]);
        break;}

        case 2:{
        cout<<"Enter the number of film to add to watchlist(Enter -1 to exit):";
        cin>>filmNum;
        if(filmNum>temppgmovies[0].getCnt()||filmNum<1){
        cout<<"Exit..."<<endl;
        return;}
        else
        users[userIndex].addToWatchlist(temppgmovies[filmNum-1]);
        break;}

        case 3:{
        cout<<"Enter the number of film to add to watchlist(Enter -1 to exit):";
        cin>>filmNum;
        if(filmNum>temppg13movies[0].getCnt()||filmNum<1){
        cout<<"Exit..."<<endl;
        return;}
        else
        users[userIndex].addToWatchlist(temppg13movies[filmNum-1]);
        break;}

        case 4:{
        cout<<"Enter the number of film to add to watchlist(Enter -1 to exit):";
        cin>>filmNum;
        if(filmNum>tempnc17movies[0].getCnt()||filmNum<1){
        cout<<"Exit..."<<endl;
        return;}
        else
        users[userIndex].addToWatchlist(tempnc17movies[filmNum-1]);
        break;}

        case 5:{
        cout<<"Enter the number of film to add to watchlist(Enter -1 to exit):";
        cin>>filmNum;
        if(filmNum>temprmovies[0].getCnt()||filmNum<1){
        cout<<"Exit..."<<endl;
        return;}
        else
        users[userIndex].addToWatchlist(temprmovies[filmNum-1]);
        break;}

        default:
        cout<<"Invalid input,Enter again..\n";
    }
    }while(true);

    cout<<users[userIndex].getWlistCnt()<<endl;
}

void searchgenre(vector<Movie>& movies, vector<User>& users, int userIndex, int movieCount) {
    cout << "Search by Genre\n";
    cout << "Enter 1 for Sci-fi\n";
    cout << "Enter 2 for Horror\n";
    cout << "Enter 3 for Animation\n";
    cout << "Enter 4 for Fantasy\n";
    cout << "Enter 5 for Adventure\n";
    cout << "Enter 6 for Action\n";
    cout << "Enter 7 for Comedy\n";
    cout << "Enter 8 for Crime\n";
    cout << "Enter 9 for Romance\n";
    cout << "Enter 10 for Drama\n";
    cout << "Enter 11 for War\n";
    cout << "Enter 12 for Thriller\n";
    cout << "Enter 13 for Musical\n";
    cout << "Enter 14 for Western\n";
    cout << "Enter 15 for Biography\n";
    cout << "Enter : ";
    int choice;
    string descend;
    int ageneeded;
    cin >> choice;
    string genres[] = {
        "sci-fi", "horror", "animation", "fantasy", "adventure",
        "action", "comedy", "crime", "romance", "drama",
        "war", "thriller", "musical", "western", "biography"
    };
    string genre;
    vector<Movie> genreMovies;
    int genreCnt = 0;

    if (choice >= 1 && choice <= 15) {
        genre = genres[choice - 1];
        }
    else{ 
            cout << "Invalid input...Exit" << endl;
            return;
    }

cout<<"Enter Y or y if you want to see movie list in rating descending order:";
    cin>>descend;

        for (int i = 0; i < movieCount; i++) {
            int userAge = users[userIndex].getAge();
            string movieClassification = movies[i].getClassification();

            if ((movieClassification == "PG-13" && userAge < 13) ||
                (movieClassification == "NC-17" && userAge < 17) ||
                (movieClassification == "R" && userAge < 17)) {
                continue;
            }

            if (genre == movies[i].getGenre()) {
                genreCnt++;
                genreMovies.push_back(movies[i]);
            }
    }

     //cout<<genreCnt<<endl;   
    if(descend=="Y"||descend=="y"){
                 for (int i = 0; i <  genreCnt - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < genreCnt ; j++) {  
      if (genreMovies[j].getRating() > genreMovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    Movie temp = genreMovies[i];  
    genreMovies[i] = genreMovies[minIndex];  
    genreMovies[minIndex] = temp;  
  }  
            }

        for(int i=0;i<genreCnt;i++){
        cout << i + 1 << ".";
        genreMovies[i].display();}
 

//users[userIndex].printfovouriteMovieintxt();

    int movieNum;
    if(genreCnt<=0){
        cout<<"No movies exist..exit"<<endl;
        return ;
    }

    do {
        cout << "Enter number of movie to add to watchlist (Enter -1 to exit): ";
        cin >> movieNum;
        if(movieNum >= 1 && movieNum <= genreCnt) {
            users[userIndex].addToWatchlist(genreMovies[movieNum-1]);
        } else if(movieNum != -1) {
            cout << "Invalid movie number. Please try again." << endl;
        }
    } while(movieNum != -1);

    cout << "Exit!" << endl;
}

void rateMovie(vector<Movie>& movies, int movieCount){
    for(int i=0;i<movieCount;i++){
        cout<<i+1<<".";
        movies[i].display();
    }
    int choice;
    do{
    cout<<"Enter number of film to rate: ";
    cin>>choice;
    }while(choice>movieCount||choice<1);
    double rate;
    do{
    cout<<"Rate 0 to 10: ";
    cin>>rate;
    }while(rate>10||rate<0);
    movies[choice-1].renewRating(rate);
    cout<<fixed<<setprecision(2);
    cout<<"Newest rating : "<<movies[choice-1].getRating()<<endl;

    ofstream update("movie.txt");
    for(int i=0;i<movieCount;i++){
        update<<fixed<<setprecision(2);
        update<<movies[i].getName()<<endl;
        update<<movies[i].getYear()<<" "<<movies[i].getRatingNum()<<" "<<movies[i].getRating()<<" "<<movies[i].getClassification()<<" "<<movies[i].getGenre()<<endl;
    }

    update.close();
}

void viewWatchlist(vector<User>& users, int userIndex){
    //cout<<users[userIndex].getWlistCnt()<<endl;
    for(int i=0;i<users[userIndex].getWlistCnt();i++){
        cout<<i+1<<".";
        (users[userIndex]).watchlist[i].display();
    }

    cout<<"If you want to delete movie from watchlist ENTER Y: ";
    char choice;
    cin>>choice;
    int movieNum;
    if(choice=='Y'||choice=='y'){
        do{
        cout<<"Enter the number of movie you want to delete: ";
        cin>>movieNum;
        }while(movieNum>users[userIndex].getWlistCnt());
        users[userIndex].removeFromWatchlist(movieNum);
    }
    else{
        cout<<"Exit!"<<endl;
    }
}

void viewmovielist(vector<Movie>& movies,int movieCount,vector<User>& users, int userIndex){
    string descend;
    vector<Movie> tempmovies;
    int tempmoviescnt=0;
    for (int i = 0; i < movieCount; i++) {
            int userAge = users[userIndex].getAge();
            string movieClassification = movies[i].getClassification();

            if ((movieClassification == "PG-13" && userAge < 13) ||
                (movieClassification == "NC-17" && userAge < 17) ||
                (movieClassification == "R" && userAge < 17)) {
                continue;
            }
            tempmoviescnt++;
            tempmovies.push_back(movies[i]);
    }

     cout<<"Enter Y or y if you want to see movie list in descending order:";
    cin>>descend;

    if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < tempmoviescnt - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < tempmoviescnt ; j++) {  
      if (tempmovies[j].getRating() > tempmovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    Movie temp = tempmovies[i];  
    tempmovies[i] = tempmovies[minIndex];  
    tempmovies[minIndex] = temp;  
  }  
            }
    
    for(int i=0;i<tempmoviescnt;i++){
        cout<<i+1<<".";
        tempmovies[i].display();
    }
    char choice;
    cout<<"Do you want to add movie into your watchlist?(Enter 'Y' or 'y'):";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
    int movieNum;
    do {
        cout << "Enter number of movie to add to watchlist (Enter -1 to exit): ";
        cin >> movieNum;
        if(movieNum >= 0 && movieNum <= tempmoviescnt) {
            users[userIndex].addToWatchlist(tempmovies[movieNum-1]);
        } else if(movieNum != -1) {
            cout << "Invalid movie number. Please try again." << endl;
        }
    } while(movieNum != -1);
    }
    cout << "Exit!" << endl<<endl;
}

void addtofavouritemovie(vector<Movie>& movies,int movieCount,vector<User>& users, int userIndex){
    string descend;
    vector<Movie> tempmovies;
    int tempmoviescnt=0;
    for (int i = 0; i < movieCount; i++) {
            int userAge = users[userIndex].getAge();
            string movieClassification = movies[i].getClassification();

            if ((movieClassification == "PG-13" && userAge < 13) ||
                (movieClassification == "NC-17" && userAge < 17) ||
                (movieClassification == "R" && userAge < 17)) {
                continue;
            }
            tempmoviescnt++;
            tempmovies.push_back(movies[i]);
    }
     cout<<"Enter Y or y if you want to see movie list in descending order:";
    cin>>descend;

    if(descend=="Y"||descend=="y"){
                 for (int i = 0; i < tempmoviescnt - 1; i++) {  
    // Find the minimum element in the unsorted portion of the array  
    int minIndex = i;  
    for (int j = i + 1; j < tempmoviescnt ; j++) {  
      if (tempmovies[j].getRating() > tempmovies[minIndex].getRating()) {  
        minIndex = j;  
      }  
    }  
    // Swap the minimum element with the current element  
    Movie temp = tempmovies[i];  
    tempmovies[i] = tempmovies[minIndex];  
    tempmovies[minIndex] = temp;  
  }  
            }
    

    for(int i=0;i<tempmoviescnt;i++){
        cout<<i+1<<".";
        tempmovies[i].display();
    }
    char choice;
    cout<<"Do you want to add movie into recommended movies list?(Enter 'Y' or 'y'):";
    cin>>choice;
    cin.ignore();
    if(choice=='Y'||choice=='y'){
    int movieNum;
    do {
        cout << "Enter number of movie to add to recommended movies list (Enter -1 to exit): ";
        cin >> movieNum;
        if(movieNum >= 0 && movieNum <= tempmoviescnt) {
            bool repeat=(users[userIndex].setfavouriteMovie(tempmovies[movieNum-1]));
            if(!repeat)users[userIndex].printfavouriteMovieintxt();
        } else if(movieNum != -1) {
            cout << "Invalid movie number. Please try again." << endl;
        }
    } while(movieNum != -1);
    
    }
    cout << "Exit!" << endl<<endl;
}

void viewallfmovielist(vector<User>& users, int userIndex){
    users[userIndex].displayfmovielist();
    char choicedelete;
    cout<<"If you want to delete movie from recommended movies list Press y or Y:";
    cin>>choicedelete;
    if(choicedelete=='Y'||choicedelete=='y'){
        int num;
        do{
            cout<<"Enter the value within number of movie in recommended movie list(enter -1 to exit):";
            cin>>num;
            if(num==-1)
            break;

            if((num>=1&&num<=users[userIndex].getfMovieCnt())){
            users[userIndex].removeFromfMovielist(num);
            break;}
            else
            cout<<"Invalid value,please enter again.\n";
        }while(true);

    }
            
        cout<<"Exit.."<<endl;
}

void userchoice(vector<User> &users,vector<Movie>& movies,int movieCount,int userIndex,vector<GMovie> gmovies,vector<NC17Movie> nc17movies,vector<PG13Movie> pg13movies,vector<PGMovie> pgmovies,vector<RMovie> rmovies){
    int choice;
    int searchedmovie;
    do{
    cout<<"\n\n\nWelcome to CineMatch\n";
    cout<<"Enter 1 to search movie by movie NAME\n";
    cout<<"Enter 2 to search movie by movie classification\n";
    cout<<"Enter 3 to search movie by genre\n";
    cout<<"Enter 4 to rate movie\n";
    cout<<"Enter 5 to view watchlist\n";
    cout<<"Enter 6 to view all movielist\n";
    cout<<"Enter 7 to add movies into users recommended movie list\n";
    cout<<"Enter 8 to view all recommended movie list\n";
    cout<<"Other input will exit\n";
    cout<<"Enter :";
    cin>>choice;
    cin.ignore();
    switch (choice){
        case 1:{
            
            searchedmovie=searchMovie(movies,movieCount);
            if(searchedmovie!=-1){
            
            int userAge = users[userIndex].getAge();
            string movieClassification = movies[searchedmovie].getClassification();

            if ((movieClassification == "PG-13" && userAge < 13) ||
                (movieClassification == "NC-17" && userAge < 17) ||
                (movieClassification == "R" && userAge < 17)) {
                cout<<"Age required for movie entered is more than your current age..Exit.."<<endl;
                break;
            }
            movies[searchedmovie].display();
            cout<<"Do you want to add to watchlist?(If yes enter Y or y):";
            char choice;
            cin>>choice;
            if(choice=='Y'||choice=='y'){
                users[userIndex].addToWatchlist(movies[searchedmovie]);
            }
            }
            else
            {cout<<"The entered movie not exist..\n";
            }
            
            break;
        }
        case 2:{searchclassification(users,userIndex,gmovies,nc17movies,pg13movies,pgmovies,rmovies);
                break;
        }
        case 3:{searchgenre(movies,users,userIndex,movieCount);break;}
        case 4:{rateMovie(movies,movieCount);break;}
        case 5:{viewWatchlist(users,userIndex);break;}
        case 6:{viewmovielist(movies,movieCount,users,userIndex);break;}
        case 7:{addtofavouritemovie(movies,movieCount,users,userIndex);break;}
        case 8:{viewallfmovielist(users,userIndex);break;}
    }
    }while(choice>=1&&choice<=8);
}

