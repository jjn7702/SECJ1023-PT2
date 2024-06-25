#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <conio.h>
#include <cctype>
using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
    int postcode;
public:
    Address() : street(""), city(""), state(""), postcode(0) {}
    Address(string st, string c, string s, int p) : street(st),
	city(c), state(s), postcode(p) {}
    ~Address(){}

    string getStreet() const { return street; }
    string getCity() const { return city; }
    string getState() const { return state; }
    int getPostcode() const { return postcode; }

    void setStreet(const string& st) { street = st; }
    void setCity(const string& c) { city = c; }
    void setState(const string& s) { state = s; }
    void setPostcode(const int& p) { postcode = p; }

    void inputAddress() {
    	cin.ignore();
        cout << "*Enter street: ";
        getline(cin, street);
        cout << "*Enter city: ";
        getline(cin, city);
        cout << "*Enter state: ";
        getline(cin, state);
        cout << "*Enter postcode: ";
        cin >> postcode;
    }

    void displayAddress() const {
    	cout << "Address "<<endl;
        cout << "*Street: " << street << endl;
        cout << "*City: " << city << endl;
        cout << "*State: " << state << endl;
        cout << "*Postcode: " << postcode << endl;
    }
};

class Profile {
private:
    string name;
    int age;
    Address address;
    string background;

public:
    Profile() : name(""), age(0), address(), background("") {}
    ~Profile(){}
    string getName() const { return name; }
    int getAge() const { return age; }
    Address getAddress() const { return address; }
    string getBackground() const { return background; }
    void setName(string n){name=n;}
    void setAge(int a){age=a;}
    void setAddress(Address addr){address=addr;}
    void setBackground(string bkg){background=bkg;}
    
	void inputInfo() {
        cin.ignore();
        cout << "Enter full name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    	cout << "Enter address "<<endl;
        address.inputAddress();
        cin.ignore();
        cout << "Enter background information: ";
        getline(cin, background);
    }
    
	void viewInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        address.displayAddress();
        cout << "Background: " << background << endl;
    }

    void updateProfile() 
    {
        cout << "\nYour Profile\n"
             << "------------\n";
        viewInfo();
        getchar();

       int choice;
       do
       {
       	system("cls");
         cout << "What would you like to update?\n";
    cout <<"1. Name\n2. Age\n3. Address\n4. Background\n5. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;
         cin.ignore();

         switch (choice)
         {
            case 1:
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                cin.ignore();
                break;
            case 3:
                cout << "Enter new address: ";
                address.inputAddress();
                break;
            case 4:
                cout << "Enter new background information: ";
                getline(cin, background);
                break;
            case 5:
                break; 
            default:
                cout << "Invalid choice.\n";
                break;
        }
       } while (choice != 5);
       
        cout << "Profile updated sucessfully...\n\n";
        viewInfo();
    }
};

class Feedback {
private:
    vector<string> feedbackList;
    string feedback;
public:
    Feedback() :feedback(""){}
    ~Feedback() {}

    string getFeedback(){return feedback;}
    void setFeedback(string fb){feedback=fb;}
    
    void addFeedback(const string& feedback) {
        feedbackList.push_back(feedback);
        cout << "Feedback added successfully." << endl;
    }
    
    const vector<string>& getFeedbackList() const {
        return feedbackList;
    }
};

class User {
protected:
    string username, password;
    Profile profile;

public:
    User() : username(""), password("") {}
	~User(){}
    string getUserName() const {return username; }
    string getPassword() const {return password; }
    void setUsername(string u){username=u;}
    void setPassword(string p){password=p;}
    
    void updateProfile() {
        profile.updateProfile();
    }
    bool checkPassword(const string&, const string&, const string&);
    void registerUser(const string&);

    virtual void menu()=0;
};

struct Event {
    double dateTime;
    string title;
    string venue;
    string description;

    Event(double dt, const string& t, const string& v, const string& d)
        : dateTime(dt), title(t), venue(v), description(d) {}
};
vector<Event> events;

class Organizer : public User {
private:
	Feedback *feedback;
public:
	 Organizer() : feedback(new Feedback()) {}
    ~Organizer() { delete feedback; }
  
    const Feedback* getFeedback() const { return feedback; }
    void createEvent();
    void menu()override;
};

vector<string> allFeedbacks;
class Participant : public User {
private:
	vector<Event> selectedEvents;
	Feedback *feedback;
public:
    Participant() : feedback(new Feedback()) {}
    ~Participant() { delete feedback; }
    
    const Feedback* getFeedback() const { return feedback; }
    void viewEvents(double);
    void displaySelectedEvent(double) const;
    void menu()override;
};


void Organizer::createEvent() {
  double dateTime;
    string title, venue, description;

    cin.ignore();
    cout << "Enter event title: ";
    getline(cin, title);
    cout << "Enter date and time (YYMMDD.HHMM): ";
    cin >> dateTime;
    cin.ignore();
    cout << "Enter venue: ";
    getline(cin, venue);
    cout << "Enter description: ";
    getline(cin, description);
    cout<<"Event have successfully created"<<endl;

    events.emplace_back(dateTime, title, venue, description);

    // Sort events by dateTime
    sort(events.begin(),events.end(),[](const Event& a,const Event& b) 
	{return a.dateTime < b.dateTime;});

}

void Organizer::menu() {
    int choice;
    while (true) {
    	system("cls");
        cout << "**********Organizer Menu**********\n";
        cout << "1. Create Event\n";
        cout << "2. Provide Feedback\n";
        cout << "3. View and Update Profile\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                {createEvent();
                getchar();}
                break;
            case 2:
                { string fb;
                    cout << "Enter feedback: ";
                    getline(cin, fb);
                    feedback->addFeedback(fb);
                allFeedbacks.push_back(fb); 
                getchar();}
                break;
            case 3:
            	 {updateProfile();
                getchar();}
                break;
            case 4:
                return;
            default:
                {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }
}

void Participant::viewEvents(double currentDateTime) {
    cout << fixed << setprecision(4) << "\n# Current date and time: " 
	<< currentDateTime <<" #"<< endl;
    cout << "\nAll events\n";
    cout << "-----------"<<endl;
    cout << "History events:\n";
    for (const auto& e : events) {
    	if (e.dateTime < currentDateTime) {
        cout << "~ Date and Time: " << e.dateTime 
		     << ", Title: " << e.title 
             << ", Venue: " << e.venue 
			 << ", Description: " << e.description 
			 << endl;}
    }
    cout << "\nUpcoming events:\n";
    for (const auto& e : events) {
        if (e.dateTime >= currentDateTime) {
            cout << "~ Date and Time: " << e.dateTime 
			     << ", Title: " << e.title 
                 << ", Venue: " << e.venue 
				 << ", Description: " << e.description 
				 << endl;
        }
    }
    cout<<"\nEnter the title of the upcoming event you want to join: ";
    string selectedTitle;
    getline(cin, selectedTitle);

    auto it=find_if(events.begin(),events.end(),
	           [&selectedTitle](const Event& e){
        return e.title == selectedTitle;
    });

    if (it != events.end() && it->dateTime >= currentDateTime) {
        selectedEvents.push_back(*it);
        cout << "You have successfully joined the event: "
		     << it->title << endl;
    } else {
        cout << "Event not found or it is not an upcoming event."
		     << endl;
    }
}

void Participant::displaySelectedEvent(double currentDateTime) const {
	cout << fixed << setprecision(4) << "Current date and time: " 
	     << currentDateTime << endl;
    cout << "\nSelected Events:\n";
    cout << "Past selected events:\n";
    for (const auto& e : selectedEvents) {
    	if (e.dateTime < currentDateTime) {
        cout << "Date and Time: " << e.dateTime 
		     << ", Title: " << e.title 
             << ", Venue: " << e.venue 
			 << ", Description: " << e.description 
			 << endl;}
    }
    cout << "\nUpcoming selected events:\n";
    for (const auto& e : selectedEvents) {
        if (e.dateTime >= currentDateTime) {
            cout << "Date and Time: " << e.dateTime 
			     << ", Title: " << e.title 
                 << ", Venue: " << e.venue 
				 << ", Description: " << e.description 
				 << endl;
        }
    }
}

void Participant::menu() {
    int choice;
    while (true) {
    	system("cls");
        cout << "**********Participant Menu**********\n";
        cout << "1. Event List\n";
        cout << "2. View Selected Events\n";
        cout << "3. Provide Feedback\n";
        cout << "4. View and Update Profile\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

    time_t t = time(0);
    struct tm* now = localtime(&t);
    double currentDateTime = (now->tm_year-100) * 10000 + 
	                         (now->tm_mon + 1) * 100 + 
							 now->tm_mday + (now->tm_hour / 100.0) 
							 + (now->tm_min / 10000.0);
                 
        switch (choice) {
            case 1:
            	{viewEvents(currentDateTime);
				getchar();}
                break;
            case 2:
               	{displaySelectedEvent(currentDateTime);
				getchar();}
                break;
            case 3:
                { string fb;
                    cout << "Enter feedback: ";
                    getline(cin, fb);
                    feedback->addFeedback(fb);
                allFeedbacks.push_back(fb); 
                getchar();}
                break;
            case 4:
                {updateProfile();
                getchar();}
                break;
            case 5:
                return;
            default:
               {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }
}

void User::registerUser(const string &role) {
    string username,password;
    while (true) {
        cout << "Enter new username (5-15 characters): ";
        cin >> username;
        if (username.length() >= 5 && username.length() <= 15) {
            break;
        }
        else {
            cout << "Username must be between 5 and 15 characters."
			     << endl;
        }
    }
    while (true) {
        cout << "Enter new password (8-20 characters): ";
        char ch = getch();
        while (ch != 13) { // character 13 is enter
                    password.push_back(ch);
                    std::cout << '*';
                    ch = getch();
                }
        if (password.length() >= 8 && password.length() <= 20) {
            break;
        }
        else {
            cout << "\nPassword must be between 8 and 20 characters." 
			     << endl;
        }
    }
    
    ofstream outfile("users.txt", ios::app);
    if (!outfile) {
        cout << "Error opening users.txt file." << endl;
        return;
    }
    outfile << setw(15) << username << setw(15) << password 
	        << setw(15) << role << endl;
    outfile.close();
    cout << "\n<<<Enter your personal data>>>\n";
    profile.inputInfo();
    cout << "Registration successful..." << endl;
}

bool User::checkPassword(const string& username, 
                        const string& password, const string& role) {
    ifstream infile("users.txt");
    if (!infile) {
        cout << "Error opening users.txt file." << endl;
        return false;
    }

    string storedUsername, storedPassword, storedRole;
    while (infile >> storedUsername >> storedPassword >> storedRole) {
        if (storedUsername == username && storedPassword 
		     == password && storedRole == role) {
            return true;
        }
    }

    return false;
}

int main() {
    Organizer org;
    Participant p;
    int choice;

    while (true) {
    	system("cls");
        cout << "**********Main Menu**********\n";
        cout << "1. Organizer Login\n";
        cout << "2. Participant Login\n";
        cout << "3. Register\n";
        cout << "4. View Feedback\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
            	cin.ignore();
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                char ch = getch();
                while (ch != 13) { // character 13 is enter
                    password.push_back(ch);
                    std::cout << '*';
                    ch = getch();
                }
                 if (org.checkPassword(username,password,"ORGANIZER"))
				{org.menu();
                } else {
                    cout << "\nInvalid username or password.\n";
                    getchar();
                }
                break;
            }
            case 2: {
            	cin.ignore();
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
               char ch = getch();
                while (ch != 13) { // character 13 is enter
                    password.push_back(ch);
                    std::cout << '*';
                    ch = getch();
                }
                if (p.checkPassword(username, password, "PARTICIPANT")){
                    p.menu();
                } else {
                    cout << "\nInvalid username or password.\n";
                    getchar();
                }
                break;
            }
            case 3:
                {string r;
                cin.ignore();
				cout << "Enter role (Participant/Organizer): ";
                getline(cin,r);
                for(int i=0;i<r.length();i++)
                  r[i]= toupper(r[i]);
                  
                if (r=="PARTICIPANT")
				p.registerUser(r); 
				else
				org.registerUser(r);
                getchar();}
                break;
            case 4:
            	{cout<<"Feedback list:\n";
            	for(const auto& feedback :allFeedbacks)
            	cout<<"- "<<feedback<<endl;
            	getchar();}
            	break;
            case 5:
                {cout << "Exiting program...\n";
                getchar();}
                return 0;
            default:
                {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }
    
    system("pause");
    return 0;
}
