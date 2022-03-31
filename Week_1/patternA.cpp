#include <iostream>

using namespace std;

int main(){
  
  int n = 4; // Use a cin instead to take user input
  for(size_t i = 0; i < n; ++i){
    for(size_t b = n-i; b > 0; --b){
      cout<<"  "; // There are 2 whitespaces here
    }
    for(size_t j = 0; j < i+1; ++j){
      cout<<j+1<<" "; // There is 1 whitespace after every digit
    }
    for(size_t k = i; k > 0; --k){
      cout<<k<<" "; // There is 1 whitespace after every digit
    }
    cout<<'\n';
  }
  
  return 0;
}
