#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
#include <set>

namespace feg {
	class Component
	{
	protected:
		Component() noexcept;
		~Component() noexcept;
	private:
		static std::set<Component*> _cachedComponents;
		//Transform* _transform;
		unsigned int _id;
	public:
		static std::set<Component*> getAllComponents() noexcept;
		//Transform* getTransform() noexcept;
		friend bool operator<(const Component& lhs, const Component& rhs) noexcept;
	};
}
#endif // !COMPONENT_H

