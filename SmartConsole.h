/**
*   Header file "Smart Console"
*   ---------------------
*   Contains the `SmartConsole` class and the declarations and types it needs.
*/

#pragma once
#include <iostream>
#include <array>
#include <string>
#include <cstdint>
#include <windows.h>

namespace top {

	// Type declaration: "Color Container"
	using Color = std::array<uint8_t, 3>;
	// Standard color constants: white & black
	Color White = Color{ 255, 255, 255 };
	Color Black = Color{ 0, 0, 0 };


	/**
	* Class "Smart Console".
	* 
	* Provides functionality:
	*  - Preparing the console, obtaining size of the screen (in chars and rows).
	*  - Print string on the console in given position (row; col).
	*  - Setting the color of output (in RGB format).
	*/
	class SmartConsole
	{
		unsigned short height;		// height of the console screen (in rows).
		unsigned short width;		// width of the console screen (in chars).
		static Color default_color;	// current setting of outut color.
	
	public:

		/**
		* Constructor.
		* 
		* Obtain and store size of the console screen.
		* Clear console and switch off the cursor.
		*/
		SmartConsole() {
			// Clear the screen and switch off the cursor
			std::cout << "\x1b[2J\x1b[?25l";
			// Obtain and save screen size
			HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO cinfo;
			GetConsoleScreenBufferInfo(cons, &cinfo);
			this->height = cinfo.srWindow.Bottom - cinfo.srWindow.Top + 1;
			this->width = cinfo.srWindow.Right - cinfo.srWindow.Left + 1;
		}

		/**
		* Set the current (default) output color
		* 
		* @param color: new default color, of type: `Color{r, g, b}`.
		* @return void
		*/
		void set_color(Color color) {
			SmartConsole::default_color = color;
		}

		/**
		* Height & width getters
		*/
		
		unsigned short get_height() { return height; }
		unsigned short get_width() { return width; }

		/**
		* Print the string at given position
		* 
		* Outputs the string at the position of (row; col).
		* If color param passed, then output uses the given color.
		* Otherwise, the default color will be used.
		* 
		* @param row: the "row" coordinate.
		* @param col: the "column" coordinate.
		* @param color: output color (`default_color` by-default).
		*/
		void print(std::string content, short row, short col, Color color = SmartConsole::default_color) {
			if (row > height) row = height - 2;
			if (col > width) col = width - 2;
			// Set cursor position
			std::cout << "\x1b[" << row << ";" << col << "H";
			// Set color
			std::cout << "\x1b[38;2;" << (short)color[0] << ";" << (short)color[1] << ";" << (short)color[2] << "m";
			// Output
			std::cout << content;
		}

	}; // class SmartConsole

	// Statics init
	Color SmartConsole::default_color = White;

} // namespace top


