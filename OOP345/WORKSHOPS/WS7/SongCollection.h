// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 9, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <string>
#include <vector>
#include <list>


namespace sdds {
	typedef struct {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		std::string m_year;
		size_t m_length;
		double m_price;
	} Song;

	class SongCollection {
		Song song;
		std::vector<sdds::Song> s;
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string str);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song> getSongsForArtist(std::string) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
