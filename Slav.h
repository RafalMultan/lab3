#pragma once
#include <string>
#include <vector>

using namespace std;
enum sex{male,female};
class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;
	
	string _name;
	int _id;

public:
	Slav();

	static int counter() { return _counter; }
	sex _sex(){if(_name[_name.size()-1]!='a')return male;else return female;}
	string name() { return _name; }
	int id() { return _id; }

	string description();
};
