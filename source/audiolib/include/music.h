/*
Copyright (C) 1994-1995 Apogee Software, Ltd.

This program is free software; you can redistribute it and/or
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

Modifications for JonoF's port by Jonathon Fowler (jf@jonof.id.au)
*/
/**********************************************************************
   module: MUSIC.H

   author: James R. Dose
   date:   March 25, 1994

   Public header for MUSIC.C

   (c) Copyright 1994 James R. Dose.  All Rights Reserved.
**********************************************************************/

#ifndef __MUSIC_H
#define __MUSIC_H

#include "compat.h"
#include "sndcards.h"

extern int MUSIC_ErrorCode;

#if defined(__linux__) && defined(USE_ALSA)
#include <vector>

struct alsa_mididevinfo_t
{
  char *name;
  int clntid;
  int portid;

  alsa_mididevinfo_t(const char *insrcname, int inclntid, int inportid) :
    name(Xstrdup(insrcname)), clntid(inclntid), portid(inportid) {}

  alsa_mididevinfo_t(const alsa_mididevinfo_t &rhs)
  {
    name = Xstrdup(rhs.name);
    clntid = rhs.clntid;
    portid = rhs.portid;
  }

  ~alsa_mididevinfo_t() { Xfree(name); }

  alsa_mididevinfo_t &operator=(const alsa_mididevinfo_t &rhs)
  {
    if (this != &rhs)
    {
        Xfree(name);
        name = Xstrdup(rhs.name);
        clntid = rhs.clntid;
        portid = rhs.portid;
    }
    return *this;
  }
};

std::vector<alsa_mididevinfo_t> const ALSADrv_MIDI_ListPorts();

extern int32_t ALSA_ClientID;
extern int32_t ALSA_PortID;
#endif

enum MUSIC_ERRORS
{
    MUSIC_Warning = -2,
    MUSIC_Error   = -1,
    MUSIC_Ok      = 0,
    MUSIC_MidiError,
};

typedef struct
{
    uint32_t tickposition;
    uint32_t milliseconds;
    uint32_t measure;
    uint32_t beat;
    uint32_t tick;
} songposition;

#define MUSIC_LoopSong ( 1 == 1 )
#define MUSIC_PlayOnce ( !MUSIC_LoopSong )

#define MUSIC_SetErrorCode(status) MUSIC_ErrorCode = (status);

extern const char *MUSIC_ErrorString(int ErrorNumber);

int  MUSIC_Init(int SoundCard);
int  MUSIC_Shutdown(void);
int  MIDI_GetDevice(void);
void MUSIC_SetVolume(int volume);
int  MUSIC_GetVolume(void);
void MUSIC_SetLoopFlag(int loopflag);
void MUSIC_Continue(void);
void MUSIC_Pause(void);
int  MUSIC_StopSong(void);
int  MUSIC_PlaySong(char *song, int songsize, int loopflag, const char *fn = nullptr);
void MUSIC_Update(void);
void MUSIC_SetSongPosition(int measure, int beat, int tick);
void MUSIC_GetSongPosition(songposition *pos);

/* returns true only after program startup */
static FORCE_INLINE int MUSIC_WarmedUp(void)
{
    return ASS_MIDISoundDriver != ASS_AutoDetect;
}

extern char SF2_BankFile[BMAX_PATH];
extern int SF2_EffectSampleBlockSize;

#endif
