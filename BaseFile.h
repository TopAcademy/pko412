// BaseFile.h
#pragma once
#include <xiosbase>
#include <fstream>
#include <string>

enum class FILE_MODES {
	READ,
	WRITE
};

// Base interface for file processing
class BaseFile
{
protected:
	//std::basic_ios<char, std::char_traits<char>> * pstream;

public:

	BaseFile() = default;

	virtual void open(std::string path) = 0;

	virtual void close() = 0;

};
