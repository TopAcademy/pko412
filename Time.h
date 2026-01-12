#pragma once
#include <iostream>

namespace top
{
	using uchar = unsigned char;
	using ushort = unsigned short;

	class Date
	{
		uchar hour, min, sec;

		Date(uchar h, uchar m, uchar s) : hour(h), min(m), sec(s) {};   // Constructor
		void display();  // Print time on the console in format `h:mm:ss`
	};


	void Date::display() {
		std::cout
			<< short(hour)
			<< ':' << ((min < 10) ? "0" : "") << short(min)
			<< ':' << ((sec < 10) ? "0" : "") << short(sec);
	}


} // namespace top
