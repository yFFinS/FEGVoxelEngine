#pragma once
#ifndef SCENE_H
#define SCENE_H

namespace feg {

	class Scene
	{
	private:
		const char* _name;
		static std::set<SceneObject*> _sceneObjects;
		static std::map<std::string, Scene*> _scenes;
		static Scene* _currentScene;
	private:
		Scene() = delete;
	public:
		Scene(const char*& name);
		static void MakeCurrent(const char*& name);
		void MakeCurrent();
		static Scene* GetCurrent() noexcept;
		SceneObject* GetAllObjects() const noexcept;
		unsigned int GetObjectCount() const noexcept;
	};

}

#endif // !SCENE_H