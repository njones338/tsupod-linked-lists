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

#include "Song.h"

using namespace std;

Song::Song()													// Default constructor
{
	artist = "<< empty >>";
	title = "<< empty >>";
	size = 0;
}

Song::Song(string cArtist, string cTitle, int cSize)			// Constructor with parameters
{
	artist = cArtist;
	title = cTitle;
	size = cSize;
}

void Song::setArtist(string songArtist)							// Sets artist private member within Song object
{
	artist = songArtist;
}

void Song::setTitle(string songTitle)							// Sets title private member within Song object
{
	title = songTitle;
}

void Song::setSize(int songSize)								// Sets size private member within Song object
{
	size = songSize;
}

string Song::getArtist() const									// Retrieves artist from Song
{
	return artist;
}

string Song::getTitle() const									// Retrieves title from Song
{
	return title;
}

int Song::getSize() const										// Retrieves size from Song
{
	return size;
}

bool Song::operator > (const Song &s1)							// Overloaded operator function "greater than" for song comparison
{
	bool status;

	if(title > s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator < (const Song &s1)							// Overloaded operator function "less than" for song comparison
{
	bool status;

	if(title < s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator == (const Song &s1)							// Overloaded operator function "equal to" for song comparison
{
	bool status;

	if(title == s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator != (const Song &sBlank)						// Overloaded operator function "not equal to" for song comparison
{
	bool status;

	if(title != sBlank.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}
