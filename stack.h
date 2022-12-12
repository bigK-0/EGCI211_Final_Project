#ifndef stack_h
#define  stack_h
#include "data.h"

class Stack{
private:
	dataPtr top;
	int size;
public:
    Stack(dataPtr = NULL);
    ~Stack();
    char pop();
    void push(string, string, int, int);
    void print_stack();
    int getSize(){return size;}
};

Stack::Stack(dataPtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(string n, string s, int a, int h){
  dataPtr new_node=new data(n,s,a,);
  if(new_node){
	 	  new_node->set_next(top);
      top = new_node;
      size++;
    //print_stack();
    //cout<<endl;
   }
 else cout<<"No memory left for new nodes"<<endl;
		 // Left missing for exercises…
}
char Stack::pop(){
 	 dataPtr t=top;
	 char value;		
	 if(t)	{
    
     value=t->get_value();
     top = t->get_next();
    
	// Left missing for exercises
     delete t;
     size--;
     //cout<<value<<" has been deleted."<<endl;    
     //print_stack();
     //cout<<endl;
     return value;
     }
    
	 //cout<<"Empty stack"<<endl;
   return 0;
	}
Stack::~Stack(){
   cout<<"Clearing all stacks"<<endl;
  dataPtr t=top;
  for(int i=0;i<size;i++){
      t=top;
      top=top->get_next();
      delete t;
           	// Left missing for exercises
  }


}

void Stack::print_stack(){
  dataPtr t = top;
  
  for(int i=0;i<size;i++){
    t->print();
    cout<<" -> ";
    t = t->get_next();
  }
  cout<<"NULL";
  cout<<endl;
}



#endif