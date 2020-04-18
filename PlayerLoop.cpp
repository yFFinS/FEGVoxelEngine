#include "PlayerLoop.h"
#include "Scene.h"
#include "Component.h"

namespace feg {

	void PlayerLoop::Update()
	{
		auto* objectsIt = Scene::GetCurrent()->GetAllObjects();
		for (auto obj = objectsIt; obj != objectsIt + Scene::GetCurrent()->GetObjectCount(); obj++)
		{
			for (auto comp : obj->getComponents())
			{
				comp
			}
		}
	}
}

