.set LOCALID_WINGULL, 3
.set LOCALID_SEAN, 1

MossdeepCity_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_House2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_House2_OnFrame
	.byte 0


MossdeepCity_House2_OnTransition::
	setvar VAR_TEMP_1, 1
	end


MossdeepCity_House2_OnFrame::
	map_script_2 VAR_TEMP_1, 1, MossdeepCity_House2_Cutscene
	.2byte 0

MossdeepCity_House2_Cutscene::
	goto_if_set FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL, MossdeepCity_House2_End
	lockall
	msgbox MossdeepCity_House2_Text_SeanCutscene1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SEAN, MossdeepCity_House2_Move_FaceDown
	msgbox MossdeepCity_House2_Text_SeanCutscene2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SEAN, MossdeepCity_House2_Move_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_House2_Move_WalkToTV
	fadeoutbgm 0
	waitmovement 0
	playbgm MUS_VS_AQUA_MAGMA_LEADER, FALSE
	delay 24
	msgbox MossdeepCity_House2_Text_SeanCutscene3, MSGBOX_AUTOCLOSE
	msgbox MossdeepCity_House2_Text_SeanCutscene32, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	fadeoutbgm 0
	delay 24
	playbgm MUS_B_FACTORY, FALSE
	applymovement LOCALID_SEAN, MossdeepCity_House2_Move_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_House2_Move_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_SEAN, MossdeepCity_House2_Move_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_House2_Move_FaceUp
	waitmovement 0
	delay 20
	applymovement LOCALID_SEAN, MossdeepCity_House2_Move_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_House2_Move_FaceLeft
	waitmovement 0
	delay 20
	callnative SetPlayerNameToChel
	msgbox MossdeepCity_House2_Text_SeanCutscene4, MSGBOX_AUTOCLOSE
	setrespawn HEAL_LOCATION_FORTREE_CITY
	callnative GetFirstMonLevel
	givemon SPECIES_CROCONAW, VAR_RESULT
	setvar VAR_RESULT, 0
	callnative DeletePartyMon
	setvar VAR_TEMP_1, 0
	goto_if_set FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL, MossdeepCity_House2_EventScript_Sean
	releaseall
	end



MossdeepCity_House2_Text_SeanCutscene1:
	.string "SEAN: Chelsea? That you?$"

MossdeepCity_House2_Move_FaceDown:
	face_down
	step_end

MossdeepCity_House2_Text_SeanCutscene2:
	.string "SEAN: Oh, perfect timing! The\n"
	.string "announcement is about to start!\p"
	.string "President Maxie looks real serious.\p"
	.string "Come on, quick!$"

MossdeepCity_House2_Move_FaceUp:
	face_up
	step_end

MossdeepCity_House2_Move_WalkToTV:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_House2_Text_SeanCutscene3:
	.string "MAXIE: My fellow citizens.\p"
	.string "We live in a region with too much water.\p"
	.string "This is a fact. Indisputable.\p"
	.string "This water divides us. Keeps us apart.\p"
	.string "Our great cities are separated... by\n"
	.string "this water.\p"
	.string "By yet another wild Tentacool every few\n"
	.string "tiles.\p"
	.string "By the long queue to fight Norman, to\n"
	.string "even earn the right to Surf.\p"
	.string "By pointless detours, currents, rapids\n"
	.string "that only waste our time.\p"
	.string "MAXIE:...\p"
	.string "We live in a region with too much water.\p"
	.string "It has upset the balance that is needed\n"
	.string "for people and Pokemon to thrive.\p"
	.string "Water-type Pokemon are everywhere,\n"
	.string "like a pestilence for all trainers.\p"
	.string "And they do not fight fairly.\p"
	.string "Steven Stone, the rightful champion of\n"
	.string "Hoenn, was defeated by a mere artist.\p"
	.string "How?\p"
	.string "Because the artist used only Water\n"
	.string "Pokemon.$"

MossdeepCity_House2_Text_SeanCutscene32:
	.string "Instead of putting Surf, Waterfall,\n"
	.string "and Dive on one low-level Pokemon,\l"
	.string "as a necessary evil...\p"
	.string "this so-called champion chose to stack\n"
	.string "his team as unfairly as possible.\p"
	.string "MAXIE:...\p"
	.string "Yes, we live in a region with too much\n"
	.string "water.\p"
	.string "And it is high time we did something\n"
	.string "about it.\p"
	.string "And that is why, effective immediately,\n"
	.string "WATER IS NOW OUTLAWED.\p"
	.string "MAXIE:...\p"
	.string "That's right.\p"
	.string "Water is now illegal in all its forms.\p"
	.string "No more pesky rain ending your outdoor\n"
	.string "games and adventures.\p"
	.string "No more ocean to cross when visiting\n"
	.string "friends or tourist attractions.\p"
	.string "No more watching your beloved Camerupt\n"
	.string "die to a Bubblebeam, again.\p"
	.string "MAXIE:...\p"
	.string "My fellow citizens...\p"
	.string "We are no longer a 7.8/10 region!$"

MossdeepCity_House2_Move_FaceLeft:
	face_left
	step_end

MossdeepCity_House2_Move_FaceRight:
	face_right
	step_end

MossdeepCity_House2_Text_SeanCutscene4:
	.string "      N: What just happened?\n"
	.string "Did Maxie really outlaw          ?\p"
	.string "Wait, what?\p"
	.string "I can't even say it?\p"
	.string "Chel     , what are... \p"
	.string "???\p"
	.string "Wait, what happened to your...\p"
	.string "What happened to MY name?!?$"






MossdeepCity_House2_EventScript_Sean::
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, MossdeepCity_House2_EventScript_Sean2
	msgbox MossdeepCity_House2_Text_Sean1, MSGBOX_AUTOCLOSE
	givemon SPECIES_KLEFKI, 25
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_House2_Text_KlefkiGet
	waitmessage
	waitfanfare
	setflag FLAG_WINGULL_DELIVERED_MAIL
	release
	end

MossdeepCity_House2_Text_Sean1:
	.string "...\p"
	.string "N: I guess I'm N now? What a disaster.\p"
	.string "Oh, I almost forgot. You're here for\n"
	.string "Penny's spare keys, right?$"

MossdeepCity_House2_EventScript_Sean2::
	msgbox MossdeepCity_House2_Text_Sean2, MSGBOX_NPC
	end

MossdeepCity_House2_Text_Sean2:
	.string "N: Dang, I just ordered some expensive\n"
	.string "monogrammed towels...\p"
	.string "Not only will the S on them not make\n"
	.string "sense, but also towels are useless now!$"

MossdeepCity_House2_Text_KlefkiGet:
	.string "CHEL received Penny's keys!$"

MossdeepCity_House2_End::
	end


MossdeepCity_House2_EventScript_TV::
	msgbox MossdeepCity_House2_Text_TV, MSGBOX_NPC
	release
	end


MossdeepCity_House2_Text_TV:
	.string "Maxie's shaking a lot of hands.\p"
	.string "He looks a little too happy.$"








MossdeepCity_House2_EventScript_Twin::
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_WINGULL_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_WingullExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_WingullExitWest
	removeobject LOCALID_WINGULL
	release
	end

MossdeepCity_House2_EventScript_WingullExitNorth::
	applymovement LOCALID_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_WingullExitWest::
	applymovement LOCALID_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_WingullExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_WingullExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don't envy her one bit at all.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
	.string "Even though I can't see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I'm not lonesome, even though we're\n"
	.string "apart.$"

MossdeepCity_House2_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

