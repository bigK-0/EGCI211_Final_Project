void sort(data *a, int N){
  int i, j, value;
  data* temp = (data*) malloc(sizeof(data)); 

  //cout<<endl<<"Sorting"<<endl;
  for ( i = 0; i<N-1; i++){
    /*value = (*a).get_next()->get_heartRate();
    temp = a;
    cout<<i<<endl;*/
    for(j = i+1 ; j < N; j++){
      
      if ((*(a+i)).get_heartRate()<(*(a+j)).get_heartRate()){ 
  
        *temp = *(a+i);
        *(a+i) = *(a+j);
        *(a+j) = *temp;
        
      } // else break;
    }   
  }
  
   cout<<endl<<"Sorted list (High to Low heart rate):"<<endl<<endl;
  
   cout<<setw(10)<<"professor"<<setw(5)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
  
  for(i=0; i<N ;i++)   {
    (*(a+i)).print();
    } 
  cout<<endl;
  
  // grouping high risk and low risk
  data* high_risk= new data[N];
  data* low_risk= new data[N];
  int k=0, l=0;

  for(i=0; i<N ;i++)   {

    if (a[i].get_age()>= 70 && a[i].get_heartRate()>128){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 65 && a[i].get_age()<70 && a[i].get_heartRate()>132){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 60 && a[i].get_age()<65 && a[i].get_heartRate()>136){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 55 && a[i].get_age()<60 && a[i].get_heartRate()>140){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 50 && a[i].get_age()<55 && a[i].get_heartRate()>145){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 45 && a[i].get_age()<50 && a[i].get_heartRate()>149){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 40 && a[i].get_age()<45 && a[i].get_heartRate()>153){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 35 && a[i].get_age()<40 && a[i].get_heartRate()>157){
      *(high_risk+k)=*(a+i);
      k++;}

    else if (a[i].get_age()>= 30 && a[i].get_age()<35 && a[i].get_heartRate()>162){
      *(high_risk+k)=*(a+i);
      k++;}

    else if(a[i].get_age()< 30 && a[i].get_heartRate()>170){
      *(high_risk+k)=*(a+i);
      k++;}

    else {
      *(low_risk+l)=*(a+i);
      l++;}
  } //end for 
  
  cout<<"Professors with HIGH risk of anxiety: "<<endl<<endl;
  cout<<setw(10)<<"professor"<<setw(5)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
  for(i=0; i<k;i++) {
    (*(high_risk+i)).print();
  }
  cout<<endl;
  
  cout<<"Professors with LOW risk of anxiety: "<<endl<<endl;
  cout<<setw(10)<<"professor"<<setw(5)<<"age"<<setw(18)<<"heart rate(bpm)"<<endl;
  for(i=0; i<l;i++) {
    (*(low_risk+i)).print();
  }
  
}