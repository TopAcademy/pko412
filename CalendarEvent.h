#pragma once
#include <iostream>
#include <string>
#include "Date.h"


namespace top {

	/// Base class for calendar events
	class CalendarEvent
	{
	protected:
		Date event_date;
		std::string comment;

	public:
		// Constructor setting event to passed date
		CalendarEvent(Date d, std::string c) : event_date(d), comment(c) {}

		// Pure vurtual function - `display` interface to implement in derived classes
		virtual void display() {
			std::cout << "Calendar Event:\n- Event date  : ";
			event_date.display();
			std::cout << "\n- Description : " << comment << std::endl;
		}
	};


	// Brithday event class
	class BDEvent : public CalendarEvent
	{
		std::string person_name;

	public:
		// Constructor
		BDEvent(Date date, std::string comment, std::string name)
			: CalendarEvent(date, comment), person_name(name) {}

		// Display implementation for BD Event
		void display() {
			event_date.display();
			std::cout << " : the birthday of person: " << person_name << "\nComment: " << comment << std::endl;
		}
	};

}

