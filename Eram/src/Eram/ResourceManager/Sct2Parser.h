#pragma once

#include "Eram/Scope/VideoMap.h"

#include <glm/glm.hpp>

namespace Eram {

	class Sct2Parser {
	public:
		static void LoadMapsFromFile(std::vector<std::shared_ptr<VideoMap>>& videoMaps, std::string filePath);
	private:
		static bool ParsePoint(std::string& x, std::string& y, glm::vec2& point);
	};

}