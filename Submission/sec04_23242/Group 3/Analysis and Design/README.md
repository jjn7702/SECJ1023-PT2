<!DOCTYPE html>
<html>

<body class="stackedit">
  <div class="stackedit__html"><h1 id="section-a-flowchart">Section A: Flowchart</h1>
    <img src="../Proposal/Image/PT2.png" width="9300" height="1000">
    Food Allergy System is a system that will save your life by detecting potential allergens found in your immune system. The system will first ask the user for their informations, such as their Name, Gender and Age. After that, the system will prompt a menu where the user has 5 options which is: "Ingredients", "Allergy", "Information", "About Us" and "Exit". The user is required to insert the options. If the user chooses Ingredients, the system will then give you another option whether you want to add ingredients or remove ingredients. If the user chooses Allergy in the menu section, the system will use the ingredients and then try to match the ingredients with the potential allergens and alert the user if there is any potential allergies. By going to the Information part, the user can see their information such as their name, gender, age, ingredients and allergy. For the About Us section, the system will display the information of the developers. Lastly the user can exit the system by choosing the exit option.
  </img>

<h1 id="section-b-problem-analysis">Section B: Problem Analysis</h1>

<table>
<thead>
<tr>
<th>Class</th>
<th>Attributes</th>
<th>Method</th>
</tr>
</thead>
<tbody>
<tr>
<td>User</td>
<td>-Name
<br>-Age
<br>-Gender</td>
  <td>-inputName<br>-inputGender<br>-inputAge </td>
        </tr>
</tr>
<td>Ingredient</td>
<td>-Array of ingredient
<br>-IngredientCount</td>  
  <td>-inputIngredient<br>-countIngredient</td>
        </tr>
<tr>
<td>Allergy</td>
<td>-Array of Allergy
<br>-Ingredient form class Ingredient
<br>-Array of Status Allergy</td>
  <td>-statusAllergy</td>
        </tr>
  <tr>
<td>Alert</td>
<td>-Allergy from class Allergy</td>
  <td>-notificationAlert</td>
        </tr>
  <tr>
        <td>Male</td>
<td>-Age<br>-Gender</td>
  <td>-inputAge<br>-inputGender</td>
        </tr>
<tr>
        <td>Female</td>
<td>-Age<br>-Gender</td>
  <td>-inputAge<br>-inputGender</td>
        </tr>

<p>The problem analysis presents a system designed to manage user information, ingredients, allergies, and alerts through four main classes: User, Ingredient, Allergy, and Alert. The User class represents individuals using the system and includes attributes for their name, age, and gender, with methods to input these details (inputName, inputGender, and inputAge). The Ingredient class handles a collection of ingredients with attributes for an array of ingredients and a count of these ingredients, and includes methods to input and count the ingredients (inputIngredient and countIngredient).

<p>The Allergy class is responsible for managing allergies. It includes attributes for an array of allergies, a reference to the Ingredient class to indicate which ingredients are involved, and an array to track the status of each allergy. This class has a method (statusAllergy) to update the allergy status based on the given ingredients. Finally, the Alert class generates notifications when an allergy is detected. It has an attribute referencing the Allergy class to determine which allergies to monitor and includes a method (notificationAlert) to trigger these alerts.</p>

<p>This detailed system structure ensures that users can input their personal details, manage and count ingredients, track and update allergy statuses, and receive notifications about potential allergic reactions, providing a comprehensive solution for allergy management.</p>


</tr>
</tbody>
</table><h1 id="section-c-class-diagram">Section C: Class Diagram</h1>
<img src="../Proposal/Image/UML CLASS DIAGRAM.jpg" width="7000" height="950">
 <p>1.Aggregation:
- The `Allergy` class contains one or more
`Ingredient` instances, showed by a hollow
diamond. `Ingredient` can exist independently
of `Allergy`.</p>
 <p>2.Association:
- `User` is associated with `Allergy`, and
`Allergy` is associated with `Alert`. These
connections show that a user can have
allergies, and allergies can trigger alerts. </p>
 <p>3.Inheritance:
- `male` and `female` classes inherit
attributes and methods from a common
superclass, including `Age`, `Gender`,
`inputAge()`, and `inputGender()`. </p>
 <p>4.Composition:
- The `Allergy` class has a composition
relationship with the `Alert` class, indicated by
a filled diamond. `Alert` is integral to `Allergy`
and cannot exist independently. </p>
</img>
</div>
</body>

</html>
