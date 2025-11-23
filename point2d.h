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
		Point2d() : x(0), y(0) {}
		// Two-args constructor
		Point2d(int x, int y) : x(x), y(y) {}
		// Copy constructor
		Point2d(const Point2d& r) : x(r.x), y(r.y) {};

		// Display position
		void print() const;
		// Move point to new coordinates
		void move(int, int);

		// Operators
		Point2d& operator=(const Point2d&);
		Point2d operator+(const Point2d&) const;
	};


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

} // namespace
