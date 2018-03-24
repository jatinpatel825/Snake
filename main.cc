/* Library includes */
#include <time.h>
#include <unistd.h>

/* Local includes */
#include "Snake.h"
#include "Food.h"

/* Dimensions to use when terminal is in corner */
#define GRID_X 100
#define GRID_Y 25

void DrawBorder()
{
    for(int i = 1; i < GRID_Y+1; ++i)
    {
        for(int j = 1; j < GRID_X+1; ++j)
        {
            if( (i == 1) || (j == 1) ||
                (i == (GRID_Y)) || (j == (GRID_X)) )
            {
                fprintf(stderr, "\033[%d;%dH", i, j);
                fprintf(stderr, "#");
            }
        }
    }
}

void DrawScore(const float currentScore)
{
    fprintf(stderr, "\033[26;43H");
    fprintf(stderr, "  Score: %d  ", static_cast<int>(currentScore));
    fprintf(stderr, "\033[25;100H");
}

bool CheckCollision(const TPos snakeHead, const TPos food)
{
    if( (snakeHead.x == food.x) &&
        (snakeHead.y == food.y) )
    {
        return true;
    }

    return false;
}

int SelectDifficulty()
{
    int difficulty = 0;
    while( (difficulty > 15) || (difficulty < 1) )
    {
        fprintf(stderr, "Enter Difficulty: [1-15]:\n");
        std::cin >> difficulty;
        system("clear");
    }
    return difficulty;
}

int main()
{
    srand(time(0));

    float score = 0;
    int difficulty = 1;
    TPos foodPosition;
    foodPosition.x = (rand() % (GRID_X - 3) ) + 2;
    foodPosition.y = (rand() % (GRID_Y - 3) ) + 2;

    std::vector<TPos> startPositions;

    for(int i = 8; i > 1; --i)
    {
        startPositions.push_back(TPos(i, 2));
    }

    CSnake* snake = new CSnake(startPositions, GRID_X, GRID_Y);
    CFood* food = new CFood(foodPosition);

    difficulty = SelectDifficulty();
    GetKey keyPress = GetKey();

    bool isCollision = false;
    while(true)
    {
        isCollision = CheckCollision(snake->GetSnakeHeadPos(), food->GetFoodPos());
        if(isCollision == true)
        {
            food->SetNewPos(GRID_X, GRID_Y);
            snake->Grow();
            score += (static_cast<float>(difficulty) / 5.0f);
        }

        DrawBorder();

        snake->Update();
        food->Update();

        DrawScore(score);

        usleep( (200000 - (difficulty * 10000)) );
    }

    return(0);
}
