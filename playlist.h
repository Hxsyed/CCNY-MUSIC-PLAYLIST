#ifndef PLAYLIST_CLASS
#define PLAYLIST_CLASS
#include <iostream>
#include <string>
#include <vector>
#include "song.h"
using namespace std;

class playlist
{
    public:

    playlist();

    playlist(string n);
   
   void addSong(song song);
   void removeSong(int n);
   double totalTime();
   song getSong(int n);
   void Display(); 
  
    private:
    std::string name;
    double tim;
    int numSongs;
    std::vector<song> list;
};

#endif

