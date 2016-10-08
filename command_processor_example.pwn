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

// ** INCLUDES

#include <a_samp>
#include <sscanf2>
#include <command_processor>

// ** MAIN

main()
{
	print("Loaded \"command_processor.amx\".");
}

// ** CALLBACKS

public OnGameModeInit()
{
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(success)
	{
		SendClientMessage(playerid, -1, "Command Processor: Command executed!");
	}
	else
	{
		SendClientMessage(playerid, -1, "Command Processor: Command couldn't executed.");
	}
	return 1;
}

// ** COMMANDS

CMD:mycommand(playerid, params[])
{
	SendClientMessage(playerid, -1, "You have used /mycommand!");
	return 1;
}

COMMAND:myothercommand(playerid, params[])
{
	SendClientMessage(playerid, -1, "You have used /myothercommand!");
	return 1;
}