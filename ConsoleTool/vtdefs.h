#pragma once
#ifndef VTDEFS_H
#define VTDEFS_H

const short VT_MAX_COLOR = 8;

const char VT_BOLD[]{ "\x1b[1m" };
const char VT_FAINT[]{ "\x1b[2m" };
const char VT_ITALIC[]{ "\x1b[3m" };
const char VT_UNDERLINE[]{ "\x1b[4m" };
const char VT_SINGLEUNDERLINE[]{ "\x1b[4:1m" };
const char VT_DOUBLEUNDERLINE[]{ "\x1b[4:2m" };
const char VT_UNDERCURL[]{ "\x1b[4:3m" };
const char VT_DOTTEDUNDERLINE[]{ "\x1b[4:4m" };
const char VT_DASHEDUNDERLINE[]{ "\x1b[4:5m" };
const char VT_BLINK[]{ "\x1b[5m" };
const char VT_RAPIDBLINK[]{ "\x1b[6m" };
const char VT_REVERSE[]{ "\x1b[7m" };
const char VT_INVISIBLE[]{ "\x1b[8m" };
const char VT_STRIKETHROUGH[]{ "\x1b[9m" };
const char VT_DOUBLEUNDERLINE2[]{ "\x1b[21m" };

const char VT_RESET[]{ "\x1b[m" };
const char VT_BLACK[]{ "\x1b[30m" };
const char VT_RED[]{ "\x1b[31m" };
const char VT_GREEN[]{ "\x1b[32m" };
const char VT_YELLOW[]{ "\x1b[33m" };
const char VT_NAVY[]{ "\x1b[34m" };
const char VT_MAGENTA[]{ "\x1b[35m" };
const char VT_CYAN[]{ "\x1b[36m" };
const char VT_WHITE[]{ "\x1b[37m" };

const char VT_COLOR_NAMES[][VT_MAX_COLOR]
{
	"Black",
	"Red",
	"Green",
	"Yellow",
	"Navy",
	"Magenta",
	"Cyan",
	"White"
};

#endif
