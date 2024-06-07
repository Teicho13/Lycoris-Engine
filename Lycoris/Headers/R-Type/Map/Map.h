#pragma once
#include <memory>

class Tile;
class Sprite;

class Map
{
public:

	Map(const char* textureMapPath, const char* tileSheetPath, const int columns, const int rows);
	~Map();

	void CreateTiles(const char* textureMapPath);
	void DrawMap() const;
	void RemoveTiles() const;


private:

	void RenderSprite(int frameID, float posX, float posY) const;

	static constexpr int m_MapRows = 12;
	static constexpr int m_MapColumns = 268;

	std::unique_ptr<Sprite> m_MapSheet = nullptr;
	Tile* m_MapTiles[m_MapRows][m_MapColumns];

	bool m_CanRender = false;
};
