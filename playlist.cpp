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

// FUNCTION TO DELETE A SONG FROM THE PLAYLIST
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

void PlaylistNode::InsertAfter(PlaylistNode *nodeLoc)
{
	PlaylistNode *tmpVal = 0;

	tmpVal = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpVal;

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
