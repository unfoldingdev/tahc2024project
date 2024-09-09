MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_NPC
	release
	end


MossdeepCity_House3_Text_YouWantSuperRod:
	.string "-sigh- Hi. Welcome to the Meris Gym.\p"
	.string "Meris's Gym Leader Kanada went to a few\n"
	.string "Feng Shui seminars and decided that it\l"
	.string "was close enough to Water for it to be\l"
	.string "her Gym puzzle.\p"
	.string "So I don't get to be in a cool indoor\n"
	.string "pool or a icy labyrinth.\p"
	.string "I'm in a badly-designed-on-purpose\n"
	.string "house, with some easy puzzles.\p"
	.string "Anyway, don't bring Fire and Ground\n"
	.string "Pokemon or whatever.$"




MossdeepCity_House3_EventScript_Trainer::
	msgbox MossdeepCity_House3_Text_Trainer, MSGBOX_NPC
	release
	end

MossdeepCity_House3_Text_Trainer:
	.string "Halt! To pass, you must first\n"
	.string "demonstrate your mastery of Water\l"
	.string "Pokemon and the art of feng shui!\p"
	.string "First, you must balance this room, and\n"
	.string "find... oh, you don't have Strength yet.\p"
	.string "How can you perfect your furniture\n"
	.string "arranging skills without Strength?$"


MossdeepCity_House3_EventScript_Pot::
	msgbox MossdeepCity_House3_Text_Pot, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_Pot:
	.string "This potted plant is obviously out\n"
	.string "of place, but you don't have STRENGTH.$"
