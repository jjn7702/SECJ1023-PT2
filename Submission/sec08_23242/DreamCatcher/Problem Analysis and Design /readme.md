<p align="center">
  <img src="." width="90" height="90">
</p>

# Sleep Cycle Analyzer
# Problem Analysis and Design
## Table of Contents
- [A: Flowchart](#A:Flowchart)
- [B: Problem Analysis](#B:Problem-Analysis)
- [C: UML Class Diagram](#C:UML-Class-Diagram)
- 
### A:Flowchart 
![Flowchart](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/DreamCatcher/Problem%20Analysis%20and%20Design/flowchart(updated).jpg)

### B:Problem Analysis 
- #### Objects and Classes
##### 1. Objects：
The user act as an object. When a new user is created, a new object is created. Thus, inside our program we have multiple objects for multiple class such as:
- 'NewUser currentUser;'
- 'NueUser tempUser(username,"");'
- 'Time timeInstance;'
- 'Music m1;'

##### 2. Classes
The following classes in involved in the project:
- `User class`
  In User class, there two protected data which is username and password. We get the input from the user and store it by using mutator functions. 
- `NewUser class`
  Inside the NewUser class, we include get input from the user such as name, gender, weight and height, store the private data by  using mutator functions.
  In this class, we also applied excecption handling for the user’s password. We let the user to double confirm the password.
  We also do exception handling about the length of the user’s passwor.  If the length of the password is less than 8 characters 
- `Time class`
  In this class, we multiple attributes to calculate the duration of time that the sleep cylce of the user. 
- `Data class`
  Inside the data class, we have the accessor and the mutator
  And the function to analayze the sleep which receive the sleep time as parameter
  Beside, we also have the function to display the result after analyzing 
- `Music class`
  Inside the Music class, we have two string to store name of the music and the url of the music.
  The use of accessor and mutator enable developer to access and change the attributes even outside the class 
- `FavM class`
  In FavM, we have array to save the user defined music and function to display it.

- #### Relationship between classes:
##### 1. User class and NewUser class -- Inheritance
User class is is a general class with basic user attributes where NewUser class is a more specific class that inherits from User time, adding additional personal details for example weight and height. Thus, NewUser is a User. 

##### 2. Data class and Time class -- Aggregation
User object has a Time object because when we create the existence of user object and time object are independent. One of them destroyed will not affect the other one. We set this relationship is because the user can work independently without the time class and vice versa. This Time object doesn’t affect the user object, we just use the Time object to calculate the duration of the cycle by using the input data (start date and end date of cycle). Thus, it doesn’t require to destroy Time object when the User object destroy. 

##### 3. NewUser class and Data class -- Composition 
NewUser object consists of Data object, both are dependent. When Data class object is destroyed. The NewUser object will also be destroyed. The data object cannot work independently without the presence of use object. We established this relationship to protect the data of the new user, and the data class object requires attributes from the new user to generate the sleep cycle report. 

##### 4. NewUser class and Music class -- Aggregation 
NewUser object has a Music object. When the newuser object is destroyed, the Music object doesn’t affect. This is because the Music object provides a list of music tracks that help the user fall asleep faster and doesn’t require any data from the new user. Since the user able to add their favorite music but this is directly added to the music library. That means that when the newuser added musics the other newuser will share the same library. Thus, the Music cannot be destroyed when the newuser object destroyed. 

##### 5. Music class and FavM class -- Inheritance 
FavM class is a Music class. It enable the user to add their favourite music into the program. Instead of there are only 10 classical music in the Music class, user can add up to 50 new music in the FavM class. This two classs is inheritance because the FavM class will print out the classical music in the Music class byu using polymorphiosm method and addition printing the user defined music. 

### C:UML Class Diagram 

![UML diagram](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/DreamCatcher/Problem%20Analysis%20and%20Design/DreamCatcherUMLDiagram.jpg)

