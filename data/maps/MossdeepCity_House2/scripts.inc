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
	waitmovement 0
	msgbox MossdeepCity_House2_Text_SeanCutscene3, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL	
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
	msgbox MossdeepCity_House2_Text_SeanCutscene4, MSGBOX_DEFAULT
	releaseall
	setvar VAR_TEMP_1, 0
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
	.string "MAXIE: My fellow citizens.$"

MossdeepCity_House2_Move_FaceLeft:
	face_left
	step_end

MossdeepCity_House2_Move_FaceRight:
	face_right
	step_end

MossdeepCity_House2_Text_SeanCutscene4:
	.string "   N: What just happened?\n"
	.string "Did Maxie really outlaw      ?\p"
	.string "What? I can't even say it?\p"
	.string "Chel    , what are... \p"
	.string "Wait, what happened to your...\p"
	.string "What happened to MY name?!?$"






MossdeepCity_House2_EventScript_Sean::
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, MossdeepCity_House2_EventScript_Sean2
	msgbox MossdeepCity_House2_Text_Sean1, MSGBOX_NPC
	givemon SPECIES_KLEFKI, 25
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_House2_Text_KlefkiGet
	waitmessage
	waitfanfare
	setflag FLAG_WINGULL_DELIVERED_MAIL
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

