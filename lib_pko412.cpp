#include <iostream>
#include "Date.h"
#include "Time.h"
#include "CalendarEvent.h"

using namespace top;
using namespace std;



int main()
{
	CalendarEvent event1(Date(1, 1, 2026), "Comment1");
	BDEvent event2(Date(2, 2, 2026), "Comment2", "Jet Li");

	event1.display();
	cout << endl;
	event2.display();
}
