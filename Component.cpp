#include "Component.h"

namespace feg {

	std::set<Component*> Component::_cachedComponents;

	Component::Component() noexcept
	{
		_id = static_cast<unsigned int>(_cachedComponents.size());
		_cachedComponents.insert(this);
	}

	Component::~Component()
	{
		_cachedComponents.erase(this);
	}

	std::set<Component*> Component::getAllComponents() noexcept
	{
		return _cachedComponents;
	}

	/*Transform* Component::getTransform() noexcept
	{
		return nullptr;
	}*/

	bool operator<(const Component& lhs, const Component& rhs) noexcept
	{
		return lhs._id < rhs._id;
	}

}