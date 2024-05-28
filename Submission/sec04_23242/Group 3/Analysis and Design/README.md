<!DOCTYPE html>
<html>

<body class="stackedit">
  <div class="stackedit__html"><h1 id="section-a-flowchart">Section A: Flowchart</h1>
    <img src="../Proposal/Image/Flowchart.png" width="7000" height="600">
    Food Allergy System is a system that will save your life by detecting potential allergens found in your immune system. The system will first ask the user for their informations, such as their Name, Gender and Age. After that, the user is required to insert the ingredients of the food that they want to check. By using these ingredients, the system will then try to match the ingredients with the potential allergens and alert the user if there is any potential allergies. After these process is done, the system will prompt all of the user information and the list of allergies found.
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

<p>The problem analysis outlines the structure and functionality of a system involving four main classes: User, Ingredient, Allergy, and Alert. Each class has specific attributes and methods:

<p>User: Represents a person using the system, with attributes for their Name, Age, and Gender, and methods to input these details.</p>
<p>Ingredient: Contains an array of ingredients and a count of these ingredients, with methods to input and count them.</p>
<p>Allergy: Manages allergies, referencing ingredients and tracking their status, with a method to update the allergy status.</p>
<p>Alert: Generates notifications based on allergies, with a method to trigger alerts when an allergy is detected.</p>

</tr>
</tbody>
</table><h1 id="section-c-class-diagram">Section C: Class Diagram</h1>
<img src="../Proposal/Image/Screenshot 2024-05-28 215950.png" width="7000" height="950">
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
