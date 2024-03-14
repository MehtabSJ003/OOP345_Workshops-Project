#define _CRT_SECURE_NO_WARNINGS
#include "SongCollection.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
namespace seneca {
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
			song.m_price = stod(line.substr(0, 5));
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
		for_each(m_songs.begin(), m_songs.end(), [&](const Song& src) 
			{
			out << src << std::endl;
			}
		);
		out << "----------------------------------------------------------------------------------------" << std::endl;
		size_t i = 0;
		for_each(m_songs.begin(), m_songs.end(), [&](const Song& src) 
			{
			i += src.s_length;
			}
		);
		int hours, mins, secs;
		 hours = (i / 60) / 60;
		 mins = (i / 60) % 60;
		 secs = i % 60;
		out << "|                                                        Total Listening Time: " << hours << ":" << mins << ":" << secs << " |" << std::endl;
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
		out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";
		return out;
	}
	void SongCollection::sort(const std::string& str) {
		auto compare = [str](const Song songA, const Song songB)
		{
			bool check = false;
			if (str == "length") 
			{
				check = songA.s_length < songB.s_length;
			}
			else if (str == "title")
			{
				check = strcmp(songA.s_title.c_str(), songB.s_title.c_str()) < 0;
			}
			else if (str == "album") 
			{
				check = strcmp(songA.s_album.c_str(), songB.s_album.c_str()) < 0;
			}
			else 
			{
				const std::string errmsg = str + ": invalid field name for sorting!";
				throw errmsg;
			}
			return check;
		};
		try 
		{
			std::sort(m_songs.begin(), m_songs.end(), compare);
		}
		catch (const std::string errmsg) 
		{
			std::cout << errmsg << std::endl;
			exit(1);
		}
	}
	void SongCollection::cleanAlbum() {
		auto cleanAlbum = [](Song& src) 
		{
			if (src.s_album == "[None]") 
			{
				src.s_album = "";
			}
		};
		std::for_each(m_songs.begin(), m_songs.end(), cleanAlbum);
	}
	bool SongCollection::inCollection(const std::string name)const {
		return std::any_of(m_songs.begin(), m_songs.end(), [name](const Song src)
			{
				return src.s_artist == name; 
			}
		);
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string name) const {
		std::list<Song> songList;
		auto addSong = [name, &songList](const Song src)
		{
			if (src.s_artist == name)
			{
				songList.push_back(src);
			}
		};
		std::for_each(m_songs.begin(), m_songs.end(), addSong);
		return songList;
	}
}