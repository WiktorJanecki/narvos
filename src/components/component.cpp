#include "components/component.h"

#include <string>
#include <typeinfo>


std::string Component::getType(){
	return typeid(*this).name();
}