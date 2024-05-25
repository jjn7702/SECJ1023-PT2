<h1 align="center"> Problem Analysis and Design </h1>
<h1> Content :star2: </h1>
<ul>
  <li><a href="#flowchart"> Flow Chart </a></li>
  <li><a href="#problemanalysis"> Problem Analysis </a></li>
  <li><a href="#classdiagram"> Class Diagram </a></li>
</ul>

<h2 id="flowchart"> Flow Chart </h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/d72d0cd0-d4c2-4742-ba21-978cf083611d"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/80005160-65bc-4fdd-92ca-4f581646cdef"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/9ae0f97d-a02f-4ff1-8330-dd9f6bfbdda3"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/b0984dae-b46c-4ae6-9673-e002e0902d9c"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/6925d0a5-426c-4664-babf-6c164f70462b"></img>

<h2 id="problemanalysis"> Problem Analysis </h2>
ii) class relationships


<style="text-decoration:underline"> Association Relationships </style>


1. Book and Publisher
Book and Publisher will have an aggregation relationship. The Book class holds a pointer to a Publisher object. A Book has a Publisher. The Publisher object is created outside the Book and is passed to it, showing a "has-a" relationship. Publisher can exist independently. If the Book object is destroyed, the Publisher object will not be destroyed. 


2. Booklist and Book
Booklist and Book will have an aggregation relationship. The Booklist class aggregates Book pointers, showing a "has-a" relationship, meaning booklist has a collection of books. Books can exist independently. If the Booklist object is destroyed, the Book object will not be destroyed. 


3. User and Booklist
User and Booklist will have a composition relationship. A User consists of a Booklist object, indicating that the Booklist cannot exist independently if no User. Booklist strongly depends on User. If the User object is destroyed, then the Booklist object is also destroyed. 


<u>Inheritance Relationships</u>
1. Book, Romance, Fantasy, SciFi
Inheritance among Book, Romance, Fantasy, and SciFi is suitable for representing an is-a relationship, where each specific genre is a type of book. Inheritance is used because it allows these specific genres to reuse common book attributes and methods defined in the Book class while also specifying their genre during instantiation.

<h2 id="classdiagram"> Class Diagram </h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/883f4a94-6eba-4e4d-a771-b7f136ef570f"></img>
