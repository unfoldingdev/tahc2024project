FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Did you see that L, though? It looks\n"
	.string "so cool - maybe it wants to take\l"
	.string "Walter's place in the group?$"



FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "He did vanish right in front of us, but\n"
	.string "honestly it's not a big loss.\p"
	.string "Dude had terrible taste in games.$"


FortreeCity_Mart_Text_SuperRepelBetter:
	.string "I'm on a tight budget, and it's\n"
	.string "hard to know what to buy!$"



