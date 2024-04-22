<h1 align="center"> 🎥Movie Recommendation System🎥 </h1>
<image src = "image/MOVIE.jpg" width="2000" height="500">

### Table
- [Synopsis](Synopsis)
- [Reporting](Reporting)
  
# Synopsis :clapper:
The movie recommendation system is a software application designed to suggest movies to users based on their preferences. It uses a combination of user input to generate personalized movie recommendations. The system aims to improve user satisfaction and engagement by providing relevant and diverse movie suggestions.This sytem will be built by using C++ language.

The movie recommendation system works by collecting data about users' movie preferences, such as ratings, genre preferences.The system employ various C++ specification.

User can interact with the system through simple input.Besides of that,they can rate the movie,add movie to their watchlist,personalized recommendation.

Overall, the movie recommendation system aims to help users discover new and interesting movies that match their tastes, thereby enhancing their movie-watching experience.

# Objective :dart:
• suggest movies to users based on their preferences,behavior
• enable user to rate the movie <br>
• organize movie information<br>
• Provide accurate movie information to user<br>
• Personalized recommendation<br>
• improving user satisfaction and engagement<br> <br>

# How to use the system :book:
## ***Step 1: sign in / sign up*** <br>
**Sign In**
  - User key in their Username and Password as input <br>
    * Both correct :+1: ->next section <br>
    * Not matched :-1: ->try again <br> <br>

**Sign Up**
  - User create their Username and Password as input <br> <br>


## ***Step 2: User Option***
|Option|Program|
|---|---|
|1|SEARCH MOVIE by MOVIE NAME|
|2|SEARCH MOVIE by MOVIE CLASSIFICATION|
|3|SEARCH MOVIE by GENRE|
|4|RATE MOVIE|
|5|VIEW USER'S WATCHLIST|
|6|EXIT|
<br>

## ***Step 3.1: Select Movie***
*For Option 1,2,3 in Step 2* <br>
**Display Movie List :clipboard::** User can select movie by input and option in Step 4 <br>

*For Option 4 in Step 2* <br>
**Movie Rating :black_nib::** User can select movie and rate the selected movie (After user rate the movie, the movie rating will be updated in the system <br>
## ***Step 3.2: User's Watchlist***
*For Option 5 in Step 2* <br>
**Watchlist View 🎞️:** User can view the movies in their watchlist and the movie can be removed if user wish to
<br> <br>

|*The user will proceed to Step 4 **ONLY IF** they select option 1/2/3 in Step 2*|
|---|
<br>

## ***Step 4: Options (CONT.)***
|OPTION|PROGRAM|DESCRIPTION|
|---|:---|:---|
|1|MOVIE INFO|After the movie been selected, user can choose to view the movie information by user input (movie name, year of movie released, genre, ratings and so on)|
|2|ADD TO WATCHLIST|User can add the selected movie to their personal watchlist (if the selected movie existed in the watchlist, the movie will not be added again and user will be notified)|
|3|REMOVE FROM WATCHLIST|User can remove the selected movie from their personal watchlist (if the selected movie do not existed in the watchlist, the movie will not be removed and user will be notified)|
|4|EXIT|User can exit the program by user input if they do not wish to proceed anymore|
<br>

# Reporting :bookmark_tabs:
This system will have different output based on user selection:
* Option 1, 2 and 3 will recommend movie to user and user can view movie info (year of release, genre, classification, rating and so on).
* User can add or remove movie in their watchlist, the latest watchlist will be updated in the system and showed in watchlist txt file.
* If user choose to rate the movie, the new rating will be updated in the movie info (movie info is in txt file).
