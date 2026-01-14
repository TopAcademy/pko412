#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace top;
using namespace std;


int main()
{
	Date d(13, 1, 2026);
	Time t(12, 9, 0);

	d.display();
	cout << " ";
	t.display();

}
