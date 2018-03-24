#include "Food.h"

CFood::CFood(TPos startPosition)
: BaseClass(startPosition)
{

}

CFood::~CFood()
{

}

void CFood::Update()
{
    this->Draw();
}

void CFood::SetNewPos(int maxX, int maxY)
{
    this->foodPosition.x = (rand() % (maxX - 3) ) + 2;
    this->foodPosition.y = (rand() % (maxY - 3) ) + 2;
}

TPos CFood::GetFoodPos() const
{
    return this->foodPosition;
}
