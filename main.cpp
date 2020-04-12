#include <iostream>
#include <string>
#include <vector>
#include "song.h"
#include "playlist.h"
using namespace std;

int main()
{
    playlist p1 = playlist("Random");


    


    song s1= song("Hello ", "Adele", 2);
    song s2= song("Godzilla ", "Eminem", 5.8);
    song s3= song("Let me Down slowly ", "Alec Benjamin", 4);

    
    p1.addSong(s1);
    p1.addSong(s2);
    p1.addSong(s3);

    p1.Display();
    //song s4 = p1.getSong(1);
    //s4.Display();
    
  /*  
    cout<<"--------------------------------------";
    p1.removeSong(1);
    p1.Display();
    
    cout<<"---------------------------------------";
    p1.addSong(s4);
    p1.Display();
    
*/
    return 0;
}  