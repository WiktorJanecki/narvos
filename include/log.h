#pragma once

#include <iostream>

std::ostream& log();

std::ostream& err();

std::ostream& warn();

#define log log()
#define err err()
#define warn warn()