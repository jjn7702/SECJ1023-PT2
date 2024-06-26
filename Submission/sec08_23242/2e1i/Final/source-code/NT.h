//Class Specification File (PROTOTYPE)
#ifndef NT_H
#define NT_H

#include<string>
#include<vector>
using namespace std;

#define MAXDAY 21
#define MAX 5

class Feedback {
    private:
        string feedbackText;
	public:
        Feedback(string);
        ~Feedback();
        void setFeedback(string);
        string getFeedback() const;
        void display();
};

class Food {
    private:
        string foodName;
        int calorie;
        int carbs;
        int fat;
        int protein;
        int fiber;

    public:
        Food(string,int,int,int,int,int);
        ~Food();

        string getFoodName() const;
        int getCalorie() const;
        int getCarbs() const;
        int getFat() const;
        int getProtein() const;
        int getFiber() const;
        void setFoodName(string);
        void setCalorie(int);
        void setCarbs(int);
        void setFat(int);
        void setProtein(int);
        void setFiber(int);

        void printFoodDetails()const;
        static void printList(const vector<Food>&);     
};

class NutritionTracker {
    private:
        vector<Food> foodList;     
        vector<Food> breakfastFoods;
        vector<Food> lunchFoods;
        vector<Food> dinnerFoods;
        vector<Food> snackFoods;
        int totalCalories;
        int totalCarbs;
        int totalFat;
        int totalProtein;
        int totalFiber;
        int caloriesBurnt;
    public:
        NutritionTracker();
        ~NutritionTracker();

        int getTotCalories();
        int getTotCarbs();
        int getTotFat();
        int getTotProtein();
        int getTotFiber();
        int getCaloriesBurnt();
        void setTotCalories(int);
        void setTotCarbs(int);
        void setTotFat(int);
        void setTotProtein(int);
        void setTotFiber(int);
        void setCaloriesBurnt(int);

        void createList();
        void addConsumedFood(const Food&,vector<Food>&);
        void enterFoodManually(vector<Food>&,string);
        void trackIntake(vector<Food>&,string);
        void displaySummary();
        void nutritionTrackerPage();
        void workoutTrackerPage();
};

class User{
    protected:
        string username;
        string password;
        Feedback feedback;
        bool login;
    public:
        User(string, string, string);
        ~User();

        Feedback& getFeedback();
        void setUsername(string);
        void setPassword(string);
        string getUsername() const;
        string getPassword() const;

        virtual void signUp(vector<User*>& users) = 0;
        virtual bool logIn(const vector<User*>& users) = 0;
        virtual string getUserType() const = 0;

};

class RegularUser:public User {
    protected:
        NutritionTracker nutrition;
        int age;
        char gender;
        double height;
        double weight;
        double bmr;
        double bmi;
        double cal_budget;
        int activityLvl;
       
    public:
    RegularUser(string,string);
    RegularUser();
    ~RegularUser();

    class InvalidInput {};
    
    string getnickname();
    int getAge();
    char getGender();
    double getHeight();
    double getWeight();
    double getBmr();
    double getBmi();
    double getCal_budget();
    int getActivityLvl();
    
    void setAge(int);
    void setGender(char);
    void setHeight(double);
    void setWeight(double);
    void setBmr(double);
    void setBmi(double);
    void setCal_budget(double);
    void setActivityLvl(int); 
    
    double calcBMI();
    void setInfo();
    void setTarget();
    void recommendation();
    void viewProfile();
    void viewDailySummary();
    void viewNutritionTracker();
    void viewWorkoutTracker();
    void viewFeedback();

    void signUp(vector<User*>&);
    bool logIn(const vector<User*>&);
    string getUserType() const;


    friend class Nutritionist;
};

class Nutritionist:public User {
    protected:
        RegularUser* regularUser[MAX];
        int userCount;
    public:
        Nutritionist(string, string, string, string);
        Nutritionist(string, string);
        Nutritionist();

        void viewUsersReport();
        void writeFeedback();

        void signUp(vector<User*>&);
        bool logIn(const vector<User*>&);
        string getUserType()const;

        void addRegularUser(RegularUser* );
};

#endif