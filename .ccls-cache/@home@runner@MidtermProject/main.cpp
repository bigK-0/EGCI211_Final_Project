#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
#include "data.h"
#include "sort.h"

int main(int argc, char* argv[]) {
 
  int n= (argc-1)/3;
  data *pt_data=new data[n];
  int i;

  cout<<endl;
  cout<<"The average heart rate throughout the day of each professor:"<<endl<<endl;
  cout<<setw(10)<<"professor"<<setw(5)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
  for(i=1;i<argc-1;i+=3)   {
    (*pt_data).setInfo(argv[i],atoi(argv[i+1]),atoi(argv[i+2]));
    (*pt_data).print();
    //(*pt_data).set_next((pt_data+1));
    pt_data++;
  }
pt_data-=n;
sort(pt_data, n);
/*
{  pt_data -= n;
  for(i=1;i<argc-1;i+=3)   {
    (*pt_data).print();
    pt_data++;
  }}
 */
  delete []pt_data;
  }