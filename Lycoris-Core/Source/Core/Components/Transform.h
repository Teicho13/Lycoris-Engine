#pragma once
#include "GLM/glm.hpp"

struct TransformComponent 
{

	glm::mat4 Transform;

	TransformComponent() = default;
	TransformComponent(const TransformComponent&) = default;
	TransformComponent(const glm::mat4& transform) : Transform(transform) {}
};