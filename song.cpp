#include <iostream>
#include <string>
#include "song.h"

using namespace std;

string title,artist;
double length;

//default constructor 
 song::song()
{
   title = " ";
   artist = " ";
   length = 0;  
}

song::song(string aTitle, string anArtist, double len)
{

title = aTitle; //Assing parameters
artist = anArtist;
length = len;

}

//getter methods 
string song::getTitle() const
{
return title; 
}
string song::getArtist() const 
{
    return artist; 
}
double song::getlength() const
{
    return length; 
}

//setter methods
void song::setTitle(string newTitle)
{
    title= newTitle; 
}

void song::setArtist(string newArtist)
{
    artist=newArtist;
}


void song::Display() 
{
    
    cout<<"Title: "<<title<<"\nArtist: "<<artist<<"\nLength: "<<length<<"\n\n";
}






