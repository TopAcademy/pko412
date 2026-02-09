// ReadFile.h
#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "BaseFile.h"
#include "stream_exceptions.h"

// Derived class - Files Reader
class ReadFile : public BaseFile
{
private:
	std::ifstream stream;

public:
	ReadFile(std::string path)
	{
		this->open(path);
	}

	// Destructor - closing the file
	~ReadFile() {
		this->close();
	}

	void open(std::string path) override {
		// Check if file exists
		std::filesystem::path fname = path;
		if (!std::filesystem::exists(fname)) {
			throw not_found("File not found");
		}
		// Try to open the file
		stream.open(path);
		if (!stream.is_open()) {
			throw std::exception("Common file open error");
		}
	}

	void close() {
		stream.close();
	}

};
