.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_SIGN
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl2::
	msgbox MossdeepCity_PokemonCenter_1F_Text_Girl2, MSGBOX_SIGN
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "Yaaaawwwwn... I just got here from\n"
	.string "the other side of the world.\p"
	.string "To me, it feels like 3:28 AM on the\n"
	.string "night before the deadline right now.$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "So, three contests at the same time,\n"
	.string "huh?\p"
	.string "It means a ton of games for people\n"
	.string "to play, so it's fine!$"

MossdeepCity_PokemonCenter_1F_Text_Girl2:
	.string "Surely no one would try to juggle\n"
	.string "all three contests...\p"
	.string "That would be like telling everyone\n"
	.string "that they have no life!$"


