#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Sprite
{
public:
	std::string n;
	int x;
	int y;
	int w;
	int h;

	Sprite() : x(), y(), w(), h() {}
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites) 
{
	sprites.clear();

	std::ifstream file(filename, std::ifstream::binary);
	string line;
	string searchSprite{ R"(<sprite)" };
	string newString;
	size_t searchIndex{};
	

	Sprite s;

	while (!file.eof()) {

		std::getline(file, line);
		size_t start = line.find(searchSprite);

		if (start != std::string::npos)
		{
				size_t searchIndex = line.find("\"");
				size_t nextSearchIndex = line.find("\"", searchIndex + 1);
				newString = line.substr(searchIndex, nextSearchIndex - searchIndex);

				s.n = newString;

				searchIndex = line.find("\"", nextSearchIndex + 1);
				nextSearchIndex = line.find("\"", searchIndex + 1);
				newString = line.substr(searchIndex+1, nextSearchIndex - searchIndex);

				s.x = std::stoi(newString);

				searchIndex = line.find("\"", nextSearchIndex + 1);
				nextSearchIndex = line.find("\"", searchIndex + 1);
				newString = line.substr(searchIndex+1, nextSearchIndex - searchIndex);

				s.y = std::stoi(newString);

				searchIndex = line.find("\"", nextSearchIndex + 1);
				nextSearchIndex = line.find("\"", searchIndex + 1);
				newString = line.substr(searchIndex+1, nextSearchIndex - searchIndex);

				s.w = std::stoi(newString);

				searchIndex = line.find("\"", nextSearchIndex + 1);
				nextSearchIndex = line.find("\"", searchIndex + 1);
				newString = line.substr(searchIndex+1, nextSearchIndex - searchIndex);

				s.h = std::stoi(newString);
				
				sprites.push_back(s);

				line.clear();
				
			
		}
	}

	file.close();
	
}

int main()
{
	std::vector<Sprite> sprite;

	LoadXML("Data/mydata.xml", sprite);

	for (auto e : sprite)
	{
		cout << e.h << " " << e.n << " " << e.w << " " << e.x << " " << e.y << endl;
	}
}