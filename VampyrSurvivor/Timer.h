#pragma once
#include "IManagable.h"
#include <SFML/Graphics.hpp>
#include <functional>

using namespace std;
using namespace sf;

class Timer : public IManagable<int>
{
	function<void()> callback;
	float currentDuration;
	float duration;
	bool isRunning;
	bool isLoop;

	bool isPause;
public:
	void AddDuration(const float _duration)
	{
		duration += _duration;
	}
	float GetCurrentDuration() const
	{
		return currentDuration;
	}
	bool IsRunning() const
	{
		return isRunning;
	}

public:

	Timer(const function<void()>& _callback, const Time& _time,
		const bool _startRunning = true, const bool _isLoop = false);

private:
	virtual void Register() override;

public:
	void Update(const float _deltaTime);
	void Start();
	void Resume();
	void Pause();
	void Reset();
	void Stop();
};

