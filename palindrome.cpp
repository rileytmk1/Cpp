#include <iostream>
#include <cstring>


using namespace std;

int main()
{
  char input[81]; //char array for input
  char str[81]; //char array for removal of spaces and punctuation
  char compare[81]; //char array to compare with str
  cin.get(input, 81);
  cin.get(); //eat new line
  int count = 0;

  // remove spaces and punctuation from input, put the result into str
  for (int i = 0; i < strlen(input); i++){
     if (isalnum(input[i])){
      str[count] = (char) tolower(input[i]);
      count++;
    }
  }

  //add null terminator for comparing

  str[count] = '\0';

  int c = 0;

  //reverse str to check for palindrome
  for (int i = strlen(str)-1; i >= 0; i--){
    compare[c] = str[i];
    c++;
  }

  //add null terminator for comapring
  compare[count] = '\0';

  if(strcmp(str, compare) == 0){
    cout << "Palindrome." << endl;
  }
  else{
    cout << "Not a palindrome." << endl;
  }
  return 0;
    
}
