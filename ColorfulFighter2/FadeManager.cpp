#include "FadeManager.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	constexpr int fadeSpeed = 5;
}

FadeManager::FadeManager():
	m_fadeFrameCount(255),
	m_isFinishFadeIn(false),
	m_isFinishFadeOut(false)
{
}

FadeManager::~FadeManager()
{
}

void FadeManager::BlackFadeDraw(bool isFadeIn)
{
	//�t�F�[�h�C��
	if (isFadeIn)
	{
		m_fadeFrameCount += fadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	//�t�F�[�h�A�E�g
	else
	{
		m_fadeFrameCount -= fadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�ő�l�ɍs�����Ƃ�
	if (m_fadeFrameCount >= 255)
	{
		m_isFinishFadeIn = true;
		m_fadeFrameCount = 255;
	}
	else
	{
		m_isFinishFadeIn = false;
	}
	//�ŏ��l�ɍs�����Ƃ�
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

void FadeManager::WhiteFadeDraw(bool isFadeIn)
{
	//�t�F�[�h�C��
	if (isFadeIn)
	{
		m_fadeFrameCount += fadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xffffff, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	//�t�F�[�h�A�E�g
	else
	{
		m_fadeFrameCount -= fadeSpeed;
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeFrameCount);
		DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xffffff, true);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�ő�l�ɍs�����Ƃ�
	if (m_fadeFrameCount >= 255)
	{
		m_isFinishFadeIn = true;
		m_fadeFrameCount = 255;
	}
	else
	{
		m_isFinishFadeIn = false;
	}
	//�ŏ��l�ɍs�����Ƃ�
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

