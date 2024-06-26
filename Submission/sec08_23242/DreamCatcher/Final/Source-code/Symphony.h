#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef SYMPHONY_H
#define SYMPHONY_H
#define N 100

class Music{
    protected:
        string cList;
        string urlcList;

    public:
        Music(string _cList,string _url){
            cList = _cList;
            urlcList = _url;
        }
        
        string getcList() { return cList; }
        string geturlcList() { return urlcList; }
    
        void setcList(string _cList) { cList = _cList; }
        void seturlcList(string _url) { urlcList = _url; }

        virtual void dispClist() {
            if (!cList.empty() && !urlcList.empty()) {
                cout << ": " << "\033]8;;" << urlcList << "\033\\" 
                     << setw(50)<< left << cList << "\033]8;;\033\\";
                cout << setw(2) << " ";
            }
        } 
        friend void loadMusic();
};

class ClassicM : public Music{
    private:
        string composer;

    public:
        ClassicM(string _list, string _url, string _composer) : Music(_list, _url){
            composer = _composer;
        }
    
        string getComposer() { return composer; }
        void setComposer(string name) { composer = name; }
    
        void dispClist(){
                Music::dispClist();
                cout << "Composer: " << composer << endl;
        }
};

class WhiteNoise : public Music{
    private
        string typeW;

    public:
        WhiteNoise(string _clist, string _urlList, string _typeW) : Music(_clist, _urlList){
            typeW = _typeW;
        }
    
        void setType(string _type) { typeW = _type; }
        string getType() { return typeW; }

    void dispClist(){
        Music::dispClist();
        cout << "Type: " << typeW << endl;
    }
};

class FavM: public Music{
    string typeF;

    public:
    FavM(string _list, string _urlList, string _typeF) : Music(_list, _urlList){
        typeF = _typeF;
    }

    void setType(string _type) { typeF = _type; }
    string getType(int i) { return typeF; }

    void dispClist(){
        Music::dispClist();
        cout << "Type: " << typeF << endl;
    }
};

#endif 
