/****************************************************
Name: Nathan Jones
Date: April 17, 2013
Problem Number: Program 6
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "tsuPod.h"

using namespace std;

TsuPod::TsuPod()								// Default constructor
{
	numSongs = 0;
	maxSize = 0;
}

TsuPod::TsuPod(int CnumSongs, int CmaxSize)		// Constructor with parameters
{
	numSongs = CnumSongs;
	maxSize = CmaxSize;
}

int TsuPod::addSong(string songTitle, string songArtist, int size, int &totalMemory, int &totalSongs)		// Adds song to tsuPod
{
	Song s;													// Declares a Song object for use within function

	if(size < 0)
	{
		cout << "Could not add song, song size cannot be less than zero." << endl << endl;
		return -4;
	}

	if(songTitle == " " || songArtist == " ")
	{
		cout << "Could not add song, song artist or title cannot be blank." << endl;
		return -6;
	}

	totalSongs++;											// Increment total number of songs in TsuPod

	if(totalSongs > numSongs)
	{
		cout << "Could not add song(s), song limit exceeded" << endl;
		totalSongs--;
		return -3;
	}

	totalMemory -= size;									// Adds size of song to memory of TsuPod

	if(totalMemory < 0)
	{
		cout << "Could not add song(s), TsuPod memory exceeded." << endl;
		totalMemory += size;
		totalSongs--;
		return -5;
	}

	s.setTitle(songTitle);									// Assigns song's title to song object

	s.setArtist(songArtist);								// Assigns song's artist to song object

	s.setSize(size);										// Assigns song's size to song object

	ListNode *pointer = new ListNode;
	pointer->song = s;
	pointer->next = NULL;

	ListNode *np;

	if(head == NULL)										// If song is first song to be added, make it the head node of linked list
	{
		head = pointer;
	}
	else													// While any node's next pointer is not NULL, traverse linked list until last node, add song to end of list
	{
		np = head;

		while(np->next != NULL)
		{
			np = np->next;
		}

		np->next = pointer;
	}

	return 0;
}

int TsuPod::removeSong(string songTitle, string songArtist, int size, int &totalMemory, int &totalSongs)		// Removes song from tsuPod
{
	Song s;													// Declares a Song object for use within function

	totalSongs--;

	totalMemory += size;

	s.setTitle(songTitle);									// Sets song title to specified title

	s.setArtist(songArtist);								// Sets song artist to specified artist

	s.setSize(size);										// Sets song size to specified size

	ListNode *nodePtr;										// Pointers to nodes within the tsuPod linked list
	ListNode *previousNode;

	if(head == NULL)										// If list is empty, return error code
		return -1;

	if(head->song == s)										// If song to be removed is first song in list, remove song and make second song first in list
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else													// Deletes specified song node from memory and bridges gap between previous node and next node
	{
		nodePtr = head;

		while(nodePtr != NULL && nodePtr->song != s)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}

	return 0;
}

int TsuPod::showSongList()									// Shows song list of tsuPod
{
	Song s;													// Declares a Song object for use within function

	int i = 0;

	if(head == NULL)										// If head node is NULL, the linked list is empty
	{
		cout << "TsuPod is empty" << endl << endl;
		return -1;
	}
	else													// Traverses linked list of song nodes and displays each song
	{
		cout << "Song List:" << endl << endl;

		ListNode *nodePtr;

		nodePtr = head;

		while(nodePtr != NULL && i < numSongs)
		{
			cout << "Song " << i + 1 << ": " << nodePtr->song.getTitle() << ", "
				<< nodePtr->song.getArtist() << ", Size: " << nodePtr->song.getSize()
				<< "MB" << endl;

			nodePtr = nodePtr->next;

			i++;
		}

		cout << endl;
	}

	return 0;
}

int TsuPod::clearSongList(int &totalMemory, int &totalSongs)			// Clears all songs from tsuPod memory
{
	Song s;													// Declares a Song object for use within function

	totalMemory = maxSize;

	totalSongs = 0;

	int i = 0;

	ListNode *nodePtr;								// Pointers to nodes within the tsuPod linked list
	ListNode *nextPtr;

	nodePtr = head;

	while(nodePtr != NULL && i < numSongs)			// While loop that deletes allocated memory for song nodes within tsuPod
	{
		nextPtr = nodePtr->next;
		delete nodePtr;
		nodePtr = nextPtr;

		i++;
	}

	if(nodePtr == NULL)
	{
		head = NULL;
	}

	return 0;
}

int TsuPod::sortSongList(int totalSongs)								// Sorts song list in alphabetical order
{
	Song s1;										// Song objects used for comparison of song nodes
	Song s2;
	Song sTemp;
	Song sBlank;

	int i = 0;
	int j = i + 1;

	bool swap = true;

	ListNode *s1Ptr;								// Pointers to nodes within the tsuPod linked list
	ListNode *s2Ptr;

	s1Ptr = head;

	while(s1Ptr != NULL && s1Ptr->next != NULL && i < numSongs)			// Loop compares each song with all songs within tsuPod, orders alphabetically
	{
		s1 = s1Ptr->song;

		s2Ptr = s1Ptr->next;

		while(s2Ptr != NULL && j < numSongs + 1)
		{
			s2 = s2Ptr->song;

			if(s2 < s1)
			{
				sTemp = s1;
				s1 = s2;
				s2 = sTemp;

				s2Ptr->song = s2;

				swap = true;
			}
			else if(s2 > s1)
			{
				swap = false;
			}
			else if(s2 == s1)
			{
				swap = false;
			}

			s2Ptr = s2Ptr->next;

			j++;
		}

		s1Ptr->song = s1;

		s1Ptr = s1Ptr->next;

		i++;
	}

	return 0;
}

int TsuPod::getNumSongs() const								// Retrieves numSongs from TsuPod
{
	return numSongs;
}

int TsuPod::getTotalMemory() const							// Retrieves maxSize from TsuPod
{
	return maxSize;
}

int TsuPod::getRemainingMemory(int totalMemory) const		// Retrieves remaining memory within TsuPod
{
	return totalMemory;
}

void TsuPod::setSong(Song sTemp)							// Sets song object
{
	song = sTemp;
}

void TsuPod::numberList()									// Sets head node in linked list to NULL
{
	head = NULL;
}
