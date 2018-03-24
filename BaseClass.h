#ifndef __BASECLASS_H__
#define __BASECLASS_H__

/* Library includes */
#include <iostream>
#include <vector>

struct TPos
{
    TPos(){}

    TPos(int posX, int posY)
    {
        x = posX;
        y = posY;
    }
    int x = 0;
    int y = 0;
};

class BaseClass
{
    /* Member functions */
public:
    BaseClass(TPos startPosition);
    BaseClass(std::vector<TPos> startPositions);
    ~BaseClass();

    std::vector<TPos> GetSegments() const;
    void SetSegments(int index, TPos& pos);
    void AddSegment(TPos newSegment);
    void Draw();

protected:
    void SetCursorPos(const TPos& pos);
private:

    /* Member variables */
public:
protected:
    std::vector<TPos> segments;
    TPos foodPosition;

private:
};

#endif // __BASECLASS_H__
