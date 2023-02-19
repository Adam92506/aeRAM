#pragma once

#include <string>

std::string Trim(std::string s);

std::vector<std::string> Split(const std::string& s, std::string split);

bool IsFloat(std::string s);