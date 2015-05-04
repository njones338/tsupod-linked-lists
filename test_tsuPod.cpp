/****************************************************
Name: Nathan Jones
Date: April 17, 2013
Problem Number: Program 6
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>

#include "tsuPod.h"
#include "Song.h"

using namespace std;

int main()
{
	TsuPod tsuPod(25, 256);									// Constructor of TsuPod with 25 songs, 256 max memory
	int totalSongs = 0;										// Starting number of songs of blank TsuPod
	int totalMemory = 256;									// Starting memory of blank TsuPod

	cout << endl << "-----  tsuPod -----" << endl << endl;

	cout << "Total memory: " << totalMemory << endl;

	int retCode;											// Return code for error coding

	tsuPod.numberList();									// Creates empty linked list with NULL head node

	tsuPod.showSongList();									// Shows song list of tsuPod

	// Following lines test tsuPod input functionality by adding songs through tsuPod member function addSong

   	retCode = tsuPod.addSong("Comfort Eagle", "Cake", 4, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Mr. Tambourine Man", "Bob Dylan", 7, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Just Like Heaven", "The Cure", 5, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Under the Bridge", "Red Hot Chili Peppers", 8, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Pancho and Lefty", "Townes Van Zandt", 7, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Space Oddity", "David Bowie", 12, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Midnight City", "M83", 9, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Icky Thump", "The White Stripes", 4, totalMemory, totalSongs);

    cout << "(Song list has been added)" << endl << endl;

	tsuPod.showSongList();

	cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << endl;		// Shows remaining memory in tsuPod

	retCode = tsuPod.removeSong("Under the Bridge", "Red Hot Chili Peppers", 8, totalMemory, totalSongs);	// Removes song from tsuPod

	if(retCode == -1)
	{
		cout << "Song list is empty...";
	}

	cout << "(Song 'Under the Bridge' has been removed)" << endl;

	cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << endl << endl;

	tsuPod.showSongList();

	tsuPod.sortSongList(totalSongs);						// Sorts song list in tsuPod

	cout << "(Song list has been sorted)" << endl << endl;

	tsuPod.showSongList();

	tsuPod.clearSongList(totalMemory, totalSongs);			// Clears all songs from tsuPod

	cout << "(Song list has been cleared)" << endl << endl;

	cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << endl;

	tsuPod.showSongList();

	return 0;
}
