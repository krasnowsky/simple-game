#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Entity.h"

class Player : public Entity
{
    private:
        int speed = 3;
        int xTravelled, yTravelled;

    public:
        Player(const char* fileName, int x, int y);
        ~Player() override;
        void Update(Entity &slime, Entity &snorlax, Map &map, Entity &dragon);
        void Render() override;
        bool checkAlive() override;
};

#endif // PLAYER_H
