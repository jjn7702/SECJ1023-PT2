#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>
using namespace std;

class Admin: public User{
    private:
        string adminUsername;
        string adminPassword;

    public:
        Admin();
        Admin(string, string);

        //accessor
        string getAdminUsername() const;
        string getAdminPassword() const;

        //mutators
        void setAdminUsername(string);
        void setAdminPassword(string);

        void resetPassword(User user[]);
        void removeUser(User user[], int &);
        void editUser(User []);
    };

#endif