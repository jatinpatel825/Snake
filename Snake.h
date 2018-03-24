#ifndef __SNAKE_H__
#define __SNAKE_H__

/* Library includes */
#include <future>
#include <atomic>
#include <chrono>

/* Local includes */
#include "BaseClass.h"
#include "GetKey.h"

class CSnake : BaseClass
{
    /* Member functions */
public:
    CSnake(std::vector<TPos> startPositions, int maxX, int maxY);
    ~CSnake();

    void Update();
    TPos GetSnakeHeadPos() const;
    void Grow();
protected:
private:
    void UpdatePosition();
    void SetDirection();
    void WrapSnake(int& posX, int& posY);
    void CheckSelfCollision();

    /* Member variables */
public:
protected:
private:
    GetKey keyPress;
    KEY currentKey;
    KEY oldKey;
    TPos direction;
    TPos headPos;
    int maxX;
    int maxY;
};

#endif // __SNAKE_H__
