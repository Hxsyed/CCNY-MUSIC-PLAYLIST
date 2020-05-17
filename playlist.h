#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <cstring>
using namespace std;

class PlaylistNode
{
public:
	PlaylistNode(string initSongName = " Unknown ", string initArtistName = " Unknown ", int initLength = 0, PlaylistNode *initLoc = 0);
	string GetSongName();
	string GetArtistName();
	PlaylistNode *GetNextNode();
	int GetSongLength();
	int GetPlaylistSongLength();
	PlaylistNode *AddSong(PlaylistNode *headNode);
	void DeleteSong(PlaylistNode *entryNode);
	void PrintPlaylistNode();
	void PrintPlaylist(PlaylistNode *headObj);
	void InsertAfter(PlaylistNode *nodeLoc);
	void play(int songs);
	void ShowStatus() const

private:
	string songName;
	string artistName;
	int songLength;
	int song_place;
	PlaylistNode *nextNodePtr;
};
#endif
