.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 25
.set LOCALID_SCOTT, 43

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end



Route119_EventScript_LedgeGuy::
	msgbox Route119_Text_LedgeGuy, MSGBOX_NPC
	end

Route119_Text_LedgeGuy:
	.string "Okay, I got this far climbing on the\n"
	.string "weeds, but there's not enough here.\p"
	.string "I think we might have to jump for it\n"
	.string "at that spot right there.$"





Route119_EventScript_Nick::
	msgbox Route119_Text_Nick, MSGBOX_NPC
	release
	end

Route119_Text_Nick:
	.string "NICK: That damn duck keeps exploding!\n"
	.string "I guess its ability is DRY SKIN now...\p"
	.string "Whenever I try to get close to her,\n"
	.string "that duck just explodes my Pokemon!$"



Route119_EventScript_Nikki::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_NikkiIntro, Route119_Text_NikkiDefeat
	msgbox Route119_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
	end


Route119_Text_NikkiIntro:
	.string "NIKKI: Hi Chel   ! ...Oh. Chel. Hi Chel!\n"
	.string "My duck is really strong now!$"

Route119_Text_NikkiDefeat:
	.string "Yayyyy!$"

Route119_Text_NikkiPostBattle:
	.string "NIKKI: I've decided! I want Daddy\n"
	.string "to get me a full team of duckies!$"


Route119_EventScript_Nicky::
	trainerbattle_single TRAINER_CLARK, Route119_Text_NickyIntro, Route119_Text_NickyDefeat
	msgbox Route119_Text_NickyPostBattle, MSGBOX_AUTOCLOSE
	end


Route119_Text_NickyIntro:
	.string "NICKY: Nikki's duck is so strong!\p"
	.string "But my fishy can also attack now!$"

Route119_Text_NickyDefeat:
	.string "Hahahahaha!$"

Route119_Text_NickyPostBattle:
	.string "NICKY: Look at fishy's cute face!$"






Route119_EventScript_MagmaGrunt::
	trainerbattle_single TRAINER_DONALD, Route119_Text_MagmaGruntIntro, Route119_Text_MagmaGruntDefeat
	msgbox Route119_Text_MagmaGruntPostBattle, MSGBOX_AUTOCLOSE
	end


Route119_Text_MagmaGruntIntro:
	.string "MAGMA GRUNT: My time has come.\n"
	.string "Laugh at my 4x weaknesses, will you?$"

Route119_Text_MagmaGruntDefeat:
	.string "MAGMA GRUNT: What?!\n"
	.string "I had every advantage!$"

Route119_Text_MagmaGruntPostBattle:
	.string "MAGMA GRUNT: Now that I look at it,\n"
	.string "Magcargo still has a 4x weakness\l"
	.string "against Ground.\p"
	.string "That's it!\p"
	.string "I'll just petition Maxie to outlaw the\n"
	.string "ground, too!$"


Route119_EventScript_AquaGrunt::
	trainerbattle_single TRAINER_BRENT, Route119_Text_AquaGruntIntro, Route119_Text_AquaGruntDefeat
	msgbox Route119_Text_AquaGruntPostBattle, MSGBOX_AUTOCLOSE
	end


Route119_Text_AquaGruntIntro:
	.string "GRUNT: What happened to my team?!\p"
	.string "What happened to my name?!$"

Route119_Text_AquaGruntDefeat:
	.string "GRUNT: Wait, 'fall' does damage to\n"
	.string "yourself for no benefit?!$"

Route119_Text_AquaGruntPostBattle:
	.string "GRUNT: I can't believe it. Maxie\n"
	.string "really outlawed Wa-... you know.\p"
	.string "He crippled my team!\p"
	.string "He broke my 500 game win streak\n"
	.string "against that Magma Grunt!\p"
	.string "He made a kooky old man appear in\n"
	.string "my pocket!\p"
	.string "And worst of all, he changed my name\n"
	.string "to Team Grunt, which sounds like a\l"
	.string "caveman football league!$"


Route119_EventScript_ShyElectric::
	trainerbattle_single TRAINER_GREG, Route119_Text_ShyElectricIntro, Route119_Text_ShyElectricDefeat
	msgbox Route119_Text_ShyElectricPostBattle, MSGBOX_AUTOCLOSE
	end


Route119_Text_ShyElectricIntro:
	.string "awholetypeisgonehowhowhowhow$"

Route119_Text_ShyElectricDefeat:
	.string "iwasntpayingattentioniwasthinking\n"
	.string "aboutthenewmeta$"

Route119_Text_ShyElectricPostBattle:
	.string "sunwinsweatherwarssofiretypesbuffed\n"
	.string "meaningstealthrockbuffed...$"


Route119_EventScript_OldLady::
	msgbox Route119_Text_OldLady, MSGBOX_NPC
	release
	end

Route119_Text_OldLady:
	.string "What happened?\p"
	.string "It was all gone so suddenly!\p"
	.string "Good thing I had a coverup, eh\n"
	.string "sweetie?\p"
	.string "Ehehehehehehe!$"

Route119_EventScript_MyLegs::
	msgbox Route119_Text_MyLegs, MSGBOX_NPC
	release
	end

Route119_Text_MyLegs:
	.string "AAAAAAAAHHHHHHH MY LEGS!$"


Route119_EventScript_MyLegsAreFine::
	msgbox Route119_Text_MyLegsAreFine, MSGBOX_NPC
	release
	end

Route119_Text_MyLegsAreFine:
	.string "I understand why the deep part is\n"
	.string "dangerous now mama!\p"
	.string "If you had a tube like mine, you\n"
	.string "could have bounced!$"


Route119_EventScript_Captain::
	msgbox Route119_Text_Captain, MSGBOX_NPC
	release
	end

Route119_Text_Captain:
	.string "In all me years at... well, here, I've\n"
	.string "never seen anything like this.\p"
	.string "Me ship and me one true love, both gone\n"
	.string "in an instant.$"

Route119_EventScript_Refund::
	msgbox Route119_Text_Refund, MSGBOX_DEFAULT
	release
	end

Route119_Text_Refund:
	.string "It's really very simple.\p"
	.string "I paid for a trip across...\n"
	.string "A trip from here to there.\p"
	.string "I'm not there. You failed to get me all\n"
	.string "the way there.\p"
	.string "So, you didn't deliver what I paid for.\p"
	.string "So, start processing my refund.$"



Route119_EventScript_NotAccountable::
	msgbox Route119_Text_NotAccountable, MSGBOX_DEFAULT
	release
	end

Route119_Text_NotAccountable:
	.string "Sir, you cannot possibly be trying to\n"
	.string "hold the ferry service accountable for\l"
	.string "the disappearance of the...\p"
	.string "the road itself.$"

Route119_EventScript_Sailor::
	msgbox Route119_Text_Sailor, MSGBOX_NPC
	release
	end

Route119_Text_Sailor:
	.string "There must be some way to undo it.\p"
	.string "But... what would even happen if Maxie\n"
	.string "just put it all back?\p"
	.string "This would be a sunken ship!$"


Route119_EventScript_Scientist::
	msgbox Route119_Text_Scientist, MSGBOX_NPC
	release
	end

Route119_Text_Scientist:
	.string "Wow, it's one thing to send out a\n"
	.string "fish in a battle on land, and\l"
	.string "watch it float in midair...\p"
	.string "But it's another to see them\n"
	.string "rolling about here, unconcerned.\p"
	.string "They actually never needed -it- to\n"
	.string "survive.$"


Route119_EventScript_PokeFanF::
	msgbox Route119_Text_PokeFanF, MSGBOX_NPC
	release
	end

Route119_Text_PokeFanF:
	.string "This is a perfect opportunity to\n"
	.string "replace the boring liquid that was\l"
	.string "here with something more interesting.\p"
	.string "Gravy, acid, paint... I always wondered\n"
	.string "why the developers didn't think out of\l"
	.string "the box.$"


Route119_EventScript_CaveLady::
	msgbox Route119_Text_CaveLady, MSGBOX_NPC
	end

Route119_Text_CaveLady:
	.string "When I took this job, they told me\n"
	.string "to tell the player about these caves.\p"
	.string "You know, communicate that they're\n"
	.string "inaccessible, like as an anti-\l"
	.string "frustration feature.\p"
	.string "But, I forgot what the player looks\n"
	.string "like, so I'm just telling everyone.$"


Route119_EventScript_NoStones::
	lockall
	goto_if_set FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL, Route119_EventScript_NoStonesGiven
	msgbox Route119_Text_NoStones, MSGBOX_NPC
	giveitem ITEM_HARD_STONE
	setflag FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL
	release
	end

Route119_Text_NoStones:
	.string "Oh my god, they're useless!\p"
	.string "Something happened, and my precious\n"
	.string "Wa- uh, evolution stones turned into...\p"
	.string "ROCKS!\p"
	.string "My poor Pokemon!\p"
	.string "Just look at this!$"

Route119_EventScript_NoStonesGiven::
	msgbox Route119_Text_NoStonesGiven, MSGBOX_NPC
	release
	end

Route119_Text_NoStonesGiven:
	.string "Eviolite Lombre? Is that really\n"
	.string "what I have to do?$"

Route119_EventScript_Mystic::
	msgbox Route119_Text_Mystic, MSGBOX_NPC
	end

Route119_Text_Mystic:
	.string "Hello, young woman. Until recently,\n"
	.string "I was attached to one of that fellow's\l"
	.string "Pokemon, providing it a damage bonus.\p"
	.string "But now, I plan to travel and seek\n"
	.string "out the mysteries of the world.\p"
	.string "The lost path is the one most sought!$"


















Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL_ON_BIKE
	addobject LOCALID_RIVAL
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_RIVAL, 25, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_RIVAL, 26, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Ship::
	msgbox Route119_Text_Ship, MSGBOX_SIGN
	end

Route119_Text_Ship:
	.string "The ship's underside is badly damaged.\n"
	.string "It must have hit the ground hard.$"

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Where were you? I was looking for you!\p"
	.string "How much stronger have you gotten?\n"
	.string "Let me check for you!\p"
	.string "Ready with your POKéMON?\n"
	.string "Of course you are! Go!$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, you're strong!\p"
	.string "I was worried that you might be\n"
	.string "struggling with your training.$"

Route119_Text_MayPresentForYou:
	.string "MAY: But I had absolutely nothing to\n"
	.string "worry about! Keep it up!\p"
	.string "And, here! I have a present for you.$"

Route119_Text_MayExplainFly:
	.string "MAY: Use FLY, and your POKéMON will\n"
	.string "instantly carry you to any town you've\l"
	.string "already visited.\p"
	.string "But, to use FLY, you have to get\n"
	.string "the GYM BADGE from FORTREE CITY.\l"
	.string "That's important, so don't forget.\p"
	.string "You should FLY home and visit\n"
	.string "LITTLEROOT for a change.\p"
	.string "I bet your mom's worried about you,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Well, let's meet again somewhere!$"

Route119_Text_BrendanIntro:
	.string "BRENDAN: {PLAYER}! So this is where\n"
	.string "you've been looking for POKéMON?\p"
	.string "Let me see how good you got.\n"
	.string "I'll test you!\p"
	.string "Now!\n"
	.string "It's a battle, so battle!$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "You've gotten pretty darn decent.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "BRENDAN: I'd say you're good enough\n"
	.string "to search for POKéMON anywhere.\p"
	.string "Here, I'll give you this.\n"
	.string "Try it out.$"

Route119_Text_BrendanExplainFly:
	.string "BRENDAN: Use FLY, and your POKéMON\n"
	.string "instantly carries you to any town\l"
	.string "you've already visited.\p"
	.string "But you need the FORTREE GYM BADGE \n"
	.string "to do that.\p"
	.string "Anyway, I have to move along.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "SCOTT: Hahahah!\n"
	.string "Way to go, {PLAYER}{KUN}!\p"
	.string "I just passed by a TRAINER riding\n"
	.string "a BIKE.\p"
	.string "You just beat that TRAINER, didn't you?\n"
	.string "It was pretty obvious that you did.\p"
	.string "The kid looked really upset with\n"
	.string "a face all red from anger.\p"
	.string "I sure seem to run into you often.\n"
	.string "Are you off to FORTREE GYM next?\p"
	.string "I expect that you'll do well at the GYM.\n"
	.string "Well, I'll be seeing you!$"


Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
	.string "Just as I thought, you won at\n"
	.string "the FORTREE GYM.\p"
	.string "Your strength…\n"
	.string "Perhaps you really are the TRAINER\l"
	.string "that I've been searching for.\p"
	.string "Remember, you have a fan in me.\n"
	.string "I'll be cheering from the sidelines.\l"
	.string "Keep up the great work!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the WEATHER\n"
	.string "INSTITUTE. It's not safe.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "WEATHER INSTITUTE.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD POKéMON, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Can your POKéMON use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute:
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration:
	.string "TRAINER TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a SECRET BASE.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own SECRET BASE exactly the\l"
	.string "way you want.$"
