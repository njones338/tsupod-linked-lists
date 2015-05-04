/****************************************************
Name: Nathan Jones
Date: April 17, 2013
Problem Number: Program 6
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef TSUPOD_H_
#define TSUPOD_H_

#include "Song.h"
#include <string>
#include <fstream>

using namespace std;

class TsuPod
{
private:
	Song song;
	int numSongs;
	int maxSize;
	fstream fio;
	struct ListNode
	{
		Song song;
		ListNode *next;
	};
	ListNode *head;
public:
	TsuPod();
	TsuPod(int, int);
	void numberList();
	int initTsuPod();
	int addSong(string, string, int, int&, int&);
	int removeSong(string, string, int, int&, int&);
	int clearSongList(int&, int&);
	int showSongList();
	int sortSongList(int);
	int getTotalMemory() const;
	int getRemainingMemory(int) const;
	int getNumSongs() const;
	void setSong(Song);
};

#endif /* TSUPOD_H_ */
