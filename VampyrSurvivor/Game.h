#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

struct Brightness
{
	Shader* shader;
	float gamma;
	float gammaMin;
	float gammaMax;

	Brightness()
	{
		shader = new Shader();
		gamma = 1.0f;
		gammaMin = 0.1f;
		gammaMax = 3.5f;
	}

	void Init()
	{
		if (!shader->loadFromFile("Assets/Shaders/shader.frag", Shader::Fragment))
		{
			cerr << "Error => The shader cannot be loaded !" << endl;
			return;
		}
		shader->setUniform("gamma", gamma);
	}

	void UpdateBrightness(const float _factor)
	{
		gamma += gammaMax * _factor / 100.0f;
		cout << gamma << endl;

		gamma = gamma < gammaMin ? gammaMin : gamma;
		gamma = gamma > gammaMax ? gammaMax : gamma;
		shader->setUniform("gamma", gamma);
	}
};

class Game
{
	static RenderWindow window;;
	static Map* map;
	Player* player;
	ShapeObject* mouse;
	bool mainMenu;
private:
	static Brightness* brightness;

public:
	static RenderWindow& GetWindow()
	{
		return window;
	}
	static Vector2f GetWindowSize()
	{
		return Vector2f(window.getSize());
	}
	static Brightness* GetBrightness()
	{
		return brightness;
	}

public:
	Game();
	~Game();

public:
	inline static Map* GetMap() { return map; }
	inline void SetMainMenu(bool _value) { mainMenu = _value; }
	void Start();
	void Init();
	void InitMouseSprite();
	void Update();
	void UpdateGame();
	void UpdateMenu();
#pragma region Draws

	void DrawWorldUIs();
	void DrawMap();
	void DrawActors();
	void DrawUIs();

#pragma endregion
	void Stop();

public:
	void Launch();
	static void Close();
};
