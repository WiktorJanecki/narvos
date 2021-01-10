#pragma once

#include <string>


class Component{
    public:
        std::string getType();
        template<typename T>
        static std::string getType(){
            T helper;
            return typeid(helper).name();
        }
        virtual ~Component(){}
};