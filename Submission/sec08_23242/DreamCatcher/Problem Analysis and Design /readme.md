<p align="center">
  <img src="." width="90" height="90">
</p>

<h1>Sleep Cycle Analyzer - </h1>
<h1>Problem Analysis and Design 💡</h1>
<h2>Table of Contents 🧾 </h2>
  <li> Section A: Flowchart </li>
  <li> Section B: Problem Analysis </li>
  <li> Section C: UML Class Diagram </li>

<h2> Section A: Flowchart </h2>
  <br />
    <img src =https://github.com/jjn7702/SECJ1023-PT2/assets/150900178/056c1c23-4c10-45cf-bfaf-24193e629c00>
  <br />
<h2> Section B: Problem Analysis 📝 </h2>
<h3> Objects and Classes </h3>
<h4> 1. Objects：</h4>
 
The user act as an object. When a new user is created, a new object is created. Thus, inside our program we have multiple objects for multiple class such as:
    <li> ```NewUser currentUser;```</li>
    <li> ```NewUser tempUser(username,"");``` </li> 
    <li> ```Time timeInstance;``` </li>
    <li> ```Music m1;``` </li> 
    
  </ul>
<h4> 2. Classes: </h4>

The following classes in involved in the project: 
<br />
  i. User class  
    <ul>
     <li> This class have two protected data which is username and password. </li>
     <li> Get the input from the user and store it by using mutator functions.</li>
    </ul>
    
     void setUsername(string _username) { username = _username;}
     void setPassword(string _password) { password = _password;}
    
  ii. NewUser class 
    <ul>
  <li> 
      This class include get input from the user and store the private data by using mutator functions. 
  </li>
    </ul>
    
      void setAge(int _age) { age = _age;}
      void setGender (char a) { gender = a;)
      void setHeight(double _height) { height = _height;}
      void setWegiht(double _weight) { weight = _weight}

  <li> 
      We also applied excecption handling for the user’s password. The user have to double confirm the password.
  </li> 
    
      void samePassword(const std::string& password1, const std::string& password2) {
          if (password1 != password2) {
              throw stf::invalid_argument("Passwords do not match ! ");
          }
      }

    <li>
      We also do exception handling about the length of the user’s password if the length of the password is less than 8 characters.
    </li>
  
      void checkPassword(const srd::straight password){
          if (password.length() < 8) {
              throw stf::invalid_argument("Password musy be at least 8 characters long! ");
          }
      }
      
  iii. Time class 
    <ul>
      <li> In this class, we multiple attributes to calculate the duration of time that the sleep cylce of the user.</li>
    </ul>
  iv. Data class 
    <ul>
      <li>Inside the data class, we have the accessor and the mutator.</li>
      <li>And the function to analayze the sleep which receive the sleep time as parameter.</li>
      <li>Beside, we also have the function to display the result after analyzing.</li>
    </ul>
  v. Music class 
    <ul>
      <li> Inside the Music class, we have two string to store name of the music and the url of the music.</li>
      <li>The use of accessor and mutator enable developer to access and change the attributes even outside the class. </li>
    </ul>
  vi. FavM class 
    <ul>
      <li> In FavM, we have array to save the user defined music and function to display it.</li>
  </ul>
  <br />
<h3> Relationship between classes: </h3>
      <h4> 1. User class and NewUser class -- Inheritance</h4>
    <ul>
      User class is is a general class with basic user attributes where NewUser class is a more specific class that inherits from User time, adding additional personal details for example weight and height. Thus, NewUser is a User. 
    </ul>
      <h4> 2. Data class and Time class -- Aggregation</h4>
    <ul>
      User object has a Time object because when we create the existence of user object and time object are independent. One of them destroyed will not affect the other one. We set this relationship is because the user can work independently without the time class and vice versa. This Time object doesn’t affect the user object, we just use the Time object to calculate the duration of the cycle by using the input data (start date and end date of cycle). Thus, it doesn’t require to destroy Time object when the User object destroy. 
    </ul>
      <h4> 3. NewUser class and Data class -- Composition </h4>
    <ul>
      NewUser object consists of Data object, both are dependent. When Data class object is destroyed. The NewUser object will also be destroyed. The data object cannot work independently without the presence of use object. We established this relationship to protect the data of the new user, and the data class object requires attributes from the new user to generate the sleep cycle report. 
    </ul>
      <h4> 4. NewUser class and Music class -- Aggregation </h4>
    <ul>
      NewUser object has a Music object. When the newuser object is destroyed, the Music object doesn’t affect. This is because the Music object provides a list of music tracks that help the user fall asleep faster and doesn’t require any data from the new user. Since the user able to add their favorite music but this is directly added to the music library. That means that when the newuser added musics the other newuser will share the same library. Thus, the Music cannot be destroyed when the newuser object destroyed. 
    </ul>
      <h4> 5. Music class and FavM class -- Inheritance </h4>
    <ul>
      FavM class is a Music class. It enable the user to add their favourite music into the program. Instead of there are only 10 classical music in the Music class, user can add up to 50 new music in the FavM class. This two classs is inheritance because the FavM class will print out the classical music in the Music class byu using polymorphiosm method and addition printing the user defined music. 
    </ul>
<h2> UML Class Diagram 💻</h2>
<img src= https://github.com/jjn7702/SECJ1023-PT2/assets/150900178/ad4ee6aa-53e6-4317-8ec7-6815a7b9524d>

