<h1 align="center"> Final </h1>

<h3> Project Description </h3>
<p align="justify">Nowadays, individuals encounter myriads of challenges to manage their finances well. From tracking their spending and analyzing their investment portfolio. The Personal Finance Manager system is intended to help individuals manage their finances effectively by tracking the users' transactions and creating reports to provide a clearer view of their monthly financial activities.  
</p >

<h3> Objectives and/or Purpose </h3>
<p align="justify">
1. To record users’ income which can be divided into passive income and active 
income <br>
2. To record the users’ expenses of different categories such as food, shopping, transportation and so on. <br>
3. To help users plan their budget to maintain a positive cash flow. <br>
</p>

<h3> Analysis and design </h3>
<h4> Flow Chart </h4>

<h4> UML Class Diagram </h4>

<h3> Concept OO </h3>
<h4> Encapsulation </h4>
<p align="justify">Encapsulation is the process of combining attributes and methods in one package and hiding the implementation of the data from the user of the object. Our system has 7 classes: ‘Expense’, ‘User’, ‘Name’, ‘Income’, ‘ActiveIncome’, ‘PassiveIncome’ and ‘Budget’.
</p>

# Expense Tracker Classes

## Class Definitions

```cpp
class Expense {
private:
    double spend;
    string date;
    string type;

public:
    // Constructor
    Expense(double s, string d, string t);

    // Getters
    double getSpend();
    string getDate();
    string getType();

    // Setters
    void setSpend(double s);
    void setDate(string d);
    void setType(string t);
};

class User {
private:
    Name name;
    Income* income;
    Expense* expense;
    int expenseCount;

public:
    // Constructor
    User(Name n);

    // Methods
    void setIncome(Income* inc);
    double getIncomeAmount();
    void addExpense(Expense* exp);
    void removeExpense(int index);
    int getExpenseCount();
    void dispUserName();
    void display();
    double getTotalExpenseByCategory(string category);
};

class Name {
private:
    string fname;
    string lname;

public:
    // Constructor
    Name(string fn, string ln);

    // Getters
    string getfname();
    string getlname();
};

class Income {
protected:
    double amount;
    string source;

public:
    // Constructor
    Income(double a, string s);

    // Getters
    double getAmount();
    string getSource();

    // Setters
    void setAmount(double a);
    void setSource(string s);

    // Virtual method
    virtual void display();
};

class ActiveIncome : public Income {
private:
    double salary;
    int otHour;
    double rate;

public:
    // Constructor
    ActiveIncome(double s, int o, double r, double a, string src);

    // Getters
    double getSalary();
    int getHour();
    double getRate();

    // Setters
    void setSalary(double s);
    void setHour(int h);
    void setRate(double r);

    // Methods
    void calcAmount();
    void display();
};

class PassiveIncome : public Income {
private:
    string type;

public:
    // Constructor
    PassiveIncome(double a, string tp, string src);

    // Getter
    string getType();

    // Setter
    void setType(string t);

    // Methods
    void setAmount(double a);
    void display();
};

class Budget {
private:
    double savingsGoal;
    double mFood;
    double mTransport;
    double mShopping;
    double mBills;
    double mEntertainment;
    double mHealthcare;
    double mEducation;
    double mGroceries;
    double mGift;
    double mOthers;
    Income* myIncome;

public:
    // Constructor
    Budget(Income* inc);

    // Methods
    void setIncome(Income* inc);
    void calcBudget();

    // Getters
    double getSavingsGoal();
    double getMoneyOnFood();
    double getMoneyOnTransport();
    double getMoneyOnShopping();
    double getMoneyOnBills();
    double getMoneyOnEntertainment();
    double getMoneyOnHealthcare();
    double getMoneyOnEducation();
    double getMoneyOnGroceries();
    double getMoneyOnGift();
    double getMoneyOnOthers();

    // Method to print budget
    void printBudget();
};
