#include "dart-c.h"

#include "dart.hpp"

dart::simulation::World* g_World = nullptr;

void CreatePhysicsWorld()
{
	g_World = new dart::simulation::World;
}

void DestroyPhysicsWorld()
{
	if (g_World)
	{
		delete g_World;
	}
	g_World = nullptr;
}

void StepWorld(float seconds)
{
	if (g_World)
	{
		g_World->setTimeStep(seconds);
		g_World->step();
	}
}

int DartCTest(int x)
{
	return x * 2;
}
