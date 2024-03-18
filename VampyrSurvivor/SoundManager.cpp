#include "SoundManager.h"

SoundManager::SoundManager()
{
	isMuted = false;
	volume = 40.0f;
	tempVolume = 1;
}


void SoundManager::Play(const string& _path, const bool _isloop, const DirectionalSettings& _settings)
{
	if (SoundData* _soundData = Get(_path))
	{
		_soundData->setPosition(Vector3f(_settings.position.x, _settings.position.y, 0.0f));
		_soundData->setRelativeToListener(_settings.attenuationSpeed == 0.0f);
		_soundData->setAttenuation(_settings.attenuationSpeed);
		_soundData->setMinDistance(_settings.minDistance);
		_soundData->setVolume(volume);
		_soundData->setLoop(_isloop);
		_soundData->play();
	}
}

void SoundManager::AdjustAllVolume(const float _value)
{
	const float _newVolume = volume + _value;
	if (_newVolume > 100.0f || _newVolume < 0.0f) return;

	volume = _newVolume;
	for (SoundData* _sound : GetAllValues())
	{
		_sound->AdjustVolume(volume);
	}
}

void SoundManager::Stop(const string& _path)
{
	if (SoundData* _soundData = Get(_path))
	{
		_soundData->stop();
	}
}
