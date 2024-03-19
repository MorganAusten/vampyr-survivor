#pragma once

class EntityManager;
class MapManager;
class TextureManager;

template <typename ID>
class IManagable
{

protected:
	bool toRemove;
	ID id;

public:
	IManagable()
	{

	}

	IManagable(const ID& _id)
	{
		id = _id;
		toRemove = false;
	}
public:
	void SetID(const ID& _id)
	{
		id = _id;
	}
	void SetToRemove(const bool _status)
	{
		toRemove = _status;
	}
	ID GetID() const
	{
		return id;
	}
	bool IsToRemove() const
	{
		return toRemove;
	}


protected:
	virtual void Register() {};
};

