#pragma once

#include "Test.h"
using namespace std;


Test::Test()
{
}


Test::~Test()
{
}

void Test::run() {

	Scene scene;

	int firstObjectID, secondObjectID;
	firstObjectID = scene.addObject();
	secondObjectID = scene.addObject();
	BaseObject *obj0, *obj1;
	obj0 = scene.getObject(firstObjectID);
	obj1 = scene.getObject(secondObjectID);

	obj0->addShape(BaseObject::DEF_TRIANGLE, 0, 0, 2, 2, 0, 1);
	obj0->addShape(BaseObject::DEF_CIRCLE, 50, 50, 20);
	obj0->shift(-10, 5);
	obj0->rotate(0.8);
	obj1->addShape(BaseObject::DEF_CIRCLE, -10, 60, 5);

	cout << obj0->toString() << endl;
	cout << obj1->toString() << endl;

	cout << "Czy kolizja wystapila: ";
	cout << obj0->areColliding(*obj1) << endl;

	vector <CollidingObjectsPair> v_collisions;
	scene.getCollidingPairs(&v_collisions);
	
	cout << "Liczba kolidujacych par: ";
	cout << v_collisions.size() << endl;
}