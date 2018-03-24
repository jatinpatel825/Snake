#include "BaseClass.h"

BaseClass::BaseClass(TPos startPosition)
{
    this->foodPosition = std::move(startPosition);
}

BaseClass::BaseClass(std::vector<TPos> startPositions)
{
    this->segments = std::move(startPositions);
}

BaseClass::~BaseClass()
{

}

std::vector<TPos> BaseClass::GetSegments() const
{
    return this->segments;
}

void BaseClass::AddSegment(TPos newSegment)
{
    this->segments.push_back( std::move(newSegment) );
}

void BaseClass::SetSegments(int index, TPos& pos)
{
    this->segments[index].x = pos.x;
    this->segments[index].y = pos.y;
}

void BaseClass::SetCursorPos(const TPos& pos)
{
    /* Requires <y,x> rather than <x, y> */
    fprintf(stderr, "\033[%d;%dH", pos.y, pos.x);
}

void BaseClass::Draw()
{
    if(this->segments.size() > 0)
    {
        for(int i = 0; i < this->segments.size(); ++i)
        {
            this->SetCursorPos(segments[i]);
            /* Clearlast 2 positions behind snake (doing last 1 doesn't work) */
            if( (i == (segments.size() - 2)) ||
                (i == (segments.size() - 1)) )
            {
                fprintf(stderr, " ");
            }
            else
            {
                fprintf(stderr, "O");
            }
        }
    }
    else
    {
        this->SetCursorPos(foodPosition);
        fprintf(stderr, "X");
    }
}
