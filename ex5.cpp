#include <iostream>
#include <string>
#include <climits>
#include <cmath>

int main (){

  using namespace std;

  double a;
  double b;
  double c;
  double d;
  double* x;
  double result;

  int choice;

  double Sum(double, double);
  double Diff(double, double);
  double Prod(double, double);
  double Div(double, double);
  double Intercept (double, double);
  double* Equation (double, double, double, double*);
  double Length3D (double, double, double);
  double Length4D (double, double, double, double);
  double InvMass (double, double, double, double);
  void print1 (int, double);
  void print2 (double*);

  string op;
  string sum;
  string diff;
  string prod;
  string div;

  int loopControl = 0;

  cout << "Hi guys, what would you like to do? \n"; 
  cout << "Choose one of the following operation, choose one number:\n"; 
  cout << "1. Basic Operation\n"; 
  cout <<   "2. Calculate the intercept of a line\n";
  cout << "3.Solve a quadratic equation\n";
  cout << "4. Calculate the length of 3D vectors\n";
  cout << "5. Calculate length of 4D vectors\n";
  cout << "6. Calculate the invariant mass of two particles" << endl;

  cin >> choice;

  while(!cin){
    cout << "Not valid choice, please try again!"<<endl;
    cin.clear(); // clear the flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
    continue;
  }

  if (choice == 1 || choice == 2){

     if (choice == 1) {cout << "Give me two numbers\n";}
     if (choice == 2) {cout << "Give me the slope and the intercept on the y-axis";} 

     while (loopControl == 0){
      
       cin >> a >> b;
       
       if (!cin){
	 cout << "Numbers not valid!"<< endl;
	 cin.clear(); // clear the flag
	 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
	 continue;
       }
       else {
	 loopControl = 1;
       }
     }
     
     if (choice == 1){ 
       while (loopControl == 1){
	 cout << "What operation do you want to perform: sum diff prod div?"<<endl;
	 cin >> op;
	 
	 if (op!= "sum" && op!= "diff" && op!="prod" && op!="div"){
	   cout << "Operation not valid!"<< endl;
	   cin.clear(); // clear the flag
	   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
	   continue;
	 }
	 else {
	   loopControl = 2;
	 }
	 
	 if (op == "sum"){result = Sum(a,b);} 
	 if (op == "diff"){result = Diff(a,b);}
	 if (op == "prod"){result = Prod(a,b);}
	 if (op == "div"){result = Div(a,b);}
       }
     }
     
     if (choice == 2){ 
       result = Intercept (a,b); 
     }
  }
  
  if (choice == 3 || choice == 4){
    
    if (choice == 3) {cout << "Give me the three coefficients of your equation\n";}
    if (choice == 4) {cout << "Give me the components of your 3D vector";} 
    
    while (loopControl == 0){
      
      cin >> a >> b >> c;
      
      if (!cin){
	cout << "Numbers not valid!"<< endl;
	cin.clear(); // clear the flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
	continue;
      }
      else {break;}
    }
    
    if (choice == 3){x = Equation (a, b, c, x);}

    if (choice == 4){result = Length3D (a,b,c);}
    
  }
  
 if (choice == 5 || choice == 6){
    
    if (choice == 5) {cout << "Give me the four component of the 4D vector\n";}
    if (choice == 6) {cout << "Give me the masses and the momenta of the particles";} 
    
    while (loopControl == 0){
      
      cin >> a >> b >> c >> d;
      
      if (!cin){
	cout << "Numbers not valid!"<< endl;
	cin.clear(); // clear the flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
	continue;
      }
      else {break;}
    }
    
    if (choice == 5){result = Length4D (a,b,c,d);}
    if (choice == 6){result = InvMass (a,b,c,d);}
    
  }
    
 if (choice != 3 ) print1 (choice, result);
 if (choice == 3) print2 (x);
 return 0;
  
}


//********* Defining function to do operation ***************

double Sum ( double a, double b){
  return a+b; 
}

double Diff ( double a, double b){
  return a-b; 
}

double Prod ( double a, double b){
  return a*b; 
}

double Div ( double a, double b){
  using namespace std;

  while (b == 0){

    cout << "Impossible dividing by zero!/n Give me another number:"<<endl;
    cin >> b;
    if (b != 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 
  return a/b;
}

double Intercept(double a, double b){
  using namespace std;
  
  while (b == 0){
    
    cout << "Impossible dividing by zero!/n Give me another slope:"<<endl;
    cin >> b;
    if (b != 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 
  return -(a/b);
}

double* Equation (double a, double b, double c, double* x){
 using namespace std;
 
 
 while (a == 0 || b*b-4*a*c < 0){
    
    cout << "Not valid coefficients, try again/n" << endl;
    cin >> a >> b >> c;
    if (a != 0 && b*b-4*a*c < 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 

  x[0] = (-b+sqrt(b*b - 4*a*c))/a;
  x[1] = (-b-sqrt(b*b - 4*a*c))/a;

  return x;

}

double Length3D (double a, double b, double c){
 
  return sqrt (a*a+b*b+c*c);

}

double Length4D (double a, double b, double c, double d){

 using namespace std;
 
 while (d*d-a*a-b*b-c*c < 0){
   
   cout << "Negative value under sqrt, try again/n" << endl;
   cin >> a >> b >> c >> d;
   if (d*d-a*a-b*b-c*c < 0){break;}
   else {
     cin.clear(); // clear the flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
     continue;
   }
 } 
 
  return sqrt (d*d-a*a-b*b-c*c);
  
}

double InvMass (double a, double b, double c, double d){
  using namespace std;
  double theta;
  
  using namespace std;
  cout << "choose the angle between two momenta" << endl;
  cin >> theta;
  
  return a*a + b*b + 2*((sqrt(a*a + c*c))*sqrt(b*b + d*d) - c*d*cos(theta)) ;
  
}

void print1 (int choice, double result ){
  using namespace std;
  if (choice == 1) cout << "The result of the operation is " << result << endl;  
  if (choice == 2) cout << "The intercept of the line on the x axis is  " << result << endl;
  if (choice == 4) cout << "The length of the 3D vector is " << result << endl;
  if (choice == 5) cout << "The length of the 4D vector is " << result << endl;  
  if (choice == 6) cout << "The invariant mass is " << result << endl;
}

void print2(double* x){
  using namespace std;
  cout << "The first result of the quadratic equation is  " << x[0] << endl;
  cout << "The second result of the quadratic equation is  " << x[1] << endl;

}