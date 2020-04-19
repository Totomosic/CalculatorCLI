#pragma once
#include <iostream>
#define CLC_ASSERT(expr, msg) { if (!(expr)) { std::cout << "ASSERTION FAILED: " << (msg) << std::endl; } }