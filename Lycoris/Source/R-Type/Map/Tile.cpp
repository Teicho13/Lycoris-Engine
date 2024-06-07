#include "./R-Type/Map/Tile.h"

Tile::Tile(const int id)
{
	m_TileID = id;
}

int Tile::GetID() const
{
	return m_TileID;
}
