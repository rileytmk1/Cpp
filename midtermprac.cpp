#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[100];
  cin.get(input, 99);
  cin.get();
  for (int i = 0; i < strlen(input); i++){
    char temp;
    if (i == 0 && input[i+1] != ' '){
      temp = input[0];
      input[0] = input[1];
      input[1] = temp;
    }
    if (input[i] == ' ' && input[i+2] != ' '){
      temp = input[i+1];
      input[i+1] = input[i+2];
      input[i+2] = temp;
    }
  }
  cout << input << endl;
  return 0;
}
