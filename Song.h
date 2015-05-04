/****************************************************
Name: Nathan Jones
Date: April 17, 2013
Problem Number: Program 6
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <fstream>

using namespace std;

class Song
{
private:
	string artist;
	string title;
	int size;
public:
	Song();
	Song(string, string, int);
	void setArtist(string);
	void setTitle(string);
	void setSize(int);
	string getArtist() const;
	string getTitle() const;
	int getSize() const;
	bool operator >(const Song &s);
	bool operator <(const Song &s);
	bool operator ==(const Song &s);
	bool operator !=(const Song &sBlank);
};

#endif /* SONG_H_ */
