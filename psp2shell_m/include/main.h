/*
	PSP2SHELL
	Copyright (C) 2016, Cpasjuste

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAIN_H
#define MAIN_H

#include "p2s_cmd.h"
#include "p2s_msg.h"
#include "file.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct {
    int msg_sock;
    int cmd_sock;
    P2S_CMD cmd;
    P2S_MSG msg;
    s_FileList fileList;
} s_client;

#endif // MAIN_H
