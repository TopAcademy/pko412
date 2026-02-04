#pragma once
#include <xiosbase>
#include <fstream>
#include <string>

enum class FILE_MODES {
	READ,
	WRITE
};


class BaseFile
{
protected:
	std::basic_ios<char, std::char_traits<char>> * pstream;

public:

	BaseFile(std::string path, FILE_MODES mode) {
		open(path, mode);
	}

	void open(std::string path, FILE_MODES mode)
	{
		if (mode == FILE_MODES::READ) {
			pstream = new std::ifstream(path);
		}
		else {
			pstream = new std::ofstream(path);
		}
	}

};
