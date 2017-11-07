
#include "Scene.h"

using namespace std;

Scene::Scene()
{
}

Scene::~Scene()
{
}

int Scene::addObject()
{
	objects.push_back(new BaseObject);
	return objects.size()-1;
}

void Scene::getCollidingPairs(vector<CollidingObjectsPair>* collisions) {
	for (int i = 0; i < objects.size(); i++) {
		for (int j = i + 1; j < objects.size(); j++) {
			if (objects[i]->areColliding(*objects[j])) {
				collisions->push_back(CollidingObjectsPair(objects[i], objects[j]));
			}
		}
	}
}

BaseObject * Scene::getObject(int ID)
{
	return objects[ID];
}
