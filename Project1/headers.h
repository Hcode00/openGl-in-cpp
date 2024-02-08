#pragma once
#include <iostream>
#pragma once
#include <GLEW/glew.h>
#pragma once
#include <GLFW/glfw3.h>
#pragma once
#include "vec2.h"


std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
	stream << vec.x << ", " << vec.y << " | Length: " << vec.Length();
	return stream;
};
