LilycoveCity_House1_MapScripts::
	.byte 0




LilycoveCity_House1_EventScript_Girl::
	msgbox LilycoveCity_House1_Text_Parallel, MSGBOX_NPC
	end

LilycoveCity_House1_Text_Parallel:
	.string "I'm reading about some other parallel\n"
	.string "universes now.\p"
	.string "There's one in which people are made\n"
	.string "of Electric, and others with people\l"
	.string "made of Fighting, or Fairy, or Flying.\p"
	.string "Fascinating stuff!$"


LilycoveCity_House1_EventScript_Gent::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "I thought the big announcement was\n"
	.string "going to be about Archie.\p"
	.string "Thank goodness it was just about\n"
	.string "removing Hoenn's identity.$"


LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Ruroro?$"

