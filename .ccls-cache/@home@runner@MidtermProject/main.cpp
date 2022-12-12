#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
#include "data.h"
#include "sort.h"
#include "queue.h"

int main(int argc, char* argv[]) {
  
  data *pt_data=new data[20];
  data *high_risk = new data[20];
  int exit = 0, age, hr, size = 0, sorted = 0;
  string name, sj;
  Queue p;
  while(exit!=1){ 
    cout<<endl<<"*************"<<endl<<endl;
    cout<<"Select an option:"<<endl;
    cout<<"\t1. Input the professor's information."<<endl;
    cout<<"\t2. Show the list of professors."<<endl;
    cout<<"\t3. Sort the list of professors."<<endl;
    cout<<"\t4. Show queue of high risk professors."<<endl;
    cout<<"\t5. therapy???dequeue"<<endl;
    cout<<"\t6. Exit the program."<<endl<<endl;
    int option;
    cin>>option;
    switch(option){
      case 1:
        cout<<"Name: ";
          cin>>name;
        cout<<endl<<"Subject: ";
          cin>>sj;
        cout<<endl<<"Age: ";
          cin>>age;
        cout<<endl<<"Heart Rate: ";
          cin>>hr;
        cout<<endl;
        (*(pt_data+size)).setInfo(name, sj, age, hr);
        size++;
        
        sorted = 0;
        break;
      
      case 2:  
        cout<<setw(10)<<"professor"<<setw(10)<<"subject"<<setw(10)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
        for(int i = 0; i<size ; i++){
          (*(pt_data+i)).print();
        }
        break;
      
      case 3: 
        high_risk = sort(pt_data, size);
        sorted = 1;
        break;
      
      case 4: //error: Segmentation fault (core dumped)
        if(sorted == 1){
          while (p.getSize()>0) p.dequeue();
          while(high_risk->get_age()!=0){
            p.enqueue(high_risk);
            high_risk++;
          }
          high_risk -= p.getSize();
          p.print_all(); //error comes up after here
        }else{ cout<<"The list has not been sorted."<<endl;}
        break;
      
      case 5: 
        cout<<p.dequeue()<<" has been dequeued."<<endl;
        break;
      
      case 6: exit = 1; break;
      default: cout<< "Wrong input."<<endl;
    }
  }
  
/*{{{  int n= (argc-1)/3;
  data *pt_data=new data[n];
  int i;

  cout<<endl;
  cout<<"The average heart rate of each professor:"<<endl<<endl;
  cout<<setw(10)<<"professor"<<setw(5)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
  for(i=1;i<argc-1;i+=3)   {
    (*pt_data).setInfo(argv[i],atoi(argv[i+1]),atoi(argv[i+2]));
    (*pt_data).print();
    //(*pt_data).set_next((pt_data+1));
    pt_data++;
  }
pt_data-=n;
sort(pt_data, n);

  delete []pt_data;}}}*/
  }