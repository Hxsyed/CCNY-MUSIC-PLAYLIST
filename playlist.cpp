#include <iostream>
#include <string>
#include <vector>
#include "song.h"
#include "playlist.h"
using namespace std;

// Global variables Playlist Name, Number of songs, tim = Length of all songs
string name;
int numSongs;
double tim;
vector <song> list;

//default constructor
playlist::playlist ()
{
    name = "PlayList";
    numSongs = 0;
    tim=0.0;
    //list={};
    
}

playlist::playlist (string n)
{
    name = n;
    numSongs = 0;
    tim=0.0;
    //list={};

}

song playlist::getSong(int n)
{
    if (list.size()>0)
    {
        return list[n];
    }
    else 
        return song();
    
}

void playlist::addSong (song song)
{
    list.push_back(song);
    numSongs = list.size();
    tim+=song.getlength();
}

 void playlist::removeSong(int n)
 {
    if (n<=list.size())
    {
        double rmt= list[n].getlength();
        list.erase(list.begin() + n);
        numSongs-=1;
        tim-=rmt;
    }
    else
        return;
        
     
 }

  double playlist::totalTime()
  {
      return tim;
  }

void playlist::Display()
{

    cout<<"\nPlayList Name : "<<name<<"\n";
    for (int i=0;i<list.size();i++)
    {
        list[i].Display();
    }
    cout <<"\nThere are "<<numSongs<<" songs in this playlist\nTotal time: "<<tim<<"\n";

    return;

}


