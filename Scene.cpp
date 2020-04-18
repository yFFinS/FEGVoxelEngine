#include "Scene.h"
#include "SafetyCheck.h"

namespace feg {

	std::set<SceneObject*> Scene::_sceneObjects;
	std::map < std::string, Scene* > Scene::_scenes;
	Scene* Scene::_currentScene = nullptr;
	Scene::Scene(const char*& name) : _name(name)
	{
		ASSERT(_scenes.find(name) != _scenes.end());
		_scenes[_name] = this;
	}

	void Scene::MakeCurrent(const char*& name)
	{
		ASSERT(_scenes.find(name) != _scenes.end());
		_scenes[name]->MakeCurrent();
	}

	void Scene::MakeCurrent()
	{
		_currentScene = this;
	}

	Scene* Scene::GetCurrent() noexcept
	{
		return _currentScene;
	}

	SceneObject* Scene::GetAllObjects() const noexcept
	{
		return *_sceneObjects.begin();
	}

	unsigned int Scene::GetObjectCount() const noexcept
	{
		return static_cast<unsigned int>(_sceneObjects.size());
	}

}