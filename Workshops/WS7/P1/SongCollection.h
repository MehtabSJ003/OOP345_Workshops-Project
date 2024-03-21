#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <iostream>
#include <vector>
namespace seneca {
	struct Song {
		std::string s_artist = "";
		std::string s_title = "";
		std::string s_album = "";
		double s_price = 0.0;
		size_t s_year = 0u;
		size_t s_length = 0;
	};
	class SongCollection {
		std::vector<Song> m_songs;
		std::string trim(std::string& src);
	public:
		SongCollection(const char* fileName);
		void display(std::ostream& out)const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SONGCOLLECTION_H
