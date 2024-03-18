#include "SoundData.h"
#include "SoundManager.h"
#include <iostream>

SoundData::SoundData(const string& _path, const float _volume, const bool _isLoop, const float _volumeMax, const AudioType& _type) : IManagable(_path)
{
	Register();

	setVolume(_volume);
	volumeMax = _volumeMax;

	if (!buffer.loadFromFile("Assets/Audio/Sounds/" + _path + "." + GetExtensionNameByType(_type)))
	{
		cerr << "Le son " << _path << " n'a pas �t� correctement charg� !" << endl;
		return;
	}
	//setBuffer(buffer); // Warning 
	// SoundManager::GetInstance().Play(_path , _isLoop);	// Warning
}

void SoundData::Register()
{
	SoundManager::GetInstance().Add(id, this);
}

void SoundData::AdjustVolume(const float _percent)
{
	float _newVolume = _percent * volumeMax / 100.0f;
	_newVolume = _newVolume < 0.0f ? 0.0f : _newVolume;
	_newVolume = _newVolume > volumeMax ? volumeMax : _newVolume;
	setVolume(_newVolume);
}

void SoundData::GetSound(const string& _sound)
{
	SoundManager::GetInstance().Get(_sound);
}
