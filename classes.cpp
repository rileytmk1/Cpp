#include <iostream>
#include <cstream>
#include "media.h"
#include "childMusic.h"
#include "childGames.h"
#include "childMovies.h"

using namespace std;

void ADD(vector<Media*>& media){
  char input[50];
  cout << "What type of media do you want to add?" << endl;
  cin.get(input,50);
  cin.get();
  if (strcmp(input, "movie") == 0){
    Movie newMovie = new Movie();
    cout << "Title: " << endl;
    cin >> newMovie->getTitle();
    
    cin.get();


    cout << "Year: " << endl;
    cin >> newMovie->getYear();
    cin.ignore();


    cout << "Publisher: " << endl;
    cin >> newMovie->getPublisher();
    cin.get();

    float rating;
    cout << "Rating: " << endl;
    cin >> newMovie->getRating;
    cin.ignore();
    
  }
  else if (strcmp(input, "video game") == 0){
    Game newGame = new Game();
    cout << "Title: " << endl;
    cin.get(input, 50);
    cin.get();


    int year;
    cout << "Year: " << endl;
    cin >> year;
    cin.ignore();
  }
  else if (strcmp(input, "music") == 0) {
    Music newMusic = new Music();
    cout << "Title: " << endl;
    cin.get(input, 50);
    cin.get();


    cout << "Year: " << endl;
    cin >> newMusic->getYear();
    cin.ignore();
  }
}

void SEARCH(vector<Media*>& media){

}



int main()
{
  char input[10];
  vector<Media*>& media;
  cin.get(input, 10);
  cin.get();

  if (strcmp(input, "ADD") == 0){
    ADD(media);
  }

  else if (strcmp(input, "SEARCH") == 0) {
    
  }

  else if(strcmp(input, "DELETE") == 0) {

  }
}
