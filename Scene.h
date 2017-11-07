#pragma once
#include <vector>
#include "BaseObject.h"
#include "CollidingObjectsPair.h"

using namespace std;
class Scene
{
private:
	vector<BaseObject*> objects;
public:
	Scene();
	~Scene();
	int addObject();
	void getCollidingPairs(vector<CollidingObjectsPair>* collisions);
	BaseObject* getObject(int ID);
};

