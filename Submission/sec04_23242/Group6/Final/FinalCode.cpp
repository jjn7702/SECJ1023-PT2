#include <iostream>
#include <cstring>
#include <string>
#include <exception>
#include <iomanip>
#include <fstream>

using namespace std;

class Goal { 
    string description;
    bool isAchieved;
public:
    Goal(string d = "", bool i = 0) : description(d), isAchieved(i) {}

    string getDesc() {
        return description;
    }

    bool getAchieved() {
        return isAchieved;
    }

    void setDesc(string d) {
        description = d;
    }

    void setAchieved(bool a) {
        isAchieved = a;
    }

    void updateGoal(string d, bool a) {
        description = d;
        isAchieved = a;
    }

    void checkGoalStatus() {
        cout << "Goal Status" << "\t" << ": ";
        if (isAchieved == 1) {
            cout << "Achieved" << endl;
        } else {
            cout << "Not achieved" << endl;
        }

        cout << "Description" << "\t" << ": " << description << endl;
        cout << "Feedback" << "\t" << ": ";
        if (isAchieved == 1) {
            cout << "Congrats! You've reached your goal!" << endl;
        } else {
            cout << "Keep it up!" << endl;
        }
    }
};

class Profile {
    Goal* goal; // aggragation
    double currentWeight, goalWeight;
public:
    Profile(double cw = 0, double gw = 0, string description = "") : currentWeight(cw), goalWeight(gw) {
        bool x = (currentWeight == goalWeight) ? 1 : 0;
        goal = new Goal(description, x);
    }

    double getCurrentWeight() {
        return currentWeight;
    }

    double getGoalWeight() {
        return goalWeight;
    }

    void updateProfile(double cw, double gw, string desc) {
        currentWeight = cw;
        goalWeight = gw;
        bool x = (currentWeight == goalWeight) ? 1 : 0;
        goal = new Goal(desc, x);
    }

    void updateGoal(double gw) {
        goalWeight = gw;
        goal->setAchieved(currentWeight == goalWeight);
    }

    void updateWeight(double cw) {
        currentWeight = cw;
        goal->setAchieved(currentWeight == goalWeight);
    }

    void updateDesc(string d) {
        goal->setDesc(d);
    }

    void displayProfile() {
        cout << "\n--------------PROFILE--------------" << endl;
        goal->checkGoalStatus();
        cout << "Current Weight" << "\t" << ": " << currentWeight << endl
            << "Goal Weight" << "\t" << ": " << goalWeight << endl << endl;
    }
};

class Nutrition {
    string food;
    int calories;
public:
    Nutrition(string f = "", int c = 0) : food(f), calories(c) {}

    string getFood() {
        return food;
    }

    int getCalories() {
        return calories;
    }

    void setFood(string f) {
        food = f;
    }

    void setCalories(int c) {
        calories = c;
    }

    void displayNutrition() {
        cout << "Food" << "\t" << "\t" << ": " << food << endl
            << "Calories" << "\t" << ": " << calories << endl;
    }
};

class Activity { // base class
    int duration, intensity;
public:
    Activity(int d = 0, int i = 0) : duration(d), intensity(i) {}

    int getDuration() {
        return duration;
    }

    int getIntensity() {
        return intensity;
    }

    virtual void calculateCaloriesBurned(double cw) { //virtual function
        cout << "Calories Burned" << "\t" << ": ";
    }

    virtual void displayActivity() { //virtual function
        cout << "Duration" << "\t" << ": " << duration << endl
            << "Intensity" << "\t" << ": " << intensity << endl;
    }
};

class SportsActivity : public Activity { //derived class
    string sportType;
public:
    SportsActivity(string st = "", int d = 0, int i = 0) : Activity(d, i), sportType(st) {}

    void setSportType(string st) {
        sportType = st;
    }

    void calculateCaloriesBurned(double cw) {
        Activity::calculateCaloriesBurned(cw);
        double cal, MET;
        string lowered = sportType;
        for (int i = 0; i < sportType.length(); i++) {
            lowered[i] = tolower(sportType[i]);
        }
        if (lowered == "badminton") {
            MET = 5.5;
        } else if (lowered == "basketball") {
            MET = 8;
        } else if (lowered == "football") {
            MET = 7;
        } else if (lowered == "volleyball") {
            MET = 3.5;
        } else if (lowered == "futsal") {
            MET = 8;
        } else {
            MET = 4;
        }
        cal = MET * cw * (double(Activity::getDuration()) / 60) * Activity::getIntensity();
        cout << cal << endl;
    }

    void displayActivity() {
        cout << "Sport Activity" << endl;
        Activity::displayActivity();
        cout << "Sport Type" << "\t" << ": " << sportType << endl;
    }
};

class CardioActivity : public Activity { //derived class
    double distance;
public:
    CardioActivity(double _distance = 0, int d = 0, int i = 0) : Activity(d, i), distance(_distance) {}

    double getDistance() {
        return distance;
    }

    void setDistance(double d) {
        distance = d;
    }

    void calculateCaloriesBurned(double cw) {
        Activity::calculateCaloriesBurned(cw);
        cout << distance * cw * Activity::getIntensity() * (double(Activity::getDuration()) / 60) << endl;
    }

    void displayActivity() {
        cout << "Cardio Activity" << endl;
        Activity::displayActivity();
        cout << "Distance" << "\t" << ": " << distance << endl;
    }
};

class StrengthActivity : public Activity { //derived class and intermediate base class
    int repsPerSet;
    int sets;
public:
    StrengthActivity(int _repsPerSet = 0, int _sets = 0, int d = 0, int i = 0) : Activity(d, i), repsPerSet(_repsPerSet), sets(_sets) {}

    int getReps() {
        return repsPerSet;
    }

    int getSets() {
        return sets;
    }

    void setReps(int r) {
        repsPerSet = r;
    }

    void setSets(int s) {
        sets = s;
    }

    virtual void calculateCaloriesBurned(double cw) {
        Activity::calculateCaloriesBurned(cw);
        cout << "";
    }

    virtual void displayActivity() {
        cout << "Strength Activity" << endl;
        Activity::displayActivity();
        cout << "Sets" << "\t" << "\t" << ": " << sets << endl
            << "Reps/set" << "\t" << ": " << repsPerSet << endl;
    }
};

class BodyweightExercise : public StrengthActivity { //derived class
    string exerciseType;
public:
    BodyweightExercise(string et, int _repsPerSet = 0, int _sets = 0, int d = 0, int i = 0) : StrengthActivity(_repsPerSet, _sets, d, i), exerciseType(et) {}

    string getExerciseType() {
        return exerciseType;
    }

    void setExerciseType(string et) {
        exerciseType = et;
    }

    void calculateCaloriesBurned(double cw) {
        StrengthActivity::calculateCaloriesBurned(cw);
        cout << Activity::getIntensity() * (double(Activity::getDuration()) / 60) * cw * StrengthActivity::getReps() * StrengthActivity::getSets() << endl;
    }

    void displayActivity() {
        StrengthActivity::displayActivity();
        cout << "Exercise" << "\t" << ": " << exerciseType << endl;
    }
};

class WeightExercise : public StrengthActivity { //derived class
    double weight;
public:
    WeightExercise(double w, int _repsPerSet = 0, int _sets = 0, int d = 0, int i = 0) : StrengthActivity(_repsPerSet, _sets, d, i), weight(w) {}

    double getWeight() {
        return weight;
    }

    void setWeight(double w) {
        weight = w;
    }

    void calculateCaloriesBurned(double w) { //dummy parameter
        StrengthActivity::calculateCaloriesBurned(weight);
        cout << Activity::getIntensity() * (double(Activity::getDuration()) / 60) * weight * StrengthActivity::getReps() * StrengthActivity::getSets() << endl;
    }

    void displayActivity() {
        StrengthActivity::displayActivity();
        cout << "Weight Lifted" << "\t" << ": " << weight << endl;
    }
};

class ProgressTracker {
    Activity* activities[100]; //aggregation
    Nutrition* nutritions[100]; //aggregation
    int numA = 0, numN = 0;
public:
    void addActivity(Activity* activity) {
        activities[numA++] = activity;
    }

    void addNutrition(Nutrition* nutrition) {
        nutritions[numN++] = nutrition;
    }

    void showProgress(double cw) {
        cout << "\n--------------ACTIVITIES--------------" << endl;
        for (int i = 0; i < numA; i++) {
            cout << "Activities " << i + 1 << endl;
            activities[i]->displayActivity();
            activities[i]->calculateCaloriesBurned(cw);
            cout << "--------------------------------------" << endl;
        }
        cout << "\n--------------NUTRITION---------------" << endl;
        for (int i = 0; i < numN; i++) {
            cout << "NUTRITION " << i + 1 << endl;
            nutritions[i]->displayNutrition();
            cout << "--------------------------------------" << endl;
        }
    }
};

class User {
    Profile p; //composition
    ProgressTracker Pt; //composition
    string username, password;
    int totalActivities; 
    int totalNutritions;

public:
    class NegativeValues {};

    User(string u = "", string pass = "") : username(u), password(pass), totalActivities(0), totalNutritions(0) {}

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    void setUsername(string u = "") {
        username = u;
    }

    void setPassword(string p = "") {
        password = p;
    }

    int checkLogin(string user, string pass) {
        return (user == username && pass == password) ? 1 : 0;
    }

    void updateProfile(double cw, double gw, string desc) {
        if (cw <= 0 || gw <= 0) {
            throw NegativeValues();
        }
        p.updateProfile(cw, gw, desc);
    }

    void updateCurrentWeight(double cw) {
        p.updateWeight(cw);
    }

    void updateGoal(double gw) {
        p.updateGoal(gw);
    }

    void updateDesc(string d) {
        p.updateDesc(d);
    }

    void displayProfile() {
        p.displayProfile();
    }

    void displayActivity() {
        Pt.showProgress(p.getCurrentWeight());
    }

    void addNutrition(Nutrition* sample) {
        Pt.addNutrition(sample);
        totalNutritions++;
    }

    void addActivity(Activity* sample) {
        Pt.addActivity(sample);
        totalActivities++;
    }

    int getTotalActivities() {
        return totalActivities;
    }

    int getTotalNutritions() {
        return totalNutritions;
    }

    void displayInfo() {
        p.displayProfile();
        Pt.showProgress(p.getCurrentWeight());
    }
};

int main() {

    int arraycounter = 0, duration, intensity, sets, repperset, weightlifted, foodcalories, currentweight, goalweight, distance, looper1 = 1, accindex = -1, menuchoice, looper2 = 1, activitychoice, looper3 = 1;
    string sportsname, exercisetype, username, password, ulogin, plogin, foodname, description, answerinput;
    User u[100];
    
    ifstream infile("C:/Users/muhdn/OneDrive/Desktop/UTM Semester 2/Programming Technique 2/Advanced Feature/FULL CODE PROJECT/input.txt"); //open input file

    //read the file line by line
    while (infile >> username >> password) {
        u[arraycounter].setUsername(username);
        u[arraycounter].setPassword(password);
        arraycounter++; // increment the user count
    }

    infile.close(); //close file
   

    cout << "-------------- Welcome to Fitness Progress Tracker System ---------------" << endl;

    while (looper1 == 1) {
        cout << "\nDo you have an account? (yes/no) or type 'stop' to exit: ";
        cin >> answerinput;
        for (char& c : answerinput) {
            c = tolower(c);
        }
        if (answerinput == "yes") {
            accindex = -1;
            while (accindex == -1) {
                cout << "\n----------------- Account Login -----------------" << endl;
                cout << "Enter Username: ";
                cin >> ulogin;
                cout << "Enter Password: ";
                cin >> plogin;
                for (int i = 0; i < 100; i++) {
                    if (u[i].checkLogin(ulogin, plogin) == 1) {
                        accindex = i;
                        break;
                    }
                }
                if (accindex != -1) {
                    cout << "Login Successful!" << endl;
                    cout << "If You Dont Update Profile Yet, Please Update First!" << endl;
                    looper2 = 1;
                    while (looper2 == 1) {
                        cout << "\n-------------- Menu --------------" << endl
                            << setw(5) << "1." << setw(20) << "Add Nutrition" << endl
                            << setw(5) << "2." << setw(20) << "Add Activity" << endl
                            << setw(5) << "3." << setw(20) << "Update Profile" << endl
                            << setw(5) << "4." << setw(20) << "Show Progress" << endl
                            << setw(5) << "5." << setw(20) << "Logout" << endl
                            << "-----------------------------------" << endl
                            << "Enter your choice (1-5): ";
                        cin >> menuchoice;
                        switch (menuchoice) {
                        case 1:
                            cout << "\n-------------- Add Nutrition --------------" << endl;
                            cout << "Enter food name: ";
                            cin.ignore();
                            getline(cin, foodname);
                            cout << "Enter food calories: ";
                            cin >> foodcalories;
                            u[accindex].addNutrition(new Nutrition(foodname, foodcalories));
                            cout << "Nutrition added successfully." << endl;
                            break;
                        case 2:
                            cout << "\n-------------- Choose Activity --------------" << endl
                                << setw(5) << "1." << setw(20) << "Cardio Activity" << endl
                                << setw(5) << "2." << setw(20) << "Sports Activity" << endl
                                << setw(5) << "3." << setw(20) << "Weight Exercise" << endl
                                << setw(5) << "4." << setw(20) << "Bodyweight Exercise" << endl
                                << "--------------------------------------------" << endl
                                << "Enter your choice (1-4): ";
                            cin >> activitychoice;
                            if (activitychoice == 1) {
                                cout << "\n-------------- Cardio Activity --------------" << endl;
                                cout << "Input distance (in km): ";
                                cin >> distance;
                                cout << "Input duration (in minutes): ";
                                cin >> duration;
                                cout << "Input intensity (1-3): ";
                                cin >> intensity;
                                u[accindex].addActivity(new CardioActivity(distance, duration, intensity));
                                cout << "Cardio Activity added successfully." << endl;
                            } else if (activitychoice == 2) {
                                cout << "\n-------------- Sports Activity --------------" << endl;
                                cout << "Input sports name: ";
                                cin >> sportsname;
                                cout << "Input duration (in minutes): ";
                                cin >> duration;
                                cout << "Input intensity (1-3): ";
                                cin >> intensity;
                                u[accindex].addActivity(new SportsActivity(sportsname, duration, intensity));
                                cout << "Sports Activity added successfully." << endl;
                            } else if (activitychoice == 3) {
                                cout << "\n-------------- Weight Exercise --------------" << endl;
                                cout << "Input weight (kg): ";
                                cin >> weightlifted;
                                cout << "Input reps per set: ";
                                cin >> repperset;
                                cout << "Input sets: ";
                                cin >> sets;
                                cout << "Input duration (in minutes): ";
                                cin >> duration;
                                cout << "Input intensity (1-3): ";
                                cin >> intensity;
                                u[accindex].addActivity(new WeightExercise(weightlifted, repperset, sets, duration, intensity));
                                cout << "Weight Exercise added successfully." << endl;
                            } else if (activitychoice == 4) {
                                cout << "\n-------------- Bodyweight Exercise --------------" << endl;
                                cout << "Input exercise type: ";
                                cin.ignore();
                                getline(cin, exercisetype);
                                cout << "Input reps per set: ";
                                cin >> repperset;
                                cout << "Input sets: ";
                                cin >> sets;
                                cout << "Input duration (in minutes): ";
                                cin >> duration;
                                cout << "Input intensity (1-3): ";
                                cin >> intensity;
                                u[accindex].addActivity(new BodyweightExercise(exercisetype, repperset, sets, duration, intensity));
                                cout << "Bodyweight Exercise added successfully." << endl;
                            } else {
                                cout << "Invalid choice. Please try again." << endl;
                            }
                            break;
                        case 3:
                            cout << "\n-------------- Update Profile --------------" << endl;
                            cout << "Enter current weight (kg): ";
                            cin >> currentweight;
                            cout << "Enter goal weight (kg): ";
                            cin >> goalweight;
                            cout << "Enter goal description: ";
                            cin.ignore();
                            getline(cin, description);
                            try {
                                u[accindex].updateProfile(currentweight, goalweight, description);
                                cout << "Profile updated successfully." << endl;
                            } catch (User::NegativeValues) {
                                cout << "\nException: Negative weight values are not allowed.\n" << endl;
                            }
                            u[accindex].displayProfile();
                            break;
                        case 4:
                            if (u[accindex].getTotalActivities() == 0 && u[accindex].getTotalNutritions() == 0) {
                                cout << "You haven't added any activities or nutrition yet. Please add them to see your progress." << endl;
                            } else {
                                u[accindex].displayInfo();
                            }
                            break;
                        case 5:
                            looper2 = 0;
                            cout << "Logged out successfully." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Invalid login credentials. Please try again." << endl;
                    cout << "Retry login? (yes/no): ";
                    cin >> answerinput;
                    for (char& c : answerinput) {
                        c = tolower(c);
                    }
                    if (answerinput != "yes") {
                        break;
                    }
                }
            }
        } else if (answerinput == "no") {
            while (true) {
                     cout << "\n-------------- Account Registration --------------" << endl;
                    cout << "Input Username: ";
                    cin.sync();
                    getline(cin, username);
                     cout << "Input Password: ";
                    getline(cin, password);
                    u[arraycounter].setUsername(username);
                    u[arraycounter].setPassword(password);
                    cout << "\n------------------ Profile ------------------" << endl;
                    cout << "Enter current weight (kg): ";
                    cin >> currentweight;
                    cout << "Enter goal weight (kg): ";
                    cin >> goalweight;
                    cout << "Enter goal description: ";
                    cin.ignore();
                    getline(cin, description);
                    try {
                        u[arraycounter].updateProfile(currentweight, goalweight, description);
                        cout << "Profile created successfully." << endl;
                        break;
                    } catch (User::NegativeValues) {
                        cout << "\nException: Negative weight values are not allowed. Please try again.\n" << endl;
                    }
                }
                cout << "\nID: " << arraycounter << "\tUsername: " << u[arraycounter].getUsername() << "\tPassword: " << u[arraycounter].getPassword() << endl;
                u[arraycounter].displayProfile();
                arraycounter++;

        } else if (answerinput == "stop") {
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        } else {
            cout << "Invalid input. Please enter 'yes', 'no', or 'stop'." << endl;
        }
    }
    return 0;
}
