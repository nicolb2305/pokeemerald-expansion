MauvilleCity_House2_MapScripts:: @ 8210C5C
	.byte 0

MauvilleCity_House2_EventScript_Woman:: @ 8210C5D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	goto MauvilleCity_House2_EventScript_AcceptTrade
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail:: @ 8210C82
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_House2_EventScript_AcceptTrade
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade:: @ 8210CB8
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase:: @ 8210CDA
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade:: @ 8210CE4
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport: @ 8210CEE
	.string "If I had a BIKE, it'd be easy to cycle to\n"
	.string "SLATEPORT for some shopping.\p"
	.string "I'd be able to buy HARBOR MAIL at the\n"
	.string "POKéMON MART in SLATEPORT…\p"
	.string "Oh? They're no longer selling\n"
	.string "HARBOR MAIL at the POKéMON MART in\l"
	.string "SLATEPORT?\p"
	.string "I guess I will just have to give you\n"
	.string "this for free then…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase: @ 8210D76
	.string "Oh! You have HARBOR MAIL?\n"
	.string "Will you trade it for a COIN CASE?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase: @ 8210DB3
	.string "Oh, I'm so happy!\n"
	.string "Okay, I'll trade you a COIN CASE!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner: @ 8210DE7
	.string "That COIN CASE can be used\n"
	.string "at the GAME CORNER.$"

MauvilleCity_House2_Text_ThatsDisappointing: @ 8210E16
	.string "Oh, that's disappointing.\p"
	.string "A COIN CASE is needed for the\n"
	.string "GAME CORNER.$"

