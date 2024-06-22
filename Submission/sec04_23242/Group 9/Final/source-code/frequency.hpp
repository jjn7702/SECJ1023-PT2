
#include <iostream>
using namespace std;
#ifndef FREQUENCY_H
#define FREQUENCY_H



class Frequency
{
    // so that child class have access
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(1){}
        Frequency(int freqVal):freqVal(freqVal){}

        // MUTATOR
        void setFreq()
        {
            cout << "\nNumber of DOSE(S) you need to take at one time : ";
            cin >> freqVal;
        }

        // ACCESSOR
        int getFreq() const { return freqVal; }

        //POLYMORPHISM
        // default print from parent class
        virtual void printFreq()
        {
            cout << "Frequency : " << freqVal << " each time\n";
        }

        // Destructor
        ~Frequency(){}

};

#endif
