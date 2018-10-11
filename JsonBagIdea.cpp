#include "JsonBagIdea.h"

std::string JsonBagIdea::GenerateJson(Profile profile)
{
	std::string json = "{\"name\":\"" + profile.name + "\",\"school_name\":\"" + profile.school_name + "\",\"age\":" + std::to_string(profile.age) + "}";

	return json;
}

std::string JsonBagIdea::GenerateJsonList(std::vector<Profile> profileList)
{
	std::string json = "{\"data\":[";

	for(int i = 0; i < profileList.size(); i++)
	{
		json.append("{\"name\":\"" + profileList[i].name + "\",\"school_name\":\"" + profileList[i].school_name + "\",\"age\":" + std::to_string(profileList[i].age) + "}" + ((i < profileList.size()-1)?",":""));
	}

	json.append("]}");

	return json;
}

Profile JsonBagIdea::CreateProfileFromJson(std::string json)
{
	Profile profile;

	std::string name_header = "\"name\":\"";
	std::string school_name_header = "\"school_name\":\"";
	std::string age_header = "\"age\":";

	size_t pos = json.find(name_header)+name_header.size();
	profile.name = json.substr(pos, json.find("\"", pos)-pos);
	pos = json.find(school_name_header)+school_name_header.size();
	profile.school_name = json.substr(pos, json.find("\"", pos)-pos);
	pos = json.find(age_header)+age_header.size();
	profile.age = std::stoi(json.substr(pos, json.find("}", pos)-pos));

	return profile;
}

std::vector<Profile> JsonBagIdea::CreateProfileVectorFromJson(std::string json)
{
	std::vector<Profile> profileList;

	std::string name_header = "\"name\":\"";
	std::string school_name_header = "\"school_name\":\"";
	std::string age_header = "\"age\":";

	size_t pos = json.find("\"data\":[")+8;
	std::string json_data = json.substr(pos, json.find("]", pos)-pos); 

	pos = 0;
	size_t end;
	
	while((end = json_data.find(name_header, pos)) != std::string::npos) 
	{
		size_t point = end+name_header.size();
		std::string _name = json_data.substr(point, json_data.find("\"", point)-point);
		point = json_data.find(school_name_header, point)+school_name_header.size();
		std::string _school_name = json_data.substr(point, json_data.find("\"", point)-point);
		point = json_data.find(age_header, point)+age_header.size();
		int _age = std::stoi(json_data.substr(point, json_data.find("}", point)-point));
		pos = point;

		profileList.push_back(Profile{_name, _school_name, _age});
	}

	return profileList;
}
