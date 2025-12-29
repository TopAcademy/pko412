#include <exception>
#include "SmartConsole.h"
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>


using namespace top;
using std::vector;
using std::string;


class VLine {
	string lamp_char;
	short x_pos;
	short height;
	SmartConsole cons;
	const Color Gray { 160,160,160 };
	static std::mutex mtx;

public:
	VLine(short x, short h, string chr = "*") : x_pos{ x }, height{ h }, lamp_char{ chr } {
		cons.set_color({ 160,160,160 });
	}
	
	void draw() {

		mtx.lock();
		for (short r = 0; r < height; r++) {
			cons.print(lamp_char, r, x_pos);
		}
		mtx.unlock();
	}

	void flash() {
		while (true) {
			short y = rand() % height;
			mtx.lock();
			cons.print(lamp_char, y, x_pos, White);
			mtx.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			mtx.lock();
			cons.print(lamp_char, y, x_pos, Gray);
			mtx.unlock();
		}
	}

};

std::mutex VLine::mtx;





int main()
{
	vector<VLine> lines{
		VLine(1, 10),
		VLine(6, 150),
		VLine(11, 13),
		VLine(16, 10),
		VLine(2000, 14),
	};
	vector<std::thread> threads;

	for (VLine& l : lines) {
		l.draw();
		threads.push_back(std::thread(&VLine::flash, &l));
	}

	for (std::thread& t : threads) {
		t.join();
	}
	
	
	
}
