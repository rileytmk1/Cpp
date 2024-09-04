#include <iostream>
#include <cstring>


using namespace std;

int main()
{
  char input[80];
  char str[80];
  char cmp[80];
  cin.get(input, 80);
  for (int i = 0; i < strlen(input); i++){
    if (isalnum(input[i])){
      strcat(str, input[i]);
    }
  }

  cout << str;
  
}
