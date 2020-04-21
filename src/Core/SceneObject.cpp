
namespace feg {

	template<class TComponent>
	TComponent* SceneObject::GetComponent(TComponent) const noexcept
	{
		const auto& id =  typeid(TComponent);
		for (auto comp : _components)
		{
			if (id == typeid(comp))
				return comp;
		}
		return nullptr;
	}
	template<class TComponent>
	TComponent* SceneObject::AddComponent(TComponent)
	{
		TComponent* comp = new TComponent();
		_components.insert(comp);
		return comp;
	}
	std::set<Component*> SceneObject::getComponents() const noexcept
	{
		return _components;
	}
}