# Problem Analysis and Design 

- Flow Chart
- Problem Analysis
- Class Diagram

## Flow Chart

## Problem Analysis

### I. Objects and Classes

**Objects:**
<ul>
  <li>User user</li>
  <li>Income income</li>
  <li>ActiveIncome activeIncome</li>
  <li>PassiveIncome passiveIncome</li>
  <li>Budget budget</li>
  <li>Expense expense</li>
  <li>Name name</li>
</ul>

**Classes:**

<p><b>1. User</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>name: Name</li>
  <li>income : Income*</li>
  <li>expenses : Expense*</li>
  <li>expenseCount : int</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li>User(fname : string, lname : string ) : name(fname, lname)</li>
  <li>getIncome() : Income*</li>
  <li>getExpenseCount() : int</li>
  <li>display(user : User) : void</li>
  <li>getExpense() : Expense*</li>
</ul>

<p><b>2. Name</b><br>
Attributes:</p>
<ul>
  <li>fname: string</li>
  <li>lname : string</li>
</ul>

<p>Methods:</p>
<ul>
  <li>getfname() : string</li>
  <li>getlname() : string</li>
  <li>getFullName() : string</li>
</ul>

<p><b>3. Expense</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>spend : double</li>
  <li>date : string</li>
  <li>type : string</li>
</ul>

<p>&nbsp &nbsp Methods:</p>
<ul>
  <li>Expense(s : double, d : string, t : string)</li>
  <li>getSpend() : double</li>
  <li>getDate() : string</li>
  <li>getType() : string</li>
</ul>

<p><b>4. Income</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>amount : double</li>
  <li>source : string</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li>Income(a : double , s : string)</li>
  <li>getAmount() : double</li>
  <li>getSource() : string</li>
  <li>virtual display() : void</li>
</ul>

<p><b>5. ActiveIncome</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>salary : double</li>
  <li>othour : int</li>
  <li>rate : double</li>
</ul>

<p>&nbsp &nbsp Methods:</p>
<ul>
  <li>ActiveIncome(s : double, o : int, r : double, a : double, src : string)</li>
  <li>getSalary() : double</li>
  <li>getHour() : int</li>
  <li>getRate() : double</li>
  <li>calcAmount() : void</li>
  <li>display() : void</li>
</ul>

<p><b>6. Passiveincome</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>type : string</li>
</ul>

<p>&nbsp &nbsp Methods:</p>
<ul>
  <li>PassiveIncome(a : double, src : string, type : string)</li>
  <li>getType() : int</li>
  <li>display() : void</li>
</ul>

<p><b>7. Budget</b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>savingGoal: double</li>
  <li>myIncome : Income*</li>
</ul>

<p>&nbsp &nbsp Methods:</p>
<ul>
  <li>Budget(inc : Income*)</li>
  <li>setIncome(inc : Income*) : void</li>
  <li>calcBudget(): void</li>
  <li>printBudget() : void</li>
</ul>

### II. Class relationships


### Association

**Aggregation:**

1. **User has an Income**
   - ‘User’ and ‘Income’ are independent where a ‘User’ may not have ‘Income’. The ‘User’ class uses ‘Income’ to get the user’s income details. The ‘Income’ object can be shared or changed without affecting the ‘User’ class.

2. **Budget has an Income**
   - ‘Budget’ and ‘Income’ are independent where the budget may not have ‘Income’. The ‘Budget’ class uses the ‘Income’ class to calculate the budget. If the ‘Budget’ is destroyed, ‘Income’ remains unaffected. A ‘User’ that has an income does not necessarily have a budget.

3. **User has an Expense**
   - ‘User’ and ‘Expense’ are independent where a user may not have expenses.

**Composition:**

1. **User consists of Name**
   - ‘User’ contains ‘Name’. This means that ‘Name’ objects are part of the ‘User’, and if the ‘User’ object is destroyed, its ‘Name’ objects are also destroyed. A ‘User’ must have a ‘Name’, else the user is not existing.

### Inheritance

**Parent Class:** Income
- We chose Income as the parent class because it contains the attributes amount and source which are common to all types of income.

**Child Classes:**

1. **ActiveIncome**
   - ActiveIncome is a specific type of income that comes with additional attributes and methods that are unique. It inherits the Income to gain the common properties but also adds its specific attributes and methods. We update the amount in the Parent Class using the attributes inside the derived class (ActiveIncome) such as salary, otHours, and rate.

2. **PassiveIncome**
   - PassiveIncome is a specific type of income that comes with additional attributes and methods that are unique. It inherits the Income to gain the common properties but also adds its own specific attributes and methods. We can display the amount in the Parent Class (that is updated in the User class’s constructor using a for loop to calculate the total passive income).





## Class Diagram

