#include <iostream>
#include <map>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  char input[100];
  cin.get(input, 99);
  cin.get();
  map <char, int> m;
  for (int i = 0; i < strlen(input); i++){
    if (isalnum(input[i])){
      m[tolower(input[i])]++;
    }
  }
  for (auto it = m.begin(); it != m.end(); it++){
    cout << (*it).first << ":" << " " << (*it).second << " ";
  }

  return 0;
  
}
  
