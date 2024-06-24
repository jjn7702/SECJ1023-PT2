#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Publisher {
	private:
    	string publisherName;
		string country;
	
	public:
	    Publisher() {}
	    
	    Publisher(string n, string c) : publisherName(n), country(c) {}
	    
		~Publisher() {}
		
	    string getPublisherName() const { 
			return publisherName; 
		}
		
	    void setPublisherName (string n) { 
			publisherName = n; 
		}
		
	    string getCountry() const { 
			return country; 
		}
		
	    void setCountry(string c) { 
			country = c; 
		}
};