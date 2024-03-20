#include "Player.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "Mob.h"

Player::Player()
{
	stat = new PlayerStat();
	Register();
}

Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data)
{
	stat = new PlayerStat();
	InitView();
	InitInput();
	Register();
	direction = { 0.f,0.f };
}

Player::~Player()
{
	delete stat;
}

void Player::Update(const float _deltaTime)
{
	if (direction != Vector2f(0.f, 0.f ))
	{
		view->move(direction * _deltaTime);
	}
	stat->money++;
	string _money = to_string(stat->money);
	stat->SetString(_money);
}

void Player::InitInput()
{
	new ActionMap("CameraMovement",
	{
		ActionData("Haut", [this]() { direction.y = -1.f; }, { Event::KeyPressed, Keyboard::Up }),
		ActionData("HautR", [this]() { direction.y = 0.f; }, { Event::KeyReleased, Keyboard::Up }),
		ActionData("Bas", [this]() { direction.y = 1.f; }, { Event::KeyPressed, Keyboard::Down }),
		ActionData("BasR", [this]() { direction.y = 0.f; }, { Event::KeyReleased, Keyboard::Down }),
		ActionData("Gauche", [this]() { direction.x = -1.f; }, { Event::KeyPressed, Keyboard::Left }),
		ActionData("GaucheR", [this]() { direction.x = 0.f; }, { Event::KeyReleased, Keyboard::Left }),
		ActionData("Droite", [this]() { direction.x = 1.f; }, { Event::KeyPressed, Keyboard::Right }),
		ActionData("DroiteR", [this]() { direction.x = 0.f; }, { Event::KeyReleased, Keyboard::Right }),
	});	

	new ActionMap("PlayerAction",
		{
			ActionData("MakeDamage",[this]() { OnClick(); }, {Event::MouseButtonPressed, Mouse::Left})
		});
}

void Player::InitView()
{
	view = new View({ 0,0 }, { SCREEN_WIDTH/2 , SCREEN_HEIGHT/2});
}

void Player::OnClick()
{
	cout << "Click" << endl;
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		if (Mob* _mob = (Mob*)_actor)
		{
			Shape* _shape = _mob->GetDrawable();
			FloatRect _rect = _shape->getGlobalBounds();

			if (_rect.contains(InputManager::GetInstance().GetWorldPosition()))
			{
				//_mob->TakeDamage(dammage);
			}
		}
	}
}

void Player::Register()
{
	ActorManager::GetInstance().RegisterPlayer(this);
}
