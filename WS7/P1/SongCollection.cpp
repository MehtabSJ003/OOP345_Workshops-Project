#define _CRT_SECURE_NO_WARNINGS
#include "SongCollection.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
namespace seneca {
	std::string SongCollection::trim(std::string& src) {
		bool valid = false;
		while (!valid)
		{
			if (src[0] == ' ')
			{
				src.erase(0, src.find_first_not_of(' '));
			}
			else if (src[src.length() - 1] == ' ')
			{
				src.erase(src.find_last_not_of(' ') + 1);
			}
			else
			{
				valid = true;
			}
		}
		return src;
	}
	SongCollection::SongCollection(const char* fileName) {
		Song song;
		std::string line;
		std::fstream file(fileName);
		if (!file) 
		{
			throw "Invalid File!";
		}
		while (!file.eof()) 
		{
			getline(file, line, '\n');
			song.s_title = line.substr(0, 25);
			line = line.erase(0, 25);
			song.s_artist = line.substr(0, 25);
			line = line.erase(0, 25);
			song.s_album = line.substr(0, 25);
			line = line.erase(0, 25);
			try
			{
				song.s_year = stoi(line.substr(0, 5));
			}
			catch (...) {
				song.s_year = 0;
			}
			line = line.erase(0, 5);
			//length and price
			song.s_length = stoi(line.substr(0, 5));
			line = line.erase(0, 5);
			song.s_price = stod(line.substr(0, 5));
			line = line.erase(0, 5);
			//title
			song.s_title.erase(0, song.s_title.find_first_not_of(' '));
			song.s_title.erase(song.s_title.find_last_not_of(' ') + 1);
			//artist
			song.s_artist.erase(0, song.s_artist.find_first_not_of(' '));
			song.s_artist.erase(song.s_artist.find_last_not_of(' ') + 1);
			//album
			song.s_album.erase(0, song.s_album.find_first_not_of(' '));
			song.s_album.erase(song.s_album.find_last_not_of(' ') + 1);
			m_songs.push_back(song);
		}
		file.close();
	}
	void SongCollection::display(std::ostream& out)const {
		std::for_each(
			m_songs.begin(), m_songs.end(), [&out](const Song src)
			{
				out << src << std::endl;
			}
		);
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::left << std::setw(20) << theSong.s_title;
		out << " | " << std::left << std::setw(15) << theSong.s_artist;
		out << " | " << std::left << std::setw(20) << theSong.s_album;
		out << " | " << std::right << std::setw(6);
		if (theSong.s_year) 
		{
			out << theSong.s_year;
		}
		else
		{
			out << "";
		}
		out << " | " << std::to_string(theSong.s_length / 60) << ":"
			<< std::setfill('0') << std::setw(2) 
			<< std::to_string(theSong.s_length % 60) << std::setfill(' ');
		out << " | " << std::fixed << std::setprecision(2) << theSong.s_price << " |";
		return out;
	}
}