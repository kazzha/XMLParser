#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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
	std::string line;

}

int main()
{
	std::vector<Sprite> sprite;

}