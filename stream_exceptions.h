// stream_exceptions.h
#include <stdexcept>
#include <string>
#pragma once

class file_error : public std::runtime_error 
{
public:
	file_error(const std::string& _Message) : runtime_error(_Message) {}

	file_error(const char* _Message) : runtime_error(_Message) {}
};


class not_found : public file_error
{
public:
	not_found(const std::string& _Message) : file_error(_Message) {
	}

	not_found(const char* _Message) : file_error(_Message) {
	};
};
