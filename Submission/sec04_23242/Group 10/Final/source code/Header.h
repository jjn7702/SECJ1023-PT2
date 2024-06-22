#ifndef HEADER_H
#define HEADER_H
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
    Address(string st, string c, string s, int p) : street(st), city(c), state(s), postcode(p) {}
    ~Address(){}

    string getStreet() const { return street; }
    string getCity() const { return city; }
    string getState() const { return state; }
    int getPostcode() const { return postcode; }

    void setStreet(const string& st) { street = st; }
    void setCity(const string& c) { city = c; }
    void setState(const string& s) { state = s; }
    void setPostcode(const int& p) { postcode = p; }
    void inputAddress();
    void displayAddress() const;
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
    
	void inputInfo();
	void viewInfo();
	void updateProfile();
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
    
    void addFeedback(const string&);
    const vector<string>& getFeedbackList() const{
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
    
    void updateProfile();
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

#endif

