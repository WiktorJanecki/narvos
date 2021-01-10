#include "log.h"

std::ostream& log{
    return std::cout;
}

std::ostream& err{
    return std::cout<<"\033[31mERROR: \033[0m";
}

std::ostream& warn{
    return std::cout<<"\033[33mWarning: \033[0m";
}