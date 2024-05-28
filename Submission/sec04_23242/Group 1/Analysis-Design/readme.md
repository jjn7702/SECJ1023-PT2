# PROJECT PROPOSAL GROUP 1
## TOPIC: Book Recommendation System

### Table of Contents
- **Section A: Flow Chart**
- **Section B: Problem Analysis**
- **Section C: Class Diagram**

## Flow Chart
<image src = "Image/FlowChart.jpeg">
  
### Main process of the system
  
> __i) User Authentication:__
  - Users input their login credentials
  - The system compares the user credentials with the database records
  - If the credentials match, the user is authenticated and granted access; otherwise, they are prompted to re-enter credentials.

> __ii) Book Type Selection:__
  - Authenticated users are prompted to choose the type of book: Fiction or NonFiction.
  - Based on the user's choice, the system proceeds to the genre selection process.

> __iii) Genre Selection:__
  - For Fiction books, users can choose from genres like Action, Romance, and Mystery.
  - For NonFiction books, users can choose from genres like Religion, Philosophy, and Biography.
    
> __iv) Book Display:__
  - Based on the selected genre, the system displays a list of books including their name, author, and ratings.

> __v) Book Selection:__
  - Users can select a book from the displayed list.
  - The system checks for more information about the selected book in the database and displays detailed information including name, type, genre, author, year published, publisher details, and ratings.

> __vi) System Reuse Decision:__
  - Users are asked if they want to use the system again.
  - Based on the user's input (Yes/No), the system either restarts the process or exits.
    
## Problem Analysis

#### i) Objects and then the classes involved in the project.

|No| Class                      | Attribute          | Method       |
|-----|----------------------------|--------------------|--------------|
|1|Book           |name, author|Book(), print()|
|2|Fiction (inherits from Book)|genre (Action, Romance, Mystery)|displayFictionBooks()|
|3|NonFiction (inherits from Book)|genre (Religion, Philosophy, Biography)|displayNonFictionBooks()|
|4|Author|authorName, fictionBook,nonFictionBook|printAuthor()|
|5|Ratings|numRatings, averageRate|Ratings(),printRatings()|
|6|Publish|publishmentDetails, year|Publish(),printPublishDetails()|

#### ii) Identify class relationships.

> __1) Association Relationships__
- **Composition**

**1. Book and Author:** Event class has an attribute of organizer of type Organizer. 
Justification: Every book has an author, and displaying the author's details is necessary for users to make informed choices. Hence, an association relationship is appropriate

**2. Book and Ratings:** Event class has an attribute of participant list of type Participant. 
Justification: Ratings influence user choices, making them a vital part of book information. Associating books with their ratings helps display comprehensive book details.

**3. Book and Publish:** User class has an attribute profile of type Profile. 
Justification: Publication details are part of the book's information that users need. Associating these details with the book ensures that all relevant information is displayed.

> __2) Inheritance Relationships__

**1. Book (superclass) and Fiction(subclass)**
Justification: Fiction common features but differ in their specific genres.Inheritance allows reuse of common attributes and methods while enabling specialisation for different book types.

**2. Book (superclass) and NonFiction (subclass)**
Justification: NonFiction books share common features but differ in their specific genres.Inheritance allows reuse of common attributes and methods while enabling specialisation for different book types.


> __3) Class Diagram Justification__

**Book as a Base Class**: Since both Book can be divide into two different types Fiction and Non Fiction, it is a good practice to make Book as the base class
  
**Fiction and Non Fiction**: Inheriting from Book allows them to use similar code function
  
**Association Relationship**: These relationships between Author, Publish, and Ratings with the book shows what important things that need to be include when making a well Book Recommendation System.


## 🧾 Class Diagram 🗂️

<image src = "Image/UMLdiagram.png">
