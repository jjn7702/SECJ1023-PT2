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
 
The user act as an object. When a new user is created, a new object is created. Thus, inside program,there are  multiple objects for multiple class such as:
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

  <ul>
  <li> 
      Excecption handling for the user’s password. The user have to double confirm their password.
  </li>
  </ul>
    
      void samePassword(const std::string& password1, const std::string& password2) {
          if (password1 != password2) {
              throw stf::invalid_argument("Passwords do not match ! ");
          }
      }

  <ul>
  <li>
      Exception handling about the length of the user’s password if the length of the password is less than 8 characters.
  </li>
  </ul>
  
      void checkPassword(const srd::straight password){
          if (password.length() < 8) {
              throw stf::invalid_argument("Password musy be at least 8 characters long! ");
          }
      }
      
  iii. Time class 
  <ul>
  <li> In this class, there are multiple attributes to calculate the duration of time that the sleep cylce of the user.</li>
  </ul>

      protected:
          int shour, sminute, ehour, eminute;
          int averageSleepMinute;
          int startTimes [30][2];
          int endTimes [30][2];
    
  iv. Data class 
  <ul>
  <li>
    Inside the data class, there are the accessor and the mutator.
  </li>
  </ul>

      void setCategory(char _category) { category = _category;}
      char getCategory() { return category;}

  <ul>
  <li>
    And the function to analayze the sleep which receive the sleep time as parameter.
  </li>
  </ul>

      void analyzeSleep(int);
  
  <ul>
  <li>
    Beside, also have the function to display the result after analyzing.
  </li>
  </ul>

      void calculateSleepDiff(int);
  
  v. Music class 
  <ul>
  <li> 
    In this class, there are two string to store name and the url of the music.
  </li>
  <li>
    The use of accessor and mutator enable developer to access and change the attributes even outside the class. 
  </li>
  </ul>
  
      string clist[N];
      string urlcList[N];
  
  vi. ClassicalM class 
  <ul>
  <li> 
    There is an extra attribute compare to Music class which is the composer of the classical music. There are 10 classical music that aid the user to sleep.
  </li>
  </ul>

      
  
  vi. WhiteNoise class 
  <ul>
  <li>
    There are 10 white noise that predefined in the program. Same as ClassicalM class, there is an extra attribute to store the type of the white noise.
  </li>
  </ul>


  
  vi. FavM class 
  <ul>
  <li> 
    The FavM class is used to store the user defined music and there are an extra attribute more than the parent class which is the type of Music such as classical, white noise or so on fot the user to enter.
  </li>
  </ul>

      string userM[N];

      void dispClist(){
 
<h3> Relationship between classes: </h3>
      <h4> 1. User class and NewUser class -- Inheritance</h4>
    <ul>
    <li>
      User class: a general class with basic user attributes
    </li>
    <li>
      NewUser class: a more specific class that inherits from User time, and adding addtional personal details.
    </li> 
    </ul>
      <h4> 2. Data class and Time class -- Aggregation</h4>
    <ul>
    <li>
      User object has a Time object. It is because both of them are independent when we create the existence of them. One of them destroyed will not affect the other one.
    </li>
    <li>
      This relationship is to allowed the user work independently without time class and vise versa.
    </li>
      <li>
        We use Time object to calculate the duration of cycle by using input data (start and end date of cycle). 
      </li>
    </ul>
      <h4> 3. NewUser class and Data class -- Composition </h4>
    <ul>
    <li>
    </li>
      NewUser object consists of Data object, both are dependent. When Data class object is destroyed. The NewUser object will also be destroyed. The data object cannot work independently without the presence of use object. We established this relationship to protect the data of the new user, and the data class object requires attributes from the new user to generate the sleep cycle report. 
    </ul>
      <h4> 4. NewUser class and Music class -- Aggregation </h4>
    <ul>
      NewUser object has a Music object. When the newuser object is destroyed, the Music object doesn’t affect. This is because the Music object provides a list of music tracks that help the user fall asleep faster and doesn’t require any data from the new user. Since the user able to add their favorite music but this is directly added to the music library. That means that when the newuser added musics the other newuser will share the same library. Thus, the Music cannot be destroyed when the newuser object destroyed. 
    </ul>
      <h4> 5. Music class and ClassicalM class -- Inheritance </h4>
    <ul>
      ClassicalM class is a Music class. This class are use to store and display the classical Music list that predefined in the program. This class inherit the both string that uses to contain the name of the classical music and the link to hyperlink to the classical music from the music class.
      </ul>
      <h4> 6. Music class and FavM class -- Inheritance </h4>
    <ul>
      FavM class is a Music class. It enable the user to add their favourite music into the program. Instead of there are only 10 classical music in the Music class, user can add up to 50 new music in the FavM class. This two classs is inheritance because the FavM class will print out the classical music in the Music class byu using polymorphiosm method and addition printing the user defined music. 
    </ul>
<h2> UML Class Diagram 💻</h2>
<img src= https://i.im.ge/2024/06/02/K0zHo9.DreamCatcherUMLDiagram.jpeg>

