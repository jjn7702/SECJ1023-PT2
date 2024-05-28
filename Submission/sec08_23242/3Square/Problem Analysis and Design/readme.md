### SECTION A : FLOW CHART


![Copy of pt draft3 drawio (1) drawio (1)-第 1 页 drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/379aeef1-56ae-4778-824c-5d8cf9c7e312)
![Copy of pt draft3 drawio (1) drawio (1)-Page-2 drawio (2)](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/90c1bfc4-e8cd-492d-9387-78e5fe8a34c4)
![Copy of pt draft3 drawio (1) drawio (1)-Page-3](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/37079d25-fe5d-495c-a20c-f59c4e3bc5c8)
![Copy of pt draft3 drawio (1) drawio (1)-Page-4](https://github.com/jjn7702/SECJ1023-PT2/assets/152403691/1edc8533-87fd-4f28-b18b-e978a890c350)

---
**SECRION A : DESCRIPTION OF PROCESS**

---
### SECTION B : PROBLEM ANALYSIS
**2.Class Relationship**

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

