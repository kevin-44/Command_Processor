# Command Processor - SA-MP

This include forwards in-game command input to hard-coded functions, at a fast speed.

Benchmark with I-ZCMD (5 consecutive tests):

	This Include: 882
	This Include: 893
	This Include: 878
	This Include: 883
	This Include: 892

	I-ZCMD: 1,111
	I-ZCMD: 1,106
	I-ZCMD: 1,105
	I-ZCMD: 1,118
	I-ZCMD: 1,115

Code used to benchmark both:

	// ** MAIN

	main()
	{
		new tick = GetTickCount();
		for(new i = 0; i < 50000; i ++)
		{
			OnPlayerCommandText(0, "/AaaaaaaaaaaaaaaAaaaaaaaaAa6 test");
			OnPlayerCommandText(0, "/AaaaaaaaaaaaaaaAaaaaaaaaAa6 test");
			OnPlayerCommandText(0, "/AaaaaaaaaaaaaaaAaaaaaaaaAa6 test");
		}

		printf("%d", GetTickCount() - tick);
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
		/*if(success)
		{
			print("success true");
		}
		else
		{
			print("success false");
		}*/
		return 1;
	}

	// ** COMMANDS

	CMD:aaaaaaaaaaaaaaaaaaaaaaaaaa6(playerid, params[])
	{
		//printf("%d %s", playerid, params);
		return 1;
	}

The example script (command_processor_example.pwn) and the include (command_processor.inc) requires:
* SSCANF: http://forum.sa-mp.com/showthread.php?t=602923
