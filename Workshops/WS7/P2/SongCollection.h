#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <iostream>
#include <vector>
#include <list>
namespace seneca {
	struct Song {
		std::string s_artist = "";
		std::string s_title = "";
		std::string s_album = "";
		double m_price = 0.0;
		size_t s_year = 0u;
		size_t s_length = 0;
	};
	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(const char* fileName);
		void display(std::ostream& out)const;
		void sort(const std::string& str);
		void cleanAlbum();
		bool inCollection(const std::string name)const;
		std::list<Song> getSongsForArtist(const std::string name) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SONGCOLLECTION_H
