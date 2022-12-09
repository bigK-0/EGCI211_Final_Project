#include <iostream>
using namespace std;

#ifndef data_h
#define data_h

class data{
  private:
    string name, department;
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
    data* get_prev();
    void set_next(data*);
    void set_prev(data*);
    void set_hr(int hr){ heartRate = hr; }
};

typedef data* dataPtr;

void data::setInfo(string n, string d, int a, int h){
  name=n;
  department = d;
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
    cout<<setw(10)<<name<<setw(25)<<department<<setw(10)<<age<<setw(18)<<heartRate<<endl; 
}

dataPtr data::get_next(){
    return next;
}

dataPtr data::get_prev(){
    return prev;
}

void data::set_next(data* t){
    next=t;
}

void data::set_prev(data* t){
    prev=t;
}



#endif