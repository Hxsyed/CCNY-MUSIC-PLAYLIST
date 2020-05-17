#include <iostream>
#include <string>
#include <fstream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode(string initSongName, string initArtistName, int initLength, PlaylistNode *initLoc)
{
	this->songName = initSongName;
	this->artistName = initArtistName;
	this->songLength = initLength;
	this->nextNodePtr = initLoc;
	num_of_songs = -1;
	song_place = 0;
	return;
};

//Accessor methods---------------------
string PlaylistNode::GetSongName()
{
	return this->songName;
}

string PlaylistNode::GetArtistName()
{
	return this->artistName;
}

int PlaylistNode::GetSongLength()
{

	return this->songLength;
}
PlaylistNode *PlaylistNode::GetNextNode()
{

	return this->nextNodePtr;
}
//----------END-------------------------

// FUNCTION TO GET THE LENGTH OF THE PLAYLIST
int PlaylistNode::GetPlaylistSongLength()
{
	PlaylistNode *currNode = this->GetNextNode();
	int PlaylistLength = 0;

	while (currNode != 0)
	{
		PlaylistLength += currNode->GetSongLength();
		currNode = currNode->GetNextNode();
	}

	return PlaylistLength;
}

// FUNCTION TO ADD  A SONG TO THE PLAYLIST
PlaylistNode *PlaylistNode::AddSong(PlaylistNode *headNode)
{
	string nSongName, nArtistName;
	int songLength;
	PlaylistNode *nNode, *tailNode = headNode;

	cout << "    ---ADD SONG---" << endl;

	cin.ignore(99, '\n');

	cout << " Enter song name : ";
	getline(cin, nSongName);

	cout << " Enter artist name : ";
	getline(cin, nArtistName);

	cout << " Enter song length (In seconds): ";
	cin >> songLength;
	while (!cin)
	{
		cin.clear();
		cin.ignore(99, '\n');
		cout << "-Enter a number : ";
		cin >> songLength;
	}
	cout << "=====Song Added!=====" << endl;

	nNode = new PlaylistNode(nSongName, nArtistName, songLength);
	while (tailNode->GetNextNode() != 0)
	{
		tailNode = tailNode->GetNextNode();
	}
	tailNode->InsertAfter(nNode);

	return nNode;
}

// Function for deleting a song from the playlist
void PlaylistNode::DeleteSong(PlaylistNode *entryNode)
{
	PlaylistNode *currNode;
	PlaylistNode *prevNode;
	string N;
	bool found = false;
	char userChoice = 'n';

	prevNode = entryNode;
	currNode = prevNode->nextNodePtr;

	if (entryNode->nextNodePtr == 0)
	{
		cout << "ERROR: Playlist is empty, nothing to delete." << endl
			 << endl;
		return;
	}

	cout << "    ----DELETE SONG----" << endl;

	cout << " Enter Name of Song to delete: ";
	cin >> N;

	while (found != true || cin.fail())
	{

		if (currNode->songName == N)
		{

			cout << "\n found\n";
			found = true;
		}
		else if (currNode->GetNextNode() == 0)
		{
			if (currNode->songName == N)
			{
				//Found song that need to be deleted
				found = true;
			}
			else
			{
				cout << "\nERROR: Song not found\n";
				break;
			}
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->GetNextNode();
		}
	}

	if (found == true)
	{

		cout << "\"" << currNode->songName << "\""
			 << ": will be deleted, are you sure? (y/n): ";
		cin >> userChoice;
		while ((userChoice != 'y' && userChoice != 'n') && (userChoice != 'Y' && userChoice != 'N'))
		{
			cout << "Must be \"y\" or \"n\" character: ";
			cin >> userChoice;
		}
		if (userChoice == 'y')
		{
			cout << "\"" << currNode->songName << "\" was deleted from your playlist" << endl
				 << endl;
			prevNode->nextNodePtr = currNode->nextNodePtr;

			delete currNode;
		}
	}

	cout << "    ----DONE----" << endl
		 << endl;

	return;
}

void PlaylistNode::PrintPlaylistNode()
{

	cout << " Song Name :   " << this->songName << endl
		 << " Artist Name : " << this->artistName << endl
		 << " Song Length : " << this->songLength << endl;

	return;
}

// FUNCTION TO PRINT THE ENTIRE PLAYLSIT
void PlaylistNode::PrintPlaylist(PlaylistNode *headObj)
{
	PlaylistNode *currObj;
	int i = 1;

	currObj = headObj->GetNextNode();

	cout << "    ----PRINTED PLAYLIST----" << endl;

	if (headObj->nextNodePtr == 0)
	{
		cout << "Playlist is empty!" << endl
			 << endl;
	}

	while (currObj != 0)
	{

		cout << i << "." << endl;
		currObj->PrintPlaylistNode();
		currObj = currObj->GetNextNode();

		cout << endl;
		++i;
	}

	return;
}
//FUNCTION TO PLAY A FIXED AMOUNT OF SONGS
void PlaylistNode::play(int songs)
{
	for (int i = 0; i < songs; i++)
	{
		if (song_place > GetPlaylistSongLength)
		{
			song_place = 0;
		}
		cout << PlaylistNode[song_place] << endl;

		song_place++;

		if (song_place == (GetPlaylistSongLength))
		{
			song_place = 0;
		}
	}
}

void PlaylistNode::InsertAfter(PlaylistNode *nodeLoc)
{
	PlaylistNode *tmpVal = 0;

	tmpVal = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpVal;

	return;
}
