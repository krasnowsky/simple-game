#include <Slime.h>

Slime::Slime(const char *fileName, int x, int y) : Entities(fileName, x, y) {
    objTexture = TextureManager::LoadTexture(fileName);
    xPos = x;
    yPos = y;
}

void Slime::Update(Entities &enemy) {
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    if(!isAttacked)
        {
        if(isRight)
        {
            xPos += speed;
            if(xPos > rightBorder)
            {
                isRight = false;
            }
        }
        else {
            xPos -= speed;
            if (xPos < leftBorder) {
                isRight = true;
            }
        }
    }


    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

    int slimePos = this -> getPositionX();
    int playerPos = enemy.getPositionX();

    if(slimePos - playerPos < 17)
    {
        isAttacked = true;
        if (enemy.checkAlive())
        {
            float dmgAD = this -> getAD();
            float enemyHP = enemy.getHP();
            float dmgADDealt;

            if(dmgAD == 0 || dmgAD <= enemy.getDEF()) dmgADDealt = 0;
            else  dmgADDealt = dmgAD - enemy.getDEF();

            enemy.setHP(enemyHP-dmgADDealt);
            std::cout << this -> name << " dealt: " << std::endl;
            std::cout << "AD Damage: " << dmgADDealt << std::endl;
            std::cout << "HP: " << enemy.getHP()<< std::endl;
            std::cout << "to: " << enemy.getName() << std::endl << std::endl;
        }
    }
}

void Slime::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}




