.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_SIGN
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_SIGN
	release
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Yaaaawwwwn... yeah, I'm jetlagged.\p"
	.string "To me, it feels like 3:36 AM on the\n"
	.string "night before the deadline right now.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "I played some of the MAGM 9 games.\p"
	.string "I really had a great time with\n"
	.string "-REDACTED, RESULTS NOT RELEASED YET-$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "I haven't gotten a chance to play\n"
	.string "the Eevee Expo games yet.\p"
	.string "Seems like a lot of variety, though!$"
