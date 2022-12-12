#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "data.h"
#include "linked_list.h"
#include "queue.h"
#include "sort.h"

int main(int argc, char *argv[]) {

  data *pt_data = new data[50];
  data *high_risk = new data[50];
  int exit = 0, age, hr, size = 0, l = 0;
  string name, dp;
  Queue p;
  LL bus, sci, eng, hum, ir, tour, des;
  LL bus_h, sci_h, eng_h, hum_h, ir_h, tour_h, des_h;

  while (exit != 1) {
    int option;
    do {
      cout << endl << "*************" << endl << endl;
      cout << "Select an option:" << endl;
      cout << "\t1. Input the professor's information." << endl;
      cout << "\t2. Show the list of professors." << endl;
      cout << "\t3. Sort and show the sorted list of professors." << endl;
      cout << "\t4. Show the queue of high risk professors." << endl;
      cout << "\t5. Dequeue a professor that has already met the therapist."
           << endl;
      cout << "\t6. Show the list of professors in the selected department."
           << endl;
      cout << "\t7. Exit the program." << endl << endl;

      if (!(cin >> option)) {
        cin.clear();
        cin.ignore();
        continue;
      }
      if ((option >= 1) && (option <= 7))
        break;
    } while (true);

    switch (option) {
    case 1:
      int ndp;
      cout << "Name: ";
      cin >> name;
      cout << endl
           << "Department options: " << endl
           << "1) Business" << endl
           << "2) Science" << endl
           << "3) Engineering" << endl
           << "4) Humanities" << endl
           << "5) International Relations" << endl
           << "6) Tourism" << endl
           << "7) Design and Media";
      l = 0;
      do {
        cout << endl << "Enter the number of the department: ";
        cin >> ndp;
        switch (ndp) {
        case 1:
          dp = "Business";
          l = 1;
          break;
        case 2:
          dp = "Science";
          l = 2;
          break;
        case 3:
          dp = "Engineering";
          l = 3;
          break;
        case 4:
          dp = "Humanities";
          l = 4;
          break;
        case 5:
          dp = "International Relations";
          l = 5;
          break;
        case 6:
          dp = "Tourism";
          l = 6;
          break;
        case 7:
          dp = "Design and media";
          l = 7;
          break;
        default:
          cout << "Incorrect input" << endl;
        }
      } while (l == 0);
      cout << endl << "Age: ";
      cin >> age;
      cout << endl << "Average Heart Rate (bpm): ";
      cin >> hr;
      cout << endl;
      (*(pt_data + size)).setInfo(name, dp, age, hr);

      // LL
      if (l == 1)
        bus.insert(pt_data + size);
      else if (l == 2)
        sci.insert(pt_data + size);
      else if (l == 3)
        eng.insert(pt_data + size);
      else if (l == 4)
        hum.insert(pt_data + size);
      else if (l == 5)
        ir.insert(pt_data + size);
      else if (l == 6)
        tour.insert(pt_data + size);
      else if (l == 7)
        des.insert(pt_data + size);

      if (queueInput(pt_data + size)){ 
        p.enqueue(pt_data + size);
        if (l == 1)
          bus_h.insert(pt_data + size);
        else if (l == 2)
          sci_h.insert(pt_data + size);
        else if (l == 3)
          eng_h.insert(pt_data + size);
        else if (l == 4)
          hum_h.insert(pt_data + size);
        else if (l == 5)
          ir_h.insert(pt_data + size);
        else if (l == 6)
          tour_h.insert(pt_data + size);
        else if (l == 7)
          des_h.insert(pt_data + size);
      }
      size++;
      break;

    case 2:
      cout << setw(10) << "professor" << setw(25) << "department" << setw(10)
           << "age" << setw(18) << "heart rate(bpm)" << endl;
      for (int i = 0; i < size; i++) {
        (*(pt_data + i)).print();
      }
      break;

    case 3:
      for (int i = 0; i < size; i++) {
        *(high_risk + i) = *(pt_data + i);
      }
      high_risk = sort(high_risk, size);
      break;

    case 4:
      p.print_all();
      break;

    case 5:
      cout << p.dequeue() << " has been dequeued." << endl;
      break;

    case 6:
      int u;
      cout << endl
           << "Department options: " << endl
           << "1) Business" << endl
           << "2) Science" << endl
           << "3) Engineering" << endl
           << "4) Humanities" << endl
           << "5) International Relations" << endl
           << "6) Tourism" << endl
           << "7) Design and media";
      cout << endl << "Enter the number of the department: ";
      cin >> u;
      switch (u) {
      case 1:
        bus.printList();
        break;
      case 2:
        sci.printList();
        break;
      case 3:
        eng.printList();
        break;
      case 4:
        hum.printList();
        break;
      case 5:
        ir.printList();
        break;
      case 6:
        tour.printList();
        break;
      case 7:
        des.printList();
        break;
      default:
        cout << "Incorrect input" << endl;
      }
      cout << endl;
      cout << "Professors with HIGH risk of anxiety: " << endl << endl;
      switch (u) {
      case 1:
        bus_h.printList();
        break;
      case 2:
        sci_h.printList();
        break;
      case 3:
        eng_h.printList();
        break;
      case 4:
        hum_h.printList();
        break;
      case 5:
        ir_h.printList();
        break;
      case 6:
        tour_h.printList();
        break;
      case 7:
        des_h.printList();
        break;
      default:
        cout << "Incorrect input" << endl;
      }
      break;

    case 7:
      exit = 1;
      break;
      // default: cout<< "Wrong input."<<endl;
    }
  }

  cout << endl << endl <<"Ending Program"<< endl;

  delete[] pt_data;
  delete[] high_risk;
}