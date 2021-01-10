#pragma once

class System{
    public:
        virtual void start() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual ~System(){}
}