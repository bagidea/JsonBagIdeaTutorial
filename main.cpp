#include <fstream>

#include "JsonBagIdea.h"

int main(int argc, char* argv[])
{
	std::cout << "//////////// Struct Profile to Json //////////////" << std::endl << std::endl;
	
	Profile user1, user2, user3;
	std::vector<Profile> profileList;

	user1.name = "Thanawat Suriya";
	user1.school_name = "BagIdea";
	user1.age = 26;

	user2.name = "Hello Jaaa";
	user2.school_name = "BagIdea";
	user2.age = 12;

	user3.name = "Sample Najaa";
	user3.school_name = "Tontan";
	user3.age = 45;

	profileList.push_back(user1);
	profileList.push_back(user2);
	profileList.push_back(user3);

	std::string json_user1 = JsonBagIdea::GenerateJson(user1);
	std::cout << json_user1 << std::endl << std::endl;

	std::string jsonList = JsonBagIdea::GenerateJsonList(profileList);
	std::cout << jsonList << std::endl;

	std::cout << "\n//////////// Json to Profile Struct //////////////" << std::endl << std::endl;

	std::string jsonTest, jsonData;
	
	std::fstream file("jsonData.txt");
	std::getline(file, jsonTest);
	std::getline(file, jsonData);
	file.close();

	std::cout << jsonTest << std::endl << std::endl;

	Profile profileTest = JsonBagIdea::CreateProfileFromJson(jsonTest);
	std::cout << "Name: " << profileTest.name << "\tSchoolName: " << profileTest.school_name << "\tAge: " << profileTest.age << std::endl << std::endl;
	
	std::cout << jsonData << std::endl << std::endl;

	std::vector<Profile> profileData = JsonBagIdea::CreateProfileVectorFromJson(jsonData);

	for(Profile obj : profileData)
		std::cout << "Name: " << obj.name << "\tSchoolName: " << obj.school_name << "\tAge: " << obj.age << std::endl;

	return 0;
}
