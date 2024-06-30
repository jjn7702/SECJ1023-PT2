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

<p align = "center">
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/148413538/c4ecd364-63dd-4c62-8a58-877cb4bb8af2" width ="800">
</p>


<h3> Concept OO </h3>
<h4> Encapsulation </h4>
<p align="justify">Encapsulation is the process of combining attributes and methods in one package and hiding the implementation of the data from the user of the object. Our system has 7 classes: ‘Expense’, ‘User’, ‘Name’, ‘Income’, ‘ActiveIncome’, ‘PassiveIncome’ and ‘Budget’.
</p>


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

```

<h4> Composition  </h4>
<p align="justify">
Composition is a restricted version of aggregation in which the enclosing and enclosed objects are highly dependent on each other. In our system, we are implementing this concept in 
</p>
<h5><b>User consists of Name</b><br></h5>
<p align="justify">
‘User’ contains ‘Name’. This means that ‘Name’ objects are part of the ‘User’, and if the ‘User’ object is destroyed, its ‘Name’ objects are also destroyed. A ‘User’ must have a ‘Name’, else the user is           not existing.</p>

```c++
class User {
    Name name; //Composition
    Income *income; 
    Expense *expense[100]; 
    int expenseCount;
};

```

<h4> Aggregation </h4>
<p align="justify">
Aggregation is a special type of association which is one way relationship. It models a 'has a' relationship between classes. The existence of the objects are independent. It is a concept of objects contain pointer to other object.
</p>
<h5><b>User has an Expense and Income</b><br></h5>
<p align="justify">
‘User’ has an 'Expense', this indicates that 'Expense' can exist independently without 'User'.<br>
Same goes to class 'User' and class 'Income'. 'User' has an 'Income' and 'Income' can exist without 'User'
</p>

```c++
class User {
    Name name; 
    Income *income; //Aggregation
    Expense *expense[100]; //Aggregation
    int expenseCount;
};

```
<h5><b>Budget has an Income</b><br></h5>
<p align="justify">
‘Budget’ has an 'Income', meaning income can exist despite no 'Budget'. 
</p>
    
```c++
class Budget {
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
    Income *myIncome; //Aggregation
};

```
<h4> Inheritance </h4>
<p align="justify">
Inheritance provides a way to create a new class from an existing class. The new class is a specialized version of the existing class. Derived classes can inherit attributes and methods from other classes, and add extra attributes and methods of its own. It is used to share commonality between two or more classes and extend the functionality of an existing class. <br>
In our system, we have parent class 'Income' and child classes 'ActiveIncome' and 'PassiveIncome'. Both child classes inherit the attributes and methods from the parent class and also has extra attributes an methods of their own. The attributes in parent class 'Income' are protected so that they are accessible by the child classes.
</p>

```cpp
class Income {
protected:
    double amount;
    string source;
public:
    Income(double a = 0, string s = "");
    double getAmount() const;
    string getSource() const;
    void setAmount(double a);
    void setSource(string s);
    virtual void display() const;
};

class ActiveIncome : public Income {
    double salary;
    int otHour;
    double rate;
public:
    ActiveIncome(double s = 0, int o = 0, double r = 0, double a = 0.0, string src = "Active Income");
    double getSalary() const;
    int getHour() const;
    double getRate() const;
    void setSalary(double s);
    void setHour(int h);
    void setRate(double r);
    void calcAmount();
    void display() const override;
};

class PassiveIncome : public Income {
    string type;
public:
    PassiveIncome(double a = 0.0, string tp = "", string src = "Passive Income");
    string getType() const;
    void setType(string t);
    void setAmount(double a);
    void display() const override;
};

```
<h4> Polymorphism  </h4>
<p align="justify">
Polymorphism is the ability of objects to perform the same actions differently. It is a concept that extends from inheritance. In our system, we have a parent class Income, and child classes PassiveIncome    and ActiveIncome. In the parent class Income, we have a display method, and the same method is also defined in the child classes PassiveIncome and ActiveIncome. We apply this concept by adding the ‘virtual’ keyword to the display method in the Income class, which allows derived classes to override this method to provide their own specific implementation.
</p>

```cpp
class Income {
protected:
    double amount;
    string source;
public:
    Income(double a = 0, string s = "");
    double getAmount() const;
    string getSource() const;
    void setAmount(double a);
    void setSource(string s);
    virtual void display() const;// Polymorphism
};

class ActiveIncome : public Income {
    double salary;
    int otHour;
    double rate;
public:
    ActiveIncome(double s = 0, int o = 0, double r = 0, double a = 0.0, string src = "Active Income");
    double getSalary() const;
    int getHour() const;
    double getRate() const;
    void setSalary(double s);
    void setHour(int h);
    void setRate(double r);
    void calcAmount();
    void display() const override;
};

class PassiveIncome : public Income {
    string type;
public:
    PassiveIncome(double a = 0.0, string tp = "", string src = "Passive Income");
    string getType() const;
    void setType(string t);
    void setAmount(double a);
    void display() const override;
};

```
<h4> Array of objects </h4>
We use an array of objects to store similar data items. For example, in the main function, we declare an array pasIncome with a maximum size of 100 to store up to 100 user's passive income. Additionally,  within the User class, we declare an array of pointers expense with a maximum size of 100 to store pointers to Expense objects. Both of the objects have different functions where the pasIncome array is declared in the main function for object initialization, while the expense array is declared in the User class to show aggregation.<br><br>
1) Array to store list of passive income
        
```cpp
int main() {
    Income income;
    ActiveIncome activeIncome;
    PassiveIncome passiveIncome;
    PassiveIncome pasIncome[100]; //Array of Object
```

```cpp
do{
        cout << "What is the passive income type : ";
        cin >> type;
        cout << "Enter passive income amount     : ";
        cin >> value; 

        while(value<=0){
            cout << "***Please re-enter your passive income and make sure it is more than 0***\n\n";
            cout << "Enter passive income amount     : ";
            cin >> value; 
        }

        pasI[count].setType(type);
        pasI[count].setAmount(value);
        count++;
        total+=value;
        clearScreen();
        cout << "Do you wish to continue entering your passive income? (press Y/y for yes) : ";
        cin >> input;
        cout << endl;
    }while(input == 'y' || input == 'Y');
```
<br>
2) Array to store list of expenses

   - in user class
   
   ```cpp
   class User {
    Name name; 
    Income *income; 
    Expense *expense[100]; //Array of object pointer
    int expenseCount;
    public:
        void addExpense(Expense *exp);
   ```
   - in main function

```cpp
     user.addExpense(new Expense(value, date, category));  
```

        
<h4> Exception handling </h4>
When executing C++ code, different errors can occur, coding errors made by programmers due to wrong input or other unforeseeable things. Exception handling is important to make sure the system is able to deal with errors that occur when we run the system. In our system, we mainly apply this concept when there is an error and to display an error message by using the concept of try, throw and catch.

1) Exception to verify the date format

   ```c++
   do {
       cout << "Enter date (YYYY-MM-DD): ";
       cin >> date;
       try {
           if (isValidDateFormat(date) == false) {
               throw "Invalid date format!\n";
           }    
       }
       catch (const char *msg) {
           cout << msg;
       }
       } while (isValidDateFormat(date) == false);
   ```
2) Exception to verify the index entered

   ```c++
   try{
    if (wrong < 2) {
        throw "Invalid choice. Please try again.\n";
    }
    
    catch (const char *msg){
        cout << msg << endl;
    }            
    }
   ```
