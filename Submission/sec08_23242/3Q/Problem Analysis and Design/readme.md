# Problem Analysis and Design 

- Flow Chart
- Problem Analysis
- Class Diagram

## Flow Chart

## Problem Analysis
1. Objects and Classes

Objects:
- User user
- Income income
- ActiveIncome activeIncome
- PassiveIncome passiveIncome
- Budget budget
- Expense expense
- Name name

Classes:
User
Attributes: 
-name: Name 
-income : Income*
-expenses : Expense*
-expenseCount : int
Methods:
-User(fname : string, lname : string ) : name(fname, lname)
-getIncome() : Income*
-getExpenseCount() : int
-display(user : User) : void
-getExpense() : Expense*

Name
Attributes:
-fname: string
-lname : string
Methods:
-getfname() : string
-getlname() : string
-getFullName() : string

Expense
Attributes:
-spend : double
-date : string
–type : string
Methods:
-Expense(s : double, d : string, t : string)
-getSpend() : double
-getDate() : string
-getType() : string

Income
Attributes:
-amount : double
-source : string
Methods:
-Income(a : double , s : string)
-getAmount() : double
-getSource() : string
-virtual display() : void

ActiveIncome
Attributes:
-salary : double
-othour : int
-rate : double
Methods:
-ActiveIncome(s : double, o : int, r : double, a : double, src : string) 
-getSalary() : double
-getHour() : int
-getRate() : double
-calcAmount() : void
-display() : void

Passiveincome 
Attributes:
-type : string
Methods:
-PassiveIncome(a : double, src : string, type : string)
-getType() : int
-display() : void

Budget
Attributes:
-savingGoal: double
-myIncome : Income*
Methods:
-Budget(inc : Income*)
-setIncome(inc : Income*) : coid
-calcBudget(): void
-printBudget()  : void






## Class Diagram

