#include "Map.h"
#include "Macro.h"
#include "Barrier.h"
#include "PathfindingComponent.h"
#include "Player.h"
#include "Spawner.h"
#include "SpriteUtils.h"
#include "ActorSpawner.h"
#include "Mob.h"

Map::Map()
{
	InitMap();
}

void Map::InitMap()
{
	ifstream _in = ifstream("Assets/map.txt");
	if (!_in)
	{
		cerr << "Erreur de chargement de la map ! " << endl;
		return;
	}

	map<char, function<void(const Vector2f& _position)>> _map =
	{
		//Chaque actor est draw dans le update du actorManager, donc quand on créer un actor et qu'il se register, ça le draw automatiquement 
		{'#',[this](const Vector2f& _position) {grid.push_back(new Tile(TT_GRASS,_position,nullptr,false,false)); }},
		{'P',[this](const Vector2f& _position) {grid.push_back(new Tile(TT_PATH,_position)); }},
		{'B',[this](const Vector2f& _position) {grid.push_back(new Tile(TT_PATH,_position,new Barrier(_position)));}},
		{'S',[this](const Vector2f& _position) {grid.push_back(new Tile(TT_SPAWNER,_position,nullptr,true)); }},
		{'E',[this](const Vector2f& _position) {grid.push_back(new Tile(TT_PORTAL,_position)); }},
	};

	string _line;
	Vector2i _startPos = Vector2i(0, 0);
	GenerateMap(_in, _line, _map, _startPos);
}

void Map::GenerateMap(std::ifstream& _in, std::string& _line, std::map<char, std::function<void(const sf::Vector2f& _position)>>& _map, sf::Vector2i& _startPos)
{
	int _index = 0;
	//X
	while (getline(_in, _line))
	{
		//Y
		for (const char _char : _line)
		{
			function<void(const Vector2f& _position)> _callback = _map[_char];
			if (_callback)
			{
				const float _positionX = (float)_startPos.x * (float)TILE_SIZE.x;
				const float _positionY = (float)_startPos.y * (float)TILE_SIZE.y;
				_callback(Vector2f(_positionX, _positionY));
				if (!sizeSet) size++;
			}
			_startPos.x++;
			_index++;
		}
		if (!sizeSet)
			sizeSet = true;
		_startPos.x = 0;
		_index;
		_startPos.y++;
	}
	SetSuccessor();
}

void Map::SetSuccessor()
{
	for (int i = 0; i < size * size; i++)
	{
		bool _canRight = i % size != size - 1,
			_canTop = i > size-1 ,
			_canDown = i < (size * size) - size,
			_canLeft = i % size != 0;
		if (_canRight)
			grid[i]->AddSuccessor(i + 1);
		if (_canLeft)
			grid[i]->AddSuccessor(i - 1);
		if (_canTop)
		{
			grid[i]->AddSuccessor(i - size);
			//if (_canRight)
			//	grid[i]->AddSuccessor((i + 1 - size));
			//if (_canLeft)
			//	grid[i]->AddSuccessor((i - 1 - size));
		}
		if (_canDown)
		{
			grid[i]->AddSuccessor(i + size);
			//if (_canRight)
			//	grid[i]->AddSuccessor((i + 1 + size));
			//if (_canLeft)
			//	grid[i]->AddSuccessor((i - 1 + size));
		}
		/*cout << "modulo : " << i % size << endl <<  grid[i]->ToString(grid[i]) << " " << i + 1 << " successors : " << grid[i]->pathfindingParam.successors.size() <<
			" Pos : (" << grid[i]->GetShapePosition().x  <<","<< grid[i]->GetShapePosition().y << ")" << " Navigable : " << grid[i]->pathfindingParam.navigable << endl;*/
	}
}

void Map::ResetGridCost()
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i]->ResetTileCost();
	}
}