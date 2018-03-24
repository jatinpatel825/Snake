#ifndef __FOOD_H__
#define __FOOD_H__

#include "BaseClass.h"

class CFood : BaseClass
{
    /* Member functions */
public:
    CFood(TPos startPosition);
    ~CFood();

    void Update();
    void SetNewPos(int maxX, int maxY);

    TPos GetFoodPos() const;
protected:
private:

    /* Member variables*/
public:
protected:
private:
};

#endif // __FOOD_H__
