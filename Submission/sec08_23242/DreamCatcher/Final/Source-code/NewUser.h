#include <iostream>
#include <string>
#include <cmath>
#include "User.h"
using namespace std;

#ifndef NEWUSER_H
#define NEWUSER_H

class NewUser : public User {      
    private:
        string name;
        int age;
        char gender;
        double height;
        double weight;


    public:
        NewUser(string _username = "", string _password = "") : User(_username, _password)  {
            name = "";
            age = 0;
            gender = ' ';
            height = 0;
            weight = 0;
        } 


        string getName() { return name; }
        int getAge() const { return age; }
        char getGender() const {return gender; }
        double getHeight() const { return height; }
        double getWeight() const { return weight; }

        void setName(string _name) { name = _name; }
        void setAge(int _age) { age = _age; }
        void setGender(char a) { gender = a; }
        void setHeight(double _height) { height = _height; }
        void setWeight(double _weight) { weight = _weight; }

        void checkPassword(const std::string& password) {
            if (password.length() < 8) {
                throw std::invalid_argument("Password must be at least 8 characters long! ");
            }
        }

        void samePassword(const std::string& password1, const std::string& password2) {
            if (password1 != password2) {
                throw std::invalid_argument("Passwords do not match! ");
            }
        }
};

#endif