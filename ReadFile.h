// ReadFile.h
#pragma once
#include <iostream>
#include <fstream>
#include "BaseFile.h"

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
		stream.open(path);
	}

	void close() {
		stream.close();
	}

};
