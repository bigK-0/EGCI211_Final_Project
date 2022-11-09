#include <iostream>
using namespace std;

class data{
private:
  string name;
  int age, heartRate;
  data *next = NULL, *prev = NULL;
public:
  void setInfo(string, int, int);
  data();
  void print();
  int get_age(){return age;}
  int get_heartRate(){return heartRate;}
  //string get_name(){return name;}
  //data* get_next();
  //void set_next(data*);
};

void data::setInfo(string n, int a, int h){
  name=n;
  age=a;
  heartRate = h;
}
data::data(){

}

void data::print(){ 
    cout<<setw(10)<<name<<setw(5)<<age<<setw(18)<<heartRate<<endl; 
}

/*data::data(){
  cout<<"Input your name: "<<endl;
  cin>>name;
  cout<<"Input your age: "<<endl;
  cin>>age;
  cout<<"Input your heart rate: "<<endl;
  cin>>heartRate;
}*/ 

/*data* data::get_next(){
    return next;
}*/

/*void data::set_next(data* t){
    next=t;
}*/

