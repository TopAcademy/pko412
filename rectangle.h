#pragma once
#include <iostream>
#include "point2d.h"

namespace top
{

	class Rectangle
	{
	private:
		// Class data
		Point2d points[4];

	public:
		// Constructor - by 4 points
		Rectangle(const Point2d& p1, const Point2d& p2, const Point2d& p3, const Point2d& p4)
			: points{ p1, p2, p3, p4 } {}

		// Constructor - by top-left point & width & height
		Rectangle(const Point2d& p1, int width, int height);

		// Print corners' points
		void print() const;
		// Operator << with ostream
		friend std::ostream& operator << (std::ostream&, const Rectangle&);

		static Rectangle create_random();
	};

	/*
	 * Class methods definition
	 */

	Rectangle Rectangle::create_random() {
		int s = double(double(rand()) / RAND_MAX) * 10 + 1;
		int x = double(double(rand()) / RAND_MAX) * 10 + 1;
		int y = double(double(rand()) / RAND_MAX) * 10 + 1;
		return Rectangle(Point2d(x, y), s, s);
	}

	// Constructor by top-left point & width & height

	Rectangle::Rectangle(const Point2d& p1, int width, int height) {
		points[0] = p1;
		points[1] = p1;
		points[1].move_x(width);
		points[2] = points[1];
		points[2].move_y(height);
		points[3] = points[2];
		points[3].move_x(-width);
	}

	// Print corners' points
	void Rectangle::print() const {
		for (const Point2d& p : points) {
			std::cout << p;
		}
	}

	// Operator << with ostream
	std::ostream& operator << (std::ostream& console, const Rectangle& r) {
		r.print();
		return console;
	}


} // namespace
