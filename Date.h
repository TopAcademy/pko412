#pragma once
#include <iostream>

namespace top
{
	using uchar = unsigned char;
	using ushort = unsigned short;

	class Date
	{
		uchar day, month, year;

		Date(uchar d, uchar m, uchar y) : day(d), month(m), year(y) {};   // Constructor
		void display();  // Print date on the console in format `dd.mm.yyyy`
	};


	void Date::display() {
		std::cout << short(day) << '.' << ((month < 10) ? "0" : "") << short(month) << '.' << short(year);
	}


} // namespace top
