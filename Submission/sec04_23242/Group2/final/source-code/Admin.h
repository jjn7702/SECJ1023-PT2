#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>
using namespace std;

class Admin {
    private:
        string adminUsername;
        string adminPassword;

    public:
        Admin();
        Admin(string, string);
        
        //mutators
        void resetPassword(User user[]);
        void removeUser(User user[], int &);
        void editUser(User []);
    };

#endif