#include "Player.h"
#include "ActorManager.h"

Player::Player()
{
	Register();
}

Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data)
{
	Register();
}

void Player::Register()
{
	ActorManager::GetInstance().RegisterPlayer(this);
}
