#pragma once
#include <iostream>

namespace top
{

	class Point2d
	{
	private:
		// Class data
		int x;
		int y;

	public:

		// Default constructor
		Point2d() : x(0), y(0) { counter++; }
		// Two-args constructor
		Point2d(int x, int y) : x(x), y(y) { counter++; }
		// Copy constructor
		Point2d(const Point2d& r) : x(r.x), y(r.y) { counter++; }

		// Display position
		void print() const;
		// Move point to new coordinates
		void move(int, int);
		// Move point horizontally & vertically
		void move_x(int);
		void move_y(int);

		// Operators
		Point2d& operator=(const Point2d&);
		Point2d operator+(const Point2d&) const;
		friend std::ostream& operator << (std::ostream&, const Point2d&);

		// statics
	private:
		static unsigned int counter;
	public:
		static void show_count() {
			std::cout << "Total points: " << Point2d::counter << std::endl;
		}

	};

	// Init static vars
	unsigned int Point2d::counter = 0;

	/*
	 * Class methods definition
	 */


	// Display position
	void Point2d::print() const {
		std::cout << "(" << x << "; " << y << ")\n";
	}

	// Move point to new coordinates
	void Point2d::move(int new_x, int new_y) {
		x = new_x;
		y = new_y;
	}

	// Move point horizontally
	void Point2d::move_x(int dx) {
		x += dx;
	}
	// Move point vertically
	void Point2d::move_y(int dy) {
		y += dy;
	}


	/*
	 * Class operators definition
	 */


	// Operator =
	Point2d& Point2d::operator=(const Point2d& right) {
		x = right.x;
		y = right.y;
		return *this;
	}

	// Operator +
	Point2d Point2d::operator+(const Point2d& right) const {
		return Point2d(x + right.x, y + right.y);
	}

	// Operator << with ostream
	std::ostream& operator << (std::ostream& console, const Point2d& p) {
		p.print();
		return console;
	}

} // namespace
