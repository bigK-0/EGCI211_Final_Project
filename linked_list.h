#include "data.h"

class LL{
   dataPtr hol;
   int size;
  public:
    LL();
	  string deletes(string);
    int isEmpty( );
    void insert(dataPtr);
    void printList( );
    data* group_high(dataPtr);
     ~LL();
};

LL::LL(){
  hol=NULL;
  size=0;
}

LL::~LL(){
  cout<<"A node has been deleted"<<endl;
  dataPtr t;
  t=hol;
  int i;
  for(i=0;i<size;i++){
      hol=hol->get_next();
      delete t;
      t=hol;
  } 
}

void LL::insert(dataPtr t) //insert and sort list from highest at hol to lowest
{ 
   dataPtr newPtr = t;
   dataPtr previousPtr; 
   dataPtr currentPtr;
   if ( newPtr != NULL ) { 
      previousPtr = NULL;
      currentPtr = hol; 
      while (currentPtr != NULL && t->get_heartRate() < currentPtr->get_heartRate()){
         previousPtr = currentPtr; 
         currentPtr = currentPtr->get_next(); 
      }  
      if ( previousPtr == NULL ) { 
        if(hol!=NULL){
          hol->set_prev(newPtr);
          newPtr->set_next(hol);
          hol = newPtr;
        }
        else {
          hol = newPtr;
        }
      }
      else {
         previousPtr->set_next(newPtr);
         newPtr->set_next(currentPtr);
        newPtr->set_prev(previousPtr);
       if(currentPtr!=NULL){
          currentPtr->set_prev(newPtr);
        }
      } 
     ++size;
   } 
   else {
      cout<<"No linked list insertion. No memory available."<<endl;
   } 
} 

int LL::isEmpty(  )
{ 
   return hol == NULL;
} 

string LL::deletes(string name){ 
   dataPtr previousPtr; 
   dataPtr currentPtr; 
   dataPtr tempPtr; 
   //string s = hol->get_name();
   if (hol->get_name()==name) { 
      tempPtr = hol; 
      hol = hol->get_next(); 
      hol->set_prev(NULL);
      size--;
      delete tempPtr; 
      return name;
   } 
   else { 
      previousPtr = hol;
      currentPtr = hol->get_next();
      while (currentPtr!=NULL && currentPtr->get_name() != name){ 
         previousPtr = currentPtr; 
         currentPtr = currentPtr->get_next(); 
      } 
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->set_next(currentPtr->get_next());
         currentPtr=currentPtr->get_next();
         currentPtr->set_prev(previousPtr);
         delete tempPtr ;
         size--;
         return name;
      } 
   } 
   return "";
} 

void LL::printList(){ 
  dataPtr currentPtr=hol;
   if (size==0) {
      cout<< "List is empty."<<endl;
   } 
   else { 
     cout<<endl<<"Sorted list (High to Low heart rate):"<<endl<<endl;
     cout<<setw(10)<<"professor"<<setw(25)<<"department"<<setw(10)<<"subject"<<setw(10)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
    int i;
    for(i=0; i<size ;i++)   {
      currentPtr->print();
      currentPtr = currentPtr->get_next();
    } 
    cout<<endl;
  } 
}

data* LL::group_high(dataPtr t) // only return if high risk
{
  int hr = t->get_heartRate(), age = t->get_age();

  if (age >= 70 && hr > 128) return t;
  else if (age >= 65 && age < 70 && hr > 132) return t;
  else if (age >= 60 && age < 65 && hr > 136) return t;
  else if (age >= 55 && age < 60 && hr > 140) return t;
  else if (age >= 50 && age < 55 && hr > 145) return t;
  else if (age >= 45 && age < 50 && hr > 149) return t;
  else if (age >= 40 && age < 45 && hr > 153) return t;
  else if (age >= 35 && age < 40 && hr > 157) return t;
  else if (age >= 30 && age < 35 && hr > 162) return t;
  else if (age <30 && hr > 170) return t;
  else return NULL;
}