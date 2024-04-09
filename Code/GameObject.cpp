#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject:: IsOverlapping(GameObject* newobj, Grid* pGrid)const
{
	return 1;
}


GameObject::~GameObject()
{
}