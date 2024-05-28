### SECTION A : FLOW CHART


![Copy of pt draft3 drawio (1) drawio (1)-第 1 页 drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/379aeef1-56ae-4778-824c-5d8cf9c7e312)
![Copy of pt draft3 drawio (1) drawio (1)-Page-2 drawio (2)](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/90c1bfc4-e8cd-492d-9387-78e5fe8a34c4)
![Copy of pt draft3 drawio (1) drawio (1)-Page-3](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/37079d25-fe5d-495c-a20c-f59c4e3bc5c8)
![Copy of pt draft3 drawio (1) drawio (1)-Page-4](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/1edc8533-87fd-4f28-b18b-e978a890c350)

---
**SECTION A : DESCRIPTION OF PROCESS**

**Validate Email**
<ul>
<li>checkEmail (email)</li>
This is a function call to check whether the entered email address is in a valid format. The email of the student (string data type)  as a parameter of the function so that the email can pass to function and undergo validation.
  </ul>
  <ul>
<li>atPos = email.find("@")</li>
This is to find the position of ‘@’ character in an email.
    </ul>
    <ul>
<li>dotPos = email.find(".", atPos)</li>
This is to find the position of the ‘.’ character after the ‘@” character in the email address.
      </ul>
      <ul>
<li>if ((dotPos == -1) || (atPos == -1) || (dotPos < atPos))? </li>
This is to ensure that the email contains both ‘.’ and ‘@’ characters and also make sure that ‘.’appears after ‘@’. If the condition does not meet, the status will return false, meaning that the email is in a invalid format. Else, if the condition is met, the status will return to true, indicating that the email is in a valid format.  If the email is invalid, the system will request the applicant to re-enter the email. This is to ease the process for further communication with the applicant. 
</ul>

**Read Scholarship Type**
<ul>
<li>Print "Scholarship Type (1 or 2): 1 = Merit-based Scholarship, 2 = Need-based Scholarship"</li>
This is to prompt the applicant to enter the scholarship type that they want to apply. We use an integer to represent the type of scholarship as we want to ease the users to key in the data. On the other hand, we also want to ensure the data can be read by the compiler accurately to reduce error.
</ul>

  
**Merit-Based Scholarship Type**
<ul>
<li>There are 4 options to choose from if the users are applying for a merit-based scholarship. The users can press ‘a’ to apply for Petronas Scholarship, press  ‘b’ to apply to the Kuok Foundation, press ‘c’ to apply for the Bank Negara Malaysia Scholarship, press ‘d’to apply c. Bank Negara Malaysia Scholarship.</li>
</ul>

  
**Amount of scholarship that assigned to Merit-Based Scholarship applicants**
<ul>
 <li>If the applicant chooses a Merit-based scholarship, they are required to key in their CGPA for the system to evaluate.</li> 
<li>If the user gets a CGPA of 4.0 the applicant will be awarded the full course fee as the scholarship amount.</li> 
<li>If the CGPA is in range 3.67 to 3.99. The applicant will be awarded a scholarship with 75% of the course fee.</li> 
<li>On the other hand, if the applicant gets a CGPA in the range of 3.66 to 3.01. They will be awarded with 50% of course fee as scholarship amount. </li>
<li>If the applicant gets a CGPA less or equal 3.00, the system will reject the application as the applicant does not meet the minimum requirement. </li>
</ul>

  
**Apply for another scholarship**
<ul>
<li>Only the applicants who fail to receive the scholarship can apply for another scholarship type.</li> 
<li>After the applicants’ scholarship application has been rejected, the system willPrint "Do you need to apply for another scholarship's type?” (Y or N)</li>
<li>The system will read the applicants’ responses. </li>
<li>If the applicant presses ‘Y’ means that they wish to apply for another scholarship. Then, the process will loop back to allow for another application. </li>
<li>If the applicant presses ‘N’ means that they reject to apply for another scholarship. Then, the process will be over. This step is important because we wish the applicants to have a higher chance to receive the financial aid. </li>
</ul>


---
### SECTION B : PROBLEM ANALYSIS

**Part 1: Object and Classes**

Objects:
<li>Applicant</li>
<ul>
It represents the students who apply for the scholarship.
It contains an array that holds students’ personal details, academic information and finance status.
  </ul>
<li>Award</li>
<ul>
It represents the scholarship awarded to the students.
It contains an array that holds details on the type of scholarship that students get and coverage percentage.
</ul>

Class: 

<p><b>1. Student</b><br></p>
<p></p>&nbsp &nbsp Attributes:</p>
<ul>
  <li>familyIncome: int</li>
  <li>cgpa: double</li>
  <li>courseFee: double</li>
  <li>yearOfStudy: int</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li>Student(int, double, double, int)</li>
  <li>apply(Scholarship): void</li>
  <li>printDetails(): virtual void</li>
</ul>

<p><b>2. StudentInfo</b><br></p>
<p></p>&nbsp &nbsp Attributes:</p>
<ul>
  <li>name: string</li>
  <li>age: int</li>
  <li>studentID: string</li>
  <li>email: string</li>
  <li>contactNum: string</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li>Information(string, int, string, string, string)</li>
  <li>getName(): string</li>
  <li>getAge(): int</li>
  <li>getStudentID(): string</li>
  <li>getEmail(): string</li>
  <li>getContactNum(): string</li>
  <li>checkEmail(): string</li>
</ul>

<p><b>3. Scholarship</b><br></p>
<p>&nbsp &nbsp Attributes:</p>
<ul>
  <li>scholarshipType: int</li>
  <li>applicationStatus: string</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li> Scholarship (int, string)</li>
  <li> updateStatus(): string </li>
  <li> scholarshipInfo(): virtual void </li>
  <li> amountReceive(_fee): virtual int</li>
</ul>

<p><b>4. Undergraduate </b><br>
<p> &nbsp &nbsp Methods:</p>
<ul>
  <li> Undergraduate (int)</li>
  <li> printDetails(): void </li>
</ul>

<p><b>5. Postgraduate </b><br>
&nbsp &nbsp Attributes:</p>
<ul>
  <li>degreeProgram: string</li>
</ul>

<p> &nbsp &nbsp Methods:</p>
<ul>
  <li> Postgraduate(int, string) </li>
  <li> printDetails(): void </li>
</ul>

<p><b>6. MeritBased </b><br>
<p> &nbsp &nbsp Methods:</p>
<ul>
  <li> amountReceive(_fee): int </li>
  <li> scholarshipInfo(): void </li>
</ul>

<p><b>7. NeedBased </b><br>
<p> &nbsp &nbsp Methods:</p>
<ul>
  <li> amountReceive(_fee): int </li>
  <li> scholarshipInfo(): void </li>
</ul>

**Part 2: Class Relationship**

**Association:** <p align="justify">
   - Relationships between Student and Scholarship could be done by aggregation. This is because a Student can have a Scholarship but Scholarship does not necessarily need to have a Student. 
   - Relationships between Student and StudentInfo could be done by composition. This is because an StudentInfo consists of Student, when a StudentInfo object is created, the Student is also created.
</p>

**Inheritance:** <p align="justify">
   - Base Class : Student  
     Derived Class: Undergraduate, Postgraduate  
     Undergraduate and Postgraduate class inherits from Student class because an undergraduate student and postgraduate student are a special type of student. They are having a  “is a” relationship as an undergraduate student is a student and the postgraduate student is also a student. By inheriting from students, both undergraduate and postgraduate classes can reuse common attributes and methods from student class while they can also create additional methods to specify their own class.
   - Base Class : Scholarship  
       Derived Class: MeritBased, NeedBased  
       NeedBased and MeritBased classes inherit from Scholarship because need-based and merit-based are both specific types of scholarship. Three of the classes have the same criteria which are related to financial need. Thus, by inheriting, both MeritBased and NeedBased classes can use the same attribute and method of Scholarship class and they can add some method to specify their class. This ensures different types of scholarships are organized under a common hierarchy and ensure that they are easy to manage.


</p>















---
### SECTION C : CLASS DIAGRAM
![uml diagram pt2 drawio (1)](https://github.com/jjn7702/SECJ1023-PT2/assets/148684518/6e5e6d88-a8d3-4509-8bf6-cf9441d714f0)

