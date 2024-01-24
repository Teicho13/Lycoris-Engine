#pragma once
#include <string>

struct NameComponent
{

	std::string Name;

	NameComponent() = default;
	NameComponent(const NameComponent&) = default;
	NameComponent(const std::string& name) : Name(name) {}
};