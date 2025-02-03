#include "Loading.h"
#include <DxLib.h>
#include"game.h"

Loading::Loading() :
	m_loadingHandle(LoadGraph("./img/Loading/NowLoading.png")),
	m_loadingPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 0)
{
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
	if (GetASyncLoadNum() > 0)
	{
		m_loadingPos.x--;
		if (m_loadingPos.x < 0)
		{
			m_loadingPos.x = Game::kScreenWidth / 2;
		}
	}
}

void Loading::Draw()
{
	DrawFormatString(0, 30, 0xff00ff, "ˆ—” = %d", GetASyncLoadNum());
	if (GetASyncLoadNum() > 0)
	{
		DrawRotaGraph(
			m_loadingPos.x, m_loadingPos.y,
			1.0, 0.0,
			m_loadingHandle, false);
	}
}
