#include <iostream>
#include <string>
#include <vector>

struct Profile
{
	std::string name;
	std::string school_name;
	int age;
};

class JsonBagIdea
{
public:
	static std::string GenerateJson(Profile profile);
	static std::string GenerateJsonList(std::vector<Profile> profileList);
	static Profile CreateProfileFromJson(std::string json);
	static std::vector<Profile> CreateProfileVectorFromJson(std::string json);
};
