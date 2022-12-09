#include <iostream>
using namespace std;

#ifndef data_h
#define data_h

class data{
  private:
    string name, subject;
    int age, heartRate;
    data *next = NULL, *prev = NULL;
  public:
    void setInfo(string, string, int, int);
    data();
    data(string , string, int, int);
    ~data();
    void print();
    int get_age(){return age;}
    int get_heartRate(){return heartRate;}
    string get_name(){return name;}
    data* get_next();
    void set_next(data*);
    void set_hr(int hr){ heartRate = hr; }
};

typedef data* dataPtr;

void data::setInfo(string n, string s, int a, int h){
  name=n;
  subject = s;
  age=a;
  heartRate = h;
}
data::data(){
  setInfo("NULL","NULL",0,0);
}
data::data(string n, string s, int a, int h){
  setInfo(n, s, a, h);
}


data::~data(){
  cout<<name<<"'s data has been deleted."<<endl;
}

void data::print(){ 
    cout<<setw(10)<<name<<setw(10)<<subject<<setw(10)<<age<<setw(18)<<heartRate<<endl; 
}

data* data::get_next(){
    return next;
}

void data::set_next(data* t){
    next=t;
}



#endif