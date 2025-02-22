#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Timer.h"

#include <SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//struct Timer
//{
//
//	Timer(c)
//	Time _current = seconds(0);
//	Time _max = milliseconds(static_cast<Int32>(_duration));
//};
class TimerManager : public Singleton<TimerManager>, public IManager<int, Timer>
{
	// Clock pour avoir acc�s � toutes les donn�es de temps
	Clock clock;


	float current;

	float max;
	// Temps en seconde depuis le d�but du programme
	float time;

	// Mettre � jour les timers
	float lastTime;

	// Mettre � jour les compteurs de FPS
	float lastFrameTime;

	// Temps en seconde depuis la derni�re image rendue
	float elapsedTime;

	// Vitesse � laquelle le temps s'�coule
	float timeScale;

	// Temps en seconde depuis la derni�re image rendue avec le time scale
	float deltaTime;

	// Nombre d'images qui ont �t� rendu depuis le d�but
	unsigned int framesCount;

	// Maximum d'image � rendre par seconde
	unsigned int maxFrameRate;

	// Nombre d'image rendu par seconde
	float fps;

	// M�thode de rappel � �x�cuter si le rendu est � jour
	function<void()> renderCallback;

	bool isPause;

private:
	void ComputeFPS()
	{
		fps = 1000.0f / (time - lastFrameTime);
	}
	bool Render()
	{
		if (lastFrameTime == 0 || time - lastFrameTime >= 1000.0f / maxFrameRate)
		{
			ComputeFPS();
			lastFrameTime = time;
			return true;
		}

		return false;
	}
public:
	void SetTimeScale(const float _timeScale)
	{
		timeScale = _timeScale;
	}
	void SetMaxFrameRate(const unsigned int _maxFrameRate)
	{
		maxFrameRate = _maxFrameRate;
	}
	void SetRenderCallback(const function<void()>& _callback)
	{
		renderCallback = _callback;
	}
	float GetDeltaTime() const
	{
		return deltaTime;
	}
	float GetFPS() const
	{
		return fps;
	}

	void SetPause(const bool _isPause)
	{
		isPause = _isPause;
	}

public:
	TimerManager();

private:
	void UpdateTimers();

public:
	void Update();

	void Pause(const float _duration);
};
