#include <iostream>
#include "Controller.hpp"
#include "Map.hpp"

using namespace std;

int main(int, char**)
{
	cout << "Hello world !" << endl;

	Map map{};
	map.chargerMap("./Carte.txt");

	return 0;
}