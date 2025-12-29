#include <exception>
#include "SmartConsole.h"


using namespace top;

int main()
{
	Color grey{ 128, 128, 128 };
	
	SmartConsole cons;
	cons.set_color({190, 10, 19});
	cons.print("Hello", 10, 10, {80,80,190});
}
