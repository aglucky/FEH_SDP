#include "Enemy.h"

#define ACTIVE true
#define INACTIVE false

/* Author: William Comer */

/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 */
Enemy::Enemy(){
    state = ACTIVE;
}

Enemy::Enemy(const char *imageFilePath, int x, int y) : GameObject(imageFilePath, x, y){
    state = INACTIVE;
    std::cout << "This shit better be called 50 times.";
}

void Enemy::setState(bool s){
    state = s;
}

bool Enemy::getState(){
    return state;
}