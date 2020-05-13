#include "Playlist.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintMenu(string name, PlaylistNode *headObj, PlaylistNode *lastObj)
{
	char input = 'n';

	while (input != 'q')
	{
		switch (input)
		{
		case 'M':
		case 'n':
			cout << " " << name << " Playlist " << endl
				 << " p -- Print Playlist" << endl
				 << " a -- Add a new song" << endl
				 << " d -- Delete a song" << endl
				 << " l -- Output length of entire library (in seconds)" << endl
				 << " q -- Quit Program" << endl;

			cout << "   Choose an option: ";
			cin >> input;
			cout << endl;
			break;
		case 'P':
		case 'p':
			headObj->PrintPlaylist(headObj);
			input = 'n';
			break;

		case 'A':
		case 'a':
			lastObj = lastObj->AddSong(headObj);
			input = 'n';
			break;
		case 'D':
		case 'd':
			headObj->DeleteSong(headObj);
			input = 'n';
			break;
		case 'L':
		case 'l':
			cout << "Playlist length is: " << headObj->GetPlaylistSongLength()
				 << " seconds" << endl
				 << endl
				 << endl
				 << endl;
			input = 'n';
			break;
		default:
			cout << "Invalid input, enter another: ";
			cin >> input;
			break;
		}
	}

	return;
}

int main()
{
	char input;
	fstream inFS;
	string name;
	PlaylistNode *headObj;
	PlaylistNode *currObj;
	PlaylistNode *lastObj;

	cout << "Enter playlist name: ";
	getline(cin, name);
	cout << endl;

	headObj = new PlaylistNode("head", "head", 1);
	lastObj = headObj;

	/*

	inFS.open("Songs.txt");
	while (!inFS.eof())
	{ // Imports song list from file
		string ID;
		string song;
		string artist;
		int length;

		inFS >> ID;
		inFS >> song;
		inFS >> artist;
		inFS >> length;

		unsigned int i = 0;
		for (i = 0; i < song.size(); ++i)
		{
			if (song.at(i) == '_')
			{ // Change '_' into spaces for song name
				song.at(i) = ' ';
			}
		}

		for (i = 0; i < artist.size(); ++i)
		{
			if (artist.at(i) == '_')
			{ // Change '_' into spaces for artist name
				artist.at(i) = ' ';
			}
		}

		currObj = new PlaylistNode(ID, song, artist, length);
		lastObj->InsertAfter(currObj);
		lastObj = currObj;
	}

	inFS.close();
	*/

	PrintMenu(name, headObj, lastObj);
	cout << endl
		 << "Have a good day!!\n";
	return 0;
}
