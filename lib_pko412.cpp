#include <iostream>
#include "Date.h"
#include "Time.h"
#include "CalendarEvent.h"

using namespace top;
using namespace std;


int main()
{
	CalendarEvent event1(Date(14, 1, 2026), "OOP Lesson");
	event1.display();
}
