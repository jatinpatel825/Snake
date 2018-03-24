#include "Snake.h"

CSnake::CSnake(std::vector<TPos> startPositions, int maxX, int maxY)
: BaseClass(startPositions)
{
    this->keyPress = GetKey();
    this->currentKey = KEY::KEY_RIGHT;
    this->oldKey = this->currentKey;
    this->direction.x = 1;
    this->direction.y = 0;
    this->maxX = maxX;
    this->maxY = maxY;
}

CSnake::~CSnake()
{

}

TPos CSnake::GetSnakeHeadPos() const
{
    return this->headPos;
}

void CSnake::Grow()
{
    int currentSize = this->GetSegments().size();
    TPos newSegment = this->GetSegments()[currentSize - 2];
    this->AddSegment(newSegment);
}

void CSnake::WrapSnake(int& posX, int& posY)
{
    posX = (posX < 2) ? (this->maxX - 1) : (posX % this->maxX);
    posY = (posY < 2) ? (this->maxY - 1) : (posY % this->maxY);
    posX = (posX == 0) ? (posX + 2) : posX;
    posY = (posY == 0) ? (posY + 2) : posY;
}

void CSnake::UpdatePosition()
{
    this->currentKey = keyPress.GetKeyPress();
    if(this->currentKey != KEY::KEY_INVALID)
    {
        this->SetDirection();
    }

    for(int i = (this->GetSegments().size() - 1); i > 0; --i)
    {
        TPos temp_pos = this->GetSegments()[i-1];
        this->SetSegments(i, temp_pos);
    }

    /* Set snake head position */
    TPos temp_pos = this->GetSegments()[0];
    temp_pos.x += this->direction.x;
    temp_pos.y += this->direction.y;
    this->WrapSnake(temp_pos.x, temp_pos.y);
    this->SetSegments(0, temp_pos);
    this->headPos = temp_pos;
}

void CSnake::SetDirection()
{
    switch(this->currentKey)
    {
        case KEY::KEY_UP:
        {
            if(this->oldKey != KEY::KEY_DOWN)
            {
                this->direction.x = 0;
                this->direction.y = -1;
                this->oldKey = this->currentKey;
            }
        }
        break;

        case KEY::KEY_DOWN:
        {
            if(this->oldKey != KEY::KEY_UP)
            {
                this->direction.x = 0;
                this->direction.y = 1;
                this->oldKey = this->currentKey;
            }
        }
        break;

        case KEY::KEY_LEFT:
        {
            if(this->oldKey != KEY::KEY_RIGHT)
            {
                this->direction.x = -1;
                this->direction.y = 0;
                this->oldKey = this->currentKey;
            }
        }
        break;

        case KEY::KEY_RIGHT:
        {
            if(this->oldKey != KEY::KEY_LEFT)
            {
                this->direction.x = 1;
                this->direction.y = 0;
                this->oldKey = this->currentKey;
            }
        }
        break;

        default:
        {
            // Do nothing
        }
        break;
    }
}

void CSnake::CheckSelfCollision()
{
    TPos head_pos = this->GetSegments()[0];
    const std::vector<TPos>& temp_segments = this->GetSegments();
    for(int i = 1; i < this->GetSegments().size() - 2; ++i)
    {
        if( (head_pos.x == temp_segments[i].x) &&
            (head_pos.y == temp_segments[i].y) )
        {
            exit(0);
        }
    }
}

void CSnake::Update()
{
    this->UpdatePosition();
    this->Draw();
    this->CheckSelfCollision();
}
