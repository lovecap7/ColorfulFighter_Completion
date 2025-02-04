#include "FadeManager.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	constexpr int kFadeSpeed = 5;
	//明るさ
	constexpr int kMaxAlpha = 255;
}

FadeManager::FadeManager():
	m_fadeFrameCount(kMaxAlpha),
	m_isFinishFadeIn(false),
	m_isFinishFadeOut(false)
{
}

FadeManager::~FadeManager()
{
}

void FadeManager::DrawBlackFade(bool isFadeIn)
{
	//フェードイン
	if (isFadeIn)
	{
		m_fadeFrameCount += kFadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x111111, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	//フェードアウト
	else
	{
		m_fadeFrameCount -= kFadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x111111, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//最大値に行ったとき
	if (m_fadeFrameCount >= kMaxAlpha)
	{
		m_isFinishFadeIn = true;
		m_fadeFrameCount = kMaxAlpha;
	}
	else
	{
		m_isFinishFadeIn = false;
	}
	//最小値に行ったとき
	if (m_fadeFrameCount <= 0)
	{
		m_isFinishFadeOut = true;
		m_fadeFrameCount = 0;
	}
	else
	{
		m_isFinishFadeOut = false;
	}
}

void FadeManager::DrawWhiteFade(bool isFadeIn)
{
	//フェードイン
	if (isFadeIn)
	{
		m_fadeFrameCount += kFadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xeeeeee, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	//フェードアウト
	else
	{
		m_fadeFrameCount -= kFadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xeeeeee, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//最大値に行ったとき
	if (m_fadeFrameCount >= kMaxAlpha)
	{
		m_isFinishFadeIn = true;
		m_fadeFrameCount = kMaxAlpha;
	}
	else
	{
		m_isFinishFadeIn = false;
	}
	//最小値に行ったとき
	if (m_fadeFrameCount <= 0)
	{
		m_isFinishFadeOut = true;
		m_fadeFrameCount = 0;
	}
	else
	{
		m_isFinishFadeOut = false;
	}
}

