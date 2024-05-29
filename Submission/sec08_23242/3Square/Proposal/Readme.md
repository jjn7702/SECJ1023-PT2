### PROJECT PROPOSAL
---

**Synopsis and general idea**

The scholarship application system typically involves students who need financial help to support their education. 
Applicants usually need to submit their application form,the evidence  of  academic results and the award they received . 
The selection between the applicants will be chosen based on the academic performance , extracurricular activities and 
financial needs to determine whether they qualify for this scholarship or not.The system aims to provide the opportunity 
for students to complete their studies regardless of financial constraints . 

---
**Objective**

1) Student would not miss the scholarship 
2) Assigns scholarship that fulfill the requirements based on student’s information 
3) To encourage students to pursue higher education by providing financial support.

---
**How to use the system**

- User registration / login

    - User registration

      New user need to sign in by using the basic information such       
      as the name and email  in the scholarship application system 
      to create an account.
      
    - User profile management
    
      Users need to update their profile information which include age ,
      full name and profile picture.
      
- Home page
  <p></p>  
  After log in to the scholarship application system, students will come to the home page that include 2 options which 
  are merit based scholarship and need Based scholarship. Students are required to choose which scholarship they wish 
  to apply for.
    

- Meritbased scholarship
        
  Students are able to see the requirement of the merit based scholarship. The scholarship will be given based on 
  the merit we gained at the university .If the student merit is more than the merit targeted by the scholarship 
  organization, the applicant is available to get this scholarship.

- Needbased scholarship
  
  Students are able to see the requirement of need based scholarship. Need Based scholarship will given based on  
  the family income and category their income into B40,M40 and T20.
        
- Application form

  An application form will be provided to the students at the end and students can check whether the information that 
  they filled is correct.
    
- Application review

  System will check whether the information key in by the students are accurate. Any inaccurate data will cause the 
  application of the student to be withdrawn.
  
- Reporting

   The users would get different outputs based on the different information they key in. The merit based scholarship will 
   be given to the students based on their CGPA and merit. However, the need based scholarship will be given to students 
   based on family income group especially B40.
---

**Array of objects**

- Array: Applicant
  
  - Example:  Student applicant[100]
    
- Array: Award
  - Example : Scholarship award[4]
    - Merit + Under (75%)
    - Merit + Post (75%)
    - Need + Under (100%)
    - Need + Post (100%)
      
**Encapsulation**

Class: Student
Data: Name, Age, Family Income, Current CGPA, Contact
Method: enterDetails()


Class: Scholarship
Data: ScholarshipName, Amount
Method: amountReceive(), printEligible()


**Association**

<li>Aggregation</li>
<p></p>
<ul>
The contained objects are said to be part of the containing object, but they can exist independently of the containing object. If the containing object is destroyed, the contained objects are not automatically destroyed along with it.
</ul>


<li>Composition </li>
<p></p>
<ul>
An object of one class being contained within another class. The contained object is said to be a part of the containing object, and it cannot exist independently of the containing object. If the containing object is destroyed, the contained object is automatically destroyed along with it.
</ul>


**Inheritance**

<li>Base class: Student</li>

<li>Derived class: Undergraduate, Postgraduate</li>

<li>Base class: Scholarship</li>

<li>Derived class: MeritBase, NeedBased</li>
<p></p>

**Polymorphism**

<li>enterDetails() const override</li>

<li>Undergraduate</li>

<li>Postgraduate</li>

<li>printEligible()</li>

<li>Merit + Under (75%)</li>

<li>Merit + Post (75%)</li>

<li>Need + Under (100%)</li>

<li>Need + Post (100%)</li>

<li>Exception handling</li> 



