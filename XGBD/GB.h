#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define GB_SCREEN_WIDTH 160
#define GB_SCREEN_HEIGHT 144

#define INDEX(coll, coll_strip, x, y) ((coll) + ((x)*coll_strip) + (y))

enum gbDisplayColor {
	BLACK, DARK_GRAY, LIGHT_GRAY, WHITE
};

struct gameBoy {
	gbDisplayColor* outVideo;


};

struct _gbMbc {
	BYTE mbcType;
	BYTE* cartBankPtr;
	BYTE bankId;
};

struct _gbRamSplit {
	BYTE cart0  [0x3fff - 0x0000];
	BYTE cartx  [0x7fff - 0x3fff];
	BYTE vram   [0x9fff - 0x8000];
	BYTE sram   [0xbfff - 0xa000];
	BYTE wram   [0xdfff - 0xc000];
	BYTE echo   [0xfdff - 0xe000];
	BYTE oam    [0xfe9f - 0xfe00];
	BYTE unused [0xfeff - 0xfea0];
	BYTE ioreg  [0xff7f - 0xff00];
	BYTE hram   [0xfffe - 0xff80];
	BYTE interrupt;
};

union _gbRam {
	BYTE ram[0xffff];
	_gbRamSplit sacc;
};

BYTE gbRamRead(gameBoy* gb, UINT16 address);
void gbRamWrite(gameBoy* gb, UINT16 address, BYTE value);