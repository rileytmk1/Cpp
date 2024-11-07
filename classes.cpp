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

    cout << "Duration: ";
    cin >> newMovie->getDuration();
    cin.ignore();
    
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

    cout << "Publisher: ";
    cin >> newMusic->getPublisher();
    cin.get();
    
    cout << "Duration: ";
    cin >> newMusic->getDuration();
    cin.ignore();
    
    media.push_back(newMusic);
   
  }
  

}

void SEARCH(char* title, vector<Media*>& media){
  bool found = false;
  for (auto& item : media){
    if (strcmp(item->getTitle(), title) == 0) {
      cout << "Title: " << item->getTitle() << ", Year: " << item->getYear() << " ";

      if (Movie* movie = dynamic_cast<Movie*>(item)){
	cout << "Director: " << movie->getDirector() << ", Duration: " << movie->getDuration() << ", Rating: " << movie->getRating();
      }
      else if (videoGame* game = dynamic_cast<videoGame*>(item)){
	cout << "Publisher: " << game->getPublisher() << ", Rating: " << game->getRating();
      }
      else if (Music* music = dynamic_cast<Music*>(item)){
	cout << "Artist: " << music->getArtist() << ", Duration: " << music->getDuration() << ", Publisher: " << music->getPublisher();
      }
      cout << endl;
      found = true;
	
    }
  }
  if (found == false) {
    cout << "No media found." << endl;
  }
}

void SEARCH(int year, vector<Media*>& media){
bool found = false;
  for (auto& item : media){
    if (item->getYear() == year) {
      cout << "Title: " << item->getTitle() << ", Year: " << item->getYear() << " ";

      if (Movie* movie = dynamic_cast<Movie*>(item)){
        cout << "Director: " << movie->getDirector() << ", Duration: " << movie->getDuration() << ", Rating: " << movie->getRating();
      }
      else if (videoGame* game = dynamic_cast<videoGame*>(item)){
        cout << "Publisher: " << game->getPublisher() << ", Rating: " << game->getRating();
      }
      else if (Music* music = dynamic_cast<Music*>(item)){
        cout << "Artist: " << music->getArtist() << ", Duration: " << music->getDuration() << ", Publisher: " << music->getPublisher();
      }
      cout << endl;
      found = true;

    }
  }
  if (found == false) {
    cout << "No media found." << endl;
  }  

}

void DELETE(char* title, vector<Media*>& media){
  bool found = false;
  char input;
  for (auto it = media.begin(); it != media.end();){
    if (strcmp((*it)->getTitle(), title) == 0){
      cout << "Media found! Are you sure you want to delete this media? (y or n) ";
      cin >> input;
      cin.ignore();
      found = true;
      if (input == 'y'){
	delete *it;
	it = media.erase(it);
      }
      cout << endl;
    }
    else{
      ++it;
    }
  }
  if (found == false){
    cout << "Media not found." << endl;
  }
  
}

void DELETE(int year, vector<Media*>& media){
  bool found = false;
  char input;
  for (auto it = media.begin(); it != media.end();){
    if ((*it)->getYear() == year){
      cout << "Media found! Are you sure you want to delete this media? (y or n) ";
      cin >> input;
      cin.ignore();
      found = true;
      if (input == 'y'){
	delete *it;
	it = media.erase(it);
      }
      cout << endl;
    }
    else{
      ++it;
    }
    
  }
  if (found == false){
    cout << "Media not found." << endl;
  }
}



int main()
{
  char input[10];
  vector<Media*> media;
  while (strcmp(input, "QUIT") != 0) {
    cout << "ADD, SEARCH or DELETE?" << endl;
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "ADD") == 0){
      ADD(media);
    }
        
    else if (strcmp(input, "SEARCH") == 0) {
      char type[20];
      cout << "What do you want to search by? (title or year)" << endl;
      cin.get(type, 20);
      cin.get();
      if (strcmp(type, "title") == 0) {
	char title[20];
	cout << "Title: ";
	cin.get(title, 20);
	cin.get();
	SEARCH(title, media);
      }
      else if (strcmp(type, "year") == 0) {
	int year;
	cout << "Year: ";
	cin >> year;
	cin.ignore();
	SEARCH(year, media);
      }
    }

    else if(strcmp(input, "DELETE") == 0) {
      char type2[20];
      cout << "What do you want to delete by? (title or year)" << endl;
      cin.get(type2, 20);
      cin.get();
      if (strcmp(type2, "title") == 0){
	char title[20];
	cout << "Title: ";
	cin.get(title, 20);
	cin.get();
	DELETE(title, media);
      }
      else if (strcmp(type2, "year") == 0) {
	int year;
	cout << "Year: ";
	cin >> year;
	cin.ignore();
        DELETE(year, media);
      }
    }
    
  }
}
