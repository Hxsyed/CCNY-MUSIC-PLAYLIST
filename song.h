#ifndef SONG_CLASS
#define SONG_CLASS

#include <iostream>
#include <string>
using namespace std;

class song
{

public:

//default constrctor set all parameter to empty string
song(); 

//constructor with user parameters 
song(string aTitle, string anArtist, double length); 

string getTitle()const; // return title
string getArtist()const; // return artist
double getlength()const; // return length

void setTitle(string newTitle);  // set title
void setArtist(string newArtist); // set Artist 


void Display();  




private:

string title; //title
string artist; //artist
double  length; // length

};

#endif