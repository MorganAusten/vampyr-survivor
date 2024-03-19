#include "Player.h"
#include "ActorManager.h"

Player::Player()
{
	Register();
}

void Player::Register()
{
	ActorManager::GetInstance().RegisterPlayer(this);
}
