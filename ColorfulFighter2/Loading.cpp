#include "Loading.h"
#include <DxLib.h>
#include"game.h"

Loading::Loading() :
	m_loadingHandle(LoadGraph("./img/Loading/NowLoading.png")),
	m_loadingPos(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 0)
{
	//非同期で読み込み
	SetUseASyncLoadFlag(true);
}

Loading::~Loading()
{
	//非同期で読み込み
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
	DrawFormatString(0, 30, 0xff00ff, "処理数 = %d", GetASyncLoadNum());
	if (GetASyncLoadNum() > 0)
	{
		DrawRotaGraph(
			m_loadingPos.x, m_loadingPos.y,
			1.0, 0.0,
			m_loadingHandle, false);
	}
}
