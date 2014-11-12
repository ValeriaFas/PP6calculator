#include <iostream>
#include <string>
#include <cmath>
#include <climits>

void swap(int& d, int& e){
  int temp1;
  int temp2;

  temp1 = d;
  temp2 = e;

  e = temp1;
  d = temp2;
    
}

void Equation (double a, double b, double c, double* res){

  double y1;
  double y2;
  bool check;

  using namespace std;
  
  while (a == 0 || b*b-4*a*c < 0){
    
    cout << "Not valid coefficients because either the first coefficient is zero or the descriminant is negative, try again\n" << endl;
    cin >> a >> b >> c;
    if (a != 0 && b*b-4*a*c < 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 
  
  y1 = (-b+sqrt(b*b - 4*a*c))/2*a;
  y2 = (-b-sqrt(b*b - 4*a*c))/2*a;
  
  res[0] = y1;
  res[1] = y2;

   return;
}


int main(){

  using namespace std;

  int a;
  int b;
  int c;

  double* solution = new double[2];

  int d = 1;
  int e = 2;

  swap (d,e);
  //cout << "The value of d is " << d << "  the value of e is  " << e << endl;

  cout << "Give me the coefficient of your quadratic equation"<< endl;

  cin >> a >> b >> c;
  
  Equation (a,b,c,solution);

  cout << "The first solution of the equation is " << solution[0] << " the second one is  " << solution[1] << endl;
  
  return 0;
}


