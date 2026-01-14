#pragma once
#include <iostream>
#include <stdexcept>

namespace top
{
	using uchar = unsigned char;
	using ushort = unsigned short;

	class Date
	{
	private:
		uchar day, month;
		ushort year;

	public:

		// Constructor setting date value
		// Throws exception `out_of_range` if the passed date items are wrong
		Date(uchar d, uchar m, ushort y) {
			set(d, m, y);
		}

		// Set date value
		// Throws exception `out_of_range` if the passed date items are wrong
		void set(uchar d, uchar m, ushort y) {
			if (m > 12) {
				throw std::out_of_range("Date items are out of range");
			}
			day = d;
			month = m;
			year = y;
		}

		// Print date on the console in format `dd.mm.yyyy`
		void display() {
			std::cout 
				<< short(day) 
				<< '.' << ((month < 10) ? "0" : "") << short(month) 
				<< '.' << year;
		}

	}; // class Date


} // namespace top
