#include "Playlist.h"
#include <iostream>
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
				 << " s -- Swap the order of songs" << endl
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
		case 'F':
		case 'f':
			headObj->SwapPositions(headObj);
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
	string name;
	PlaylistNode *headObj;
	PlaylistNode *currObj;
	PlaylistNode *lastObj;

	cout << "Enter playlist name: ";
	getline(cin, name);
	cout << endl;

	headObj = new PlaylistNode("head", "head", 1);
	lastObj = headObj;

	PrintMenu(name, headObj, lastObj);
	cout << endl
		 << "Have a good day!!\n";
	return 0;
}
