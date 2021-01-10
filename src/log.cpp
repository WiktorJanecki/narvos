#include "log.h"

std::ostream& log{
    return std::cout;
}

std::ostream& err{
    return std::cout<<"\033[31m ERR: \033[0m";
}

std::ostream& warn{
    return std::cout<<"\033[33m Warning: \033[0m";
}