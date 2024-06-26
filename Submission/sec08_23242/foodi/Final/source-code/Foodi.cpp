    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <stdexcept>
    #include <iomanip>
    using namespace std;

    // Class representing an allergen
    class Allergen {
    private:
        string name;

    public:
        Allergen(string _name) : name(_name) {}
        string getName() const {
            return name;
        }
        void setName(string _name) {
            name = _name;
        }
    };

    // Class representing a User
    class User {
    private:
        string name;
        string email;
        vector<Allergen> allergies;

    public:
        User(string _name = "", string _email = "", vector<Allergen> _allergies = {})
            : name(_name), email(_email), allergies(_allergies) {}

        string getEmail() const {
            return email;
        }
        void setEmail(string _email) {
            email = _email;
        }
        string getName() const {
            return name;
        }
        void setName(string _name) {
            name = _name;
        }
        vector<Allergen> getAllergies() const {
            return allergies;
        }
        void addAllergy(vector<Allergen> _allergens) {
            allergies = _allergens;
        }

        // Save user data to file
        void saveUserData() const {
            ofstream file("profiles.txt", ios::app);
            if (file.is_open()) {
                file << "name:" << name << endl;
                file << "email:" << email << endl;
                for (const auto& allergen : allergies) {
                    file << "allergen:" << allergen.getName() << endl;
                }
                file << endl; // Separate profiles with a blank line
                file.close();
            } else {
                throw runtime_error("Unable to open file.");
            }
        }

        // Display the user's profile
        void displayProfile() const {
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
            cout << "Allergens: ";
            for (const auto& allergen : allergies) {
                cout << allergen.getName() << " ";
            }
            cout << endl;
        }
    };

    // Function to create a new profile
    void createNewProfile(User &currentUser) {
        string profileName, email;
        cout << "\n* New Profile *\n";
        cout << "Name: ";
        getline(cin, profileName);
        cout << "Email: ";
        getline(cin, email);
        cout << "List of common allergens (enter one word: milk, egg, fish, etc.)\n";
        
        vector<Allergen> allergies;
        while (true) {
            string allergenName;
            cout << "Allergen (type 'done' to finish): ";
            getline(cin, allergenName);
            if (allergenName == "done") {
                break;
            }
            allergies.push_back(Allergen(allergenName));
        }

        currentUser.setEmail(email);
        currentUser.setName(profileName);
        currentUser.addAllergy(allergies);
        currentUser.saveUserData();
        cout << "\nProfile created successfully.\n";
    }

    // Function to load all profiles from the file
    vector<User> loadAllProfiles() {
        vector<User> users;
        ifstream file("profiles.txt");
        if (file.is_open()) {
            string line, name, email;
            vector<Allergen> allergies;
            while (getline(file, line)) {
                if (line.find("name:") == 0) {
                    name = line.substr(5);
                } else if (line.find("email:") == 0) {
                    email = line.substr(6);
                } else if (line.find("allergen:") == 0) {
                    allergies.push_back(Allergen(line.substr(9)));
                } else if (line.empty() && !name.empty() && !email.empty()) {
                    users.push_back(User(name, email, allergies));
                    name.clear();
                    email.clear();
                    allergies.clear();
                }
            }
            file.close();
        } 
        else {
            throw runtime_error("Unable to open file.");
        }
        return users;
    }
    User loadProfileByName(const string& profileName) {
        vector<User> users = loadAllProfiles();
        for (const auto& user : users) {
            if (user.getName() == profileName) {
                return user;
            }
        }
        return User("", "", {});
    }
    // Function to display all profiles
    void displayAllProfiles() {
        try {
            vector<User> users = loadAllProfiles();
            cout << "\nAvailable Profiles:\n";
            for (const auto& user : users) {
                cout <<"Profile Name: " << user.getName() << endl;
            }
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    }

    // Function to check if a profile exists
    bool isProfileFound(const string& profile_Name) {
        try {
            vector<User> users = loadAllProfiles();
            for (const auto& user : users) {
                if (user.getName() == profile_Name) {
                    return true;
                }
            }
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
        return false;
    }

    void deleteProfile(const string& profileName) {
        vector<User> users = loadAllProfiles();
        ofstream file("profiles.txt");
        if (file.is_open()) {
            for (const auto& user : users) {
                if (user.getName() != profileName) {
                    file << "name:" << user.getName() << endl;
                    file << "email:" << user.getEmail() << endl;
                    for (const auto& allergen : user.getAllergies()) {
                        file << "allergen:" << allergen.getName() << endl;
                    }
                    file << endl; // Separate profiles with a blank line
                }
            }
            file.close();
            cout << "Profile deleted successfully.\n";
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // Function to edit a profile
    void editProfile(const string& profileName) {
        vector<User> users = loadAllProfiles();
        for (auto& user : users) {
            if (user.getName() == profileName) {
                string newEmail;
                cout << "\nEditing Profile: " << profileName << endl;
                cout << "Current Email: " << user.getEmail() << endl;
                cout << "New Email: ";
                getline(cin, newEmail);
                user.setEmail(newEmail);

                vector<Allergen> newAllergies;
                cout << "Update Allergens (type 'done' to finish):\n";
                while (true) {
                    string allergenName;
                    cout << "Allergen: ";
                    getline(cin, allergenName);
                    if (allergenName == "done") {
                        break;
                    }
                    newAllergies.push_back(Allergen(allergenName));
                }
                user.addAllergy(newAllergies);

                // Save updated profiles
                ofstream file("profiles.txt");
                if (file.is_open()) {
                    for (const auto& u : users) {
                        file << "name:" << u.getName() << endl;
                        file << "email:" << u.getEmail() << endl;
                        for (const auto& allergen : u.getAllergies()) {
                            file << "allergen:" << allergen.getName() << endl;
                        }
                        file << endl; // Separate profiles with a blank line
                    }
                    file.close();
                    cout << "Profile updated successfully.\n";
                } else {
                    cout << "Unable to open file." << endl;
                }
                return;
            }
        }
        cout << "Profile not found." << endl;
    }
    // Function for profile management
    void profileManagement() {
        int choice;
        bool status = false;
        string profile_Name;
        while (!status) {
            cout << "\nProfile Management:\n"
                << "[1] Delete Profile\n"
                << "[2] Edit Profile\n"
                << ">> ";
            cin >> choice;
            cin.ignore();
            if (choice != 1 && choice != 2) {
                cout << "Error! Enter 1 or 2.\n";
            } else {
                status = true;
            }

            if (choice == 1) {
                status = false;
                while (!status) {
                    displayAllProfiles();
                    cout << "\nChoose profile name: ";
                    getline(cin, profile_Name);
                    if (!isProfileFound(profile_Name)) {
                        cout << "Error! Profile not found.\n";
                    } else {
                        status = true;
                        deleteProfile(profile_Name);
                    }
                }
            } else if (choice == 2) {
                status = false;
                while (!status) {
                    displayAllProfiles();
                    cout << "\nChoose profile name: ";
                    getline(cin, profile_Name);
                    if (!isProfileFound(profile_Name)) {
                        cout << "Error! Profile not found.\n";
                    } else {
                        status = true;
                        editProfile(profile_Name);
                    }
                }
            }
        }
    }

    class Cuisine {
        protected:
            string cuisine_Name;
        public:
            Cuisine(string n = "") : cuisine_Name(n) {}
            virtual ~Cuisine() {}

            void setCuisine(string n) { cuisine_Name = n; }
            string getCuisine() const { return cuisine_Name; }
    };

    class FoodCategory {
        public:
            virtual string getCategory() const = 0;
            virtual ~FoodCategory() {};
    };

    class Dessert: public FoodCategory {
    public:
        string getCategory() const {
            return "dessert";
        }
    };

    class Breakfast: public FoodCategory {
    public:
        string getCategory() const {
            return "breakfast";
        }
    };

    class Lunch: public FoodCategory {
    public:
        string getCategory() const {
            return "lunch";
        }
    };

    class Dinner: public FoodCategory {
    public:
        string getCategory() const {
            return "dinner";
        }
    };

    static Dessert dessert;
    static Breakfast breakfast;
    static Lunch lunch;
    static Dinner dinner;

    class Diet{
        private:
            string name;
        public:
            Diet(string n = ""){ setName(n);};
            ~Diet(){};

            void setName(string n) {name = n;}
            string getName()const {return name;}
    };

    class FoodItem: public Cuisine {
    private:
        string name;
        vector<string> ingredients;
        FoodCategory* category;
        Diet diet;

    public:
        FoodItem(string cuisine_n = "", string n = "", vector<string> ing = {},
                FoodCategory* c = nullptr, string diet_n = "")
            : Cuisine(cuisine_n), name(n), ingredients(ing), category(c), diet(diet_n) {}

        ~FoodItem() {}

        void setName(string n) { name = n; }
        void setIngredients(vector<string> ing) { ingredients = ing; }
        void setDiet(string d_n) {diet.setName(d_n);}
        void setCategory(FoodCategory* c) { category = c; }

        string getName() const { return name; }
        string getCuisine() const { return cuisine_Name; }
        vector<string> getIngredients() const { return ingredients; }
        string getDiet()const {return diet.getName();}
        string getCategory() const { 
            if(category != nullptr){
                return category->getCategory();
            }
            return "No_category";
        }

        friend ostream& operator<<(ostream& os, const FoodItem& f);
        friend istream& operator>>(istream& is, FoodItem& f);
    };

    ostream& operator<<(ostream& os, const FoodItem& f) {
        os << endl;
        os << "Food Item" << endl;
        os << "Name: " << f.name << endl;
        os << "Cuisine: " << f.cuisine_Name << endl;
        os << "Ingredients: ";
        for (const auto& ingredient: f.ingredients)
            os << ingredient << " ";
        os << endl;
        os << "Category: " << f.getCategory() << endl;
        os << "Diet: " << f.getDiet() << endl;

        return os;
    }

    istream& operator>>(istream& is, FoodItem& f) {
        string name;
        cout << "Enter name: ";
        getline(is, f.name);

        cout << "Enter cuisine: ";
        getline(is, f.cuisine_Name);

        int n;
        try{
            cout << "Enter number of ingredients: ";
            is >> n;
        }
        catch(exception& e){
            cout << "Invalid input" << endl;
        }
        cin.ignore();
        vector<string> ingredients;
        string ingredient;
        for (int i = 0; i < n; ++i) {
            cout << "Enter ingredient: ";
            getline(is, ingredient);
            ingredients.push_back(ingredient);
        }
        f.setIngredients(ingredients);

        cout << "Enter category (dessert, breakfast, lunch, dinner): ";
        string c;
        getline(is, c);

        if (c == "dessert") {
            f.setCategory(&dessert);
        } 
        else if (c == "breakfast") {
            f.setCategory(&breakfast);
        } 
        else if (c == "lunch") {
            f.setCategory(&lunch);
        } 
        else if (c == "dinner") {
            f.setCategory(&dinner);
        }else {
            cout << "Invalid category" << endl;
            f.setCategory(nullptr);
        }

        cout << "Enter diet (vegan, vegetarian, keto, non_vegetarian): ";
        string d;
        is >> d;
        if (d == "vegan") {
            f.setDiet("vegan");
        } 
        else if (d == "vegetarian") {
            f.setDiet("vegetarian");
        }
        else if (d == "keto") {
            f.setDiet("keto");
        } 
        else if(d == "non_vegetarian"){
            f.setDiet("non_vegetarian");
        }
        else {
            cout << "Invalid diet" << endl;
            f.setDiet("none");
        }

        return is;
    }

    vector<FoodItem> loadAllFoodItem() {
        ofstream fileo("fooditems.txt", ios::out | ios::app);

        if (!fileo) {
            throw runtime_error("Error opening file");
        }
        fileo.close();

        vector<FoodItem> foodItems;
        FoodCategory* foodCategory = nullptr;
        ifstream file("fooditems.txt");
        if (!file.is_open()) {
            throw runtime_error("Error opening file");
        }

        string line;
        while (getline(file, line)) {
            if (line.empty() || line[0] != '~') {
                continue; 
            }

            line = line.substr(1);

            size_t pos = line.find(' ');
            if (pos == string::npos) continue;
            string name = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(' ');
            if (pos == string::npos) continue;
            string cuisine = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(' ');
            if (pos == string::npos) continue;
            string diet = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(' ');
            if (pos == string::npos) continue;
            string category = line.substr(0, pos);
            line = line.substr(pos + 1);

            vector<string> ingredients;
            while (!line.empty() && line != "%") {
                pos = line.find(' ');
                if (pos == string::npos) break;
                string ingredient = line.substr(0, pos);
                ingredients.push_back(ingredient);
                line = line.substr(pos + 1);
            }
            if(category == "dessert"){
                foodCategory = &dessert;
            }
            else if(category == "breakfast"){
                foodCategory = &breakfast;
            }
            else if(category == "lunch"){
                foodCategory = &lunch;
            }
            else if(category == "dinner"){
                foodCategory = &dinner;
            }
            else{
                foodCategory = nullptr;
            }
    
            foodItems.push_back(FoodItem(cuisine, name, ingredients, foodCategory, diet));
        }

        file.close();
        return foodItems;
    }

    void addFoodItem(vector<FoodItem> &FI, const FoodItem& f) {
        FI.push_back(f);
        ofstream file("fooditems.txt", ios::app);
        if (!file.is_open()) {
            throw runtime_error("Error opening file");
        }
        file << "~" << f.getName() << " " << f.getCuisine() << " " << f.getDiet() << " " << f.getCategory() << " ";
        for (const auto& ingredient : f.getIngredients()) {
            file << ingredient << " ";
        }
        file << "%" << endl;
        file.close();
    }

    void FoodItem_Has_Allergen(const vector<FoodItem> &FI, string f_n, const User& u) {
        vector<string> allergens_Found;
        bool Allergen_found = false, Food_found = false;
        for(int i = 0; i < FI.size(); i++){
            if(FI[i].getName() == f_n){
                for(int j = 0; j < u.getAllergies().size(); j++){
                    for(int k = 0; k < FI[i].getIngredients().size(); k++){
                        if(FI[i].getIngredients()[k] == u.getAllergies()[j].getName()){
                            allergens_Found.push_back(u.getAllergies()[j].getName());
                            Allergen_found = true;
                        }
                    }
                }
                Food_found = true;
            }
        }
        if (Food_found) {
            if(Allergen_found){
                cout << "Allergens found in the food item: " << endl;
                for (int i = 0; i < allergens_Found.size(); i++) {
                    cout << allergens_Found[i] << endl;
                }
            }
            else {
                cout << "No allergens found in the food item." << endl;
            }
        }
        else {
            cout << "Food item not found." << endl;
        }
    }

    void searchFoodItems(const vector<FoodItem>& foodItems, const User& u) {
        string filterType, filterValue;
        vector<string> validFilterTypes = {"diet", "cuisine", "category"};
        bool validFilter = false;

        while (!validFilter) {
            cout << "\nEnter filter type (diet/cuisine/category) or 'none' for no filter: ";
            cin >> filterType;

            if (filterType == "none") {
                validFilter = true;
            } else {
                for (const string& validFilterType : validFilterTypes) {
                    if (filterType == validFilterType) {
                        validFilter = true;
                        break;
                    }
                }
                if (!validFilter) {
                    cout << "Invalid filter type. Please enter 'diet', 'cuisine', 'category', or 'none'." << endl;
                }
            }
        }

        if (filterType != "none") {
            cout << "Enter filter value: ";
            if(filterType == "diet"){
            cout << "Enter A diet (vegan, vegetarian, keto, non_vegetarian): ";
            cin >> filterValue;
            }
            else if(filterType == "cuisine"){
                cout << "Enter A cuisine (italian, etc): ";
                cin >> filterValue;
            }
            else if(filterType == "category"){
                cout << "Enter A category (dessert, breakfast, lunch, dinner): ";
                cin >> filterValue;
            }
            
        }

        vector<FoodItem> filteredItems;
        for (const auto& item : foodItems) {
            if (filterType == "none" ||
                (filterType == "diet" && item.getDiet() == filterValue) ||
                (filterType == "cuisine" && item.getCuisine() == filterValue) ||
                (filterType == "category" && item.getCategory() == filterValue)) {
                filteredItems.push_back(item);
            }
        }

        if (filteredItems.empty()) {
            cout << "No food items found matching the filter criteria." << endl;
        } else {
            vector<FoodItem>::iterator it;

            for (it = filteredItems.begin(); it != filteredItems.end(); it++) {
                cout << *it;
            }
            cout << endl << endl;
            cout << "Enter the name of the food item you would like to view: ";
            string foodItemName;
            cin >> foodItemName;
            FoodItem_Has_Allergen(filteredItems, foodItemName, u);
        }
    }

    void displayMenu(User& currentUser, vector<FoodItem>& foodItems) {
        bool status = false;
        string profileName;
        while (true) {
            cout << endl
                << "Main Menu:\n"
                << "[1] Select Existing Profile\n"
                << "[2] Create New Profile\n"
                << "[3] Profile Management\n"
                << "[4] Search Food Items\n"
                << "[5] Add Food Item\n"
                << "[6] Exit\n"
                << ">> ";
            int choice;
            cin >> choice;
            cin.ignore();

            if (choice < 1 || choice > 6) {
                cout << "Error! Enter a number between 1 and 6.\n" << endl;
                continue;
            }

            if (choice == 1) {
            status = false;
            
            while (!status) {
                displayAllProfiles();
                cout << "\nChoose profile name(press 0 if none): ";
                getline(cin, profileName);
                if (profileName == "0") {
                    status = true;
                    createNewProfile(currentUser);
                } else if (!isProfileFound(profileName)) {
                    cout << "Error! Profile not found. Press 2 to create new profile\n";
                } else {
                    status = true;
                    currentUser = loadProfileByName(profileName);
                    currentUser.displayProfile();
                }
            }
            } else if (choice == 2) {
                createNewProfile(currentUser);
            } else if (choice == 3) {
                profileManagement();
            } else if (choice == 4) {
                try {
                    searchFoodItems(foodItems, currentUser);
                } catch (const exception& e) {
                    cout << "Exception: " << e.what() << endl;
                }
            }  else if (choice == 5) {
                FoodItem f;
                cin >> f;
                try {
                    addFoodItem(foodItems, f);
                } catch (const exception& e) {
                    cout << "Exception: " << e.what() << endl;
                }
            } else if (choice == 6) {
                exit(0);
            }
        }
    }

    int main() {
        vector<FoodItem> foodItems;
        try {
            foodItems = loadAllFoodItem();
        } 
        catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
            return 1;
        }
        User currentUser;
        currentUser.setName("Test User");
        currentUser.setEmail("testuser@example.com");

        cout << "************************************ ";
        cout << "Welcome to Foodi the Food Allergen Checker! ";
        cout << "************************************" << endl;

        while(true){
            try {
                displayMenu(currentUser, foodItems);
            } catch (const exception& e) {
                cout << "Exception: " << e.what() << endl;
            }
        }

        return 0;
    }
