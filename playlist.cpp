#include <iostream>
#include <string>
#include <fstream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode(string initID, string initSongName, string initArtistName, int initLength, PlaylistNode *initLoc)
{

	this->uniqueID = initID;
	this->songName = initSongName;
	this->artistName = initArtistName;
	this->songLength = initLength;
	this->nextNodePtr = initLoc;

	return;
};

string PlaylistNode::GetID()
{

	return this->uniqueID;
}

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

PlaylistNode *PlaylistNode::AddSong(PlaylistNode *headNode)
{
	string nID, nSongName, nArtistName;
	int songLength;
	PlaylistNode *nNode, *tailNode = headNode;

	cout << "    ---ADD SONG---" << endl;

	cin.ignore(99, '\n');
	cout << " Enter unique ID: ";
	cin >> nID;

	nID = headNode->CheckID(nID, tailNode, headNode);

	cin.ignore();
	cout << " Enter song name: ";
	getline(cin, nSongName);

	cout << " Enter artist name: ";
	getline(cin, nArtistName);

	cout << " Enter song length (In seconds): ";
	cin >> songLength;
	while (!cin)
	{
		cin.clear();
		cin.ignore(99, '\n');
		cout << "-Enter a number: ";
		cin >> songLength;
	}

	nNode = new PlaylistNode(nID, nSongName, nArtistName, songLength);
	while (tailNode->GetNextNode() != 0)
	{
		tailNode = tailNode->GetNextNode();
	}
	tailNode->InsertAfter(nNode);

	return nNode;
}

void PlaylistNode::DeleteSong(PlaylistNode *entryNode)
{
	PlaylistNode *currNode;
	PlaylistNode *prevNode;
	string deleteID;
	bool found = false;
	char userChoice = 'n';

	prevNode = entryNode;
	currNode = prevNode->nextNodePtr;

	if (entryNode->nextNodePtr == 0)
	{
		cout << "ERROR: Playlist is empty, nothing to delete... you monster..." << endl
			 << endl;
		return;
	}

	cout << "    ----DELETE SONG----" << endl;

	cout << " Enter ID to delete: ";
	cin >> deleteID;

	while (found != true || cin.fail())
	{

		if (currNode->uniqueID == deleteID)
		{

			cout << "\n found\n";
			found = true;
		}
		else if (currNode->GetNextNode() == 0)
		{
			if (currNode->uniqueID == deleteID)
			{
				cout << "\n found, \n";
				found = true;
			}
			else
			{
				cout << "\nERROR: ID not found\n";
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
			 << " will be deleted, are you sure? (y/n): ";
		cin >> userChoice;
		while ((userChoice != 'y' && userChoice != 'n') && (userChoice != 'Y' && userChoice != 'N'))
		{
			cout << "Must be \"y\" or \"n\" character: ";
			cin >> userChoice;
		}
		if (userChoice == 'y')
		{
			cout << "\"" << currNode->songName << "\" was deleted" << endl
				 << endl;
			prevNode->nextNodePtr = currNode->nextNodePtr;

			delete currNode;
		}
	}

	cout << "    ----DONE----" << endl
		 << endl;

	return;
}

PlaylistNode *PlaylistNode::GetNextNode()
{

	return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{

	cout << " Unique ID:   " << this->uniqueID << endl
		 << " Song Name:   " << this->songName << endl
		 << " Artist Name: " << this->artistName << endl
		 << " Song Length: " << this->songLength << endl;

	return;
}

void PlaylistNode::PrintPlaylist(PlaylistNode *headObj)
{
	PlaylistNode *currObj;
	int i = 1;

	currObj = headObj->GetNextNode();

	cout << "    ----PRINT PLAYLIST----" << endl;

	if (headObj->nextNodePtr == 0)
	{
		cout << "Playlist is empty, fill it up!!" << endl
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

void PlaylistNode::PrintSongByArtist()
{
	PlaylistNode *currNode;
	string searchArtist;
	bool found = false;

	currNode = this;

	cout << "    ----FIND SONG BY ARTIST----" << endl;

	cout << " Enter artist name: ";
	cin.ignore(99, '\n');
	getline(cin, searchArtist);

	while (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "--ERROR Enter another name: ";
		cin >> searchArtist;
	}

	while (currNode != 0)
	{
		if (currNode->GetArtistName() == searchArtist)
		{
			cout << currNode->GetSongName() << endl;
			found = true;
		}
		currNode = currNode->GetNextNode();
	}

	if (found == false)
	{
		cout << " Artist not found" << endl
			 << endl;
	}

	delete currNode;
	return;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodeLoc)
{
	PlaylistNode *tmpVal = 0;

	tmpVal = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpVal;

	return;
}

void PlaylistNode::ChangePositions(PlaylistNode *headNode)
{
	PlaylistNode *currNode;
	PlaylistNode *targetNode = 0;
	int i = 1, songPos, newSongPos, playlistLength = 0;

	currNode = headNode->GetNextNode();

	while (currNode != 0)
	{
		++playlistLength;
		currNode = currNode->GetNextNode();
	}

	cout << "    --SWAP POSTIONS--" << endl;

	cout << " Enter song's current position: ";
	cin >> songPos;
	while (songPos < 1 || songPos > playlistLength || cin.fail())
	{
		cin.clear(); // Determines whether input is valid
		cin.ignore(999, '\n');
		cout << "(ERROR) Enter a number 1-" << playlistLength << ": ";
		cin >> songPos;
	}

	currNode = headNode->GetNextNode();

	while (currNode != 0)
	{
		if (i == songPos)
		{
			targetNode = currNode;
			break;
		}
		++i;
		currNode = currNode->GetNextNode();
	}

	cout << endl
		 << endl
		 << " Enter new position for song \"" << targetNode->songName << "\": ";
	cin >> newSongPos;
	while (cin.fail())
	{
		cin.clear(); // Determines whether input is valid
		cin.ignore(999, '\n');
		cout << "(ERROR) Enter a number 1-" << playlistLength << ": ";
		cin >> newSongPos;
	}

	if (newSongPos < 1)
	{ // Sets value to 1 or max value if input is too high
		newSongPos = 1;
	}
	else if (newSongPos > playlistLength)
	{
		newSongPos = playlistLength;
	}
	else if (newSongPos == songPos)
	{
		return;
	}

	currNode = headNode;

	while (currNode != 0)
	{
		if (currNode->nextNodePtr == targetNode)
		{
			currNode->nextNodePtr = targetNode->nextNodePtr;
			targetNode->nextNodePtr = 0;
			break;
		}

		currNode = currNode->nextNodePtr;
	}

	currNode = headNode;
	i = 0;

	while (currNode != 0)
	{
		if ((i + 1) == newSongPos)
		{
			currNode->InsertAfter(targetNode);
			break;
		}
		currNode = currNode->GetNextNode();
		++i;
	}

	cout << endl
		 << "    --DONE--" << endl
		 << endl;
	return;
}

void PlaylistNode::OutputToFile()
{
	PlaylistNode *currNode = this->GetNextNode();
	fstream outFS;
	unsigned int i, length;
	string song, artist, ID;

	outFS.open("Songs.txt", std::istream::out | std::istream::trunc);

	while (currNode != 0)
	{
		song = currNode->GetSongName();
		artist = currNode->GetArtistName();
		ID = currNode->GetID();
		length = currNode->GetSongLength();

		for (i = 0; i < song.size(); ++i)
		{
			if (song.at(i) == ' ')
			{
				song.at(i) = '_';
			}
		}

		for (i = 0; i < artist.size(); ++i)
		{
			if (artist.at(i) == ' ')
			{
				artist.at(i) = '_';
			}
		}
		if (currNode->GetNextNode() == 0)
		{
			outFS << ID << " "
				  << song << " "
				  << artist << " "
				  << length;
		}
		else
		{
			outFS << ID << " "
				  << song << " "
				  << artist << " "
				  << length << endl;
		}

		currNode = currNode->GetNextNode();
	}

	outFS.close();

	cout << endl
		 << endl;
	return;
}

string PlaylistNode::CheckID(string checkNodeID, PlaylistNode *tailNode, PlaylistNode *headNode)
{
	PlaylistNode *currNode, *prevNode;

	prevNode = headNode;
	currNode = headNode->nextNodePtr;

	while (prevNode != tailNode)
	{
		if (currNode->uniqueID == checkNodeID)
		{
			cout << "ERROR: ID already taken, choose another: ";
			cin >> checkNodeID;
			currNode = headNode;
		}
		else if ((currNode == tailNode) && (currNode->uniqueID == checkNodeID))
		{
			cout << "ERROR: ID already taken, choose another: ";
			cin >> checkNodeID;
			currNode = headNode;
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->nextNodePtr;
		}
	}

	return checkNodeID;
}
