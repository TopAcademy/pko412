#pragma once
#include <iostream>
#include <string>
#include "Date.h"


namespace top {

	/// Base class for calendar events
	class CalendarEvent
	{
	private:

		Date event_date;
		std::string comment;

	public:

		// Constructor setting event to passed date
		CalendarEvent(Date d, std::string c) : event_date(d), comment(c) {}

		// Print event date on the console
		void display() {
			std::cout << "Calendar Event:\n- Event date  : ";
			event_date.display();
			std::cout << "\n- Description : " << comment << std::endl;
		}
	};
}

