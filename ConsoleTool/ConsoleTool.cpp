//
//  ConsoleTool -- Win32 console tweak tool.
//

#include "pch.h"

#include <cassert>

#include "getopt.h"

#if !defined(ENABLE_VIRTUAL_TERMINAL_INPUT)
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif
#if !defined(ENABLE_VIRTUAL_TERMINAL_PROCESSING)
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#if !defined(DISABLE_NEWLINE_AUTO_RETURN)
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif
#if !defined(ENABLE_LVB_GRID_WORLDWIDE)
#define ENABLE_LVB_GRID_WORLDWIDE 0x0010
#endif

using namespace std;

void Status(DWORD dwMode);
void Summary(HANDLE hConsole, const DWORD dwMode);

void DisplayAvailableColorsVT();
void DisplayAvailableColors256();
void DisplayAvailableColorsCubes();
void DisplayAvailableColorsXTERM();
void DisplayCurrentCP(HANDLE hConsole);
void DisplayCurrentFontDetails(HANDLE hConsole);
void PrintError(string);

#define XTERMCOLORS	4
#define CUBES256	2
#define VTCOLORS	1
#define NOCOLORS	0

static int verbose_flag = 0;
static int color_info	= 1;
static int font_info	= 1;

static struct option long_options[] = {
	{"verbose",	no_argument,	&verbose_flag, 1},
	{"brief",	no_argument,	&verbose_flag, 0},
	{"cubes",	no_argument,	&color_info, CUBES256},
	{"xtermcolors",	no_argument,	&color_info, XTERMCOLORS},
	{"vtcolors",	no_argument,	&color_info, VTCOLORS},
	{"nocolors",	no_argument,	&color_info, NOCOLORS},
	{"font",	no_argument,	&font_info, 1},
	{"nofont",	no_argument,	&font_info, 0},
//	{"set", 	no_argument,	0, 's'},
//	{"clr", 	no_argument,	0, 'c'},
	{0}
	};

int main(int argc, const char *argv[])
{
	int option_index = 0, c;

	while ((c = getopt_long (argc, argv, "bvc", long_options, &option_index, -1)) != -1) {
		switch (c) {
		case 'b':
			verbose_flag = 0;
			break;
		case 'v':
			verbose_flag = 1;
			break;
		case 'c':
			color_info = CUBES256;
			break;
//		case 's':
//			break;
//		case 'c':
//			break;
		case 0: //argument set.
			break;
		default:
			assert('?' == c || ':' == c);
			return EXIT_FAILURE;
		}
	}

	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
	DWORD dwMode{ 0 };

	if (GetConsoleMode(hConsole, &dwMode)) {

		cout << "Console Tool\n" << endl;

		if (verbose_flag) {
			Status(dwMode);
		}

		if ((ENABLE_VIRTUAL_TERMINAL_PROCESSING & dwMode) ||
				SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {

			// Sumary information
			Summary(hConsole, dwMode);

			// Restore Console output mode
			SetConsoleMode(hConsole, dwMode);

		} else {
			cout << "Error: Could not enable VT Processing - please update to a recent Windows 10 build";
		}

	} else {
		PrintError("Cannot determine console mode!");
	}

	return EXIT_SUCCESS;
}


void Status(DWORD dwMode)
{
	std::cout << "Console Output Mode: 0x" << std::hex << dwMode << std::dec << "\n";

	if (dwMode & ENABLE_PROCESSED_OUTPUT)			std::cout << "\tENABLE_PROCESSED_OUTPUT\n";
	if (dwMode & ENABLE_WRAP_AT_EOL_OUTPUT)			std::cout << "\tENABLE_WRAP_AT_EOL_OUTPUT\n";
	if (dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)	std::cout << "\tENABLE_VIRTUAL_TERMINAL_PROCESSING\n";
	if (dwMode & DISABLE_NEWLINE_AUTO_RETURN)		std::cout << "\tDISABLE_NEWLINE_AUTO_RETURN\n";
	if (dwMode & ENABLE_LVB_GRID_WORLDWIDE)			std::cout << "\tENABLE_LVB_GRID_WORLDWIDE\n";
	std::cout << endl;

	if (GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &dwMode)) {
		std::cout << "Console Input Mode: 0x" << std::hex << dwMode << std::dec << "\n";

		if (dwMode & ENABLE_ECHO_INPUT)			std::cout << "\tENABLE_ECHO_INPUT\n";
		if (dwMode & ENABLE_INSERT_MODE)		std::cout << "\tENABLE_INSERT_MODE\n";
		if (dwMode & ENABLE_LINE_INPUT)			std::cout << "\tENABLE_LINE_INPUT\n";
		if (dwMode & ENABLE_MOUSE_INPUT)		std::cout << "\tENABLE_MOUSE_INPUT\n";
		if (dwMode & ENABLE_PROCESSED_INPUT)		std::cout << "\tENABLE_PROCESSED_INPUT\n";
		if (dwMode & ENABLE_QUICK_EDIT_MODE)		std::cout << "\tENABLE_QUICK_EDIT_MODE\n";
		if (dwMode & ENABLE_WINDOW_INPUT)		std::cout << "\tENABLE_WINDOW_INPUT\n";
		if (dwMode & ENABLE_VIRTUAL_TERMINAL_INPUT)	std::cout << "\tENABLE_VIRTUAL_TERMINAL_INPUT\n";

		std::cout << endl;
	}
}


void Summary(HANDLE hConsole, const DWORD dwMode)
{
	DWORD dwNewMode{};
	(void) GetConsoleMode(hConsole, &dwNewMode);

	if (ENABLE_VIRTUAL_TERMINAL_PROCESSING & dwNewMode) {
		switch (color_info) {
		case XTERMCOLORS:
			DisplayAvailableColorsXTERM();
			break;
		case CUBES256:
			DisplayAvailableColorsCubes();
			break;
		case VTCOLORS:
			DisplayAvailableColorsVT();
			DisplayAvailableColors256();
			break;
                }
	} else {
		PrintError("Can't display ANSI/VT-Sequences - you may need to upgrade to a recent Windows 10 build");
	}

	if (font_info) {
		DisplayCurrentCP(hConsole);
	}
}


void DisplayAvailableColorsVT()
{
	cout << "Available Colors VT:" << endl;

	for (short c = 0; c < VT_MAX_COLOR; ++c) {
		if (c > 0) { cout << "\x1b[" << to_string(30 + c) << 'm'; }
		cout << "0x" << hex << c << dec << ": " << VT_COLOR_NAMES[c] << VT_RESET << endl;
	}
	cout << endl;
}


void DisplayAvailableColors256()
{
	cout << "Available Colors 256:" << endl;

	for (unsigned i = 0; i < 16; ++i) {	// foregrounds
		for (unsigned j = 0; j < 16; ++j) {
			const unsigned code = i * 16 + j;

			cout << "\x1b[38;5;" + to_string(code) << "m " << setw(4) << code;
		}
		cout << endl;
	}
	cout << endl;

	for (unsigned i = 0; i < 16; ++i) {	// backgrounds
		for (unsigned j = 0; j < 16; ++j) {
			const unsigned code = i * 16 + j;

			cout << "\x1b[48;5;" + to_string(code) << "m " << setw(4) << code;
		}
                cout << "\x1b[0m" << endl;
	}
	cout << endl;
}


void DisplayAvailableColorsCubes()
{
	cout << "System colors:\n";
	for (unsigned color = 0; color < 8; ++color) {
		cout << "\x1b[48;5;" << to_string(color) << "m   ";
	}
	cout << "\x1b[0m\n";
	for (unsigned color = 8; color < 16; ++color) {
		cout << "\x1b[48;5;" << to_string(color) << "m   ";
	}
	cout << "\x1b[0m\n\n";

	//////////////////////////////////////////////////
	cout << "Color cube, 6x6x6:\n";
	for (unsigned green = 0; green < 6; ++green) {
		for (unsigned red = 0; red < 6; ++red) {
			for (unsigned blue = 0; blue < 6; ++blue) {
				unsigned color = 16 + (red * 36) + (green * 6) + blue;
				cout << "\x1b[48;5;" << to_string(color) << "m  ";
			}
			cout << "\x1b[0m";
		}
		cout << "\n";
	}

	////////////////////////////////////////////////
	cout << "Grayscale ramp:\n";
	for (unsigned color = 232; color < 256; ++color) {
		cout << "\x1b[48;5;" << to_string(color) << "m ";
	}

	cout << "\x1b[0m\n";
}


void DisplayAvailableColorsXTERM()
{
	char buffer[512] = {0};

	cout << "XTERM Colors:\n\n";
	cout << "Display           Number    Name                  HEX      RGB\n";

	for (unsigned i = 0; i < _countof(XTERM_COLORS); ++i) {
		const struct XTERM_COLOR *color = XTERM_COLORS + i;

		snprintf(buffer, sizeof(buffer) - 1,            // Background RGB
		    "\x1b[48;2;%u;%u;%um%16s\x1b[0m  %-8u  %-20.20s  #%06x  %02x/%02x/%02x\n",
		    GetRValue(color->rbg), GetGValue(color->rbg), GetBValue(color->rbg), "",
			i, color->name, color->rbg, GetRValue(color->rbg), GetGValue(color->rbg), GetBValue(color->rbg));

		cout << buffer;
	}
	cout << endl;
}


void DisplayCurrentCP(HANDLE hConsole)
{
	const UINT nCodepage = GetConsoleOutputCP();

	if (SetConsoleOutputCP(65001)) {
		DisplayCurrentFontDetails(hConsole);
		SetConsoleOutputCP(nCodepage);			// Restore Console codepage

	} else {
		cout << "Error: Could not set codepage to UTF-8 (65001)" << endl;
	}
}


void DisplayCurrentFontDetails(HANDLE hConsole)
{
	CONSOLE_FONT_INFOEX fontInfo = { sizeof(CONSOLE_FONT_INFOEX) };

	cout << "Current Font:" << endl;

	if (GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo))
	{
		wcout << "Font face: " << fontInfo.FaceName << endl;
		cout  << "\tFont weight: " << fontInfo.FontWeight << " (Normal = 400)" << endl;
		cout  << "\tFont size: [" << fontInfo.dwFontSize.X << " x " << fontInfo.dwFontSize.Y << ']' << endl;
	}
	else
	{
		PrintError("Cannot find current font info!");
		GetLastError();
	}
}

void PrintError(std::string msg)
{
	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
	DWORD dwNewMode{};
	GetConsoleMode(hConsole, &dwNewMode);
	bool fVTEnabled = (ENABLE_VIRTUAL_TERMINAL_PROCESSING && dwNewMode);

	if (fVTEnabled) {
		cout << VT_RED;
	}

	cout << "Error: " << msg << endl;

	LPTSTR lpMessage{};

	DWORD dwErrCode = GetLastError();

	DWORD nChars = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, // no source buffer needed
		dwErrCode, // error code for this message
		NULL, // default language ID
		(LPTSTR)&lpMessage, // allocated by fcn
		NULL, // minimum size of buffer
		NULL); // no inserts

	wcout << lpMessage;

	if (fVTEnabled) {
		cout << VT_RESET;
	}

	cout << endl;

	LocalFree(lpMessage);
}

/*end*/

