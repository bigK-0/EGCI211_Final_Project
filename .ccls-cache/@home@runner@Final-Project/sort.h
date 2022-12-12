#include "data.h"

data *sort(data *a, int N) {
  int i, j, value;
  data *temp = (data *)malloc(sizeof(data));
  for (i = 0; i < N - 1; i++) {
    for (j = i + 1; j < N; j++) {
      if ((*(a + i)).get_heartRate() < (*(a + j)).get_heartRate()) {
        *temp = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = *temp;
      }
    }
  }

  cout << endl << "Sorted list (High to Low heart rate):" << endl << endl;

  cout << setw(10) << "professor" << setw(25) << "department" << setw(10)
       << "age" << setw(18) << "heart rate(bpm)" << endl;

  for (i = 0; i < N; i++) {
    (*(a + i)).print();
  }
  cout << endl;

  // grouping high risk and low risk
  data *high_risk = new data[N];
  data *low_risk = new data[N];
  int k = 0, l = 0;

  for (i = 0; i < N; i++) {

    if (a[i].get_age() >= 70 && a[i].get_heartRate() > 128) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 65 && a[i].get_age() < 70 &&
             a[i].get_heartRate() > 132) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 60 && a[i].get_age() < 65 &&
             a[i].get_heartRate() > 136) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 55 && a[i].get_age() < 60 &&
             a[i].get_heartRate() > 140) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 50 && a[i].get_age() < 55 &&
             a[i].get_heartRate() > 145) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 45 && a[i].get_age() < 50 &&
             a[i].get_heartRate() > 149) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 40 && a[i].get_age() < 45 &&
             a[i].get_heartRate() > 153) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 35 && a[i].get_age() < 40 &&
             a[i].get_heartRate() > 157) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() >= 30 && a[i].get_age() < 35 &&
             a[i].get_heartRate() > 162) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else if (a[i].get_age() < 30 && a[i].get_heartRate() > 170) {
      *(high_risk + k) = *(a + i);
      k++;
    }

    else {
      *(low_risk + l) = *(a + i);
      l++;
    }
  } // end for

  cout << "Professors with HIGH risk of anxiety: " << endl;
  cout << setw(10) << "professor" << setw(25) << "department" << setw(10)
       << "age" << setw(18) << "heart rate(bpm)" << endl;
  for (i = 0; i < k; i++) {
    (*(high_risk + i)).print();
  }
  if (k == 0)
    cout << setw(27) << "-----None-----";
  cout << endl;
  cout << endl;

  cout << "Professors with LOW risk of anxiety: " << endl;
  cout << setw(10) << "professor" << setw(25) << "department" << setw(10)
       << "age" << setw(18) << "heart rate(bpm)" << endl;
  for (i = 0; i < l; i++) {
    (*(low_risk + i)).print();
  }
  if (l == 0)
    cout << setw(27) << "-----None-----";
  cout << endl;
  return high_risk;
}

bool queueInput(data *a) {
  if ((a->get_age() >= 70 && a->get_heartRate() > 128) ||
      (a->get_age() >= 65 && a->get_age() < 70 && a->get_heartRate() > 132) ||
      (a->get_age() >= 60 && a->get_age() < 65 && a->get_heartRate() > 136) ||
      (a->get_age() >= 55 && a->get_age() < 60 && a->get_heartRate() > 140) ||
      (a->get_age() >= 50 && a->get_age() < 55 && a->get_heartRate() > 145) ||
      (a->get_age() >= 45 && a->get_age() < 50 && a->get_heartRate() > 149) ||
      (a->get_age() >= 40 && a->get_age() < 45 && a->get_heartRate() > 153) ||
      (a->get_age() >= 35 && a->get_age() < 40 && a->get_heartRate() > 157) ||
      (a->get_age() >= 30 && a->get_age() < 35 && a->get_heartRate() > 162) ||
      (a->get_age() < 30 && a->get_heartRate() > 170))
    return true;
  else
    return false;
}