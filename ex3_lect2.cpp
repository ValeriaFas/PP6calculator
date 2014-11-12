#include <iostream>
#include <string>
#include <cmath>
#include <climits>


// function declaration

void swap (int* array){

  int dim = 5;
  int temp1;
  int temp2;

   while (array[0] < array[1] || array[1] < array[2] || array[2] < array[3] || array[3] < array[4]){
    for (int h = 0; h < dim; h ++){
      if (array[h] < array[h+1]) {
	temp1 = array[h];
	temp2 = array[h+1];
	array[h] = temp2;
	array[h+1] = temp1;
      }
      else continue;      
    }
  }
  return;
}



int main(){
  
  using namespace std;

  int dim = 5;
  int *array = new int[dim];
 

  for (int k = 0; k < dim; k ++){
    cout << "Give the component " << k << " of the array" << endl; 
    cin >> array[k];// >> array[1] >> array[2] >> array[3] >> array[4];
  }

  swap (array);

  cout << "your array is" << endl;
  for (int j = 0; j < dim; j++){
    cout << array[j] << endl;
  }
  return 0;
}


