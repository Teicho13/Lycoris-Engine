#pragma once
class Tile
{
public:
	Tile(const int id);

	int GetID() const;

private:
	int m_TileID = 0;
};
