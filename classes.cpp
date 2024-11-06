#include <iostream>
#include <cstring>
#include <vector>
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
    Movie* newMovie = new Movie();
    cout << "Title: ";
    cin.get(newMovie->getTitle(), 20);
    cin.get();
    
    cout << "Year: ";
    cin >> (newMovie->getYear());
    cin.ignore();
    
   
    cout << "Director: ";
    cin.get(newMovie->getDirector(), 20);
    cin.get();
    
    
    cout << "Rating: ";
    cin >> newMovie->getRating();
    cin.ignore();
    
    media.push_back(newMovie);
    
  }
  
  else if (strcmp(input, "video game") == 0){
    videoGame* newGame = new videoGame();
    cout << "Title: ";
    cin.get(newGame->getTitle(), 20);
    cin.get();

    
    cout << "Year: ";
    cin >> newGame->getYear();
    cin.ignore();
    
    cout << "Publisher: ";
    cin.get(newGame->getPublisher(), 20);
    cin.get();
    
    cout << "Rating: ";
    cin >> newGame->getRating();
    cin.ignore();
    
    media.push_back(newGame);
  }
  
  else if (strcmp(input, "music") == 0) {
    Music* newMusic = new Music();
    cout << "Title: ";
    cin.get(newMusic->getTitle(), 20);
    cin.get();

    
    cout << "Year: ";
    cin >> newMusic->getYear();
    cin.ignore();
    
    cout << "Artist: ";
    cin.get(newMusic->getArtist(), 20);
    cin.get();
    
    cout << "Duration: ";
    cin >> newMusic->getDuration();
    cin.ignore();
    
    media.push_back(newMusic);
   
  }
  

}

void SEARCH(vector<Media*>& media){
  
}



int main()
{
  char input[10];
  vector<Media*> media;
  while (strcmp(input, "QUIT") != 0) {
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "ADD") == 0){
      ADD(media);
    }
    /*
      else if (strcmp(input, "SEARCH") == 0) {
    
      }

      else if(strcmp(input, "DELETE") == 0) {

      }
    */
  }
}
