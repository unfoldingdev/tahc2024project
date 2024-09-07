FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end


FortreeCity_EventScript_FreshWater::
	msgbox FortreeCity_Text_WalterL, MSGBOX_NPC
	giveitem ITEM_ADAMANT_MINT
	release
	end

FortreeCity_Text_FreshWater:
	.string "It's all gone. My beautiful stash\n"
	.string "of Fresh...\p"
	.string "Now they've turned into candy.\p"
	.string "A whole pocketful.\p"
	.string "How many could I possibly use?\p"
	.string "Here, take one.$"


FortreeCity_EventScript_WalterL::
	msgbox FortreeCity_Text_WalterL, MSGBOX_SIGN
	end

FortreeCity_Text_WalterL:
	.string "There's... a letter L on the\n"
	.string "ground here?$"


FortreeCity_EventScript_NSign::
	msgbox FortreeCity_Text_NSign, MSGBOX_SIGN
	end

FortreeCity_Text_NSign:
	.string "      n's House$"

FortreeCity_EventScript_CitySign1::
	msgbox FortreeCity_Text_CitySign1, MSGBOX_SIGN
	end

FortreeCity_Text_CitySign1:
	.string "Meris Village\p"
	.string "The only rock around here that can\n"
	.string "hold multiple low-maintenance people.$"

FortreeCity_EventScript_BillSign::
	msgbox FortreeCity_Text_BillSign, MSGBOX_SIGN
	end

FortreeCity_Text_BillSign:
	.string "Bill's House$"


FortreeCity_EventScript_Fisherman::
	lockall
	faceplayer
	goto_if_set FLAG_HIDE_FORTREE_CITY_KECLEON, FortreeCity_EventScript_FishermanRodGiven
	msgbox FortreeCity_Text_Fisherman, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_EventScript_FishermanNoRod
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_FishermanYesRod
	release
	end

FortreeCity_Text_Fisherman:
	.string "Hahahahaha!\n"
	.string "Why didn't anyone think of this before?\p"
	.string "I don't have to wait around for hours\n"
	.string "hoping the fish bite!\p"
	.string "I can just pick fish off the ground!\p"
	.string "I don't need my rod anymore, do you\n"
	.string "want it?$"

FortreeCity_EventScript_FishermanNoRod::
	msgbox FortreeCity_Text_FishermanNoRod, MSGBOX_DEFAULT
	release
	end

FortreeCity_Text_FishermanNoRod:
	.string "Yeah, figured it was useless. Maybe it\n"
	.string "could be a cat toy... for a faraway cat?$"

FortreeCity_EventScript_FishermanYesRod::
	setflag FLAG_HIDE_FORTREE_CITY_KECLEON
	msgbox FortreeCity_Text_FishermanYesRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	release
	end

FortreeCity_Text_FishermanYesRod:
	.string "I have no idea what you want it for,\n"
	.string "but it's all yours!$"

FortreeCity_EventScript_FishermanRodGiven::
	msgbox FortreeCity_Text_FishermanRodGiven, MSGBOX_DEFAULT
	release
	end

FortreeCity_Text_FishermanRodGiven:
	.string "Ooh. I just realized something.\n"
	.string "Are these fish safe to eat?\p"
	.string "Normally they'd be swimming and it would\n"
	.string "be fine, but now I gotta worry about\l"
	.string "the five second rule.$"



FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "No one believes me, but I saw this\n"
	.string "gigantic POKéMON in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "ROUTE 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh…smell singed.\p"
	.string "Were you at a volcano or something?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "I want to go to the POKéMON GYM,\n"
	.string "but something's blocking the way.\p"
	.string "After all the bother I went through\n"
	.string "training on ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "I've got my pride-and-joy POKéMON\n"
	.string "with me. This time, I'll beat WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our FORTREE CITY exists because\n"
	.string "there's both water and soil.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "The CITY consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Living on top of trees is okay.\p"
	.string "But sometimes BUG POKéMON come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "There are POKéMON that evolve when\n"
	.string "you trade them! That's what I heard.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Something unseeable is in the way.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON fled!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY\n"
	.string "“The treetop city that frolics with\l"
	.string "nature.”$"

FortreeCity_Text_GymSign:
	.string "FORTREE CITY POKéMON GYM\n"
	.string "LEADER: WINONA\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"

