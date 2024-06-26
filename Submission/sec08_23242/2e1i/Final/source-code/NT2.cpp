//Implementation file
#include "NT.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
#include<cctype>
#include<fstream>
#include<chrono>
#include<thread>

using namespace chrono;
using namespace this_thread;
using namespace std;
#define MAX 5

#define BREAKFAST 1
#define LUNCH 2
#define DINNER 3
#define SNACK 4

const string RESET = "\033[0m";
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string CYAN = "\033[1;36m";
const string BRIGHT_BLUE = "\033[1;94m";
const string ORANGE = "\033[38;5;208m";
const string PURPLE = "\033[38;5;165m";

//Feedback Class
Feedback::Feedback(string fb = ""):feedbackText(fb){}
Feedback::~Feedback(){}

void Feedback::setFeedback(string fb) {
    feedbackText = fb;
}

string Feedback::getFeedback() const {return feedbackText;}


//Food Class
Food::Food(string _foodName = "", int _calorie = 0, int _carbs = 0, int _fat = 0, int _protein = 0, int _fiber = 0): foodName(_foodName), calorie(_calorie), carbs(_carbs), fat(_fat), protein(_protein), fiber(_fiber){}
Food::~Food(){}

string Food::getFoodName() const { return foodName; }
int Food::getCalorie() const { return calorie; }
int Food::getCarbs() const { return carbs; }
int Food::getFat() const { return fat; }
int Food::getProtein() const { return protein; }
int Food::getFiber() const { return fiber; }
void Food::setFoodName(string _foodName) { foodName = _foodName; }
void Food::setCalorie(int _calorie) { calorie = _calorie; }
void Food::setCarbs(int _carbs) { carbs = _carbs; }
void Food::setFat(int _fat) { fat = _fat; }
void Food::setProtein(int _protein) { protein = _protein; }
void Food::setFiber(int _fiber) { fiber = _fiber; }

void Food::printFoodDetails() const {
    cout << "\t\tFood: " << foodName
         << ", Calories: " << calorie
         << ", Carbs: " << carbs
         << ", Fat: " << fat
         << ", Protein: " << protein
         << ", Fiber: " << fiber << endl;}
void Food::printList(const vector<Food>& foodList) {
    cout << "\t\tFrequently Tracked Food:\n";
    for (size_t i = 0; i < foodList.size(); ++i) {
        cout << "\t\t" << i + 1 << ". " << foodList[i].getFoodName() << endl;
    }
        cout << "\t\t" << foodList.size() + 1 << ". Key In Manually\n";
        cout << "\t\t" << foodList.size() + 2 << ". Exit\n";
}


//NutritionTracker Class
NutritionTracker::NutritionTracker() : totalCalories(0),totalCarbs(0),totalFat(0),totalProtein(0),totalFiber(0),caloriesBurnt(0) {createList();}
NutritionTracker::~NutritionTracker() {}

int NutritionTracker::getTotCalories() { return totalCalories; }
int NutritionTracker::getTotCarbs() { return totalCarbs; }
int NutritionTracker::getTotFat() { return totalFat; }
int NutritionTracker::getTotProtein(){ return totalProtein;}
int NutritionTracker::getTotFiber() { return totalFiber; }
int NutritionTracker::getCaloriesBurnt() { return caloriesBurnt; }
void NutritionTracker::setTotCalories(int _totalCalories) { totalCalories = _totalCalories; }
void NutritionTracker::setTotCarbs(int _totalCarbs) { totalCarbs = _totalCarbs; }
void NutritionTracker::setTotFat(int _totalFat) { totalFat = _totalFat; }
void NutritionTracker::setTotProtein(int _totalProtein){ totalProtein = _totalProtein;}
void NutritionTracker::setTotFiber(int _totalFiber) { totalFiber = _totalFiber; }
void NutritionTracker::setCaloriesBurnt(int _caloriesBurnt) { caloriesBurnt = _caloriesBurnt; }

void NutritionTracker::createList() {
    foodList.push_back(Food("Milk", 168, 11, 10, 8, 0));
    foodList.push_back(Food("Boiled Egg", 77, 1, 5, 6, 0));
    foodList.push_back(Food("White Bread", 59, 11, 1, 2, 1));
    foodList.push_back(Food("Mee goreng", 316, 31, 14, 18, 2));
    foodList.push_back(Food("White Rice", 135, 29, 0, 3, 0));
    foodList.push_back(Food("Fried Rice", 250, 31, 9, 9, 1));
    foodList.push_back(Food("Mix Vegetable", 82, 7, 6, 2, 2));
    foodList.push_back(Food("Salad", 36, 7, 1, 1, 2));
    foodList.push_back(Food("Chicken Meat", 332, 0, 17, 43, 0));
    foodList.push_back(Food("Fried Chicken", 259, 6, 18, 18, 0));
    foodList.push_back(Food("Apple", 88, 20, 1, 0, 5));
    foodList.push_back(Food("Orange", 63, 14, 0, 1, 2));
    foodList.push_back(Food("Coffee", 2, 0, 0, 0, 0));
}
void NutritionTracker::addConsumedFood(const Food& f, vector<Food>& mealFoods) {
    mealFoods.push_back(f);
    totalCalories += f.getCalorie();
    totalCarbs += f.getCarbs();
    totalFat += f.getFat();
    totalProtein += f.getProtein();
    totalFiber += f.getFiber();
}
void NutritionTracker::enterFoodManually(vector<Food>& mealCategory, string meal) {
    string foodName;
    int calorie, carbs, fat, protein, fiber;

    cout << "\t\t====================================================================\n";
    cout << "\t\tEnter the food name: ";
    cin.ignore();
    getline(cin, foodName);
    cout << "\t\tEnter the nutrition facts\n\t\tSeparate by spacing\n\t\t(calorie, carbs, fat, protein, fiber): ";
    cin >> calorie >> carbs >> fat >> protein >> fiber;

    Food newFood(foodName, calorie, carbs, fat, protein, fiber);
    mealCategory.push_back(newFood);

    cout << GREEN <<"\t\t"<< newFood.getFoodName() << " added to your " << meal << ".\n\n"<<RESET;
}
void NutritionTracker::trackIntake(vector<Food>& mealCategory, string meal) {
    int input;

    system("cls");

    cout <<YELLOW<<"\n\n\n\t\t\t\t\t***TRACKING PAGE***\n"<<RESET;
    cout << "\t\t====================================================================\n";
    Food::printList(foodList);

    cout << GREEN << "\n\t\t\tTrack for **" << meal << "**\n"
         << "\t\t-------------------------------------------------"<<RESET<<endl;
    do {
        cout << "\t\tEnter the code (1 - " << foodList.size()+2 << "): ";
        cin >> input;
        
        while(input < 1 || input > foodList.size() + 2){
            cout << "\t\tINVALID INPUT. Please enter the code (1 - " << foodList.size() + 2 << "): ";
            cin >> input;
        }
        if(input > 0 && input <= foodList.size()){
            addConsumedFood(foodList[input - 1], mealCategory);
            cout << GREEN <<"\t\t"<< foodList[input - 1].getFoodName() << " added to your " << meal << ".\n\n"<<RESET;
        }
        else if(input == foodList.size() + 1){enterFoodManually(mealCategory, meal);}
        else if(input == foodList.size() + 2){cout <<ORANGE<< "\n\t\tBack to Nutrition Tracker page...\n"<<RESET; sleep_for(seconds(1));}

    } while(input != foodList.size() + 2);
}
void NutritionTracker::displaySummary() {
    cout << "\n\t\tConsumed Foods:\n";
    cout << "\t\tBreakfast:\n";
    for (const Food& f : breakfastFoods){f.printFoodDetails();}
    
    cout << "\n\t\tLunch:\n";
    for (const Food& f : lunchFoods) {f.printFoodDetails();}
    
    cout << "\n\t\tDinner:\n";
    for (const Food& f : dinnerFoods) {f.printFoodDetails();}
    
    cout << "\n\t\tSnacks:\n";
    for (const Food& f : snackFoods) {f.printFoodDetails();}

    cout << "\n\t\t=================================================================\n";
    cout << YELLOW <<"\n\t\t\t\t  Total Nutrition Facts:\n"<<RESET;
    cout << "\t\t=================================================================\n";
    cout << "\t\tTotal Calories: " << getTotCalories() << endl;
    cout << "\t\tTotal Carbs: " << getTotCalories() << "g\n";
    cout << "\t\tTotal Fat: " << getTotFat() << "g\n";
    cout << "\t\tTotal Protein: " << getTotProtein() << "g\n";
    cout << "\t\tTotal Fiber: " << getTotCalories() << "g\n";
}
void NutritionTracker::nutritionTrackerPage() {
    int choice;
    do 
    {   
        system("cls");
        cout << YELLOW<<"\n\n\n\t\t\t*** Welcome to the NUTRITION TRACKER page... ***\n"<<RESET;
        cout << "\t\t====================================================================\n";
        cout << "\t\t1. Breakfast\n"
            << "\t\t2. Lunch\n"
            << "\t\t3. Dinner\n"
            << "\t\t4. Snack\n"
            << "\t\t5. Back to Main page\n";
        cout << "\t\tPlease enter the code (1 - 5): ";
        cin >> choice;

        while(choice < 1 || choice > 5) 
        {
            cout << "\t\tINVALID INPUT. Please enter the code (1 - 5): ";
            cin >> choice;
        }

        switch (choice)
        {
        case BREAKFAST:
            trackIntake(breakfastFoods, "BREAKFAST");
            break;

        case LUNCH:
            trackIntake(lunchFoods, "LUNCH");
            break;
        
        case DINNER:
            trackIntake(dinnerFoods, "DINNER");
            break;
        
        case SNACK:
            trackIntake(snackFoods, "SNACK");
            break;

        case 5:
            cout << ORANGE << "\n\t\tBack to MAIN PAGE...\n" <<RESET;
            sleep_for(seconds(1));
            
        default:
            break;
        } 
        system("cls");
}while(choice != 5);
}
void NutritionTracker::workoutTrackerPage() {
    int total;
    char option;
    
    system("cls");
    cout << YELLOW <<"\n\n\t\t\t***Welcome to the WORKOUTS TRACKER page...***\n"<<RESET;
    cout <<"\t\t====================================================================\n";
    cout << "\t\tSport & Activty\tCalorie Burnt (cal)"<<endl;
    cout << "\t\t\tBadminton         224\n"
         << "\t\t\tBasketball        400\n"
         << "\t\t\tFootball          419\n"
         << "\t\t\tSwimming          367\n"
         << "\t\t\tTennis            350\n"
         << "\t\t\tJogging           367\n"
         << "\t\t\tStanding          120\n"
         << "\t\t\tSleeping           44\n"
         << "\t\t\tSweeping          199\n"
         << "\t\t\tWalk Dog          157\n";

    do{
        cout<<"\n\t\tEnter calories burnt for the activity: ";
        cin >> total;
        caloriesBurnt += total;
    
        cout<<"\n\t\tWould you like to enter more? (Y/N): ";
        cin >> option;

    }while(toupper(option) == 'Y');

    cout << "\n\t\tYour total Calorie Burnt: " << caloriesBurnt << RED << " cal\n" << RESET;
    cout << ORANGE <<"\n\t\tPress Enter to continue..." <<RESET;
    cin.ignore();
    cin.get(); 
}


//User Class
User::User(string _username = "", string _password = "",string fb="") : username(_username), password(_password), login(false), feedback(fb) {}
User::~User(){}

Feedback& User::getFeedback() {return feedback;}
void User::setUsername(string u) {username =  u;}
void User::setPassword(string s){password = s;}
string User::getUsername() const { return username; }
string User::getPassword() const { return password; }


//RegularUser class
RegularUser::RegularUser(string _username = "", string _password = ""): age(0), gender('X'), height(0.0), weight(0.0), bmr(0.0), bmi(0.0), cal_budget(0.0), activityLvl(0), User(_username, _password) {}

RegularUser::RegularUser(): age(0), gender('X'), height(0.0), weight(0.0), bmr(0.0), bmi(0.0), cal_budget(0.0), activityLvl(0), User() {}

RegularUser::~RegularUser() {}


int RegularUser::getAge(){return age;}
char RegularUser::getGender(){return gender;}
double RegularUser::getHeight(){return height;}
double RegularUser::getWeight(){return weight;}
double RegularUser::getBmr(){return bmr;}
double RegularUser::getBmi(){return bmi;}
double RegularUser::getCal_budget(){return cal_budget;}
int RegularUser::getActivityLvl(){return activityLvl;}


void RegularUser::setAge(int a) {
    if (a <= 0 || a > 100) 
        throw InvalidInput();
    else
        age = a;
}
void RegularUser::setGender(char g) {
    if (toupper(g) != 'M' && toupper(g) != 'F') 
        throw InvalidInput();
    else
        gender = g; 
}
void RegularUser::setHeight(double h){
    if (h > 2.5 || h <= 0) 
        throw InvalidInput();
    else
        height = h; 
}
void RegularUser::setWeight(double w){
    if (w < 0 || w > 250) 
        throw InvalidInput();
    else
        weight = w;
}
    
void RegularUser::setActivityLvl(int al) {
    if (al < 1 || al > 5) 
        throw InvalidInput();
    else
        activityLvl = al;
}
void RegularUser::setBmr(double br){bmr=br;}
void RegularUser::setBmi(double bi){bmi=bi;}
void RegularUser::setCal_budget(double cal){cal_budget=cal;}


double RegularUser::calcBMI(){
        bmi = weight / pow(height, 2);
        return bmi;
}
void RegularUser::setInfo() {
    int i;
    double d,h,w;
    char c;
    

    system("cls");

    cout << YELLOW << "\n\n\t\t\t\t***Welcome! SET UP YOUR PROFILE***\n" << RESET;
    cout <<"\t\t====================================================================\n";

    cout << "\t\tName: ";
    cout << getUsername();

    do
    {
        try
        {   cout << "\n\t\tAge: ";
            cin >> i;
            setAge(i);
            break;
        }
        catch(RegularUser::InvalidInput)
        {
            cout << RED << "\t\tInvalid input" << RESET << endl;
            cin.clear();
            cin.ignore();
            continue;  
        }
        break;
    } while (true);

    do
    {
        try
        {   
            cout << "\t\tGender (M/F) : ";
            cin >> c;
            setGender(c);
            break;
        }
        catch(RegularUser::InvalidInput)
        {
            cout << RED << "\t\tInvalid input" << RESET << endl;
            cin.clear();
            cin.ignore();
            continue;  
        }
        break;
    } while (true);
    
    do
    {
        try
        {   cout << "\t\tHeight (m): ";
            cin >> h;
            setHeight(h);
            break;
        }
        catch(RegularUser::InvalidInput)
        {
            cout << RED << "\t\tInvalid input" << RESET << endl;
            cin.clear();
            cin.ignore();
            continue;  
        }
        break;
    } while (true);
    
    do
    {
        try
        {   cout << "\t\tWeight (kg): ";
            cin >> w;
            setWeight(w);
            break;
        }
        catch(RegularUser::InvalidInput)
        {
            cout << RED << "\t\tInvalid input" << RESET << endl;
            cin.clear();
            cin.ignore();
            continue;  
        }
        break;
    } while (true);


    cout << YELLOW <<"\n\t\t***Activity Level***\n\n" << RESET;
    cout << "\t\t1. Sedentary (little or no exercise)\n"
         << "\t\t2. Lightly active (exercise 1-3 days a week)\n"
         << "\t\t3. Moderately active (exercise 3-5 days a week)\n"
         << "\t\t4. Very active (exercise 6-7 days a week)\n"
         << "\t\t5. Super active (very hard exercise/physical job)\n";
    do
    {
        try
        {   
            cout << "\n\t\tActivity level (1 - 5): ";
            cin >> i;
            setActivityLvl(i);
            break;
        }
        catch(RegularUser::InvalidInput)
        {
            cout << RED << "\t\tInvalid input" << RESET << endl;
            cin.clear();
            cin.ignore();
            continue;  
        }
        break;
    } while (true);

    recommendation();
    setTarget();
    cout << GREEN << "\t\tSuccessfully Set Up Profile!!\n" <<RESET;
}
void RegularUser::setTarget() {
    cout<< "\t\tDear user, please enter your target for your daily calories consumption: ";
    cin >> cal_budget;
}
void RegularUser::recommendation() {
        if (toupper(gender) == 'M')
            bmr = 88.362 + (13.397 * weight) + (4.799 * (height * 100)) - (5.677 * age);
        else if (toupper(gender) == 'F')
            bmr = 447.593 + (9.2478 * weight) + (3.098 * (height * 100)) - (4.330 * age);

        switch (activityLvl) {
            case 1:
                bmr = bmr * 1.2;
                break;
            case 2:
                bmr = bmr * 1.375;
                break;
            case 3:
                bmr = bmr * 1.55;
                break;
            case 4:
                bmr = bmr * 1.725;
                break;
            case 5:
                bmr = bmr * 1.9;
                break;
            default:
                cout << RED << "\t\tInvalid\n"<<RESET;
        }

        cout << "\n\t\tYour recommended daily calories needs is " << GREEN << bmr << RESET <<endl;
    }
void RegularUser::viewProfile() {
        cout << "\t\t=================================================================\n\n";
        cout << YELLOW << "\t\t                          User Profile                         " << RESET << endl;
        cout << "\t\t=================================================================\n\n";
        cout << "\t\tName   : " << getUsername() << endl;
        cout << "\t\tAge    : " << getAge() << " years old" << endl;
        cout << "\t\tHeight : " << fixed << setprecision(2) << getHeight() << "m" << endl;
        cout << "\t\tWeight : " << getWeight() << "kg" << endl;
        cout << "\t\tBMI    : " << calcBMI() << " kg/m^2 " << endl;
        cout << "\t\tCalories Budget: " << getCal_budget()<< " kg/m^2 " << endl;
        cout << ORANGE <<"\n\t\tPress Enter to continue..." <<RESET;
        cin.ignore();
        cin.get();
        } 
void RegularUser::viewDailySummary() {
    system("cls");
    cout << "\t\t====================================================================\n";
    cout << YELLOW << "\t\t\t               Daily Summary                " << RESET <<endl;
    cout << "\t\t====================================================================\n";
    nutrition.displaySummary();
    cout << "\t\tTotal Calories Ate: " << nutrition.getTotCalories() << endl;
    cout << "\n\t\tCalories Burnt: "<< nutrition.getCaloriesBurnt() << endl;
    cout << "\t\tDaily Calories: "<< (nutrition.getTotCalories() - nutrition.getCaloriesBurnt()) <<endl;
    
    cout << ORANGE << "\n\t\tPress Enter to continue..." <<RESET;
    cin.ignore();
    cin.get();
}

void RegularUser::viewNutritionTracker(){
    nutrition.nutritionTrackerPage();
}
void RegularUser::viewWorkoutTracker(){
    nutrition.workoutTrackerPage();
}

void RegularUser::signUp(vector<User*>& users){
    system("cls");
    cout << "\t\t====================================================================\n";
    cout <<BLUE<< "\n\t\t\t\t***SIGN UP (Regular User)***\n\n"<<RESET;
    cout << "\t\t====================================================================\n";
    bool name;
    do {
        name = true;
        cout << "\n\t\tPlease enter your username: ";
        getline(cin, username);

        ifstream infile("regular_user.txt");
        string existingUsername, existingPassword;
        while (infile >> existingUsername >> existingPassword) {
            if (existingUsername == username) {
                cout << RED <<"\t\tUsername already exists. Please choose a different username.\n"<<RESET;
                name = false;
                break;
            }
        }
        infile.close();
    } while (!name);

    cout << "\n\t\tPlease enter your password: ";
    getline(cin, password);

    ofstream outfile("regular_user.txt", ios::app); 
    if (outfile.is_open()) {
        outfile << username << " " << password << "\n";
        outfile.close();
    } else {
        cout << RED << "\t\tUnable to open file to save user data.\n"<<RESET;
    }

    users.push_back(this);
    cout << GREEN << "\n\t\tAccount (Regular User) created successfully!\n" <<RESET;
    sleep_for(seconds(1));
    system("cls");
    
}
bool RegularUser::logIn(const vector<User*>& users){     
        string b;

        cout << "\n\t\tPlease enter your password: ";
        getline(cin, b);

        if (b == getPassword()) {
            login = true;
                cout << GREEN << "\n\t\tLOGIN SUCCESSFUL! WELCOME, " << getUsername() << ".\n"<<RESET;
                sleep_for(seconds(1));
                return true;
        }
        
        cout << RED << "\t\tInvalid password.\n"<< RESET;
        sleep_for(seconds(1));
        return false;
}

string RegularUser::getUserType() const{
        return "RegularUser";
    }

void RegularUser::viewFeedback(){
    system("cls");
    cout << "\t\t====================================================================\n";
    cout << YELLOW << "\n\t\t\t\t\t***Feedback***\n\n" << RESET;
    cout << "\t\t====================================================================\n";
    
    cout << "\t\t" << feedback.getFeedback();
    cout << endl;
    cout << ORANGE << "\n\t\tPress Enter to continue..."<<RESET;
    cin.ignore();
    cin.get();
}

//Nutritionist Class
Nutritionist::Nutritionist(string _username = "", string _password = "",string _feedback="",string _recommendation="") : userCount(0), User(_username, _password,_feedback) {}

Nutritionist::Nutritionist(string _username="",string _password=""):userCount(0),User(_username,_password){}

Nutritionist::Nutritionist():userCount(0),User(){}


void Nutritionist::viewUsersReport() {
    system("cls");
    string name;
    cout << "\t\t=================================================================\n";
    cout << YELLOW << "\n\t\t\t\t\tView User Report \n\n"<<RESET;

    for (int i = 0; i < userCount; i++)
    {       
        cout << "\t\t=================================================================\n\n";
        cout << YELLOW << "\t\t\t\t\t    User #" << i+1 << RESET << endl << endl;
        regularUser[i]->viewProfile();
        cout << endl;
        regularUser[i]->viewDailySummary();
        cout << endl;
        system("cls");
        
    }
}
void Nutritionist::writeFeedback(){
    system("cls");
    cout << "\t\t=================================================================\n";
    cout << YELLOW << "\n\t\t\t\t\tWrite Feedback \n\n"<<RESET;
    cout << "\t\t=================================================================\n\n";
    cin.ignore();
    for (int i = 0; i < userCount; i++)
    {       
        cout << "\t\t=================================================================\n\n";
        cout << YELLOW << "\t\t\t\t\t    User #" << i+1 << RESET << endl << endl;
        cout << "\t\t=================================================================\n\n";
        cout << "\t\tWrite Feedback: ";
        string fb;
        
        getline(cin, fb);
        regularUser[i]->feedback.setFeedback(fb);
        system("cls");
    }
}


void Nutritionist::signUp(vector<User*>& users){
    system("cls");
    cout << "\t\t====================================================================\n";
    cout <<CYAN<< "\n\t\t\t\t***SIGN UP (Nutritionist)***\n\n"<<RESET;
    cout << "\t\t====================================================================\n";
    bool name;
    do {
        name = true;
        cout << "\n\t\tPlease enter your username: ";
        getline(cin, username);

        ifstream infile("nutritionists.txt");
        string existingUsername, existingPassword;
        while (infile >> existingUsername >> existingPassword) {
            if (existingUsername == username) {
                cout << "\t\tUsername already exists. Please choose a different username.\n";
                cout << ORANGE <<"\n\t\tPress Enter to continue..." <<RESET;
                cin.ignore();
                cin.get();
                name = false;
                break;
            }
        }
        infile.close();
    } while (!name);

    cout << "\n\t\tPlease enter your password: ";
    getline(cin, password);

    ofstream outfile("nutritionists.txt", ios::app);
    if (outfile.is_open()) {
        outfile << username << " " << password << "\n";
        outfile.close();
    } else {
        cout << "\t\tUnable to open file to save user data.\n";
    }

    users.push_back(this);
    cout << GREEN << "\n\t\tAccount (Regular User) created successfully!\n" <<RESET;
    sleep_for(seconds(1));
    system("cls");
}
bool Nutritionist::logIn(const vector<User*>& users){
            string a, b;

            cout << "\n\t\t============***LOG IN (" << CYAN << "NUTRITIONIST" << RESET << ")***============\n";
            cout << "\n\t\tPlease enter your username: ";
            getline(cin, a);
            cout << "\n\t\tPlease enter your password: ";
            getline(cin, b);

            ifstream infile("nutritionists.txt");
            string storedUsername, storedPassword;
            while (infile >> storedUsername >> storedPassword) {
                if (storedUsername == a && storedPassword == b) {
                    login = true;
                    cout << GREEN << "\n\t\tLOGIN SUCCESSFUL!\n"<<RESET;
                    sleep_for(seconds(1));
                    return true;
                }
            }

            cout << RED <<"\n\t\tInvalid username or password.\n"<<RESET;
            sleep_for(seconds(1));
            system("cls");
            return false;
        }
string Nutritionist::getUserType() const{return "Nutritionist";}

void Nutritionist::addRegularUser(RegularUser* user) {
    if (userCount < MAX) {
        regularUser[userCount] = user;
        userCount++;
    } else {
        cout << "\t\tUser array is full." << endl;
    }
}