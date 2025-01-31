#pragma once
class FadeManager
{
private:
	int m_fadeFrameCount;
	bool m_isFinishFadeIn;
	bool m_isFinishFadeOut;
public:
	FadeManager();
	~FadeManager();

	void BlackFadeDraw(bool isFadeIn);
	void WhiteFadeDraw(bool isFadeIn);
	bool IsFinishFadeIn() { return m_isFinishFadeIn; }
	bool IsFinishFadeOut() { return m_isFinishFadeOut; }
	int GetFadeFrameCount() { return m_fadeFrameCount; }
};

