#include "Loading.h"
#include <DxLib.h>
#include"game.h"

Loading::Loading() :
	m_loadingHandle(LoadGraph("./img/Loading/NowLoading.png")),
	m_animCountFrame(0),
	m_actor1{-1,8,2},
	m_actor2{-1,8,2},
	m_actor3{-1,8,2},
	m_actor4{-1,8,2},
	m_actor5{-1,8,2}
{
	m_actor1.handle = LoadGraph("./img/Chara/White/playerbase/walk_front_001.png");
	m_actor2.handle = LoadGraph("./img/Chara/Red/playerbase/walk_front_001.png");
	m_actor3.handle = LoadGraph("./img/Chara/Blue/playerbase/walk_front_001.png");
	m_actor4.handle = LoadGraph("./img/Chara/Yellow/playerbase/walk_front_001.png");
	m_actor5.handle = LoadGraph("./img/Chara/Green/playerbase/walk_front_001.png");
	//”ñ“¯Šú‚Å“Ç‚Ýž‚Ý
	SetUseASyncLoadFlag(true);
}

Loading::~Loading()
{
	//”ñ“¯Šú‚Å“Ç‚Ýž‚Ý
	SetUseASyncLoadFlag(false);
}

void Loading::Update()
{
	//if (GetASyncLoadNum() > 0)
	if (true)
	{
		++m_animCountFrame;
	}
}

void Loading::Draw()
{
	DrawFormatString(0, 30, 0xff00ff, "ˆ—” = %d", GetASyncLoadNum());
	//if (GetASyncLoadNum() > 0)
	if (true)
	{
		DrawGraph(0, 0, m_loadingHandle, false);
		DrawGraph(100, 0, m_actor1.handle, true);
		DrawGraph(120, 0, m_actor2.handle, true);
		DrawGraph(140, 0, m_actor3.handle, true);
		DrawGraph(160, 0, m_actor4.handle, true);
		DrawGraph(180, 0, m_actor5.handle, true);
	}
}
