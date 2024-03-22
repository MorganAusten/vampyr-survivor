#include "Player.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "ProgressBar.h"
#include "Mob.h"

Player::Player()
{

}

Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data)
{
	viewZoom = ZOOM;
	stat =new PlayerStat(20,0,0,CURRENT_MONEY_POS);
	viewOffset = Vector2f(0, 0);
	dammage = 20;
	InitView();
	InitInput();
	shop = new Shop("PlayerShop");
	direction = { 0,0 };
	Register();
}

Player::~Player()
{

}

void Player::Update(const float _deltaTime)
{
	if (direction != Vector2f(0, 0))
	{
		view->move(direction * _deltaTime);
		viewOffset += direction * _deltaTime;
		cout << "(" << viewOffset.x << "," << viewOffset.y << ")" << endl;
	}
}

void Player::InitInput()
{
	new ActionMap("CameraMovement",
		{
			ActionData("Haut", [this]() { direction.y = -1; }, {Event::KeyPressed, Keyboard::Z}),
			ActionData("HautR", [this]() { direction.y = 0; }, { Event::KeyReleased, Keyboard::Z }),
			ActionData("Bas", [this]() { direction.y = 1; }, { Event::KeyPressed, Keyboard::S }),
			ActionData("BasR", [this]() { direction.y = 0; ; }, { Event::KeyReleased, Keyboard::S }),
			ActionData("Gauche", [this]() { direction.x = -1; }, { Event::KeyPressed, Keyboard::Q }),
			ActionData("GaucheR", [this]() { direction.x = 0; }, { Event::KeyReleased, Keyboard::Q }),
			ActionData("Droite", [this]() { direction.x = 1; }, { Event::KeyPressed, Keyboard::D }),
			ActionData("DroiteR", [this]() { direction.x = 0;; }, { Event::KeyReleased, Keyboard::D }),
		});

	new ActionMap("PlayerAction",
		{
			ActionData("MakeDamage",[this]() { if (!shop->isOpen())OnClick(); }, {Event::MouseButtonPressed, Mouse::Left}),
			ActionData("ToggleShop",[this]() {
				shop->ToggleShop();
				}, {Event::KeyPressed, Keyboard::B}),

		});
}

void Player::InitView()
{
	view = new View({ 0,0 }, { SCREEN_WIDTH / viewZoom , SCREEN_HEIGHT / viewZoom });
}

void Player::OnClick()
{
	Vector2f _halfWorldPosition = Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Vector2f _mousePosition = InputManager::GetInstance().GetMousePosition() - _halfWorldPosition;
	Vector2f _mousePositionOffset = Vector2f((_mousePosition.x + viewOffset.x * viewZoom) / viewZoom, (_mousePosition.y + viewOffset.y * viewZoom) / viewZoom);
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		Mob* _mob = (Mob*)_actor;
		if (_mob)
		{
			Shape* _shape = _mob->GetDrawable();
			FloatRect _rect = _shape->getGlobalBounds();
			if (_rect.contains(_mousePositionOffset) && _mob->GetActorType() == ActorType::MOB)
			{
				cout << _mob->GetID() << endl;
				cout << "TakesDamages" << endl;
				_mob->TakeDamages(-dammage);
				cout << "HP:" << _mob->GetLifeBar()->GetCurrentValue() << endl;
			}
		}
	}
	stat->money++;
	stat->score++;
	string _money = to_string(stat->money);
	stat->SetString(_money);
}

void Player::Register()
{
	ActorManager::GetInstance().RegisterPlayer(this);
}
