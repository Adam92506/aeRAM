#include "erpch.h"
#include "Sct2Parser.h"

#include "Eram/Core/Log.h"

#include "Eram/Core/Utill.h"

namespace Eram {

	void Sct2Parser::LoadMapsFromFile(std::vector<std::shared_ptr<VideoMap>>& videoMaps, std::string filePath)
	{
		std::vector<std::string> lines;

		{
			std::string text;
			std::ifstream in(filePath, std::ios::in, std::ios::binary);
			if (in)
			{
				in.seekg(0, std::ios::end);
				text.resize(in.tellg());
				in.seekg(0, std::ios::beg);
				in.read(&text[0], text.size());
				in.close();
			}
			else
			{
				ER_ERROR("Could not open file: {0}", filePath);
			}

			lines = Split(text, "\n");
		}


		std::shared_ptr<VideoMap> currentMap = nullptr;
		std::string sectionName = "";
		for (int i = 0; i < lines.size(); i++)
		{
			std::string data;

			if (lines[i].find(";") != std::string::npos)
			{
				data = lines[i].substr(0, lines[i].find(";"));
			}
			else { data = lines[i]; }

			if ((data.find("[") != std::string::npos) && (data.find("]") != std::string::npos))
			{
				sectionName = data.substr(data.find("[") + 1, data.find("]") - data.find("[") - 1);
				std::transform(data.begin(), data.end(), data.begin(), ::toupper);
				continue;
			}

			if (data.size() == 0 || (sectionName != "SID" && sectionName != "STAR")) { continue; }

			if (Trim(data.substr(0, 1)).size() != 0)
			{
				std::string mapName = Trim(data.substr(0, 25));
				data = data.substr(26);

				currentMap = std::make_shared<VideoMap>(mapName);
				videoMaps.push_back(currentMap);
			}

			if (currentMap != nullptr)
			{
				std::vector<std::string> dataParts = Split(Trim(data), " ");
				if (dataParts.size() < 4) { continue; }

				glm::vec2 point1 = { 0, 0 };
				glm::vec2 point2 = { 0, 0 };

				if (Sct2Parser::ParsePoint(dataParts[0], dataParts[1], point1) && Sct2Parser::ParsePoint(dataParts[2], dataParts[3], point2))
				{
					currentMap->AddVertex(point1);
					currentMap->AddVertex(point2);
				}
			}
		}

		ER_INFO("Loaded sector file: {0}", filePath);
	}

	bool Sct2Parser::ParsePoint(std::string& x, std::string& y, glm::vec2& point)
	{
		std::vector<std::string> lat = Split(x, ".");
		std::vector<std::string> lon = Split(y, ".");

		std::string latHem = lat[0].substr(0, 1);
		std::string lonHem = lon[0].substr(0, 1);
		lat[0].erase(0, 1);
		lon[0].erase(0, 1);

		float latitude = 0, longitude = 0;
		
		if (lat.size() == 2 && IsFloat(x))
		{
			latitude = std::stof(x);
		}
		else
		{
			if (lat[0].size() >= 2 && IsFloat(lat[0]))
			{
				latitude += std::stof(lat[0]);
			}
			else
			{
				return false;
			}
			if (lat.size() > 2 && IsFloat(lat[1]))
			{
				latitude += std::stof(lat[1]) / 60;
			}
			if (lat.size() >= 3 && IsFloat(lat[2]))
			{
				latitude += std::stof(lat[2]) / 3600;
			}
			if (lat.size() >= 4 && IsFloat(lat[3]))
			{
				latitude += std::stof(lat[3]) / (3600 * pow(10, Trim(lat[3]).size()));
			}
		}
		if (latHem == "S") { latitude *= -1; }

		if (lon.size() == 2 && IsFloat(y))
		{
			longitude = std::stof(y);
		}
		else
		{
			longitude += std::stof(lon[0]);
			if (lon.size() > 2 && IsFloat(lat[1]))
			{
				longitude += std::stof(lon[1]) / 60;
			}
			if (lon.size() >= 3 && IsFloat(lat[2]))
			{
				longitude += std::stof(lon[2]) / 3600;
			}
			if (lon.size() >= 4 && IsFloat(lat[3]))
			{
				longitude += std::stof(lon[3]) / (3600 * pow(10, Trim(lon[3]).size()));
			}
		}
		if (lonHem == "W") { longitude *= -1; }

		point = { longitude, latitude };
	}

}