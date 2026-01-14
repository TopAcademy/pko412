#pragma once
#include <iostream>
#include <stdexcept>

namespace top
{
	using uchar = unsigned char;
	using ushort = unsigned short;

	class Time
	{
	private:
		uchar hour, min, sec;
	
	public:
		
		// Constructor setting time value
		// Throws exception `out_of_range` if the passed time items are wrong
		Time(uchar h, uchar m, uchar s) {
			set(h, m, s);
		}

		// Set time value
		// Throws exception `out_of_range` if the passed time items are wrong
		void set(uchar h, uchar m, uchar s) {
			if (h > 23 || m > 59 || s > 59) {
				throw std::out_of_range("Time items are out of range");
			}
			hour = h;
			min = m;
			sec = s;
		}

		// Print time on the console in format `h:mm:ss`
		void display() {
			std::cout
				<< short(hour)
				<< ':' << ((min < 10) ? "0" : "") << short(min)
				<< ':' << ((sec < 10) ? "0" : "") << short(sec);
		}

	}; // class Time


} // namespace top
