//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
Modifications for JonoF's port by Jonathon Fowler (jf@jonof.id.au)
*/
//-------------------------------------------------------------------------

#pragma once

#ifndef keyboard_public_h_
#define keyboard_public_h_

#include "baselayer.h"	// for the keyboard stuff
#include "scancodes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t kb_scancode;

// translation table for taking key names to scancodes and back again
static struct
{
    const char *key;
    kb_scancode sc;
} CONSTEXPR sctokeylut[] = {
#ifdef __MIYOO__
    { "Menu",   0x01 }, // Escape
    { "Up",     0xc8 }, // Up
    { "Down",   0xd0 }, // Down
    { "Left",   0xcb }, // Left
    { "Right",  0xcd }, // Right
    { "L1",     0x12 }, // E
    { "L2",     0x0f }, // Tab
    { "R1",     0x14 }, // T
    { "R2",     0x0e }, // BakSpc
    { "A",      0x39 }, // Space
    { "B",      0x1d }, // LCtrl
    { "X",      0x2a }, // LShift
    { "Y",      0x38 }, // LAlt
    { "Select", 0x9d }, // RCtrl
    { "Start",  0x1c }, // Enter/Return

    // Menu Chorded Keys
    { "Fn_Up",        0x09 }, // 8
    { "Fn_Down",      0x03 }, // 2
    { "Fn_Left",      0x05 }, // 4
    { "Fn_Right",     0x07 }, // 6
    { "Fn_L1",        0xc9 }, // PgUp
    { "Fn_L2",        0xc7 }, // Home
    { "Fn_R1",        0xd1 }, // PgDn
    { "Fn_R2",        0xcf }, // End
    { "Fn_A",         0x17 }, // I
    { "Fn_B",         0x25 }, // K
    { "Fn_X",         0x16 }, // U
    { "Fn_Y",         0x24 }, // J
    { "Fn_Select",    0x36 }, // RShift
    { "Fn_Start",     0x9c }, // KpdEnt

#else
    { "Escape", 0x1 },     { "1", 0x2 },       { "2", 0x3 },       { "3", 0x4 },      { "4", 0x5 },       { "5", 0x6 },       { "6", 0x7 },
    { "7", 0x8 },          { "8", 0x9 },       { "9", 0xa },       { "0", 0xb },      { "-", 0xc },       { "=", 0xd },       { "BakSpc", 0xe },
    { "Tab", 0xf },        { "Q", 0x10 },      { "W", 0x11 },      { "E", 0x12 },     { "R", 0x13 },      { "T", 0x14 },      { "Y", 0x15 },
    { "U", 0x16 },         { "I", 0x17 },      { "O", 0x18 },      { "P", 0x19 },     { "[", 0x1a },      { "]", 0x1b },      { "Enter", 0x1c },
    { "LCtrl", 0x1d },     { "A", 0x1e },      { "S", 0x1f },      { "D", 0x20 },     { "F", 0x21 },      { "G", 0x22 },      { "H", 0x23 },
    { "J", 0x24 },         { "K", 0x25 },      { "L", 0x26 },      { ";", 0x27 },     { "'", 0x28 },      { "`", 0x29 },      { "LShift", 0x2a },
    { "Backslash", 0x2b }, { "Z", 0x2c },      { "X", 0x2d },      { "C", 0x2e },     { "V", 0x2f },      { "B", 0x30 },      { "N", 0x31 },
    { "M", 0x32 },         { ",", 0x33 },      { ".", 0x34 },      { "/", 0x35 },     { "RShift", 0x36 }, { "Kpad*", 0x37 },  { "LAlt", 0x38 },
    { "Space", 0x39 },     { "CapLck", 0x3a }, { "F1", 0x3b },     { "F2", 0x3c },    { "F3", 0x3d },     { "F4", 0x3e },     { "F5", 0x3f },
    { "F6", 0x40 },        { "F7", 0x41 },     { "F8", 0x42 },     { "F9", 0x43 },    { "F10", 0x44 },    { "NumLck", 0x45 }, { "ScrLck", 0x46 },
    { "Kpad7", 0x47 },     { "Kpad8", 0x48 },  { "Kpad9", 0x49 },  { "Kpad-", 0x4a }, { "Kpad4", 0x4b },  { "Kpad5", 0x4c },  { "Kpad6", 0x4d },
    { "Kpad+", 0x4e },     { "Kpad1", 0x4f },  { "Kpad2", 0x50 },  { "Kpad3", 0x51 }, { "Kpad0", 0x52 },  { "Kpad.", 0x53 },  { "LessThan", 0x56 },
    { "F11", 0x57 },       { "F12", 0x58 },    { "KpdEnt", 0x9c }, { "RCtrl", 0x9d }, { "Kpad/", 0xb5 },  { "RAlt", 0xb8 },   { "PrtScn", 0xb7 },
    { "Pause", 0xc5 },     { "Home", 0xc7 },   { "Up", 0xc8 },     { "PgUp", 0xc9 },  { "Left", 0xcb },   { "Right", 0xcd },  { "End", 0xcf },
    { "Down", 0xd0 },      { "PgDn", 0xd1 },   { "Insert", 0xd2 }, { "Delete", 0xd3 },
#endif
};

#ifdef __MIYOO__
static inline kb_scancode miyoo_key_to_chorded(kb_scancode key)
{
    switch(key)
    {
        case 0xc8: return 0x09;
        case 0xd0: return 0x03;
        case 0xcb: return 0x05;
        case 0xcd: return 0x07;
        case 0x12: return 0xc9;
        case 0x0f: return 0xc7;
        case 0x14: return 0xd1;
        case 0x0e: return 0xcf;
        case 0x39: return 0x17;
        case 0x1d: return 0x25;
        case 0x2a: return 0x16;
        case 0x38: return 0x24;
        case 0x9d: return key; //HACK: Should be `return 0x36;`, but since it's the function key, can cause problems
        case 0x1c: return 0x9c;
        default: return key;
    }
}

static inline kb_scancode miyoo_get_unchorded_key(kb_scancode key)
{
    switch(key)
    {
        case 0x09: return 0xc8;
        case 0x03: return 0xd0;
        case 0x05: return 0xcb;
        case 0x07: return 0xcd;
        case 0xc9: return 0x12;
        case 0xc7: return 0x0f;
        case 0xd1: return 0x14;
        case 0xcf: return 0x0e;
        case 0x17: return 0x39;
        case 0x25: return 0x1d;
        case 0x16: return 0x2a;
        case 0x24: return 0x38;
        case 0x36: return 0x9d;
        case 0x9c: return 0x1c;
        default: return key;
    }
}

static inline int8_t miyoo_is_chorded_key(kb_scancode key)
{
    switch (key)
    {
        case 0x09:
        case 0x03:
        case 0x05:
        case 0x07:
        case 0xc9:
        case 0xc7:
        case 0xd1:
        case 0xcf:
        case 0x17:
        case 0x25:
        case 0x16:
        case 0x24:
        case 0x36:
        case 0x9c:
            return TRUE;
        default:
            return FALSE;
    }
}

static inline const char* miyoo_get_key_name(kb_scancode key)
{
    switch(key)
    {
        case 0x01: return "Menu";
        case 0xc8: return "Up";
        case 0xd0: return "Down";
        case 0xcb: return "Left";
        case 0xcd: return "Right";
        case 0x12: return "L1";
        case 0x0f: return "L2";
        case 0x14: return "R1";
        case 0x0e: return "R2";
        case 0x39: return "A";
        case 0x1d: return "B";
        case 0x2a: return "X";
        case 0x38: return "Y";
        case 0x9d: return "Select";
        case 0x1c: return "Start";
        case 0x09: return "Fn + Up";
        case 0x03: return "Fn + Down";
        case 0x05: return "Fn + Left";
        case 0x07: return "Fn + Right";
        case 0xc9: return "Fn + L1";
        case 0xc7: return "Fn + L2";
        case 0xd1: return "Fn + R1";
        case 0xcf: return "Fn + R2";
        case 0x17: return "Fn + A";
        case 0x25: return "Fn + B";
        case 0x16: return "Fn + X";
        case 0x24: return "Fn + Y";
        case 0x36: return "Fn + Select";
        case 0x9c: return "Fn + Start";
        default: return "[UNKNOWN]";
    }
}
#endif

#define MAXKEYBOARDSCAN  256

#define KB_KeyDown keystatus
extern kb_scancode KB_LastScan;

#define KB_GetLastScanCode() (KB_LastScan)
#define KB_SetLastScanCode(scancode) \
    {                                \
        KB_LastScan = (scancode);    \
    }
#define KB_ClearLastScanCode()       \
    {                                \
        KB_SetLastScanCode(sc_None); \
    }
#define KB_KeyPressed(scan) (keystatus[(scan)] != 0)

#ifdef __MIYOO__
#define KB_ClearKeyDown(scan)      \
    {                              \
        if (miyoo_is_chorded_key(scan)) \
        {                               \
            keystatus[0x9d] = FALSE;    \
            keystatus[(scan)] = FALSE;  \
            keystatus[miyoo_get_unchorded_key(scan)] = FALSE; \
        }                               \
        else \
        { \
            keystatus[(scan)] = FALSE; \
            keystatus[miyoo_key_to_chorded(scan)] = FALSE; \
        } \
    }
#else
#define KB_ClearKeyDown(scan)      \
    {                              \
        keystatus[(scan)] = FALSE; \
    }
#endif

#define KB_UnBoundKeyPressed(scan) (keystatus[(scan)] != 0 && !CONTROL_KeyBinds[scan].cmdstr)
#define KB_GetCh keyGetChar
#define KB_KeyWaiting keyBufferWaiting
#define KB_FlushKeyboardQueue keyFlushChars
#define KB_FlushKeyboardQueueScans keyFlushScans

static inline void KB_ClearKeysDown(void)
{
    KB_LastScan = 0;
    Bmemset(keystatus, 0, sizeof(keystatus));
}

static inline void KB_KeyEvent(int32_t scancode, int32_t keypressed)
{
    if (keypressed)
    {
#ifdef __MIYOO__
        // Check if function button is pressed, and if so change it to the modified scancode
        // TODO: The function button is forced to Select at the moment, should be modifiable
        if (keystatus[0x9d])
        {
            KB_LastScan = miyoo_key_to_chorded(scancode);
            
        }
        else
#endif
        {
            KB_LastScan = scancode;
        }
    }
}

static inline void KB_Startup(void) { keySetCallback(KB_KeyEvent); }
static inline void KB_Shutdown(void) { keySetCallback((void (*)(int32_t, int32_t))NULL); }
const char *  KB_ScanCodeToString( kb_scancode scancode ); // convert scancode into a string
kb_scancode KB_StringToScanCode( const char * string );  // convert a string into a scancode

#ifdef __cplusplus
}
#endif
#endif
