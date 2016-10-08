/*
	Command Processor ~ Kevin-Reinke

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _cmdp_included
	#endinput
#endif

#define _cmdp_included

#if !defined sscanf
	#error "SSCANF could not be found"
#endif

#if defined OnPlayerCommandPerformed
	forward OnPlayerCommandPerformed(playerid, cmdtext[], success);
#endif

// ** DEFINES

// *** FUNCTIONS

#define CMD:%1(%2) forward cmd_%1(%2); public cmd_%1(%2)
#define COMMAND:%1(%2) forward cmd_%1(%2); public cmd_%1(%2)

// ** CALLBACKS

public OnPlayerCommandText(playerid, cmdtext[])
{
	new cmd[32] = "cmd_", params[128];
	if(sscanf(cmdtext[1], "s[28]s[128]", cmd[4], params))
	{
		for(new i = 4, j = strlen(cmd); i < j; i ++)
		{
			cmd[i] |= 0x20;
		}

		#if defined OnPlayerCommandPerformed
			return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(cmd, "is", playerid, "\1"));
		#else
			return CallLocalFunction(cmd, "is", playerid, "\1");
		#endif
	}
	else
	{
		for(new i = 4, j = strlen(cmd); i < j; i ++)
		{
			cmd[i] |= 0x20;
		}

		#if defined OnPlayerCommandPerformed
			return OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(cmd, "is", playerid, params));
		#else
			return CallLocalFunction(cmd, "is", playerid, params);
		#endif
	}
}