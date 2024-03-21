#include "Player.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "Mob.h"

Player::Player()
{
	stat = new PlayerStat();
	dammage = 20;
	Register();
}

Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data)
{
	viewZoom = 3;
	stat = new PlayerStat();
	viewOffset = Vector2f(0, 0);
	dammage = 20;
	InitView();
	InitInput();
	direction = { 0,0 };
	Register();
}

Player::~Player()
{
	delete stat;
}

void Player::Update(const float _deltaTime)
{
	if (direction != Vector2f(0, 0 ))
	{
		view->move(direction * _deltaTime);
		viewOffset += direction * _deltaTime;
		cout << "(" << viewOffset.x << "," << viewOffset.y << ")" << endl;
	}
	stat->money++;
	string _money = to_string(stat->money);
	stat->SetString(_money);
}

void Player::InitInput()
{
	new ActionMap("CameraMovement",
	{
		ActionData("Haut", [this]() { direction.y = -1; }, {Event::KeyPressed, Keyboard::Up}),
		ActionData("HautR", [this]() { direction.y = 0;}, { Event::KeyReleased, Keyboard::Up }),
		ActionData("Bas", [this]() { direction.y = 1; }, { Event::KeyPressed, Keyboard::Down }),
		ActionData("BasR", [this]() { direction.y = 0; ;}, { Event::KeyReleased, Keyboard::Down }),
		ActionData("Gauche", [this]() { direction.x = -1;}, { Event::KeyPressed, Keyboard::Left }),
		ActionData("GaucheR", [this]() { direction.x = 0;}, { Event::KeyReleased, Keyboard::Left }),
		ActionData("Droite", [this]() { direction.x = 1; }, { Event::KeyPressed, Keyboard::Right }),
		ActionData("DroiteR", [this]() { direction.x = 0;; }, { Event::KeyReleased, Keyboard::Right }),
	});	

	new ActionMap("PlayerAction",
		{
			ActionData("MakeDamage",[this]() { OnClick(); }, {Event::MouseButtonPressed, Mouse::Left})
		});
}

void Player::InitView()
{
	view = new View({ 0,0 }, { SCREEN_WIDTH/viewZoom , SCREEN_HEIGHT/viewZoom});
}

void Player::OnClick()
{
	//for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	//{
	//	Mob* _mob = (Mob*)_actor;
	//	if (_mob)
	//	{
	//		Shape* _shape = _mob->GetDrawable();
	//		FloatRect _rect = _shape->getGlobalBounds();

	//		if (_rect.contains(InputManager::GetInstance().GetWorldPosition()))
	//		{
	//			cout <<  _mob->GetID() << endl;
	//			cout << "TakesDamages" << endl;
	//			//_mob->TakeDamages(dammage);
	//		}
	//	}
	//}
	Vector2f _halfWorldPosition =  Vector2f(SCREEN_WIDTH /2,SCREEN_HEIGHT/2) ;
	Vector2f _mousePosition = InputManager::GetInstance().GetMousePosition() - _halfWorldPosition;
	Vector2f _mousePositionOffset = Vector2f((_mousePosition.x + viewOffset.x * viewZoom) / viewZoom, (_mousePosition.y + viewOffset.y * viewZoom)/viewZoom);
	cout << "[Player::OnClick] => _mousePositionOffset = (" << _mousePositionOffset.x << "," << _mousePositionOffset.y << ")" << endl;
}

void Player::Register()
{
	ActorManager::GetInstance().RegisterPlayer(this);
}
