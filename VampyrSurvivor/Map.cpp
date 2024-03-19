#include "Map.h"
#include "Macro.h"

Map::Map()
{
	GenerateMap();
}

void Map::GenerateMap()
{

	ifstream _in = ifstream("Assets/map.txt");
	if (!_in)
	{
		cerr << "Erreur de chargement de la map ! " << endl;
		return;
	}

	map<char, function<void(const Vector2f& _position)>> _map =
	{
		{'#',[this](const Vector2f& _position) {tiles.push_back(new Tile(TT_GRASS,_position)); }},
		{'P',[this](const Vector2f& _position) {tiles.push_back(new Tile(TT_PATH,_position)); }}
	};

	string _line;
	Vector2i _startPos = Vector2i(0,0);

	while (getline(_in,_line))
	{
		for (const char _char : _line)
		{ 
			function<void(const Vector2f& _position)> _callback = _map[_char];
			if (_callback)
			{
				const float _positionX = (float)_startPos.x * (float)TILE_SIZE.x;
				const float _positionY = (float)_startPos.y * (float)TILE_SIZE.y;
				_callback(Vector2f(_positionX, _positionY));
			}
			_startPos.x++;
		}
		_startPos.x = 0;
		_startPos.y++;
	}
}
