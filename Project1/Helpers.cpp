#pragma once
#include "vec2.h"
#pragma once
#include <functional>
#pragma once
#include <GLFW/glfw3.h>

void GLVec2f(const Vec2& vec2)
{
	std::apply(glVertex2f, vec2.Point());
}