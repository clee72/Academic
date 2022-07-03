// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 9, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <numeric>


namespace sdds {

	SongCollection::SongCollection(std::string filename) {
		std::ifstream file(filename);
		//	file.open(filename);
		if (!file)
			throw "an exception error occurred";
		else {
			while (file && !file.eof()) {
				std::string temp;
				std::getline(file, temp);

				std::string title = temp.substr(0, 25);
				title.erase(0, title.find_first_not_of(' '));
				title.erase(title.find_last_not_of(' ') + 1);

				std::string artist = temp.substr(25, 25);
				artist.erase(0, artist.find_first_not_of(' '));
				artist.erase(artist.find_last_not_of(' ') + 1);

				std::string album = temp.substr(50, 25);
				album.erase(0, album.find_first_not_of(' '));
				album.erase(album.find_last_not_of(' ') + 1);

				std::string year = temp.substr(75, 5);
				year.erase(0, year.find_first_not_of(' '));
				year.erase(year.find_last_not_of(' ') + 1);

				std::string length = temp.substr(80, 5);
				length.erase(0, length.find_first_not_of(' '));
				length.erase(length.find_last_not_of(' ') + 1);


				std::string price = temp.substr(85, temp.find('\n'));
				price.erase(0, price.find_first_not_of(' '));
				price.erase(price.find_last_not_of(' ') + 1);

				song.m_title = title;
				song.m_album = album;
				song.m_artist = artist;
				song.m_length = stoi(length);
				song.m_year = year;
				song.m_price = stod(price);

				s.push_back(song);
			}
		}
		file.close();
	}


	void SongCollection::display(std::ostream& out) const {

		for_each(s.begin(), s.end(), [&out](const Song& s) {out << s << std::endl; });

		size_t T_sum = std::accumulate(s.begin(), s.end(), (size_t)0, [](size_t& sum, const Song& t_song) {return sum += t_song.m_length; });

		size_t hr = (T_sum / 60) / 60;
		size_t min = (T_sum) / 60 - 60;
		size_t sec = (T_sum) % 60;

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::setw(78) << "Total Listening Time: " << hr << ":" << min << ":" << sec << " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		size_t len_min = theSong.m_length / 60;
		size_t len_sec = theSong.m_length % 60;
		out << "| " << std::setw(20) << std::left << theSong.m_title;
		out << " | " << std::setw(15) << std::left << theSong.m_artist;
		out << " | " << std::setw(20) << std::left << theSong.m_album;
		out << " | " << std::setw(6) << std::right << theSong.m_year;
		out << " | " << std::right << len_min << ":";

		if (len_sec < 10 && len_sec >= 0) {
			out << "0" << len_sec;
		}
		else {
			out << len_sec;
		}
		out << " | " << std::right << theSong.m_price << " |";
		return out;
	}

	void SongCollection::sort(std::string str) {
		if (str == "title") {

			std::sort(s.begin(), s.end(), [](const Song& a, const Song& b) {return a.m_title.compare(b.m_title) < 0; });
		}
		else if (str == "album") {
			std::sort(s.begin(), s.end(), [](const Song& a, const Song& b) {return a.m_title.compare(b.m_title) < 0; });

		}
		else if (str == "length") {
			std::sort(s.begin(), s.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
		}
	}

	void SongCollection::cleanAlbum() {

		std::transform(s.begin(), s.end(), s.begin(), [](Song& song) {
			Song tmp = song;
			if (tmp.m_album == "[None]") {
				tmp.m_album = " ";
			}
			return tmp; });
	}

	bool SongCollection::inCollection(std::string artist) const {
		auto res = std::find_if(s.begin(), s.end(), [&artist](const Song& t_song) {return artist == t_song.m_artist; });
		return res != s.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const {
		auto cnt = std::count_if(s.begin(), s.end(), [&artist](const Song& a_song) {return a_song.m_artist == artist; });

		std::list<Song>  songs(cnt);
		std::copy_if(s.begin(), s.end(), songs.begin(), [&artist](const Song& t_song) {
			return artist == t_song.m_artist;
		});
		return songs;
	}
}