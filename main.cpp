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
	
	std::getline(file, line);

	size_t start = line.find(searchSprite);

	if (start != std::string::npos)
	{

	}


	
}

int main()
{
	std::vector<Sprite> sprite;

}