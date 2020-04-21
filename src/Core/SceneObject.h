#pragma once
#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

namespace feg {

	class SceneObject
	{
	private:
		std::set<Component*> _components;
	public:
		template<class TComponent>
		TComponent* GetComponent(TComponent) const noexcept;
		template<class TComponent>
		TComponent* AddComponent(TComponent);
	public:
		std::set<Component*> getComponents() const noexcept;
	};
}

#endif // !SCENE_OBJECT_H