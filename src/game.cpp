#include "game.h"

#include <iostream>

#include "log.h"
#include "definitions.h"


void Game::start(){

    log << "\n Narvos has started \n";
    if(DEBUG){warn << "Game started in debug mode\n";}
    log << " Version: " << VERSION << "\n\n";

    while(false){
        update();
        render();
    }
}

void Game::update(){}

void Game::render(){}