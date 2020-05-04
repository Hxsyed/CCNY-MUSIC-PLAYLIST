#include "Playlist.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintMenu(string name, PlaylistNode *headObj, PlaylistNode *lastObj)
{
	char input = 'm';

	while (input != 'q')
	{
		switch (input)
		{
		case 'M':
		case 'm':
			cout << " ====== " << name << " Playlist ======" << endl
				 << " p -- Print Playlist" << endl
				 << " a -- Add a new song" << endl
				 << " d -- Delete a song" << endl
				 << " c -- Change position of song" << endl
				 << " l -- Output length of entire library (in seconds)" << endl
				 << " f -- Find song by artist" << endl
				 << " o -- Output playlist to file" << endl
				 << " q -- Quit Program" << endl;

			cout << "   Choose an option: ";
			cin >> input;
			cout << " ======================================";
			cout << endl;
			break;
		case 'P':
		case 'p':
			headObj->PrintPlaylist(headObj);
			input = 'm';
			break;

		case 'A':
		case 'a':
			lastObj = lastObj->AddSong(headObj);
			input = 'm';
			break;
		case 'D':
		case 'd':
			headObj->DeleteSong(headObj);
			input = 'm';
			break;
		case 'C':
		case 'c':
			headObj->ChangePositions(headObj);
			input = 'm';
			break;
		case 'L':
		case 'l':
			cout << "Playlist length is: " << headObj->GetPlaylistSongLength()
				 << " seconds" << endl
				 << endl
				 << endl
				 << endl;
			input = 'm';
			break;
		case 'F':
		case 'f':
			headObj->PrintSongByArtist();
			cout << endl
				 << endl
				 << endl;
			input = 'm';
			break;
		case 'O':
		case 'o':
			headObj->OutputToFile();
			input = 'm';
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

	headObj = new PlaylistNode("head", "head", "head", 1);
	lastObj = headObj;

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

	PrintMenu(name, headObj, lastObj);

	cout << endl
		 << endl
		 << "Save playlist to file? (y/n): ";
	cin >> input;
	while ((input != 'y' && input != 'Y') && (input != 'n' && input != 'N'))
	{ // Asks whether to save playlist
		cin.clear();
		cin.ignore(99, '\n');
		cout << "-Enter either \"y\" or \"n\":";
		cin >> input;
	}

	if (input == 'y' || input == 'Y')
	{
		headObj->OutputToFile();
	}

	cout << endl
		 << "Have a good day!!";
	return 0;
}