
namespace feg {

	void PlayerLoop::Update()
	{
		auto* objectsIt = Scene::GetCurrent()->GetAllObjects();
		for (auto obj = objectsIt; obj != objectsIt + Scene::GetCurrent()->GetObjectCount(); obj++)
		{
			for (auto comp : obj->getComponents())
			{
			};
		}
	}
}

