MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_NPC
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "It's nice to have a neighbor like\n"
	.string "Sean.\p"
	.string "He has a nice TV, so whenever there's\n"
	.string "something going on, we get to know.\p"
	.string "It is a little inconvenient that he\n"
	.string "has to sleep here every night, though.$"



MossdeepCity_House4_EventScript_NinjaBoy::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_NPC
	release
	end

MossdeepCity_House4_Text_MakeSecretBase:
	.string "You should make a SECRET BASE\n"
	.string "somewhere. I'll go find it!$"


MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end


MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "My little brother says he likes to\n"
	.string "visit people's SECRET BASES and have\l"
	.string "POKéMON battles.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Was it you who made a SECRET BASE\n"
	.string "near {STR_VAR_1}?$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY: Miyaan?$"

