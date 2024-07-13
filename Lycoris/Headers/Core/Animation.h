#pragma once
#include <SDL_timer.h>

struct Animation
{
	void Initialize(int maxFrame) { if (maxFrame <= 0) { m_MaxFrames = 1; } m_MaxFrames = maxFrame; }

	void SetLooped(bool val) { m_LoopAnimation = val; }

	//Set Delay between each frame (in ms)
	void SetFrameDelay(int val) { m_FrameDelay = val; }

	void Play() { m_IsPlaying = true; }
	void Stop() { m_IsPlaying = false; }
	void ResetAnimation() { m_CurrentFrame = 0; }

	void Update()
	{
		if(m_IsPlaying)
		{
			m_CurrentFrame = static_cast<int>((SDL_GetTicks() / m_FrameDelay) % m_MaxFrames);

			if (!m_LoopAnimation && m_CurrentFrame == (m_MaxFrames - 1))
			{
				Stop();
			}
		}
	}

	bool IsLooped() const { return m_LoopAnimation; }
	int GetCurrentFrame() const { return m_CurrentFrame; }

private:
	bool m_IsPlaying = false;
	bool m_LoopAnimation = true;

	//Delay in ms
	int m_FrameDelay = 1000;

	int m_CurrentFrame = 0;
	int m_MaxFrames = 0;
};
