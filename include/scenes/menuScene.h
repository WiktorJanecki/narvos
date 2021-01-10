#pragma once

#include "scenes/scene.h"

class MenuScene : public Scene{
    public:
        void start() override;
        void update() override;
        void render() override;
        void clean() override;
};