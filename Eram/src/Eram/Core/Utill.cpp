#include "erpch.h"
#include "Utill.h"

#include <sstream>

std::string Trim(std::string s)
{
	s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
	s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
	return s;
}

std::vector<std::string> Split(const std::string& s, std::string split)
{
	std::vector<std::string> lines;
	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = s.find(split, prev)) != std::string::npos)
	{
		lines.push_back(s.substr(prev, pos - prev));
		prev = pos + 1;
	};
	lines.push_back(s.substr(prev));

	return lines;
}

bool IsFloat(std::string s)
{
	try
	{
		double returnValue = std::stof(s);
		return true;
	}
	catch (std::exception& ia)
	{
		return false;
	}
}