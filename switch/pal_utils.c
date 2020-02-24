/* -*- mode: c; tab-width: 4; c-basic-offset: 4; c-file-style: "linux" -*- */
//
// Copyright (c) 2009-2011, Wei Mingzhi <whistler_wmz@users.sf.net>.
// Copyright (c) 2011-2020, SDLPAL development team.
// All rights reserved.
//
// This file is part of SDLPAL.
//
// SDLPAL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include "main.h"
#include "SDL.h"

static int input_event_filter(const SDL_Event *lpEvent, volatile PALINPUTSTATE *state) {
  int button, which;
  switch (lpEvent->type)
  {
    case SDL_JOYBUTTONDOWN:
      button = lpEvent->jbutton.button;
      which = lpEvent->jbutton.which;
      switch (button)
      {
        case 0: //A
          state->dwKeyPress |= kKeySearch;
          return 1;

          //case 1: //B

        case 2: //X
          state->dwKeyPress |= kKeyMenu;
          return 1;

        //case 3: //Y

        //case 4: //LSTICK

        //case 5: //RSTICK

        case 6: //L
        case 8: //ZL
          state->dwKeyPress |= kKeyPgUp;
          return 1;

        case 7: //R
        case 9: //ZR
          state->dwKeyPress |= kKeyPgDn;

        //case 10: //PLUS

        //case 11: //MINUS

        case 12: //DLEFT
        case 16: //LSTICKLEFT
          state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
          state->dir = kDirWest;
          state->dwKeyPress |= kKeyLeft;
          break;

        case 13: //DUP
        case 17: //LSTICKUP
          state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
          state->dir = kDirNorth;
          state->dwKeyPress |= kKeyUp;
          break;

        case 14: //DRIGHT
        case 18: //LSTICKRIGHT
          state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
          state->dir = kDirEast;
          state->dwKeyPress |= kKeyRight;
          break;

        case 15: //DDOWN
        case 19: //LSTICK DOWN
          state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
          state->dir = kDirSouth;
          state->dwKeyPress |= kKeyDown;
          break;
      }
  }
  return 0;
}

BOOL
UTIL_GetScreenSize(
	DWORD *pdwScreenWidth,
	DWORD *pdwScreenHeight
)
{
	return (pdwScreenWidth && pdwScreenHeight && *pdwScreenWidth && *pdwScreenHeight);
}

BOOL
UTIL_IsAbsolutePath(
	LPCSTR  lpszFileName
)
{
	return FALSE;
}

INT
UTIL_Platform_Init(
	int argc,
	char* argv[]
)
{
	PAL_RegisterInputFilter(NULL, input_event_filter, NULL);
	gConfig.fLaunchSetting = FALSE;
	return 0;
}

VOID
UTIL_Platform_Quit(
	VOID
)
{
}
