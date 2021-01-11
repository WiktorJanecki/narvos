#pragma once

#include "systems/system.h"


class RenderingSystem : public System{
    public:
    void start() override;
    void update() override;
    void render() override;
    virtual ~RenderingSystem(){};
};